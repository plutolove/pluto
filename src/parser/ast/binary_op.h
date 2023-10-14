#pragma once
#include <type_traits>

#include "parser/ast/ast_node.h"

namespace pluto {

/*
EQ  : '=' | '==';
NEQ : '<>';
NEQ: '!=';
LT  : '<';
LTE : '<=' | '!>';
GT  : '>';
GTE : '>=' | '!<';

PLUS: '+';
MINUS: '-';
ASTERISK: '*';
SLASH: '/';
PERCENT: '%';
AMPERSAND: '&';
PIPE: '|';
HAT: '^';
*/
class BinaryOp : public AstNode {
 public:
  enum class BinaryOpType : int8_t {
    Unknow,
    // cmp
    EQ,
    NEQ,
    LT,
    LTE,
    GT,
    GTE,
    // arithmetic
    PLUS,
    MINUS,
    ASTERISK,
    SLASH,
    PERCENT,
    AMPERSAND,
    PIPE,
    HAT,
    // logical
    AND,
    OR,
  };

  BinaryOp();
  BinaryOp(Location loc, const AstNodePtr& left, BinaryOpType opt,
           const AstNodePtr& right);
  AstNodePtr getlhs() const { return left_; }
  AstNodePtr getrhs() const { return right_; }
  BinaryOpType getOp() const { return opt_; }

  static bool classof(const AstNode* c) {
    return c->getType() == AstNodeType::BinaryOP;
  }

  virtual std::string toString() const {
    return left_->toString() + " OP " + right_->toString();
  }

 protected:
  AstNodePtr left_{nullptr};
  BinaryOpType opt_{BinaryOpType::Unknow};
  AstNodePtr right_{nullptr};
};

}  // namespace pluto