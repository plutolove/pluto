#include <chrono>
#include <iostream>
#include <memory>
#include <thread>

#include "absl/flags/flag.h"
#include "absl/flags/internal/flag.h"
#include "absl/flags/parse.h"
#include "absl/random/random.h"
#include "absl/status/status.h"
#include "absl/status/statusor.h"
#include "absl/time/time.h"
#include "antlr4-runtime.h"
#include "common/exception.h"
#include "common/log.h"
#include "common/type_cast.h"
#include "fmt/format.h"
#include "jit/jit.h"
#include "mlir/IR/Builders.h"
#include "mlir/IR/BuiltinTypes.h"
#include "mlir/IR/MLIRContext.h"
#include "parser/ast_builder.h"

ABSL_FLAG(std::string, input, "", "input source file path");

int main(int argc, char** argvs) {
  absl::ParseCommandLine(argc, argvs);
  auto path = absl::GetFlag(FLAGS_input);
  std::cout << "flags: " << absl::GetFlag(FLAGS_input) << std::endl;
  auto& jit = pluto::SQLJit::getInstance();
  pluto::ASTBuilder builder;
  builder.parse("def x ( )  { D2w8E4 ( )    ;    }  ");
  builder.parse_file("/home/meng/workspace/compiler/data/test.toy");
  return 0;
}