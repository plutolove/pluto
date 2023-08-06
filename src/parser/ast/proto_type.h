#pragma once
#include <memory>
#include <vector>

#include "parser/ast/ast_node.h"

namespace pluto {

class VariableExpr : public AstNode {
 public:
  VariableExpr(Location loc, const std::string& name)
      : AstNode(AstNodeType::VariableExpr, loc) {}

  const std::string& getVarName() const { return name_; }

 protected:
  std::string name_;
};
using VariableExprPtr = std::shared_ptr<VariableExpr>;

class ProtoType : public AstNode {
 public:
  ProtoType(Location loc, const std::string& name,
            const std::vector<VariableExprPtr>& args)
      : AstNode(AstNodeType::ProtoType, loc), name_(name), args_(args) {}

  const std::string& getProtoName() const { return name_; }

  const std::vector<VariableExprPtr>& getArgs() const { return args_; }

 protected:
  std::string name_;
  std::vector<VariableExprPtr> args_;
};

using ProtoTypePtr = std::shared_ptr<ProtoType>;
}  // namespace pluto