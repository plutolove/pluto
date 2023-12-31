#include "parser/ast/binary_op.h"

#include "parser/ast/ast_node.h"

namespace pluto {
BinaryOp::BinaryOp() : AstNode(AstNodeType::BinaryOP) {}

BinaryOp::BinaryOp(Location loc, const AstNodePtr& left, BinaryOpType opt,
                   const AstNodePtr& right)
    : AstNode(AstNodeType::BinaryOP, loc),
      left_(left),
      opt_(opt),
      right_(right) {}

}  // namespace pluto