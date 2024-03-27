#pragma once
#include <memory>

#include "common/noncopyable.h"
#include "folly/futures/Future.h"

namespace pluto {

class AsynchronousReader : public noncopyable {
 public:
  struct FileDescriptor {
    virtual ~FileDescriptor() = default;
  };
  using FileDescriptorPtr = std::shared_ptr<FileDescriptor>;

  struct LocalFileDescriptor : public FileDescriptor {
    explicit LocalFileDescriptor(int fd_) : fd(fd_) {}
    int fd;
  };

  struct Request {
    FileDescriptorPtr descriptor;
    size_t offset = 0;
    size_t size = 0;
    char* buf = nullptr;
  };

  struct Result {
    size_t size = 0;
    size_t offset = 0;
    char* buf = nullptr;
  };

  virtual folly::Future<Result> submit(Request request) = 0;
  virtual Result execute(Request request) = 0;

  virtual void wait() = 0;

  virtual ~AsynchronousReader() = default;
};

using AsynchronousReaderPtr = std::shared_ptr<AsynchronousReader>;

}  // namespace pluto