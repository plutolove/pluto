#include "parser/ast/function_call.h"

#include "parser/ast/ast_node.h"

namespace pluto {

FunctionCall::FunctionCall() : AstNode(AstNodeType::FunctionCall) {}

FunctionCall::FunctionCall(Location loc, const std::string& name,
                           const std::vector<AstNodePtr>& args)
    : AstNode(AstNodeType::FunctionCall, loc), name_(name), arguments_(args) {}

FunctionCall::FunctionCall(Location loc, const std::string& name,
                           std::initializer_list<AstNodePtr> args)
    : AstNode(AstNodeType::FunctionCall, loc), name_(name), arguments_(args) {}

}  // namespace pluto