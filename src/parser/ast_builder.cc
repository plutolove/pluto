#include "parser/ast_builder.h"

#include "parser/PlutoLexer.h"
#include "parser/PlutoParser.h"
#include "parser/ast/ast_node.h"
namespace pluto {

AstNodePtr ASTBuilder::parse(const std::string& str) {
  antlr4::ANTLRInputStream inputStream(str);
  PlutoLexer lexer(&inputStream);
  antlr4::CommonTokenStream tokens(&lexer);
  PlutoParser parser(&tokens);
  auto root = parser.function_list();
  return typeVisit(root);
}

AstNodePtr ASTBuilder::typeVisit(antlr4::ParserRuleContext* ctx) {
  auto val = ctx->accept(this);
  return std::any_cast<AstNodePtr>(val);
}

}  // namespace pluto