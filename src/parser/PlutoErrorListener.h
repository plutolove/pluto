#pragma once
#include "BaseErrorListener.h"
#include "fmt/format.h"

class PlutoErrorListener : public antlr4::BaseErrorListener {
 public:
  PlutoErrorListener(void);
  virtual void syntaxError(antlr4::Recognizer *recognizer,
                           antlr4::Token *offendingSymbol, size_t line,
                           size_t charPositionInLine, const std::string &msg,
                           std::exception_ptr e) override;
  std::string error_msg() const {
    return fmt::format("line: {}, pos: {}, err msg: {}, symbol: {}, stack: {}",
                       m_nLine, m_nPositionInLine, m_strErrMsg,
                       m_strOffendingSymbol, m_strStack);
  }

 public:
  int m_nLine;
  int m_nPositionInLine;
  std::string m_strOffendingSymbol;
  std::string m_strErrMsg;
  std::string m_strStack;
};