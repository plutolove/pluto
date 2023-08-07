/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Dialect Definitions                                                        *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::pluto::PlutoDialect)
namespace mlir {
namespace pluto {

PlutoDialect::PlutoDialect(::mlir::MLIRContext *context) 
    : ::mlir::Dialect(getDialectNamespace(), context, ::mlir::TypeID::get<PlutoDialect>()) {
  
  initialize();
}

PlutoDialect::~PlutoDialect() = default;

} // namespace pluto
} // namespace mlir
