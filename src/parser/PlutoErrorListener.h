#pragma once
#include "BaseErrorListener.h"

class PlutoErrorListener : public antlr4::BaseErrorListener {
 public:
  PlutoErrorListener(void);
  virtual void syntaxError(antlr4::Recognizer *recognizer,
                           antlr4::Token *offendingSymbol, size_t line,
                           size_t charPositionInLine, const std::string &msg,
                           std::exception_ptr e) override;

 public:
  int m_nLine;
  int m_nPositionInLine;
  std::string m_strOffendingSymbol;
  std::string m_strErrMsg;
  std::string m_strStack;
};