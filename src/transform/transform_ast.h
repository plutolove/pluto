#pragma once
#include "common/log.h"
#include "llvm/Support/raw_ostream.h"
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

class TransformAst {
 public:
  void visit(ModuleAstPtr &module);
  void visit(VarDeclExpr *varDecl);
  void visit(const AstNodePtr &expr);
  void visit(LiteralDouble *num);
  void visit(LiteralTensor *node);
  void visit(ReturnExpr *node);
  void visit(BinaryOp *node);
  void visit(FunctionCall *node);
  void visit(ProtoType *node);
  void visit(FunctionDef *node);
  void dump(const VarType &type);
  void visit(VariableExpr *node);
  void indent() {
    for (int i = 0; i < curIndent; i++) {
      llvm::errs() << "  ";
    }
  }
  int curIndent = 0;
};

static inline void transformAst(ModuleAstPtr &moduel) {
  TransformAst().visit(moduel);
}

}  // namespace pluto