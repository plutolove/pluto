#pragma once
#include "parser/PlutoBaseVisitor.h"
#include "parser/ast/ast_node.h"
#include "parser/ast/module_ast.h"

namespace pluto {

class ASTBuilder : public pluto::PlutoBaseVisitor {
 public:
  ASTBuilder() = default;
  ModuleAstPtr parse(const std::string &str);
  ModuleAstPtr parse_file(const std::string &path);
  AstNodePtr typeVisit(antlr4::ParserRuleContext *ctx);

  // visitor
  virtual std::any visitFunction_list(
      PlutoParser::Function_listContext *ctx) override;

  virtual std::any visitFuncdef(PlutoParser::FuncdefContext *ctx) override;

  virtual std::any visitFunc_dec(PlutoParser::Func_decContext *ctx) override;

  virtual std::any visitBlockItem(PlutoParser::BlockItemContext *ctx) override;

  virtual std::any visitReturn_stmt(
      PlutoParser::Return_stmtContext *ctx) override;

  virtual std::any visitNormal_var_decl(
      PlutoParser::Normal_var_declContext *ctx) override;

  virtual std::any visitConstant_var_decl(
      PlutoParser::Constant_var_declContext *ctx) override;

  virtual std::any visitExpression(
      PlutoParser::ExpressionContext *ctx) override;

  virtual std::any visitValueExpressionDefault(
      PlutoParser::ValueExpressionDefaultContext *ctx) override;

  virtual std::any visitArithmeticBinary(
      PlutoParser::ArithmeticBinaryContext *ctx) override;

  virtual std::any visitConstantDefault(
      PlutoParser::ConstantDefaultContext *ctx) override;

  virtual std::any visitFunctionCall(
      PlutoParser::FunctionCallContext *ctx) override;

  virtual std::any visitColumnReference(
      PlutoParser::ColumnReferenceContext *ctx) override;

  virtual std::any visitParenthesizedExpression(
      PlutoParser::ParenthesizedExpressionContext *ctx) override;

  virtual std::any visitConstant_vector(
      PlutoParser::Constant_vectorContext *ctx) override;
};

}  // namespace pluto