#include "parser/ast_builder.h"

#include <fstream>

#include "common/log.h"
#include "parser/PlutoErrorListener.h"
#include "parser/PlutoLexer.h"
#include "parser/PlutoParser.h"
#include "parser/ast/ast_node.h"

namespace pluto {

AstNodePtr ASTBuilder::parse(const std::string& str) {
  antlr4::ANTLRInputStream inputStream(str);
  PlutoLexer lexer(&inputStream);
  antlr4::CommonTokenStream tokens(&lexer);
  PlutoParser parser(&tokens);
  parser.removeErrorListeners();
  PlutoErrorListener listenerError;
  parser.addErrorListener(&listenerError);
  auto root = parser.function_list();
  INFO("00 text: {}", root->getText());
  if (not listenerError.m_strErrMsg.empty()) {
    INFO("00 error msg: {}", listenerError.m_strErrMsg);
  }
  return nullptr;
}

AstNodePtr ASTBuilder::parse_file(const std::string& path) {
  std::ifstream fin;
  fin.open(path);
  antlr4::ANTLRInputStream inputStream(fin);
  PlutoLexer lexer(&inputStream);
  antlr4::CommonTokenStream tokens(&lexer);
  PlutoParser parser(&tokens);
  parser.removeErrorListeners();
  PlutoErrorListener listenerError;
  parser.addErrorListener(&listenerError);
  auto root = parser.function_list();
  INFO("text: {}", root->getText());
  if (not listenerError.m_strErrMsg.empty()) {
    INFO("error msg: {}", listenerError.m_strErrMsg);
  }
  // return typeVisit(root);
  return nullptr;
}

AstNodePtr ASTBuilder::typeVisit(antlr4::ParserRuleContext* ctx) {
  auto val = ctx->accept(this);
  return std::any_cast<AstNodePtr>(val);
}

}  // namespace pluto