#include "parser/ast_builder.h"

#include <any>
#include <fstream>
#include <memory>

#include "TokenFactory.h"
#include "common/exception.h"
#include "common/log.h"
#include "common/typeid_cast.h"
#include "parser/PlutoErrorListener.h"
#include "parser/PlutoLexer.h"
#include "parser/PlutoParser.h"
#include "parser/ast/ast_node.h"
#include "parser/ast/function_def.h"
#include "parser/ast/module_ast.h"
#include "parser/ast/proto_type.h"
#include "parser/ast/return_expr.h"
#include "parser/ast/var_decl_expr.h"

namespace pluto {

static inline Location generateLoc(antlr4::Token *token) {
  Location loc{.line = token->getLine(), .col = token->getCharPositionInLine()};
  return loc;
}

#define LOC() (generateLoc(ctx->start))

#define AssertAst(ast_ptr, type)                                              \
  do {                                                                        \
    if (ast_ptr->getType() != type) {                                         \
      INFO("node type not same, {}:{}", static_cast<int>(ast_ptr->getType()), \
           static_cast<int>(type));                                           \
    }                                                                         \
  } while (0)

ModuleAstPtr ASTBuilder::parse(const std::string &str) {
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
    INFO("00 error msg: {}", listenerError.error_msg());
  }
  return nullptr;
}

ModuleAstPtr ASTBuilder::parse_file(const std::string &path) {
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
    INFO("error msg: {}", listenerError.error_msg());
  }
  return typeid_cast<ModuleAstPtr>(typeVisit(root));
}

AstNodePtr ASTBuilder::typeVisit(antlr4::ParserRuleContext *ctx) {
  auto val = ctx->accept(this);
  return std::any_cast<AstNodePtr>(val);
}

std::any ASTBuilder::visitFunction_list(
    PlutoParser::Function_listContext *ctx) {
  std::vector<FunctionDefPtr> function_list;
  function_list.reserve(ctx->funcdef().size());
  // for (auto &func : ctx->funcdef()) {
  //   function_list.push_back(std::any_cast<FunctionDefPtr>(typeVisit(func)));
  // }
  INFO("debug token: {}, line: {}, pos: {}", ctx->start->getText(),
       ctx->start->getLine(), ctx->start->getCharPositionInLine());
  AstNodePtr module_ast = std::make_shared<ModuleAst>(LOC(), function_list);
  return module_ast;
}

std::any ASTBuilder::visitFuncdef(PlutoParser::FuncdefContext *ctx) {
  // proto
  auto proto = typeid_cast<ProtoTypePtr>(typeVisit(ctx->func_dec()));
  // body
  std::vector<AstNodePtr> body;
  if (ctx->block()->return_stmt()) {
    body.reserve(ctx->block()->blockItemList()->blockItem().size() + 1);
  } else {
    body.reserve(ctx->block()->blockItemList()->blockItem().size());
  }
  // nomal block
  for (auto &item : ctx->block()->blockItemList()->blockItem()) {
    body.push_back(typeVisit(item));
  }
  // return stmt
  if (ctx->block()->return_stmt()) {
    body.push_back(typeVisit(ctx->block()->return_stmt()));
  }

  AstNodePtr ret = std::make_shared<FunctionDef>(LOC(), proto, body);
  return ret;
}

std::any ASTBuilder::visitFunc_dec(PlutoParser::Func_decContext *ctx) {
  auto func_name = ctx->func_name->getText();
  std::vector<VariableExprPtr> vars;
  for (auto &param : ctx->parameters()->argument) {
    vars.push_back(
        std::make_shared<VariableExpr>(generateLoc(param), param->getText()));
  }
  AstNodePtr ret = std::make_shared<ProtoType>(LOC(), func_name, vars);
  return ret;
}

std::any ASTBuilder::visitBlockItem(PlutoParser::BlockItemContext *ctx) {
  return typeVisit(ctx->expressionStatement());
}

std::any ASTBuilder::visitReturn_stmt(PlutoParser::Return_stmtContext *ctx) {
  auto expr = typeVisit(ctx->expression());
  AstNodePtr ret = std::make_shared<ReturnExpr>(LOC(), expr);
  return ret;
}

std::any ASTBuilder::visitNormal_var_decl(
    PlutoParser::Normal_var_declContext *ctx) {
  auto expr = typeVisit(ctx->expression());
  VarType type;
  AstNodePtr ret =
      std::make_shared<VarDeclExpr>(LOC(), ctx->name->getText(), type, expr);
  return ret;
}

std::any ASTBuilder::visitConstant_var_decl(
    PlutoParser::Constant_var_declContext *ctx) {
  auto expr = typeVisit(ctx->expression());
  VarType type;
  type.dims.push_back(std::stoi(ctx->dim->dim_x->getText()));
  type.dims.push_back(std::stoi(ctx->dim->dim_y->getText()));
  AstNodePtr ret =
      std::make_shared<VarDeclExpr>(LOC(), ctx->name->getText(), type, expr);
  return ret;
}

std::any ASTBuilder::visitExpression(PlutoParser::ExpressionContext *ctx) {}

std::any ASTBuilder::visitValueExpressionDefault(
    PlutoParser::ValueExpressionDefaultContext *ctx) {}

std::any ASTBuilder::visitArithmeticBinary(
    PlutoParser::ArithmeticBinaryContext *ctx) {}

std::any ASTBuilder::visitConstantDefault(
    PlutoParser::ConstantDefaultContext *ctx) {}

std::any ASTBuilder::visitFunctionCall(PlutoParser::FunctionCallContext *ctx) {}

std::any ASTBuilder::visitColumnReference(
    PlutoParser::ColumnReferenceContext *ctx) {}

std::any ASTBuilder::visitParenthesizedExpression(
    PlutoParser::ParenthesizedExpressionContext *ctx) {}

std::any ASTBuilder::visitDim_value(PlutoParser::Dim_valueContext *ctx) {}

std::any ASTBuilder::visitConstant_vector(
    PlutoParser::Constant_vectorContext *ctx) {}

}  // namespace pluto