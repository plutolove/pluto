#include "ir/mlir_gen.h"

#include "mlir/IR/BuiltinOps.h"
#include "mlir/IR/MLIRContext.h"
#include "mlir/Support/LogicalResult.h"

namespace pluto {

MlirGenImpl::MlirGenImpl(mlir::MLIRContext& context) : builder(&context) {}
mlir::OwningOpRef<mlir::ModuleOp> MlirGenImpl::genMlir(ModuleAst& ast) {
  theModule = mlir::ModuleOp::create(builder.getUnknownLoc());

  for (auto& f : ast) mlirGen(*f);

  // Verify the module after we have finished constructing it, this will check
  // the structural properties of the IR and invoke any specific verifiers we
  // have on the Toy operations.
  if (failed(mlir::verify(theModule))) {
    theModule.emitError("module verification error");
    return nullptr;
  }

  return theModule;
}

mlir::pluto::FuncOp MlirGenImpl::mlirGen(ProtoType& proto) {
  auto location = loc(proto.loc());

  // This is a generic function, the return type will be inferred later.
  // Arguments type are uniformly unranked tensors.
  llvm::SmallVector<mlir::Type, 4> argTypes(proto.getArgs().size(),
                                            getType(VarType{}));
  auto funcType = builder.getFunctionType(argTypes, llvm::None);
  return builder.create<mlir::pluto::FuncOp>(location, proto.getProtoName(),
                                             funcType);
}

mlir::pluto::FuncOp MlirGenImpl::mlirGen(FunctionDef& funcAST) {
  // Create a scope in the symbol table to hold variable declarations.
  llvm::ScopedHashTableScope<llvm::StringRef, mlir::Value> varScope(
      symbolTable);

  // Create an MLIR function for the given prototype.
  builder.setInsertionPointToEnd(theModule.getBody());
  mlir::pluto::FuncOp function = mlirGen(*funcAST.getProto());
  if (!function) return nullptr;

  // Let's start the body of the function now!
  mlir::Block& entryBlock = function.front();
  auto protoArgs = funcAST.getProto()->getArgs();

  // Declare all the function arguments in the symbol table.
  for (const auto nameValue : llvm::zip(protoArgs, entryBlock.getArguments())) {
    if (failed(declare(std::get<0>(nameValue)->getVarName(),
                       std::get<1>(nameValue))))
      return nullptr;
  }

  // Set the insertion point in the builder to the beginning of the function
  // body, it will be used throughout the codegen to create operations in this
  // function.
  builder.setInsertionPointToStart(&entryBlock);

  // Emit the body of the function.
  if (mlir::failed(mlirGen(funcAST.getBody()))) {
    function.erase();
    return nullptr;
  }

  // Implicitly return void if no return statement was emitted.
  // FIXME: we may fix the parser instead to always return the last expression
  // (this would possibly help the REPL case later)
  mlir::pluto::ReturnOp returnOp;
  if (!entryBlock.empty())
    returnOp = llvm::dyn_cast<mlir::pluto::ReturnOp>(entryBlock.back());
  if (!returnOp) {
    builder.create<mlir::pluto::ReturnOp>(loc(funcAST.getProto()->loc()));
  } else if (returnOp.hasOperand()) {
    // Otherwise, if this return operation has an operand then add a result to
    // the function.
    function.setType(builder.getFunctionType(
        function.getFunctionType().getInputs(), getType(VarType{})));
  }

  return function;
}

/// Emit a binary operation
mlir::Value MlirGenImpl::mlirGen(BinaryOp& binop) {
  // First emit the operations for each side of the operation before emitting
  // the operation itself. For example if the expression is `a + foo(a)`
  // 1) First it will visiting the LHS, which will return a reference to the
  //    value holding `a`. This value should have been emitted at declaration
  //    time and registered in the symbol table, so nothing would be
  //    codegen'd. If the value is not in the symbol table, an error has been
  //    emitted and nullptr is returned.
  // 2) Then the RHS is visited (recursively) and a call to `foo` is emitted
  //    and the result value is returned. If an error occurs we get a nullptr
  //    and propagate.
  //
  mlir::Value lhs = mlirGen(*binop.getlhs());
  if (!lhs) return nullptr;
  mlir::Value rhs = mlirGen(*binop.getrhs());
  if (!rhs) return nullptr;
  auto location = loc(binop.loc());

  // Derive the operation name from the binary operator. At the moment we only
  // support '+' and '*'.
  switch (binop.getOp()) {
    case BinaryOp::BinaryOpType::PLUS:
      return builder.create<mlir::pluto::AddOp>(location, lhs, rhs);
    case BinaryOp::BinaryOpType::ASTERISK:
      return builder.create<mlir::pluto::MulOp>(location, lhs, rhs);
    default:
      ThrowException(-1, "unknow op: {}", static_cast<int>(binop.getOp()));
  }

  emitError(location, "invalid binary operator '") << binop.toString() << "'";
  return nullptr;
}

mlir::Value MlirGenImpl::mlirGen(VariableExpr& expr) {
  if (auto variable = symbolTable.lookup(expr.getVarName())) return variable;

  emitError(loc(expr.loc()), "error: unknown variable '")
      << expr.getVarName() << "'";
  return nullptr;
}

mlir::LogicalResult MlirGenImpl::mlirGen(ReturnExpr& ret) {
  auto location = loc(ret.loc());

  // 'return' takes an optional expression, handle that case here.
  mlir::Value expr = nullptr;
  if (ret.getExpr()) {
    if (!(expr = mlirGen(*ret.getExpr()))) return mlir::failure();
  }

  // Otherwise, this return operation has zero operands.
  builder.create<mlir::pluto::ReturnOp>(
      location,
      expr ? llvm::makeArrayRef(expr) : llvm::ArrayRef<mlir::Value>());
  return mlir::success();
}

mlir::Value MlirGenImpl::mlirGen(LiteralTensor& lit) {
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
mlir::Value MlirGenImpl::mlirGen(FunctionCall& call) {
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
  return builder.create<mlir::pluto::GenericCallOp>(location, callee, operands);
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
mlir::Value MlirGenImpl::mlirGen(LiteralDouble& num) {
  return builder.create<mlir::pluto::ConstantOp>(loc(num.loc()),
                                                 num.getValue());
}

/// Dispatch codegen for the right expression subclass using RTTI.
mlir::Value MlirGenImpl::mlirGen(AstNode& expr) {
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
mlir::Value MlirGenImpl::mlirGen(VarDeclExpr& vardecl) {
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
mlir::LogicalResult MlirGenImpl::mlirGen(
    const std::vector<AstNodePtr>& blockAST) {
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

}  // namespace pluto