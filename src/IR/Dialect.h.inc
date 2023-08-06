/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Dialect Declarations                                                       *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

namespace mlir {
namespace pluto {

class PlutoDialect : public ::mlir::Dialect {
  explicit PlutoDialect(::mlir::MLIRContext *context);

  void initialize();
  friend class ::mlir::MLIRContext;
public:
  ~PlutoDialect() override;
  static constexpr ::llvm::StringLiteral getDialectNamespace() {
    return ::llvm::StringLiteral("pluto");
  }
};
} // namespace pluto
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::pluto::PlutoDialect)
