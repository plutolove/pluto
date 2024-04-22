// #include <chrono>
// #include <iostream>
// #include <memory>
// #include <thread>

// #include "absl/flags/flag.h"
// #include "absl/flags/internal/flag.h"
// #include "absl/flags/parse.h"
// #include "absl/random/random.h"
// #include "absl/status/status.h"
// #include "absl/status/statusor.h"
// #include "absl/time/time.h"
// #include "antlr4-runtime.h"
// #include "common/exception.h"
// #include "common/log.h"
// #include "common/typeid_cast.h"
// #include "fmt/format.h"
// #include "ir/mlir_gen.h"
// #include "jit/jit.h"
// #include "mlir/IR/Builders.h"
// #include "mlir/IR/BuiltinTypes.h"
// #include "mlir/IR/MLIRContext.h"
// #include "parser/ast_builder.h"
// #include "transform/transform_ast.h"

// ABSL_FLAG(std::string, input, "", "input source file path");
// ABSL_FLAG(std::string, emit, "", "transform ast/mlir");

// int main(int argc, char** argvs) {
//   absl::ParseCommandLine(argc, argvs);
//   auto path = absl::GetFlag(FLAGS_input);
//   auto emit = absl::GetFlag(FLAGS_emit);
//   INFO("input: {}, emit: {}", path, emit);
//   auto& jit = pluto::SQLJit::getInstance();
//   pluto::ASTBuilder builder(path);
//   auto module_ast = builder.parse_file(path);
//   if ("ast" == emit) {
//     pluto::transformAst(module_ast);
//   } else if ("mlir" == emit) {
//     DumpIR(module_ast);
//   }
//   return 0;
// }

#include <type_traits>

#include "common/dag.h"
#include "common/typelist.h"

template <typename X, typename Y>
struct Cmp {
  static constexpr auto value = sizeof(X) < sizeof(Y);
};

template <int ID>
struct Node {
  static constexpr auto id = ID;
};

using namespace pluto;
int main() {
  using x = TypeList<int, double, float, char, std::string>;
  print(x{});
  using number = Filter_t<x, std::is_arithmetic>;
  print(number{});
  auto type_in = TypeIn_v<x, std::vector<int>>;
  INFO("{}", type_in);

  using c = Concat_t<x, x>;
  print(c{});
  using u = Unique_t<c>;
  print(u{});
  using sort_ = Sort_t<c, Cmp>;
  print(sort_{});

  using g = Graph<auto (*)(Node<0>)->auto (*)(Node<1>)->auto (*)(Node<3>)->void,
                  auto (*)(Node<1>)->auto (*)(Node<2>)->auto (*)(Node<3>)->void,
                  auto (*)(Node<3>)->auto (*)(Node<1>)->void,
                  auto (*)(Node<1>)->auto (*)(Node<4>)->void>::type;
  print(g{});
  using from = Filter_t<g, EdgeTrait<Node<0>>::IsFrom>;
  print(from{});
  using to = Map_t<from, EdgeTrait<>::GetTo>::type;
  print(to{});
  using path = FindShortestPath<g::type, Node<0>, Node<4>>::type;
  print(path{});
  return 0;
}