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
#include "common/typeid_cast.h"
#include "fmt/format.h"
#include "ir/mlir_gen.h"
#include "jit/jit.h"
#include "mlir/IR/Builders.h"
#include "mlir/IR/BuiltinTypes.h"
#include "mlir/IR/MLIRContext.h"
#include "parser/ast_builder.h"
#include "transform/transform_ast.h"

ABSL_FLAG(std::string, input, "", "input source file path");
ABSL_FLAG(std::string, emit, "", "transform ast/mlir");

int main(int argc, char** argvs) {
  absl::ParseCommandLine(argc, argvs);
  auto path = absl::GetFlag(FLAGS_input);
  auto emit = absl::GetFlag(FLAGS_emit);
  INFO("input: {}, emit: {}", path, emit);
  auto& jit = pluto::SQLJit::getInstance();
  pluto::ASTBuilder builder(path);
  auto module_ast = builder.parse_file(path);
  if ("ast" == emit) {
    pluto::transformAst(module_ast);
  } else if ("mlir" == emit) {
    mlir::MLIRContext context;
    // Load our Dialect in this MLIR Context.
    context.getOrLoadDialect<mlir::pluto::PlutoDialect>();
    mlir::OwningOpRef<mlir::ModuleOp> module = mlirGen(context, *module_ast);
    if (!module) return 1;

    module->dump();
  }
  return 0;
}
