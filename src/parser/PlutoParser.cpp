
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
      "function_list", "funcdef", "func_dec", "parameters", "block", "blockItemList", 
      "blockItem", "return_stmt", "expressionStatement", "expression", "valueExpression", 
      "primaryExpression", "identifier_with_dim", "dim_value", "constant_vector"
    },
    std::vector<std::string>{
      "", "'def'", "'('", "','", "')'", "'{'", "'}'", "'return'", "';'", 
      "'var'", "'='", "'<'", "'>'", "'['", "']'", "", "'+'", "'-'", "'*'", 
      "'/'", "'%'", "'~'", "'&'", "'|'", "'^'", "", "", "", "'/**/'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "Identifier", 
      "PLUS", "MINUS", "ASTERISK", "SLASH", "PERCENT", "TILDE", "AMPERSAND", 
      "PIPE", "HAT", "INTEGER_VALUE", "DECIMAL_DIGITS", "SIMPLE_COMMENT", 
      "BRACKETED_EMPTY_COMMENT", "BRACKETED_COMMENT", "WS", "UNRECOGNIZED"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,31,153,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,1,0,5,0,32,8,0,10,0,12,0,35,9,0,1,0,1,0,1,1,1,1,1,1,1,1,1,2,1,2,1,
  	2,1,3,1,3,1,3,1,3,5,3,50,8,3,10,3,12,3,53,9,3,3,3,55,8,3,1,3,1,3,1,4,
  	1,4,1,4,3,4,62,8,4,1,4,1,4,1,5,1,5,1,6,5,6,69,8,6,10,6,12,6,72,9,6,1,
  	7,1,7,1,7,1,7,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,3,8,90,
  	8,8,1,9,1,9,3,9,94,8,9,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,5,
  	10,105,8,10,10,10,12,10,108,9,10,1,11,1,11,1,11,1,11,1,11,1,11,5,11,116,
  	8,11,10,11,12,11,119,9,11,3,11,121,8,11,1,11,1,11,1,11,1,11,1,11,1,11,
  	3,11,129,8,11,1,12,1,12,1,12,1,13,1,13,1,13,1,13,1,13,1,13,1,14,1,14,
  	1,14,1,14,5,14,144,8,14,10,14,12,14,147,9,14,3,14,149,8,14,1,14,1,14,
  	1,14,0,1,20,15,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,0,3,1,0,18,20,
  	1,0,16,17,1,0,25,26,153,0,33,1,0,0,0,2,38,1,0,0,0,4,42,1,0,0,0,6,45,1,
  	0,0,0,8,58,1,0,0,0,10,65,1,0,0,0,12,70,1,0,0,0,14,73,1,0,0,0,16,89,1,
  	0,0,0,18,93,1,0,0,0,20,95,1,0,0,0,22,128,1,0,0,0,24,130,1,0,0,0,26,133,
  	1,0,0,0,28,139,1,0,0,0,30,32,3,2,1,0,31,30,1,0,0,0,32,35,1,0,0,0,33,31,
  	1,0,0,0,33,34,1,0,0,0,34,36,1,0,0,0,35,33,1,0,0,0,36,37,5,0,0,1,37,1,
  	1,0,0,0,38,39,3,4,2,0,39,40,3,6,3,0,40,41,3,8,4,0,41,3,1,0,0,0,42,43,
  	5,1,0,0,43,44,5,15,0,0,44,5,1,0,0,0,45,54,5,2,0,0,46,51,3,18,9,0,47,48,
  	5,3,0,0,48,50,3,18,9,0,49,47,1,0,0,0,50,53,1,0,0,0,51,49,1,0,0,0,51,52,
  	1,0,0,0,52,55,1,0,0,0,53,51,1,0,0,0,54,46,1,0,0,0,54,55,1,0,0,0,55,56,
  	1,0,0,0,56,57,5,4,0,0,57,7,1,0,0,0,58,59,5,5,0,0,59,61,3,10,5,0,60,62,
  	3,14,7,0,61,60,1,0,0,0,61,62,1,0,0,0,62,63,1,0,0,0,63,64,5,6,0,0,64,9,
  	1,0,0,0,65,66,3,12,6,0,66,11,1,0,0,0,67,69,3,16,8,0,68,67,1,0,0,0,69,
  	72,1,0,0,0,70,68,1,0,0,0,70,71,1,0,0,0,71,13,1,0,0,0,72,70,1,0,0,0,73,
  	74,5,7,0,0,74,75,3,18,9,0,75,76,5,8,0,0,76,15,1,0,0,0,77,78,5,9,0,0,78,
  	79,5,15,0,0,79,80,5,10,0,0,80,81,3,18,9,0,81,82,5,8,0,0,82,90,1,0,0,0,
  	83,84,5,9,0,0,84,85,3,24,12,0,85,86,5,10,0,0,86,87,3,18,9,0,87,88,5,8,
  	0,0,88,90,1,0,0,0,89,77,1,0,0,0,89,83,1,0,0,0,90,17,1,0,0,0,91,94,3,20,
  	10,0,92,94,3,20,10,0,93,91,1,0,0,0,93,92,1,0,0,0,94,19,1,0,0,0,95,96,
  	6,10,-1,0,96,97,3,22,11,0,97,106,1,0,0,0,98,99,10,2,0,0,99,100,7,0,0,
  	0,100,105,3,20,10,3,101,102,10,1,0,0,102,103,7,1,0,0,103,105,3,20,10,
  	2,104,98,1,0,0,0,104,101,1,0,0,0,105,108,1,0,0,0,106,104,1,0,0,0,106,
  	107,1,0,0,0,107,21,1,0,0,0,108,106,1,0,0,0,109,129,3,28,14,0,110,111,
  	5,15,0,0,111,120,5,2,0,0,112,117,3,18,9,0,113,114,5,3,0,0,114,116,3,18,
  	9,0,115,113,1,0,0,0,116,119,1,0,0,0,117,115,1,0,0,0,117,118,1,0,0,0,118,
  	121,1,0,0,0,119,117,1,0,0,0,120,112,1,0,0,0,120,121,1,0,0,0,121,122,1,
  	0,0,0,122,129,5,4,0,0,123,129,5,15,0,0,124,125,5,2,0,0,125,126,3,18,9,
  	0,126,127,5,4,0,0,127,129,1,0,0,0,128,109,1,0,0,0,128,110,1,0,0,0,128,
  	123,1,0,0,0,128,124,1,0,0,0,129,23,1,0,0,0,130,131,5,15,0,0,131,132,3,
  	26,13,0,132,25,1,0,0,0,133,134,5,11,0,0,134,135,5,25,0,0,135,136,5,3,
  	0,0,136,137,5,25,0,0,137,138,5,12,0,0,138,27,1,0,0,0,139,148,5,13,0,0,
  	140,145,7,2,0,0,141,142,5,3,0,0,142,144,7,2,0,0,143,141,1,0,0,0,144,147,
  	1,0,0,0,145,143,1,0,0,0,145,146,1,0,0,0,146,149,1,0,0,0,147,145,1,0,0,
  	0,148,140,1,0,0,0,148,149,1,0,0,0,149,150,1,0,0,0,150,151,5,14,0,0,151,
  	29,1,0,0,0,14,33,51,54,61,70,89,93,104,106,117,120,128,145,148
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


//----------------- Function_listContext ------------------------------------------------------------------

PlutoParser::Function_listContext::Function_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PlutoParser::Function_listContext::EOF() {
  return getToken(PlutoParser::EOF, 0);
}

std::vector<PlutoParser::FuncdefContext *> PlutoParser::Function_listContext::funcdef() {
  return getRuleContexts<PlutoParser::FuncdefContext>();
}

PlutoParser::FuncdefContext* PlutoParser::Function_listContext::funcdef(size_t i) {
  return getRuleContext<PlutoParser::FuncdefContext>(i);
}


size_t PlutoParser::Function_listContext::getRuleIndex() const {
  return PlutoParser::RuleFunction_list;
}


std::any PlutoParser::Function_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PlutoVisitor*>(visitor))
    return parserVisitor->visitFunction_list(this);
  else
    return visitor->visitChildren(this);
}

PlutoParser::Function_listContext* PlutoParser::function_list() {
  Function_listContext *_localctx = _tracker.createInstance<Function_listContext>(_ctx, getState());
  enterRule(_localctx, 0, PlutoParser::RuleFunction_list);
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
    setState(33);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PlutoParser::T__0) {
      setState(30);
      funcdef();
      setState(35);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(36);
    match(PlutoParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncdefContext ------------------------------------------------------------------

PlutoParser::FuncdefContext::FuncdefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PlutoParser::Func_decContext* PlutoParser::FuncdefContext::func_dec() {
  return getRuleContext<PlutoParser::Func_decContext>(0);
}

PlutoParser::ParametersContext* PlutoParser::FuncdefContext::parameters() {
  return getRuleContext<PlutoParser::ParametersContext>(0);
}

PlutoParser::BlockContext* PlutoParser::FuncdefContext::block() {
  return getRuleContext<PlutoParser::BlockContext>(0);
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
  enterRule(_localctx, 2, PlutoParser::RuleFuncdef);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(38);
    func_dec();
    setState(39);
    parameters();
    setState(40);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Func_decContext ------------------------------------------------------------------

PlutoParser::Func_decContext::Func_decContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PlutoParser::Func_decContext::Identifier() {
  return getToken(PlutoParser::Identifier, 0);
}


size_t PlutoParser::Func_decContext::getRuleIndex() const {
  return PlutoParser::RuleFunc_dec;
}


std::any PlutoParser::Func_decContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PlutoVisitor*>(visitor))
    return parserVisitor->visitFunc_dec(this);
  else
    return visitor->visitChildren(this);
}

PlutoParser::Func_decContext* PlutoParser::func_dec() {
  Func_decContext *_localctx = _tracker.createInstance<Func_decContext>(_ctx, getState());
  enterRule(_localctx, 4, PlutoParser::RuleFunc_dec);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(42);
    match(PlutoParser::T__0);
    setState(43);
    antlrcpp::downCast<Func_decContext *>(_localctx)->func_name = match(PlutoParser::Identifier);
   
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

std::vector<PlutoParser::ExpressionContext *> PlutoParser::ParametersContext::expression() {
  return getRuleContexts<PlutoParser::ExpressionContext>();
}

PlutoParser::ExpressionContext* PlutoParser::ParametersContext::expression(size_t i) {
  return getRuleContext<PlutoParser::ExpressionContext>(i);
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
  enterRule(_localctx, 6, PlutoParser::RuleParameters);
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
    setState(45);
    match(PlutoParser::T__1);
    setState(54);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 40964) != 0)) {
      setState(46);
      antlrcpp::downCast<ParametersContext *>(_localctx)->expressionContext = expression();
      antlrcpp::downCast<ParametersContext *>(_localctx)->argument.push_back(antlrcpp::downCast<ParametersContext *>(_localctx)->expressionContext);
      setState(51);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == PlutoParser::T__2) {
        setState(47);
        match(PlutoParser::T__2);
        setState(48);
        antlrcpp::downCast<ParametersContext *>(_localctx)->expressionContext = expression();
        antlrcpp::downCast<ParametersContext *>(_localctx)->argument.push_back(antlrcpp::downCast<ParametersContext *>(_localctx)->expressionContext);
        setState(53);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(56);
    match(PlutoParser::T__3);
   
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
  enterRule(_localctx, 8, PlutoParser::RuleBlock);
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
    setState(58);
    match(PlutoParser::T__4);
    setState(59);
    blockItemList();
    setState(61);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PlutoParser::T__6) {
      setState(60);
      return_stmt();
    }
    setState(63);
    match(PlutoParser::T__5);
   
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
  enterRule(_localctx, 10, PlutoParser::RuleBlockItemList);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(65);
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
  enterRule(_localctx, 12, PlutoParser::RuleBlockItem);
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
    setState(70);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PlutoParser::T__8) {
      setState(67);
      expressionStatement();
      setState(72);
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

PlutoParser::ExpressionContext* PlutoParser::Return_stmtContext::expression() {
  return getRuleContext<PlutoParser::ExpressionContext>(0);
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
  enterRule(_localctx, 14, PlutoParser::RuleReturn_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(73);
    match(PlutoParser::T__6);
    setState(74);
    expression();
    setState(75);
    match(PlutoParser::T__7);
   
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

tree::TerminalNode* PlutoParser::ExpressionStatementContext::Identifier() {
  return getToken(PlutoParser::Identifier, 0);
}

PlutoParser::Identifier_with_dimContext* PlutoParser::ExpressionStatementContext::identifier_with_dim() {
  return getRuleContext<PlutoParser::Identifier_with_dimContext>(0);
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
  enterRule(_localctx, 16, PlutoParser::RuleExpressionStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(89);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(77);
      match(PlutoParser::T__8);
      setState(78);
      antlrcpp::downCast<ExpressionStatementContext *>(_localctx)->name = match(PlutoParser::Identifier);
      setState(79);
      match(PlutoParser::T__9);
      setState(80);
      expression();
      setState(81);
      match(PlutoParser::T__7);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(83);
      match(PlutoParser::T__8);
      setState(84);
      identifier_with_dim();
      setState(85);
      match(PlutoParser::T__9);
      setState(86);
      expression();
      setState(87);
      match(PlutoParser::T__7);
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
  enterRule(_localctx, 18, PlutoParser::RuleExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(93);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(91);
      valueExpression(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(92);
      valueExpression(0);
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
  size_t startState = 20;
  enterRecursionRule(_localctx, 20, PlutoParser::RuleValueExpression, precedence);

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

    setState(96);
    primaryExpression();
    _ctx->stop = _input->LT(-1);
    setState(106);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(104);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<ArithmeticBinaryContext>(_tracker.createInstance<ValueExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleValueExpression);
          setState(98);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(99);
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
          setState(100);
          antlrcpp::downCast<ArithmeticBinaryContext *>(_localctx)->right = valueExpression(3);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<ArithmeticBinaryContext>(_tracker.createInstance<ValueExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleValueExpression);
          setState(101);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(102);
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
          setState(103);
          antlrcpp::downCast<ArithmeticBinaryContext *>(_localctx)->right = valueExpression(2);
          break;
        }

        default:
          break;
        } 
      }
      setState(108);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
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

PlutoParser::Constant_vectorContext* PlutoParser::ConstantDefaultContext::constant_vector() {
  return getRuleContext<PlutoParser::Constant_vectorContext>(0);
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
  enterRule(_localctx, 22, PlutoParser::RulePrimaryExpression);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(128);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<PlutoParser::ConstantDefaultContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(109);
      constant_vector();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<PlutoParser::FunctionCallContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(110);
      antlrcpp::downCast<FunctionCallContext *>(_localctx)->functionName = match(PlutoParser::Identifier);
      setState(111);
      match(PlutoParser::T__1);
      setState(120);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 40964) != 0)) {
        setState(112);
        antlrcpp::downCast<FunctionCallContext *>(_localctx)->expressionContext = expression();
        antlrcpp::downCast<FunctionCallContext *>(_localctx)->argument.push_back(antlrcpp::downCast<FunctionCallContext *>(_localctx)->expressionContext);
        setState(117);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PlutoParser::T__2) {
          setState(113);
          match(PlutoParser::T__2);
          setState(114);
          antlrcpp::downCast<FunctionCallContext *>(_localctx)->expressionContext = expression();
          antlrcpp::downCast<FunctionCallContext *>(_localctx)->argument.push_back(antlrcpp::downCast<FunctionCallContext *>(_localctx)->expressionContext);
          setState(119);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(122);
      match(PlutoParser::T__3);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<PlutoParser::ColumnReferenceContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(123);
      match(PlutoParser::Identifier);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<PlutoParser::ParenthesizedExpressionContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(124);
      match(PlutoParser::T__1);
      setState(125);
      expression();
      setState(126);
      match(PlutoParser::T__3);
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
  enterRule(_localctx, 24, PlutoParser::RuleIdentifier_with_dim);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(130);
    antlrcpp::downCast<Identifier_with_dimContext *>(_localctx)->name = match(PlutoParser::Identifier);
    setState(131);
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
  enterRule(_localctx, 26, PlutoParser::RuleDim_value);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(133);
    match(PlutoParser::T__10);
    setState(134);
    antlrcpp::downCast<Dim_valueContext *>(_localctx)->dim_x = match(PlutoParser::INTEGER_VALUE);
    setState(135);
    match(PlutoParser::T__2);
    setState(136);
    antlrcpp::downCast<Dim_valueContext *>(_localctx)->dim_y = match(PlutoParser::INTEGER_VALUE);
    setState(137);
    match(PlutoParser::T__11);
   
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

std::vector<tree::TerminalNode *> PlutoParser::Constant_vectorContext::INTEGER_VALUE() {
  return getTokens(PlutoParser::INTEGER_VALUE);
}

tree::TerminalNode* PlutoParser::Constant_vectorContext::INTEGER_VALUE(size_t i) {
  return getToken(PlutoParser::INTEGER_VALUE, i);
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
  enterRule(_localctx, 28, PlutoParser::RuleConstant_vector);
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
    setState(139);
    match(PlutoParser::T__12);
    setState(148);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PlutoParser::INTEGER_VALUE

    || _la == PlutoParser::DECIMAL_DIGITS) {
      setState(140);
      antlrcpp::downCast<Constant_vectorContext *>(_localctx)->_tset321 = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == PlutoParser::INTEGER_VALUE

      || _la == PlutoParser::DECIMAL_DIGITS)) {
        antlrcpp::downCast<Constant_vectorContext *>(_localctx)->_tset321 = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      antlrcpp::downCast<Constant_vectorContext *>(_localctx)->vec.push_back(antlrcpp::downCast<Constant_vectorContext *>(_localctx)->_tset321);
      setState(145);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == PlutoParser::T__2) {
        setState(141);
        match(PlutoParser::T__2);
        setState(142);
        antlrcpp::downCast<Constant_vectorContext *>(_localctx)->_tset332 = _input->LT(1);
        _la = _input->LA(1);
        if (!(_la == PlutoParser::INTEGER_VALUE

        || _la == PlutoParser::DECIMAL_DIGITS)) {
          antlrcpp::downCast<Constant_vectorContext *>(_localctx)->_tset332 = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        antlrcpp::downCast<Constant_vectorContext *>(_localctx)->vec.push_back(antlrcpp::downCast<Constant_vectorContext *>(_localctx)->_tset332);
        setState(147);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(150);
    match(PlutoParser::T__13);
   
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
    case 10: return valueExpressionSempred(antlrcpp::downCast<ValueExpressionContext *>(context), predicateIndex);

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
