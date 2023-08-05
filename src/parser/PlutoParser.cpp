
// Generated from ./src/parser/Pluto.g4 by ANTLR 4.12.0


#include "PlutoVisitor.h"

#include "PlutoParser.h"


using namespace antlrcpp;
using namespace pluto;

using namespace antlr4;

namespace {

struct PlutoParserStaticData final {
  PlutoParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  PlutoParserStaticData(const PlutoParserStaticData&) = delete;
  PlutoParserStaticData(PlutoParserStaticData&&) = delete;
  PlutoParserStaticData& operator=(const PlutoParserStaticData&) = delete;
  PlutoParserStaticData& operator=(PlutoParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag plutoParserOnceFlag;
PlutoParserStaticData *plutoParserStaticData = nullptr;

void plutoParserInitialize() {
  assert(plutoParserStaticData == nullptr);
  auto staticData = std::make_unique<PlutoParserStaticData>(
    std::vector<std::string>{
      "funcdef", "parameters", "block", "blockItemList", "blockItem", "return_stmt", 
      "expressionStatement", "expression", "valueExpression", "primaryExpression", 
      "constant", "identifier_with_dim", "dim_value", "constant_vector"
    },
    std::vector<std::string>{
      "", "'('", "')'", "'{'", "'}'", "';'", "','", "'='", "'<'", "'>'", 
      "'['", "']'", "", "'var'", "'def'", "'return'", "'+'", "'-'", "'*'", 
      "'/'", "'%'", "'~'", "'&'", "'|'", "'^'", "", "", "'/**/'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "Identifier", "VAR", 
      "DEF", "RETURN", "PLUS", "MINUS", "ASTERISK", "SLASH", "PERCENT", 
      "TILDE", "AMPERSAND", "PIPE", "HAT", "INTEGER_VALUE", "SIMPLE_COMMENT", 
      "BRACKETED_EMPTY_COMMENT", "BRACKETED_COMMENT", "WS", "UNRECOGNIZED", 
      "DECIMAL_DIGITS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,31,125,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,1,0,1,0,
  	1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,2,1,2,1,2,3,2,41,8,2,1,2,1,2,1,3,1,3,1,
  	4,5,4,48,8,4,10,4,12,4,51,9,4,1,5,1,5,1,5,1,6,3,6,57,8,6,1,6,1,6,1,7,
  	1,7,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,5,8,72,8,8,10,8,12,8,75,9,8,1,
  	9,1,9,1,9,1,9,1,9,1,9,5,9,83,8,9,10,9,12,9,86,9,9,3,9,88,8,9,1,9,1,9,
  	1,9,1,9,1,9,1,9,3,9,96,8,9,1,10,1,10,1,10,1,10,1,10,1,11,1,11,1,11,1,
  	12,1,12,1,12,1,12,1,12,1,12,1,13,1,13,1,13,1,13,5,13,116,8,13,10,13,12,
  	13,119,9,13,3,13,121,8,13,1,13,1,13,1,13,0,1,16,14,0,2,4,6,8,10,12,14,
  	16,18,20,22,24,26,0,2,1,0,18,20,1,0,16,17,122,0,28,1,0,0,0,2,33,1,0,0,
  	0,4,37,1,0,0,0,6,44,1,0,0,0,8,49,1,0,0,0,10,52,1,0,0,0,12,56,1,0,0,0,
  	14,60,1,0,0,0,16,62,1,0,0,0,18,95,1,0,0,0,20,97,1,0,0,0,22,102,1,0,0,
  	0,24,105,1,0,0,0,26,111,1,0,0,0,28,29,5,14,0,0,29,30,5,12,0,0,30,31,3,
  	2,1,0,31,32,3,4,2,0,32,1,1,0,0,0,33,34,5,1,0,0,34,35,5,12,0,0,35,36,5,
  	2,0,0,36,3,1,0,0,0,37,38,5,3,0,0,38,40,3,6,3,0,39,41,3,10,5,0,40,39,1,
  	0,0,0,40,41,1,0,0,0,41,42,1,0,0,0,42,43,5,4,0,0,43,5,1,0,0,0,44,45,3,
  	8,4,0,45,7,1,0,0,0,46,48,3,12,6,0,47,46,1,0,0,0,48,51,1,0,0,0,49,47,1,
  	0,0,0,49,50,1,0,0,0,50,9,1,0,0,0,51,49,1,0,0,0,52,53,5,15,0,0,53,54,3,
  	12,6,0,54,11,1,0,0,0,55,57,3,14,7,0,56,55,1,0,0,0,56,57,1,0,0,0,57,58,
  	1,0,0,0,58,59,5,5,0,0,59,13,1,0,0,0,60,61,3,16,8,0,61,15,1,0,0,0,62,63,
  	6,8,-1,0,63,64,3,18,9,0,64,73,1,0,0,0,65,66,10,2,0,0,66,67,7,0,0,0,67,
  	72,3,16,8,3,68,69,10,1,0,0,69,70,7,1,0,0,70,72,3,16,8,2,71,65,1,0,0,0,
  	71,68,1,0,0,0,72,75,1,0,0,0,73,71,1,0,0,0,73,74,1,0,0,0,74,17,1,0,0,0,
  	75,73,1,0,0,0,76,96,3,20,10,0,77,78,5,12,0,0,78,87,5,1,0,0,79,84,3,14,
  	7,0,80,81,5,6,0,0,81,83,3,14,7,0,82,80,1,0,0,0,83,86,1,0,0,0,84,82,1,
  	0,0,0,84,85,1,0,0,0,85,88,1,0,0,0,86,84,1,0,0,0,87,79,1,0,0,0,87,88,1,
  	0,0,0,88,89,1,0,0,0,89,96,5,2,0,0,90,96,5,12,0,0,91,92,5,1,0,0,92,93,
  	3,14,7,0,93,94,5,2,0,0,94,96,1,0,0,0,95,76,1,0,0,0,95,77,1,0,0,0,95,90,
  	1,0,0,0,95,91,1,0,0,0,96,19,1,0,0,0,97,98,5,13,0,0,98,99,3,22,11,0,99,
  	100,5,7,0,0,100,101,3,26,13,0,101,21,1,0,0,0,102,103,5,12,0,0,103,104,
  	3,24,12,0,104,23,1,0,0,0,105,106,5,8,0,0,106,107,5,25,0,0,107,108,5,6,
  	0,0,108,109,5,25,0,0,109,110,5,9,0,0,110,25,1,0,0,0,111,120,5,10,0,0,
  	112,117,5,31,0,0,113,114,5,6,0,0,114,116,5,31,0,0,115,113,1,0,0,0,116,
  	119,1,0,0,0,117,115,1,0,0,0,117,118,1,0,0,0,118,121,1,0,0,0,119,117,1,
  	0,0,0,120,112,1,0,0,0,120,121,1,0,0,0,121,122,1,0,0,0,122,123,5,11,0,
  	0,123,27,1,0,0,0,10,40,49,56,71,73,84,87,95,117,120
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  plutoParserStaticData = staticData.release();
}

}

PlutoParser::PlutoParser(TokenStream *input) : PlutoParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

PlutoParser::PlutoParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  PlutoParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *plutoParserStaticData->atn, plutoParserStaticData->decisionToDFA, plutoParserStaticData->sharedContextCache, options);
}

PlutoParser::~PlutoParser() {
  delete _interpreter;
}

const atn::ATN& PlutoParser::getATN() const {
  return *plutoParserStaticData->atn;
}

std::string PlutoParser::getGrammarFileName() const {
  return "Pluto.g4";
}

const std::vector<std::string>& PlutoParser::getRuleNames() const {
  return plutoParserStaticData->ruleNames;
}

const dfa::Vocabulary& PlutoParser::getVocabulary() const {
  return plutoParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView PlutoParser::getSerializedATN() const {
  return plutoParserStaticData->serializedATN;
}


//----------------- FuncdefContext ------------------------------------------------------------------

PlutoParser::FuncdefContext::FuncdefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PlutoParser::FuncdefContext::DEF() {
  return getToken(PlutoParser::DEF, 0);
}

PlutoParser::ParametersContext* PlutoParser::FuncdefContext::parameters() {
  return getRuleContext<PlutoParser::ParametersContext>(0);
}

PlutoParser::BlockContext* PlutoParser::FuncdefContext::block() {
  return getRuleContext<PlutoParser::BlockContext>(0);
}

tree::TerminalNode* PlutoParser::FuncdefContext::Identifier() {
  return getToken(PlutoParser::Identifier, 0);
}


size_t PlutoParser::FuncdefContext::getRuleIndex() const {
  return PlutoParser::RuleFuncdef;
}


std::any PlutoParser::FuncdefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PlutoVisitor*>(visitor))
    return parserVisitor->visitFuncdef(this);
  else
    return visitor->visitChildren(this);
}

PlutoParser::FuncdefContext* PlutoParser::funcdef() {
  FuncdefContext *_localctx = _tracker.createInstance<FuncdefContext>(_ctx, getState());
  enterRule(_localctx, 0, PlutoParser::RuleFuncdef);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(28);
    match(PlutoParser::DEF);
    setState(29);
    antlrcpp::downCast<FuncdefContext *>(_localctx)->func_name = match(PlutoParser::Identifier);
    setState(30);
    parameters();
    setState(31);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParametersContext ------------------------------------------------------------------

PlutoParser::ParametersContext::ParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PlutoParser::ParametersContext::Identifier() {
  return getToken(PlutoParser::Identifier, 0);
}


size_t PlutoParser::ParametersContext::getRuleIndex() const {
  return PlutoParser::RuleParameters;
}


std::any PlutoParser::ParametersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PlutoVisitor*>(visitor))
    return parserVisitor->visitParameters(this);
  else
    return visitor->visitChildren(this);
}

PlutoParser::ParametersContext* PlutoParser::parameters() {
  ParametersContext *_localctx = _tracker.createInstance<ParametersContext>(_ctx, getState());
  enterRule(_localctx, 2, PlutoParser::RuleParameters);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(33);
    match(PlutoParser::T__0);
    setState(34);
    antlrcpp::downCast<ParametersContext *>(_localctx)->identifierToken = match(PlutoParser::Identifier);
    antlrcpp::downCast<ParametersContext *>(_localctx)->args.push_back(antlrcpp::downCast<ParametersContext *>(_localctx)->identifierToken);
    setState(35);
    match(PlutoParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

PlutoParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PlutoParser::BlockItemListContext* PlutoParser::BlockContext::blockItemList() {
  return getRuleContext<PlutoParser::BlockItemListContext>(0);
}

PlutoParser::Return_stmtContext* PlutoParser::BlockContext::return_stmt() {
  return getRuleContext<PlutoParser::Return_stmtContext>(0);
}


size_t PlutoParser::BlockContext::getRuleIndex() const {
  return PlutoParser::RuleBlock;
}


std::any PlutoParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PlutoVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

PlutoParser::BlockContext* PlutoParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 4, PlutoParser::RuleBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(37);
    match(PlutoParser::T__2);
    setState(38);
    blockItemList();
    setState(40);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PlutoParser::RETURN) {
      setState(39);
      return_stmt();
    }
    setState(42);
    match(PlutoParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockItemListContext ------------------------------------------------------------------

PlutoParser::BlockItemListContext::BlockItemListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PlutoParser::BlockItemContext* PlutoParser::BlockItemListContext::blockItem() {
  return getRuleContext<PlutoParser::BlockItemContext>(0);
}


size_t PlutoParser::BlockItemListContext::getRuleIndex() const {
  return PlutoParser::RuleBlockItemList;
}


std::any PlutoParser::BlockItemListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PlutoVisitor*>(visitor))
    return parserVisitor->visitBlockItemList(this);
  else
    return visitor->visitChildren(this);
}

PlutoParser::BlockItemListContext* PlutoParser::blockItemList() {
  BlockItemListContext *_localctx = _tracker.createInstance<BlockItemListContext>(_ctx, getState());
  enterRule(_localctx, 6, PlutoParser::RuleBlockItemList);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(44);
    blockItem();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockItemContext ------------------------------------------------------------------

PlutoParser::BlockItemContext::BlockItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PlutoParser::ExpressionStatementContext *> PlutoParser::BlockItemContext::expressionStatement() {
  return getRuleContexts<PlutoParser::ExpressionStatementContext>();
}

PlutoParser::ExpressionStatementContext* PlutoParser::BlockItemContext::expressionStatement(size_t i) {
  return getRuleContext<PlutoParser::ExpressionStatementContext>(i);
}


size_t PlutoParser::BlockItemContext::getRuleIndex() const {
  return PlutoParser::RuleBlockItem;
}


std::any PlutoParser::BlockItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PlutoVisitor*>(visitor))
    return parserVisitor->visitBlockItem(this);
  else
    return visitor->visitChildren(this);
}

PlutoParser::BlockItemContext* PlutoParser::blockItem() {
  BlockItemContext *_localctx = _tracker.createInstance<BlockItemContext>(_ctx, getState());
  enterRule(_localctx, 8, PlutoParser::RuleBlockItem);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(49);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 12322) != 0)) {
      setState(46);
      expressionStatement();
      setState(51);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Return_stmtContext ------------------------------------------------------------------

PlutoParser::Return_stmtContext::Return_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PlutoParser::Return_stmtContext::RETURN() {
  return getToken(PlutoParser::RETURN, 0);
}

PlutoParser::ExpressionStatementContext* PlutoParser::Return_stmtContext::expressionStatement() {
  return getRuleContext<PlutoParser::ExpressionStatementContext>(0);
}


size_t PlutoParser::Return_stmtContext::getRuleIndex() const {
  return PlutoParser::RuleReturn_stmt;
}


std::any PlutoParser::Return_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PlutoVisitor*>(visitor))
    return parserVisitor->visitReturn_stmt(this);
  else
    return visitor->visitChildren(this);
}

PlutoParser::Return_stmtContext* PlutoParser::return_stmt() {
  Return_stmtContext *_localctx = _tracker.createInstance<Return_stmtContext>(_ctx, getState());
  enterRule(_localctx, 10, PlutoParser::RuleReturn_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(52);
    match(PlutoParser::RETURN);
    setState(53);
    expressionStatement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionStatementContext ------------------------------------------------------------------

PlutoParser::ExpressionStatementContext::ExpressionStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PlutoParser::ExpressionContext* PlutoParser::ExpressionStatementContext::expression() {
  return getRuleContext<PlutoParser::ExpressionContext>(0);
}


size_t PlutoParser::ExpressionStatementContext::getRuleIndex() const {
  return PlutoParser::RuleExpressionStatement;
}


std::any PlutoParser::ExpressionStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PlutoVisitor*>(visitor))
    return parserVisitor->visitExpressionStatement(this);
  else
    return visitor->visitChildren(this);
}

PlutoParser::ExpressionStatementContext* PlutoParser::expressionStatement() {
  ExpressionStatementContext *_localctx = _tracker.createInstance<ExpressionStatementContext>(_ctx, getState());
  enterRule(_localctx, 12, PlutoParser::RuleExpressionStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(56);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 12290) != 0)) {
      setState(55);
      expression();
    }
    setState(58);
    match(PlutoParser::T__4);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

PlutoParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PlutoParser::ValueExpressionContext* PlutoParser::ExpressionContext::valueExpression() {
  return getRuleContext<PlutoParser::ValueExpressionContext>(0);
}


size_t PlutoParser::ExpressionContext::getRuleIndex() const {
  return PlutoParser::RuleExpression;
}


std::any PlutoParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PlutoVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}

PlutoParser::ExpressionContext* PlutoParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 14, PlutoParser::RuleExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(60);
    valueExpression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ValueExpressionContext ------------------------------------------------------------------

PlutoParser::ValueExpressionContext::ValueExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PlutoParser::ValueExpressionContext::getRuleIndex() const {
  return PlutoParser::RuleValueExpression;
}

void PlutoParser::ValueExpressionContext::copyFrom(ValueExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ValueExpressionDefaultContext ------------------------------------------------------------------

PlutoParser::PrimaryExpressionContext* PlutoParser::ValueExpressionDefaultContext::primaryExpression() {
  return getRuleContext<PlutoParser::PrimaryExpressionContext>(0);
}

PlutoParser::ValueExpressionDefaultContext::ValueExpressionDefaultContext(ValueExpressionContext *ctx) { copyFrom(ctx); }


std::any PlutoParser::ValueExpressionDefaultContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PlutoVisitor*>(visitor))
    return parserVisitor->visitValueExpressionDefault(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArithmeticBinaryContext ------------------------------------------------------------------

std::vector<PlutoParser::ValueExpressionContext *> PlutoParser::ArithmeticBinaryContext::valueExpression() {
  return getRuleContexts<PlutoParser::ValueExpressionContext>();
}

PlutoParser::ValueExpressionContext* PlutoParser::ArithmeticBinaryContext::valueExpression(size_t i) {
  return getRuleContext<PlutoParser::ValueExpressionContext>(i);
}

tree::TerminalNode* PlutoParser::ArithmeticBinaryContext::ASTERISK() {
  return getToken(PlutoParser::ASTERISK, 0);
}

tree::TerminalNode* PlutoParser::ArithmeticBinaryContext::SLASH() {
  return getToken(PlutoParser::SLASH, 0);
}

tree::TerminalNode* PlutoParser::ArithmeticBinaryContext::PERCENT() {
  return getToken(PlutoParser::PERCENT, 0);
}

tree::TerminalNode* PlutoParser::ArithmeticBinaryContext::PLUS() {
  return getToken(PlutoParser::PLUS, 0);
}

tree::TerminalNode* PlutoParser::ArithmeticBinaryContext::MINUS() {
  return getToken(PlutoParser::MINUS, 0);
}

PlutoParser::ArithmeticBinaryContext::ArithmeticBinaryContext(ValueExpressionContext *ctx) { copyFrom(ctx); }


std::any PlutoParser::ArithmeticBinaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PlutoVisitor*>(visitor))
    return parserVisitor->visitArithmeticBinary(this);
  else
    return visitor->visitChildren(this);
}

PlutoParser::ValueExpressionContext* PlutoParser::valueExpression() {
   return valueExpression(0);
}

PlutoParser::ValueExpressionContext* PlutoParser::valueExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  PlutoParser::ValueExpressionContext *_localctx = _tracker.createInstance<ValueExpressionContext>(_ctx, parentState);
  PlutoParser::ValueExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 16;
  enterRecursionRule(_localctx, 16, PlutoParser::RuleValueExpression, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<ValueExpressionDefaultContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(63);
    primaryExpression();
    _ctx->stop = _input->LT(-1);
    setState(73);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(71);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<ArithmeticBinaryContext>(_tracker.createInstance<ValueExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleValueExpression);
          setState(65);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(66);
          antlrcpp::downCast<ArithmeticBinaryContext *>(_localctx)->operator_ = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 1835008) != 0))) {
            antlrcpp::downCast<ArithmeticBinaryContext *>(_localctx)->operator_ = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(67);
          antlrcpp::downCast<ArithmeticBinaryContext *>(_localctx)->right = valueExpression(3);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<ArithmeticBinaryContext>(_tracker.createInstance<ValueExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleValueExpression);
          setState(68);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(69);
          antlrcpp::downCast<ArithmeticBinaryContext *>(_localctx)->operator_ = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == PlutoParser::PLUS

          || _la == PlutoParser::MINUS)) {
            antlrcpp::downCast<ArithmeticBinaryContext *>(_localctx)->operator_ = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(70);
          antlrcpp::downCast<ArithmeticBinaryContext *>(_localctx)->right = valueExpression(2);
          break;
        }

        default:
          break;
        } 
      }
      setState(75);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- PrimaryExpressionContext ------------------------------------------------------------------

PlutoParser::PrimaryExpressionContext::PrimaryExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PlutoParser::PrimaryExpressionContext::getRuleIndex() const {
  return PlutoParser::RulePrimaryExpression;
}

void PlutoParser::PrimaryExpressionContext::copyFrom(PrimaryExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ConstantDefaultContext ------------------------------------------------------------------

PlutoParser::ConstantContext* PlutoParser::ConstantDefaultContext::constant() {
  return getRuleContext<PlutoParser::ConstantContext>(0);
}

PlutoParser::ConstantDefaultContext::ConstantDefaultContext(PrimaryExpressionContext *ctx) { copyFrom(ctx); }


std::any PlutoParser::ConstantDefaultContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PlutoVisitor*>(visitor))
    return parserVisitor->visitConstantDefault(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ColumnReferenceContext ------------------------------------------------------------------

tree::TerminalNode* PlutoParser::ColumnReferenceContext::Identifier() {
  return getToken(PlutoParser::Identifier, 0);
}

PlutoParser::ColumnReferenceContext::ColumnReferenceContext(PrimaryExpressionContext *ctx) { copyFrom(ctx); }


std::any PlutoParser::ColumnReferenceContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PlutoVisitor*>(visitor))
    return parserVisitor->visitColumnReference(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParenthesizedExpressionContext ------------------------------------------------------------------

PlutoParser::ExpressionContext* PlutoParser::ParenthesizedExpressionContext::expression() {
  return getRuleContext<PlutoParser::ExpressionContext>(0);
}

PlutoParser::ParenthesizedExpressionContext::ParenthesizedExpressionContext(PrimaryExpressionContext *ctx) { copyFrom(ctx); }


std::any PlutoParser::ParenthesizedExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PlutoVisitor*>(visitor))
    return parserVisitor->visitParenthesizedExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FunctionCallContext ------------------------------------------------------------------

tree::TerminalNode* PlutoParser::FunctionCallContext::Identifier() {
  return getToken(PlutoParser::Identifier, 0);
}

std::vector<PlutoParser::ExpressionContext *> PlutoParser::FunctionCallContext::expression() {
  return getRuleContexts<PlutoParser::ExpressionContext>();
}

PlutoParser::ExpressionContext* PlutoParser::FunctionCallContext::expression(size_t i) {
  return getRuleContext<PlutoParser::ExpressionContext>(i);
}

PlutoParser::FunctionCallContext::FunctionCallContext(PrimaryExpressionContext *ctx) { copyFrom(ctx); }


std::any PlutoParser::FunctionCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PlutoVisitor*>(visitor))
    return parserVisitor->visitFunctionCall(this);
  else
    return visitor->visitChildren(this);
}
PlutoParser::PrimaryExpressionContext* PlutoParser::primaryExpression() {
  PrimaryExpressionContext *_localctx = _tracker.createInstance<PrimaryExpressionContext>(_ctx, getState());
  enterRule(_localctx, 18, PlutoParser::RulePrimaryExpression);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(95);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<PlutoParser::ConstantDefaultContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(76);
      constant();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<PlutoParser::FunctionCallContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(77);
      antlrcpp::downCast<FunctionCallContext *>(_localctx)->functionName = match(PlutoParser::Identifier);
      setState(78);
      match(PlutoParser::T__0);
      setState(87);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 12290) != 0)) {
        setState(79);
        antlrcpp::downCast<FunctionCallContext *>(_localctx)->expressionContext = expression();
        antlrcpp::downCast<FunctionCallContext *>(_localctx)->argument.push_back(antlrcpp::downCast<FunctionCallContext *>(_localctx)->expressionContext);
        setState(84);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PlutoParser::T__5) {
          setState(80);
          match(PlutoParser::T__5);
          setState(81);
          antlrcpp::downCast<FunctionCallContext *>(_localctx)->expressionContext = expression();
          antlrcpp::downCast<FunctionCallContext *>(_localctx)->argument.push_back(antlrcpp::downCast<FunctionCallContext *>(_localctx)->expressionContext);
          setState(86);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(89);
      match(PlutoParser::T__1);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<PlutoParser::ColumnReferenceContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(90);
      match(PlutoParser::Identifier);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<PlutoParser::ParenthesizedExpressionContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(91);
      match(PlutoParser::T__0);
      setState(92);
      expression();
      setState(93);
      match(PlutoParser::T__1);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstantContext ------------------------------------------------------------------

PlutoParser::ConstantContext::ConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PlutoParser::ConstantContext::VAR() {
  return getToken(PlutoParser::VAR, 0);
}

PlutoParser::Constant_vectorContext* PlutoParser::ConstantContext::constant_vector() {
  return getRuleContext<PlutoParser::Constant_vectorContext>(0);
}

PlutoParser::Identifier_with_dimContext* PlutoParser::ConstantContext::identifier_with_dim() {
  return getRuleContext<PlutoParser::Identifier_with_dimContext>(0);
}


size_t PlutoParser::ConstantContext::getRuleIndex() const {
  return PlutoParser::RuleConstant;
}


std::any PlutoParser::ConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PlutoVisitor*>(visitor))
    return parserVisitor->visitConstant(this);
  else
    return visitor->visitChildren(this);
}

PlutoParser::ConstantContext* PlutoParser::constant() {
  ConstantContext *_localctx = _tracker.createInstance<ConstantContext>(_ctx, getState());
  enterRule(_localctx, 20, PlutoParser::RuleConstant);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(97);
    match(PlutoParser::VAR);
    setState(98);
    antlrcpp::downCast<ConstantContext *>(_localctx)->name = identifier_with_dim();
    setState(99);
    match(PlutoParser::T__6);
    setState(100);
    constant_vector();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Identifier_with_dimContext ------------------------------------------------------------------

PlutoParser::Identifier_with_dimContext::Identifier_with_dimContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PlutoParser::Identifier_with_dimContext::Identifier() {
  return getToken(PlutoParser::Identifier, 0);
}

PlutoParser::Dim_valueContext* PlutoParser::Identifier_with_dimContext::dim_value() {
  return getRuleContext<PlutoParser::Dim_valueContext>(0);
}


size_t PlutoParser::Identifier_with_dimContext::getRuleIndex() const {
  return PlutoParser::RuleIdentifier_with_dim;
}


std::any PlutoParser::Identifier_with_dimContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PlutoVisitor*>(visitor))
    return parserVisitor->visitIdentifier_with_dim(this);
  else
    return visitor->visitChildren(this);
}

PlutoParser::Identifier_with_dimContext* PlutoParser::identifier_with_dim() {
  Identifier_with_dimContext *_localctx = _tracker.createInstance<Identifier_with_dimContext>(_ctx, getState());
  enterRule(_localctx, 22, PlutoParser::RuleIdentifier_with_dim);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(102);
    antlrcpp::downCast<Identifier_with_dimContext *>(_localctx)->name = match(PlutoParser::Identifier);
    setState(103);
    antlrcpp::downCast<Identifier_with_dimContext *>(_localctx)->dim = dim_value();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Dim_valueContext ------------------------------------------------------------------

PlutoParser::Dim_valueContext::Dim_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> PlutoParser::Dim_valueContext::INTEGER_VALUE() {
  return getTokens(PlutoParser::INTEGER_VALUE);
}

tree::TerminalNode* PlutoParser::Dim_valueContext::INTEGER_VALUE(size_t i) {
  return getToken(PlutoParser::INTEGER_VALUE, i);
}


size_t PlutoParser::Dim_valueContext::getRuleIndex() const {
  return PlutoParser::RuleDim_value;
}


std::any PlutoParser::Dim_valueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PlutoVisitor*>(visitor))
    return parserVisitor->visitDim_value(this);
  else
    return visitor->visitChildren(this);
}

PlutoParser::Dim_valueContext* PlutoParser::dim_value() {
  Dim_valueContext *_localctx = _tracker.createInstance<Dim_valueContext>(_ctx, getState());
  enterRule(_localctx, 24, PlutoParser::RuleDim_value);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(105);
    match(PlutoParser::T__7);
    setState(106);
    antlrcpp::downCast<Dim_valueContext *>(_localctx)->dim_x = match(PlutoParser::INTEGER_VALUE);
    setState(107);
    match(PlutoParser::T__5);
    setState(108);
    antlrcpp::downCast<Dim_valueContext *>(_localctx)->dim_y = match(PlutoParser::INTEGER_VALUE);
    setState(109);
    match(PlutoParser::T__8);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Constant_vectorContext ------------------------------------------------------------------

PlutoParser::Constant_vectorContext::Constant_vectorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> PlutoParser::Constant_vectorContext::DECIMAL_DIGITS() {
  return getTokens(PlutoParser::DECIMAL_DIGITS);
}

tree::TerminalNode* PlutoParser::Constant_vectorContext::DECIMAL_DIGITS(size_t i) {
  return getToken(PlutoParser::DECIMAL_DIGITS, i);
}


size_t PlutoParser::Constant_vectorContext::getRuleIndex() const {
  return PlutoParser::RuleConstant_vector;
}


std::any PlutoParser::Constant_vectorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PlutoVisitor*>(visitor))
    return parserVisitor->visitConstant_vector(this);
  else
    return visitor->visitChildren(this);
}

PlutoParser::Constant_vectorContext* PlutoParser::constant_vector() {
  Constant_vectorContext *_localctx = _tracker.createInstance<Constant_vectorContext>(_ctx, getState());
  enterRule(_localctx, 26, PlutoParser::RuleConstant_vector);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(111);
    match(PlutoParser::T__9);
    setState(120);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PlutoParser::DECIMAL_DIGITS) {
      setState(112);
      antlrcpp::downCast<Constant_vectorContext *>(_localctx)->decimal_digitsToken = match(PlutoParser::DECIMAL_DIGITS);
      antlrcpp::downCast<Constant_vectorContext *>(_localctx)->vec.push_back(antlrcpp::downCast<Constant_vectorContext *>(_localctx)->decimal_digitsToken);
      setState(117);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == PlutoParser::T__5) {
        setState(113);
        match(PlutoParser::T__5);
        setState(114);
        antlrcpp::downCast<Constant_vectorContext *>(_localctx)->decimal_digitsToken = match(PlutoParser::DECIMAL_DIGITS);
        antlrcpp::downCast<Constant_vectorContext *>(_localctx)->vec.push_back(antlrcpp::downCast<Constant_vectorContext *>(_localctx)->decimal_digitsToken);
        setState(119);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(122);
    match(PlutoParser::T__10);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool PlutoParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 8: return valueExpressionSempred(antlrcpp::downCast<ValueExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool PlutoParser::valueExpressionSempred(ValueExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 2);
    case 1: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

void PlutoParser::initialize() {
  ::antlr4::internal::call_once(plutoParserOnceFlag, plutoParserInitialize);
}
