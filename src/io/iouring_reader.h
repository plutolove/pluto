#pragma once
#include <mutex>

#include "common/exception.h"
#include "folly/executors/CPUThreadPoolExecutor.h"
#include "io/asynchronous_reader.h"
#include "liburing.h"

namespace pluto {

class IOUringReader : public AsynchronousReader {
 private:
  std::mutex mtx_;
  struct io_uring ring;
  uint32_t cq_entries;
  std::atomic<bool> cancelled;
  std::unique_ptr<folly::CPUThreadPoolExecutor> ring_completion_monitor;

  struct EnqueuedRequest {
    folly::Promise<AsynchronousReader::Result> promise;
    AsynchronousReader::Request request;
    bool resubmitting;
    size_t bytes_read;
  };

  std::deque<EnqueuedRequest> pending_requests;
  std::unordered_map<int64_t, EnqueuedRequest> in_flight_requests;

  int submitToRing(EnqueuedRequest& enqueued);

  using EnqueuedIterator =
      std::unordered_map<int64_t, EnqueuedRequest>::iterator;

  void failRequest(const EnqueuedIterator& requestIt, const Exception& ex);
  void finalizeRequest(const EnqueuedIterator& requestIt);

  void monitorRing();

  template <typename T>
  inline void failPromise(folly::Promise<T>& promise, const Exception& ex) {
    promise.setException(ex);
  }

  inline folly::Future<Result> makeFailedResult(const Exception& ex) {
    auto promise = folly::Promise<Result>{};
    failPromise(promise, ex);
    return promise.getFuture();
  }

 public:
  IOUringReader(uint32_t entries);
  virtual ~IOUringReader();

  virtual folly::Future<Result> submit(Request request) override;
  virtual Result execute(Request request) override {
    ThrowException(-1, "not implement");
  }

  virtual void wait() override {}
};

}  // namespace pluto