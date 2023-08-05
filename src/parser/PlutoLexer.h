
// Generated from ./src/parser/Pluto.g4 by ANTLR 4.12.0

#pragma once


#include "antlr4-runtime.h"


namespace pluto {


class  PlutoLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, Identifier = 12, VAR = 13, 
    DEF = 14, RETURN = 15, PLUS = 16, MINUS = 17, ASTERISK = 18, SLASH = 19, 
    PERCENT = 20, TILDE = 21, AMPERSAND = 22, PIPE = 23, HAT = 24, INTEGER_VALUE = 25, 
    SIMPLE_COMMENT = 26, BRACKETED_EMPTY_COMMENT = 27, BRACKETED_COMMENT = 28, 
    WS = 29, UNRECOGNIZED = 30
  };

  explicit PlutoLexer(antlr4::CharStream *input);

  ~PlutoLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

}  // namespace pluto
