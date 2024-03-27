#include <fcntl.h>
#include <folly/experimental/FunctionScheduler.h>
#include <folly/init/Init.h>

#include <atomic>
#include <chrono>
#include <iostream>
#include <memory>
#include <mutex>
#include <string_view>
#include <thread>

#include "common/exception.h"
#include "common/log.h"
#include "common/typeid_cast.h"
#include "fmt/format.h"
#include "folly/executors/CPUThreadPoolExecutor.h"
#include "folly/executors/FutureExecutor.h"
#include "folly/executors/thread_factory/NamedThreadFactory.h"
#include "folly/executors/thread_factory/ThreadFactory.h"
#include "io/asynchronous_reader.h"
#include "io/iouring_reader.h"

// auto threadFactory =
//     std::make_shared<folly::NamedThreadFactory>("async_copp_sql");

// static folly::FutureExecutor<folly::CPUThreadPoolExecutor>*
// copp_thread_pool() {
//   static folly::FutureExecutor<folly::CPUThreadPoolExecutor>*
//       copp_thread_pool_ptr =
//           new folly::FutureExecutor<folly::CPUThreadPoolExecutor>(
//               std::make_pair(3, 3), threadFactory);
//   return copp_thread_pool_ptr;
// }

struct TT {
  TT()
      : pool(std::make_shared<folly::CPUThreadPoolExecutor>(
            1, std::make_shared<folly::NamedThreadFactory>("copp"))) {
    pool->add([this]() {
      while (not cancel.load(std::memory_order_relaxed)) {
        LOG_INFO("thread running--------------");
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
      }
    });
  }
  ~TT() {
    LOG_INFO("free thread-----------");
    cancel.store(true, std::memory_order_relaxed);
    pool->join();
  }
  std::atomic<bool> cancel{false};
  std::shared_ptr<folly::CPUThreadPoolExecutor> pool;
};

void periodicTask() {
  std::cout << "任务执行: "
            << std::chrono::system_clock::now().time_since_epoch().count()
            << std::endl;
}

struct BUF {
  char buf[512];
};

int main(int argc, char** argvs) {
  // TT t{};
  // // std::this_thread::sleep_for(std::chrono::microseconds(19));

  // folly::FunctionScheduler scheduler;

  // scheduler.start();

  // scheduler.addFunction(folly::Func(periodicTask),
  //                       std::chrono::milliseconds(100),
  //                       "periodicTaskLabel"
  // );

  // std::this_thread::sleep_for(std::chrono::seconds(1));

  // scheduler.shutdown();
  auto fd =
      ::open("/data01/home/mengshangqi.123/workspace/ClickHouse/CMakeLists.txt",
             O_RDONLY | O_LARGEFILE);
  pluto::AsynchronousReader::FileDescriptorPtr file_dpr =
      std::make_shared<pluto::AsynchronousReader::LocalFileDescriptor>(fd);
  pluto::IOUringReader reader(128);
  std::vector<BUF> bufs;
  std::vector<folly::Future<pluto::AsynchronousReader::Result>> res;
  char buf[512];
  std::mutex mtx;
  bufs.resize(100);

  auto pool = std::make_shared<folly::CPUThreadPoolExecutor>(
      20, std::make_shared<folly::NamedThreadFactory>("copp"));

  for (size_t i = 0; i < 10; i++) {
    auto func = [i, &file_dpr, &reader, &bufs, &res, &mtx]() {
      pluto::IOUringReader::Request req{
          .descriptor = file_dpr, .offset = i, .size = 512, .buf = bufs[i].buf};

      auto f = reader.submit(req);
      std::lock_guard lock(mtx);
      res.push_back(std::move(f));
    };
    pool->add(func);
    // std::move(f).then([](folly::Try<pluto::IOUringReader::Result> res) {
    //   LOG_INFO("msq debug buf: {}", std::string(res->buf));
    // });
  }
  pool->join();
  LOG_INFO("-----------------------------");
  for (auto& f : res) {
    std::move(f).then([](folly::Try<pluto::IOUringReader::Result> val) {
      LOG_INFO("ptr: {}, str: {}", fmt::ptr(val->buf),
               std::string_view(val->buf, 512));
    });
  }
  return 0;
}
