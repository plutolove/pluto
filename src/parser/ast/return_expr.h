#pragma once
#include "parser/ast/ast_node.h"

namespace pluto {

class ReturnExpr : public AstNode {
 public:
  ReturnExpr(Location loc, const AstNodePtr& expr)
      : AstNode(AstNodeType::ReturnExpr, loc), expr_(expr) {}

  AstNodePtr getExpr() const { return expr_; }

  static bool classof(const AstNode* c) {
    return c->getType() == AstNodeType::ReturnExpr;
  }

 protected:
  AstNodePtr expr_{nullptr};
};

}  // namespace pluto