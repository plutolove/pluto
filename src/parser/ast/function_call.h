#pragma once
#include <initializer_list>
#include <string_view>
#include <vector>

#include "fmt/format.h"
#include "parser/ast/ast_node.h"

namespace pluto {

class FunctionCall : public AstNode {
 public:
  FunctionCall();
  FunctionCall(Location loc, const std::string& name,
               const std::vector<AstNodePtr>& args);
  FunctionCall(Location loc, const std::string& name,
               std::initializer_list<AstNodePtr> args);

  std::string_view getFunctionName() const { return name_; }
  const std::vector<AstNodePtr>& getArgs() const { return arguments_; }

  static bool classof(const AstNode* c) {
    return c->getType() == AstNodeType::FunctionCall;
  }

  virtual std::string toString() const {
    std::vector<std::string> args;
    for (auto& arg : arguments_) {
      args.push_back(arg->toString());
    }
    return fmt::format("name: {}, args: {}", name_, fmt::join(args, ", "));
  }

 protected:
  std::string name_;
  std::vector<AstNodePtr> arguments_;
};

}  // namespace pluto