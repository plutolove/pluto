#pragma once
#include <iostream>
#include <numeric>

#include "common/exception.h"
#include "common/log.h"
#include "ir/dialect.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/ADT/ScopedHashTable.h"
#include "llvm/Support/raw_ostream.h"
#include "mlir/IR/Attributes.h"
#include "mlir/IR/Builders.h"
#include "mlir/IR/BuiltinOps.h"
#include "mlir/IR/BuiltinTypes.h"
#include "mlir/IR/MLIRContext.h"
#include "mlir/IR/Verifier.h"
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

class MlirGenImpl {
 public:
  MlirGenImpl(mlir::MLIRContext& context);
  mlir::OwningOpRef<mlir::ModuleOp> genMlir(ModuleAst& ast);

 private:
  mlir::ModuleOp theModule;

  mlir::OpBuilder builder;

  llvm::ScopedHashTable<llvm::StringRef, mlir::Value> symbolTable;

  mlir::Location loc(const Location& loc) {
    return mlir::FileLineColLoc::get(builder.getStringAttr(loc.file), loc.line,
                                     loc.col);
  }

  /// Declare a variable in the current scope, return success if the variable
  /// wasn't declared yet.
  mlir::LogicalResult declare(llvm::StringRef var, mlir::Value value) {
    if (symbolTable.count(var)) return mlir::failure();
    symbolTable.insert(var, value);
    return mlir::success();
  }
  /// Build a tensor type from a list of shape dimensions.
  mlir::Type getType(llvm::ArrayRef<int64_t> shape) {
    // If the shape is empty, then this type is unranked.
    if (shape.empty())
      return mlir::UnrankedTensorType::get(builder.getF64Type());

    // Otherwise, we use the given shape.
    return mlir::RankedTensorType::get(shape, builder.getF64Type());
  }

  mlir::pluto::FuncOp mlirGen(FunctionDef& funcAST);

  mlir::Type getType(const VarType& type) { return getType(type.shape); }

  mlir::pluto::FuncOp mlirGen(ProtoType& proto);

  mlir::Value mlirGen(BinaryOp& binop);

  /// This is a reference to a variable in an expression. The variable is
  /// expected to have been declared and so should have a value in the symbol
  /// table, otherwise emit an error and return nullptr.
  mlir::Value mlirGen(VariableExpr& expr);

  /// Emit a return operation. This will return failure if any generation fails.
  mlir::LogicalResult mlirGen(ReturnExpr& ret);

  void collectData(AstNode& expr, std::vector<double>& data) {
    if (auto* lit = llvm::dyn_cast<LiteralTensor>(&expr)) {
      for (auto& value : lit->getValues()) collectData(*value, data);
      return;
    }

    assert(llvm::isa<LiteralDouble>(expr) && "expected literal or number expr");
    data.push_back(llvm::cast<LiteralDouble>(expr).getValue());
  }

  mlir::Value mlirGen(LiteralTensor& lit);
  mlir::Value mlirGen(FunctionCall& call);

  mlir::Value mlirGen(LiteralDouble& num);

  mlir::Value mlirGen(AstNode& expr);

  mlir::Value mlirGen(VarDeclExpr& vardecl);

  mlir::LogicalResult mlirGen(const std::vector<AstNodePtr>& blockAST);
};

static inline mlir::OwningOpRef<mlir::ModuleOp> mlirGen(
    mlir::MLIRContext& context, ModuleAst& ast) {
  return MlirGenImpl(context).genMlir(ast);
}

static inline void DumpIR(ModuleAstPtr& ast) {
  mlir::MLIRContext context;
  // Load our Dialect in this MLIR Context.
  context.getOrLoadDialect<mlir::pluto::PlutoDialect>();
  mlir::OwningOpRef<mlir::ModuleOp> module = mlirGen(context, *ast);
  if (!module) {
    ERROR("module nullptr");
    return;
  }

  module->dump();
}

}  // namespace pluto