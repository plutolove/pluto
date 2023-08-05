#include "parser/PlutoErrorListener.h"

#include <Parser.h>
#include <Recognizer.h>
#include <Token.h>

#include <algorithm>

PlutoErrorListener::PlutoErrorListener(void) {
  m_nLine = 0;
  m_nPositionInLine = 0;
}

void PlutoErrorListener::syntaxError(antlr4::Recognizer *recognizer,
                                     antlr4::Token *offendingSymbol,
                                     size_t line, size_t charPositionInLine,
                                     const std::string &msg,
                                     std::exception_ptr /*e*/) {
  m_nLine = line;
  m_nPositionInLine = charPositionInLine;
  m_strErrMsg = msg;
  m_strOffendingSymbol = offendingSymbol->toString();
  std::vector<std::string> stack =
      dynamic_cast<antlr4::Parser *>(recognizer)->getRuleInvocationStack();
  std::reverse(stack.begin(), stack.end());
  m_strStack.clear();
  for (size_t nIndex = 0; nIndex < stack.size(); nIndex++) {
    m_strStack += stack[nIndex];
    if (nIndex + 1 < stack.size()) m_strStack += "\r\n";
  }
}