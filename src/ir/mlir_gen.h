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

  mlir::Value mlirGen(LiteralTensor& lit) {
    auto type = getType(lit.getDims());

    // The attribute is a vector with a floating point value per element
    // (number) in the array, see `collectData()` below for more details.
    std::vector<double> data;
    data.reserve(std::accumulate(lit.getDims().begin(), lit.getDims().end(), 1,
                                 std::multiplies<int>()));
    collectData(lit, data);
    // The type of this attribute is tensor of 64-bit floating-point with the
    // shape of the literal.
    mlir::Type elementType = builder.getF64Type();
    auto dataType = mlir::RankedTensorType::get(lit.getDims(), elementType);

    // This is the actual attribute that holds the list of values for this
    // tensor literal.
    auto dataAttribute =
        mlir::DenseElementsAttr::get(dataType, llvm::makeArrayRef(data));

    // Build the MLIR op `toy.constant`. This invokes the `ConstantOp::build`
    // method.
    return builder.create<mlir::pluto::ConstantOp>(loc(lit.loc()), type,
                                                   dataAttribute);
  }

  /// Emit a call expression. It emits specific operations for the `transpose`
  /// builtin. Other identifiers are assumed to be user-defined functions.
  mlir::Value mlirGen(FunctionCall& call) {
    llvm::StringRef callee = call.getFunctionName();
    auto location = loc(call.loc());

    // Codegen the operands first.
    llvm::SmallVector<mlir::Value, 4> operands;
    for (auto& expr : call.getArgs()) {
      auto arg = mlirGen(*expr);
      if (!arg) return nullptr;
      operands.push_back(arg);
    }

    // Builtin calls have their custom operation, meaning this is a
    // straightforward emission.
    if (callee == "transpose") {
      if (call.getArgs().size() != 1) {
        emitError(location,
                  "MLIR codegen encountered an error: toy.transpose "
                  "does not accept multiple arguments");
        return nullptr;
      }
      return builder.create<mlir::pluto::TransposeOp>(location, operands[0]);
    }
    // Otherwise this is a call to a user-defined function. Calls to
    // user-defined functions are mapped to a custom call that takes the callee
    // name as an attribute.
    return builder.create<mlir::pluto::GenericCallOp>(location, callee,
                                                      operands);
  }

  // /// Emit a print expression. It emits specific operations for two builtins:
  // /// transpose(x) and print(x).
  // mlir::LogicalResult mlirGen(PrintExprAST& call) {
  //   auto arg = mlirGen(*call.getArg());
  //   if (!arg) return mlir::failure();

  //   builder.create<PrintOp>(loc(call.loc()), arg);
  //   return mlir::success();
  // }

  /// Emit a constant for a single number (FIXME: semantic? broadcast?)
  mlir::Value mlirGen(LiteralDouble& num) {
    return builder.create<mlir::pluto::ConstantOp>(loc(num.loc()),
                                                   num.getValue());
  }

  /// Dispatch codegen for the right expression subclass using RTTI.
  mlir::Value mlirGen(AstNode& expr) {
    switch (expr.getType()) {
      case AstNodeType::BinaryOP:
        return mlirGen(llvm::cast<BinaryOp>(expr));
      case AstNodeType::VariableExpr:
        return mlirGen(llvm::cast<VariableExpr>(expr));
      case AstNodeType::LiteralTensor:
        return mlirGen(llvm::cast<LiteralTensor>(expr));
      case AstNodeType::FunctionCall:
        return mlirGen(llvm::cast<FunctionCall>(expr));
      case AstNodeType::LiteralDouble:
        return mlirGen(llvm::cast<LiteralDouble>(expr));
      default:
        emitError(loc(expr.loc()))
            << "MLIR codegen encountered an unhandled expr kind '";
        return nullptr;
    }
  }

  /// Handle a variable declaration, we'll codegen the expression that forms the
  /// initializer and record the value in the symbol table before returning it.
  /// Future expressions will be able to reference this variable through symbol
  /// table lookup.
  mlir::Value mlirGen(VarDeclExpr& vardecl) {
    auto init = vardecl.getVarExpr();
    if (!init) {
      emitError(loc(vardecl.loc()),
                "missing initializer in variable declaration");
      return nullptr;
    }

    mlir::Value value = mlirGen(*init);
    if (!value) return nullptr;

    // We have the initializer value, but in case the variable was declared
    // with specific shape, we emit a "reshape" operation. It will get
    // optimized out later as needed.
    if (!vardecl.getVarType().shape.empty()) {
      value = builder.create<mlir::pluto::ReshapeOp>(
          loc(vardecl.loc()), getType(vardecl.getVarType()), value);
    }

    // Register the value in the symbol table.
    if (failed(declare(vardecl.getVarName(), value))) return nullptr;
    return value;
  }

  /// Codegen a list of expression, return failure if one of them hit an error.
  mlir::LogicalResult mlirGen(const std::vector<AstNodePtr>& blockAST) {
    llvm::ScopedHashTableScope<llvm::StringRef, mlir::Value> varScope(
        symbolTable);
    for (auto& expr : blockAST) {
      // Specific handling for variable declarations, return statement, and
      // print. These can only appear in block list and not in nested
      // expressions.
      if (auto* vardecl = llvm::dyn_cast<VarDeclExpr>(expr.get())) {
        if (!mlirGen(*vardecl)) return mlir::failure();
        continue;
      }
      if (auto* ret = llvm::dyn_cast<ReturnExpr>(expr.get()))
        return mlirGen(*ret);
      // if (auto* print = dyn_cast<PrintExprAST>(expr.get())) {
      //   if (mlir::failed(mlirGen(*print))) return mlir::success();
      //   continue;
      // }

      // Generic expression dispatch codegen.
      if (!mlirGen(*expr)) return mlir::failure();
    }
    return mlir::success();
  }
};

static inline mlir::OwningOpRef<mlir::ModuleOp> mlirGen(
    mlir::MLIRContext& context, ModuleAst& ast) {
  return MlirGenImpl(context).genMlir(ast);
}

}  // namespace pluto