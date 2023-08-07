#pragma once
#include "llvm/ADT/STLExtras.h"
#include "llvm/ADT/ScopedHashTable.h"
#include "llvm/Support/raw_ostream.h"
#include "mlir/IR/Attributes.h"
#include "mlir/IR/Builders.h"
#include "mlir/IR/BuiltinOps.h"
#include "mlir/IR/BuiltinTypes.h"
#include "mlir/IR/MLIRContext.h"
#include "mlir/IR/Verifier.h"
#include "parser/ast/module_ast.h"

namespace pluto {

class MlirGenImpl {
 public:
  MlirGenImpl(mlir::MLIRContext& context);
  mlir::OwningOpRef<mlir::ModuleOp> genMlir(ModuleAst& ast);

 protected:
  mlir::ModuleOp theModule;

  mlir::OpBuilder builder;

  llvm::ScopedHashTable<llvm::StringRef, mlir::Value> symbolTable;
};

static inline mlir::OwningOpRef<mlir::ModuleOp> mlirGen(
    mlir::MLIRContext& context, ModuleAst& ast) {
  return MlirGenImpl(context).genMlir(ast);
}

}  // namespace pluto