#pragma once
#include <vector>

#include "absl/container/internal/compressed_tuple.h"
#include "parser/ast/ast_node.h"

namespace pluto {

struct VarType {
  std::vector<int32_t> dims;
};

class VarDeclExpr : public AstNode {
 public:
  VarDeclExpr(Location loc, const std::string& name, VarType type,
              const AstNodePtr& value)
      : AstNode(AstNodeType::VarDecl, loc),
        name_(name),
        type_(std::move(type)),
        value_(value) {}

  const std::string& getVarName() const { return name_; }

  VarType getVarType() const { return type_; }

  AstNodePtr getVarExpr() const { return value_; }

 protected:
  std::string name_;
  VarType type_;
  AstNodePtr value_;
};

}  // namespace pluto