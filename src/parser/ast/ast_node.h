#pragma once
#include <memory>
#include <string>

namespace pluto {

struct AstNode;

using AstNodePtr = std::shared_ptr<AstNode>;
using AstNodeRawPtr = AstNode*;

struct Location {
  size_t line;  ///< line number.
  size_t col;   ///< column number.
};

enum class AstNodeType : int32_t {
  Unknow = 0,
  BinaryOP,
  UnaryOp,
  FunctionCall,
  VarDecl,
  ReturnExpr,
  VariableExpr,
  ProtoType,
  FunctionDef,
  ModuleAst,
  LiteralDouble,
  LiteralTensor,
};

class AstNode {
 public:
  AstNode() : ntype_(AstNodeType::Unknow) {}
  AstNode(AstNodeType type) : ntype_(type) {}
  AstNode(AstNodeType type, Location loc)
      : ntype_(type), location_(std::move(loc)) {}

  virtual ~AstNode() = default;
  virtual std::string toString() const { return "AstNde"; }
  AstNodeType getType() const { return ntype_; }

 protected:
  AstNodeType ntype_;
  Location location_;
};

}  // namespace pluto