
// Generated from ./src/parser/Pluto.g4 by ANTLR 4.12.0

#pragma once


#include "antlr4-runtime.h"
#include "PlutoParser.h"


namespace pluto {

/**
 * This class defines an abstract visitor for a parse tree
 * produced by PlutoParser.
 */
class  PlutoVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by PlutoParser.
   */
    virtual std::any visitFuncdef(PlutoParser::FuncdefContext *context) = 0;

    virtual std::any visitParameters(PlutoParser::ParametersContext *context) = 0;

    virtual std::any visitBlock(PlutoParser::BlockContext *context) = 0;

    virtual std::any visitBlockItemList(PlutoParser::BlockItemListContext *context) = 0;

    virtual std::any visitBlockItem(PlutoParser::BlockItemContext *context) = 0;

    virtual std::any visitReturn_stmt(PlutoParser::Return_stmtContext *context) = 0;

    virtual std::any visitExpressionStatement(PlutoParser::ExpressionStatementContext *context) = 0;

    virtual std::any visitExpression(PlutoParser::ExpressionContext *context) = 0;

    virtual std::any visitValueExpressionDefault(PlutoParser::ValueExpressionDefaultContext *context) = 0;

    virtual std::any visitArithmeticBinary(PlutoParser::ArithmeticBinaryContext *context) = 0;

    virtual std::any visitConstantDefault(PlutoParser::ConstantDefaultContext *context) = 0;

    virtual std::any visitFunctionCall(PlutoParser::FunctionCallContext *context) = 0;

    virtual std::any visitColumnReference(PlutoParser::ColumnReferenceContext *context) = 0;

    virtual std::any visitParenthesizedExpression(PlutoParser::ParenthesizedExpressionContext *context) = 0;

    virtual std::any visitConstant(PlutoParser::ConstantContext *context) = 0;

    virtual std::any visitIdentifier_with_dim(PlutoParser::Identifier_with_dimContext *context) = 0;

    virtual std::any visitDim_value(PlutoParser::Dim_valueContext *context) = 0;

    virtual std::any visitConstant_vector(PlutoParser::Constant_vectorContext *context) = 0;


};

}  // namespace pluto
