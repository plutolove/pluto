#pragma once
#include "parser/ast/ast_node.h"

namespace pluto {

class ReturnExpr : public AstNode {
 public:
  ReturnExpr(Location loc, const AstNodePtr& expr)
      : AstNode(AstNodeType::ReturnExpr, loc), expr_(expr) {}

  AstNodePtr getExpr() const { return expr_; }

 protected:
  AstNodePtr expr_{nullptr};
};

}  // namespace pluto