#include "parser/ast_builder.h"

#include <any>
#include <exception>
#include <fstream>
#include <memory>
#include <string>
#include <string_view>
#include <vector>

#include "TokenFactory.h"
#include "atn/ParserATNSimulator.h"
#include "atn/PredictionMode.h"
#include "common/exception.h"
#include "common/log.h"
#include "common/typeid_cast.h"
#include "parser/PlutoErrorListener.h"
#include "parser/PlutoLexer.h"
#include "parser/PlutoParser.h"
#include "parser/ast/ast_node.h"
#include "parser/ast/binary_op.h"
#include "parser/ast/function_call.h"
#include "parser/ast/function_def.h"
#include "parser/ast/literal.h"
#include "parser/ast/module_ast.h"
#include "parser/ast/proto_type.h"
#include "parser/ast/return_expr.h"
#include "parser/ast/var_decl_expr.h"

namespace pluto {

static inline Location generateLoc(antlr4::Token *token,
                                   std::string_view path) {
  Location loc{.line = token->getLine(),
               .col = token->getCharPositionInLine(),
               .file = path};
  return loc;
}

#define LOC() (generateLoc(ctx->start, path))

#define AssertAst(ast_ptr, type)                                               \
  do {                                                                         \
    if (ast_ptr->getType() != type) {                                          \
      FATAL("node type not same, {}:{}", static_cast<int>(ast_ptr->getType()), \
            static_cast<int>(type));                                           \
    }                                                                          \
  } while (0)

ModuleAstPtr ASTBuilder::parse(const std::string &str) {
  antlr4::ANTLRInputStream inputStream(str);
  PlutoLexer lexer(&inputStream);
  antlr4::CommonTokenStream tokens(&lexer);
  PlutoParser parser(&tokens);
  parser.removeErrorListeners();
  PlutoErrorListener listenerError;
  parser.addErrorListener(&listenerError);
  parser.getInterpreter<antlr4::atn::ParserATNSimulator>()->setPredictionMode(
      antlr4::atn::PredictionMode::SLL);
  auto root = parser.function_list();
  if (not listenerError.m_strErrMsg.empty()) {
    ERROR("error msg: {}", listenerError.error_msg());
  }
  return typeid_cast<ModuleAstPtr>(typeVisit(root));
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
  if (not listenerError.m_strErrMsg.empty()) {
    ERROR("error msg: {}", listenerError.error_msg());
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
  for (auto &func : ctx->funcdef()) {
    auto ptr = typeVisit(func);
    function_list.push_back(typeid_cast<FunctionDefPtr>(ptr));
  }
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
    vars.push_back(std::make_shared<VariableExpr>(generateLoc(param, path),
                                                  param->getText()));
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
  type.shape.push_back(std::stoi(ctx->dim->dim_x->getText()));
  type.shape.push_back(std::stoi(ctx->dim->dim_y->getText()));
  AstNodePtr ret =
      std::make_shared<VarDeclExpr>(LOC(), ctx->name->getText(), type, expr);
  return ret;
}

std::any ASTBuilder::visitExpression(PlutoParser::ExpressionContext *ctx) {
  return typeVisit(ctx->valueExpression());
}

std::any ASTBuilder::visitValueExpressionDefault(
    PlutoParser::ValueExpressionDefaultContext *ctx) {
  return typeVisit(ctx->primaryExpression());
}

std::any ASTBuilder::visitArithmeticBinary(
    PlutoParser::ArithmeticBinaryContext *ctx) {
  auto loc = LOC();
  auto lhs = typeVisit(ctx->left);
  auto rhs = typeVisit(ctx->right);
  AstNodePtr ret;
  if ("+" == ctx->operator_->getText()) {
    ret =
        std::make_shared<BinaryOp>(loc, lhs, BinaryOp::BinaryOpType::PLUS, rhs);
  } else if ("-" == ctx->operator_->getText()) {
    ret = std::make_shared<BinaryOp>(loc, lhs, BinaryOp::BinaryOpType::MINUS,
                                     rhs);
  } else if ("*" == ctx->operator_->getText()) {
    ret = std::make_shared<BinaryOp>(loc, lhs, BinaryOp::BinaryOpType::ASTERISK,
                                     rhs);
  } else {
    ThrowException(-1, "not support: {}", ctx->getText());
  }
  return ret;
}

std::any ASTBuilder::visitConstantDefault(
    PlutoParser::ConstantDefaultContext *ctx) {
  return typeVisit(ctx->constant_vector());
}

std::any ASTBuilder::visitFunctionCall(PlutoParser::FunctionCallContext *ctx) {
  std::vector<AstNodePtr> args;
  for (auto &item : ctx->argument) {
    args.push_back(typeVisit(item));
  }
  AstNodePtr ret =
      std::make_shared<FunctionCall>(LOC(), ctx->functionName->getText(), args);
  return ret;
}

std::any ASTBuilder::visitColumnReference(
    PlutoParser::ColumnReferenceContext *ctx) {
  AstNodePtr ret = std::make_shared<VariableExpr>(LOC(), ctx->getText());
  return ret;
}

std::any ASTBuilder::visitParenthesizedExpression(
    PlutoParser::ParenthesizedExpressionContext *ctx) {
  return typeVisit(ctx->expression());
}

std::any ASTBuilder::visitConstant_vector(
    PlutoParser::Constant_vectorContext *ctx) {
  std::vector<int64_t> dims;
  std::vector<AstNodePtr> values;
  for (auto &item : ctx->vec) {
    values.push_back(std::make_shared<LiteralDouble>(
        generateLoc(item, path), std::stod(item->getText())));
  }
  dims.push_back(values.size());
  AstNodePtr ret = std::make_shared<LiteralTensor>(LOC(), values, dims);
  return ret;
}

}  // namespace pluto