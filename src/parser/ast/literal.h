#pragma once
#include <cstdint>
#include <vector>

#include "parser/ast/ast_node.h"

namespace pluto {

class LiteralDouble : public AstNode {
 public:
  LiteralDouble(Location loc, double value)
      : AstNode(AstNodeType::LiteralDouble, loc), value_(value) {}

  double getValue() const { return value_; }

  static bool classof(const AstNode* c) {
    return c->getType() == AstNodeType::LiteralDouble;
  }

 protected:
  double value_;
};

class LiteralTensor : public AstNode {
 public:
  LiteralTensor(Location loc, const std::vector<AstNodePtr>& values,
                const std::vector<int64_t>& dims)
      : AstNode(AstNodeType::LiteralTensor, loc),
        values_(values),
        dims_(dims) {}

  const std::vector<AstNodePtr>& getValues() const { return values_; }

  const std::vector<int64_t>& getDims() const { return dims_; }

  static bool classof(const AstNode* c) {
    return c->getType() == AstNodeType::LiteralTensor;
  }

 protected:
  std::vector<AstNodePtr> values_;
  std::vector<int64_t> dims_;
};
}  // namespace pluto