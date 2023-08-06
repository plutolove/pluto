#include "IR/mlir_gen.h"

#include "mlir/IR/BuiltinOps.h"
#include "mlir/IR/MLIRContext.h"
#include "mlir/Support/LogicalResult.h"

namespace pluto {

MlirGenImpl::MlirGenImpl(mlir::MLIRContext& context) : builder(&context) {}
mlir::OwningOpRef<mlir::ModuleOp> MlirGenImpl::genMlir(ModuleAst& ast) {
  theModule = mlir::ModuleOp::create(builder.getUnknownLoc());
  if (mlir::failed(mlir::verify(theModule))) {
    theModule.emitError("module verification error");
    return nullptr;
  }
  return theModule;
}

}  // namespace pluto