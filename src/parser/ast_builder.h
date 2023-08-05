#pragma once
#include "parser/PlutoBaseVisitor.h"
#include "parser/ast/ast_node.h"

namespace pluto {

class ASTBuilder : public pluto::PlutoBaseVisitor {
 public:
  ASTBuilder() = default;
  AstNodePtr parse(const std::string& str);
  AstNodePtr typeVisit(antlr4::ParserRuleContext* ctx);
};

}  // namespace pluto