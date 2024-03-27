#include "io/iouring_reader.h"

#include <atomic>
#include <mutex>

#include "common/exception.h"
#include "common/log.h"
#include "common/typeid_cast.h"
#include "folly/futures/Promise.h"
#include "folly/system/ThreadName.h"
#include "liburing.h"

namespace pluto {

std::string errnoToString(int the_errno) {
  const size_t buf_size = 128;
  char buf[buf_size];
  return fmt::format("errno: {}, strerror: {}", the_errno,
                     strerror_r(the_errno, buf, sizeof(buf)));
}

IOUringReader::IOUringReader(uint32_t entries) {
  struct io_uring_probe* probe = io_uring_get_probe();
  if (!probe) {
    ThrowException(-1, "io_uring_get_probe failed");
    return;
  }

  bool is_supported = io_uring_opcode_supported(probe, IORING_OP_READ);
  io_uring_free_probe(probe);

  if (!is_supported) {
    ThrowException(-1, "not support iouring");
    return;
  }

  struct io_uring_params params = {
      .sq_entries = 0,  // filled by the kernel, initializing to silence warning
      .cq_entries = 0,  // filled by the kernel, initializing to silence warning
      .flags = 0,
      .sq_thread_cpu =
          0,  // Unused (IORING_SETUP_SQ_AFF isn't set). Silences warning
      .sq_thread_idle =
          0,          // Unused (IORING_SETUP_SQPOL isn't set). Silences warning
      .features = 0,  // filled by the kernel, initializing to silence warning
      .wq_fd =
          0,  // Unused (IORING_SETUP_ATTACH_WQ isn't set). Silences warning.
      .resv = {0, 0, 0},  // "The resv array must be initialized to zero."
      .sq_off = {},  // filled by the kernel, initializing to silence warning
      .cq_off = {},  // filled by the kernel, initializing to silence warning
  };

  int ret = io_uring_queue_init_params(entries, &ring, &params);
  if (ret < 0) {
    ThrowException(-1, "init iouring failed");
  }

  cq_entries = params.cq_entries;
  ring_completion_monitor = std::make_unique<folly::CPUThreadPoolExecutor>(
      1, std::make_shared<folly::NamedThreadFactory>("iouring_reader"));
  ring_completion_monitor->add([this]() { monitorRing(); });
}

folly::Future<AsynchronousReader::Result> IOUringReader::submit(
    Request request) {
  assert(request.size);
  std::unique_lock lock(mtx_);

  auto req_id = reinterpret_cast<uint64_t>(request.buf);
  folly::Promise<AsynchronousReader::Result> promise;
  auto enqueued_request = EnqueuedRequest{.promise = std::move(promise),
                                          .request = request,
                                          .resubmitting = false,
                                          .bytes_read = 0};

  if (in_flight_requests.size() < cq_entries) {
    int ret = submitToRing(enqueued_request);
    if (ret > 0) {
      const auto [kv, success] =
          in_flight_requests.emplace(req_id, std::move(enqueued_request));
      if (!success) {
        return makeFailedResult(Exception(-1, "resubmit req_id: {}", req_id));
      }
      return (kv->second).promise.getFuture();
    } else {
      return makeFailedResult(
          Exception(-1, "submit failed, msg: {}",
                    ret < 0 ? errnoToString(-ret) : "no SQE submitted"));
    }
  } else {
    pending_requests.push_back(std::move(enqueued_request));
    return pending_requests.back().promise.getFuture();
  }
}

int IOUringReader::submitToRing(EnqueuedRequest& enqueued) {
  struct io_uring_sqe* sqe = io_uring_get_sqe(&ring);
  if (!sqe) return 0;
  auto request = enqueued.request;
  auto request_id = reinterpret_cast<int64_t>(request.buf);
  int fd = typeid_cast<const LocalFileDescriptor&>(*request.descriptor).fd;

  io_uring_sqe_set_data64(sqe, request_id);
  io_uring_prep_read(sqe, fd, request.buf,
                     static_cast<unsigned>(request.size - enqueued.bytes_read),
                     request.offset + enqueued.bytes_read);
  int ret = 0;
  do {
    ret = io_uring_submit(&ring);
  } while (ret == -EINTR || ret == -EAGAIN);

  return ret;
}

void IOUringReader::failRequest(const EnqueuedIterator& requestIt,
                                const Exception& ex) {
  (requestIt->second).promise.setException(ex);
  finalizeRequest(requestIt);
}

void IOUringReader::finalizeRequest(const EnqueuedIterator& requestIt) {
  in_flight_requests.erase(requestIt);

  if (!pending_requests.empty()) {
    auto pending_request = std::move(pending_requests.front());
    pending_requests.pop_front();

    int ret = submitToRing(pending_request);
    if (ret > 0) {
      auto request_id = reinterpret_cast<int64_t>(pending_request.request.buf);
      if (!in_flight_requests.count(request_id))
        in_flight_requests.emplace(request_id, std::move(pending_request));
      else
        failPromise(pending_request.promise,
                    Exception(-1,
                              "Tried enqueuing pending read request for {} "
                              "that is already submitted",
                              request_id));
    } else {
      failPromise(
          pending_request.promise,
          Exception(-1, "Failed submitting SQE for pending request: {}",
                    ret < 0 ? errnoToString(-ret) : "no SQE submitted"));
    }
  }
}

void IOUringReader::monitorRing() {
  folly::setThreadName("iouring_monitor");
  while (not cancelled.load(std::memory_order_relaxed)) {
    // 等待读事件
    struct io_uring_cqe* cqe = nullptr;
    int ret = io_uring_wait_cqe(&ring, &cqe);
    if (ret == -EAGAIN || ret == -EINTR) {
      LOG_ERROR("Restarting waiting for CQEs due to: {}", errnoToString(-ret));

      io_uring_cqe_seen(&ring, cqe);
      continue;
    }

    if (ret < 0) {
      LOG_ERROR("Failed waiting for io_uring CQEs: {}", errnoToString(-ret));
      continue;
    }

    if (!cqe) {
      LOG_ERROR("Unexpectedly got a null CQE, continuing");
      continue;
    }

    if (cancelled.load(std::memory_order_relaxed) ||
        (cqe && cqe->user_data == 0)) {
      LOG_DEBUG("Stopping IOUringMonitor thread");

      io_uring_cqe_seen(&ring, cqe);
      break;
    }

    std::unique_lock lock{mtx_};
    auto request_id = cqe->user_data;
    const auto it = in_flight_requests.find(request_id);
    // 读到的req不在队列中
    if (it == in_flight_requests.end()) {
      LOG_ERROR(
          "Got a completion event for a request {} that was not submitted",
          request_id);

      io_uring_cqe_seen(&ring, cqe);
      continue;
    }

    auto& enqueued = it->second;
    // 结果异常重新提交
    if (cqe->res == -EAGAIN || cqe->res == -EINTR) {
      enqueued.resubmitting = true;

      ret = submitToRing(enqueued);
      if (ret <= 0) {
        failRequest(
            it, Exception(-1, "Failed re-submitting SQE: {}",
                          ret < 0 ? errnoToString(-ret) : "no SQE submitted"));
      }

      io_uring_cqe_seen(&ring, cqe);
      continue;
    }

    if (cqe->res < 0) {
      auto req = enqueued.request;
      int fd = typeid_cast<const LocalFileDescriptor&>(*req.descriptor).fd;
      failRequest(
          it, Exception(-1,
                        "Failed reading {} bytes at offset {} to address {} "
                        "from fd {}: {}",
                        req.size, req.offset, static_cast<void*>(req.buf), fd,
                        errnoToString(-cqe->res)));

      io_uring_cqe_seen(&ring, cqe);
      continue;
    }

    size_t bytes_read = cqe->res;
    size_t total_bytes_read = enqueued.bytes_read + bytes_read;
    // 读的数据比要读的size小, 重新提交
    if (bytes_read > 0 && total_bytes_read < enqueued.request.size) {
      enqueued.resubmitting = true;
      enqueued.bytes_read += bytes_read;

      ret = submitToRing(enqueued);
      if (ret <= 0) {
        failRequest(
            it, Exception(-1, "Failed re-submitting SQE for short read: {}",
                          ret < 0 ? errnoToString(-ret) : "no SQE submitted"));
      }
    } else {
      enqueued.promise.setValue(Result{.size = total_bytes_read,
                                       .offset = enqueued.request.offset,
                                       .buf = enqueued.request.buf});
      finalizeRequest(it);
    }
    io_uring_cqe_seen(&ring, cqe);
  }
}

IOUringReader::~IOUringReader() {
  cancelled.store(true, std::memory_order_relaxed);
  {
    std::unique_lock lock{mtx_};

    struct io_uring_sqe* sqe = io_uring_get_sqe(&ring);
    io_uring_prep_nop(sqe);
    io_uring_sqe_set_data(sqe, nullptr);
    io_uring_submit(&ring);
  }
  ring_completion_monitor->join();
  io_uring_queue_exit(&ring);
}

}  // namespace pluto