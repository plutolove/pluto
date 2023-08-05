
// Generated from ./src/parser/Pluto.g4 by ANTLR 4.12.0

#pragma once


#include "antlr4-runtime.h"
#include "PlutoVisitor.h"


namespace pluto {

/**
 * This class provides an empty implementation of PlutoVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  PlutoBaseVisitor : public PlutoVisitor {
public:

  virtual std::any visitFuncdef(PlutoParser::FuncdefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParameters(PlutoParser::ParametersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlock(PlutoParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlockItemList(PlutoParser::BlockItemListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlockItem(PlutoParser::BlockItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturn_stmt(PlutoParser::Return_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpressionStatement(PlutoParser::ExpressionStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpression(PlutoParser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitValueExpressionDefault(PlutoParser::ValueExpressionDefaultContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArithmeticBinary(PlutoParser::ArithmeticBinaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstantDefault(PlutoParser::ConstantDefaultContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionCall(PlutoParser::FunctionCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitColumnReference(PlutoParser::ColumnReferenceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParenthesizedExpression(PlutoParser::ParenthesizedExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstant(PlutoParser::ConstantContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIdentifier_with_dim(PlutoParser::Identifier_with_dimContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDim_value(PlutoParser::Dim_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstant_vector(PlutoParser::Constant_vectorContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace pluto
