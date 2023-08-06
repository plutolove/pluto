#pragma once
#include <memory>

#include "parser/ast/ast_node.h"
#include "parser/ast/function_def.h"

namespace pluto {

class ModuleAst : public AstNode {
 public:
  ModuleAst(Location loc, const std::vector<FunctionDefPtr>& functions)
      : AstNode(AstNodeType::ModuleAst, loc), functions_(functions) {}

  const std::vector<FunctionDefPtr>& getFunctions() const { return functions_; }

 protected:
  std::vector<FunctionDefPtr> functions_;
};

using ModuleAstPtr = std::shared_ptr<ModuleAst>;
}  // namespace pluto