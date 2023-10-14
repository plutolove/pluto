#include "transform/transform_ast.h"

#include "common/log.h"
#include "llvm/ADT/Twine.h"
#include "llvm/ADT/TypeSwitch.h"

namespace pluto {

struct Indent {
  Indent(int &level) : level(level) { ++level; }
  ~Indent() { --level; }
  int &level;
};

template <typename T>
static std::string loc(T *node) {
  const auto &loc = node->loc();
  return (llvm::Twine("@") + ":" + std::string(loc.file) + ":" +
          llvm::Twine(loc.line) + ":" + llvm::Twine(loc.col))
      .str();
}

#define INDENT()            \
  Indent level_(curIndent); \
  indent();

void TransformAst::visit(const AstNodePtr &expr) {
  llvm::TypeSwitch<AstNode *>(expr.get())
      .Case<BinaryOp, FunctionCall, LiteralTensor, LiteralDouble, ReturnExpr,
            VarDeclExpr, FunctionDef, ProtoType, VariableExpr>(
          [&](auto *node) { this->visit(node); })
      .Default([&](AstNode *node) {
        // No match, fallback to a generic message
        INDENT();
        INFO("<unknown Expr, kind, {}>", int(node->getType()));
      });
}

void TransformAst::visit(VariableExpr *node) {
  INDENT();
  llvm::errs() << "var: " << node->getVarName() << " " << loc(node) << "\n";
}
void TransformAst::visit(ModuleAstPtr &module) {
  INDENT();
  llvm::errs() << "Module:\n";
  for (auto &f : module->getFunctions()) visit(f.get());
}
void TransformAst::visit(FunctionDef *node) {
  INDENT();
  llvm::errs() << "Function \n";
  visit(node->getProto().get());
  {
    INDENT();
    llvm::errs() << "Block {\n";
    for (auto &ptr : node->getBody()) {
      visit(ptr);
    }
    {
      INDENT();
      llvm::errs() << "} // block\n";
    }
  }
}

void TransformAst::visit(ProtoType *node) {
  INDENT();
  llvm::errs() << "Proto '" << node->getProtoName() << "' " << loc(node)
               << "\n";
  indent();
  llvm::errs() << "Params: [";
  llvm::interleaveComma(node->getArgs(), llvm::errs(),
                        [](auto &arg) { llvm::errs() << arg->getVarName(); });
  llvm::errs() << "]\n";
}

void TransformAst::visit(FunctionCall *node) {
  INDENT();
  llvm::errs() << "Call '" << node->getFunctionName() << "' [ " << loc(node)
               << "\n";
  for (auto &arg : node->getArgs()) visit(arg);
  indent();
  llvm::errs() << "]\n";
}

void TransformAst::dump(const VarType &type) {
  llvm::errs() << "<";
  llvm::interleaveComma(type.dims, llvm::errs());
  llvm::errs() << ">";
}

void TransformAst::visit(VarDeclExpr *varDecl) {
  INDENT();
  llvm::errs() << "VarDecl " << varDecl->getVarName();
  dump(varDecl->getVarType());
  llvm::errs() << " " << loc(varDecl) << "\n";
  visit(varDecl->getVarExpr());
}

void printLitHelper(AstNode *litOrNum) {
  // Inside a literal expression we can have either a number or another literal
  if (auto *num = llvm::dyn_cast<LiteralDouble>(litOrNum)) {
    llvm::errs() << num->getValue();
    return;
  }
  auto *literal = llvm::cast<LiteralTensor>(litOrNum);

  // Print the dimension for this literal first
  llvm::errs() << "<";
  llvm::interleaveComma(literal->getDims(), llvm::errs());
  llvm::errs() << ">";

  // Now print the content, recursing on every element of the list
  llvm::errs() << "[ ";
  llvm::interleaveComma(literal->getValues(), llvm::errs(),
                        [&](auto &elt) { printLitHelper(elt.get()); });
  llvm::errs() << "]";
}

void TransformAst::visit(LiteralDouble *num) {
  INDENT();
  llvm::errs() << num->getValue() << " " << loc(num) << "\n";
}
void TransformAst::visit(LiteralTensor *node) {
  INDENT();
  llvm::errs() << "Literal: ";
  printLitHelper(node);
  llvm::errs() << " " << loc(node) << "\n";
}

void TransformAst::visit(ReturnExpr *node) {
  INDENT();
  llvm::errs() << "Return\n";
  if (node->getExpr()) {
    visit(node->getExpr());
    return;
  }
  {
    INDENT();
    llvm::errs() << "(void)\n";
  }
}

void TransformAst::visit(BinaryOp *node) {
  INDENT();
  llvm::errs() << "BinOp: " << int(node->getOp()) << " " << loc(node) << "\n";
  visit(node->getlhs());
  visit(node->getrhs());
}

}  // namespace pluto