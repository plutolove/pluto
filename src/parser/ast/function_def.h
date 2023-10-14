#pragma once
#include <memory>

#include "parser/ast/ast_node.h"
#include "parser/ast/proto_type.h"

namespace pluto {

class FunctionDef : public AstNode {
 public:
  FunctionDef(Location loc, const ProtoTypePtr& proto,
              const std::vector<AstNodePtr>& body)
      : AstNode(AstNodeType::FunctionDef, loc), proto_(proto), body_(body) {}

  ProtoTypePtr getProto() const { return proto_; }
  const std::vector<AstNodePtr>& getBody() const { return body_; }

  static bool classof(const AstNode* c) {
    return c->getType() == AstNodeType::FunctionDef;
  }

 protected:
  ProtoTypePtr proto_;
  std::vector<AstNodePtr> body_;
};

using FunctionDefPtr = std::shared_ptr<FunctionDef>;
}  // namespace pluto