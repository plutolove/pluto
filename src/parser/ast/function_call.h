#pragma once
#include <initializer_list>
#include <string_view>
#include <vector>

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

 protected:
  std::string name_;
  std::vector<AstNodePtr> arguments_;
};

}  // namespace pluto