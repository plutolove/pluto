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

 protected:
  double value_;
};

class LiteralTensor : public AstNode {
 public:
  LiteralTensor(Location loc, const std::vector<AstNodePtr>& values,
                const std::vector<int32_t>& dims)
      : AstNode(AstNodeType::LiteralTensor, loc),
        values_(values),
        dims_(dims) {}

  const std::vector<AstNodePtr>& getValues() const { return values_; }

  const std::vector<int32_t>& getDims() const { return dims_; }

 protected:
  std::vector<AstNodePtr> values_;
  std::vector<int32_t> dims_;
};
}  // namespace pluto