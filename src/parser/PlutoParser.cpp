
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
      "primaryExpression", "dim_value", "constant_vector"
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
  	4,1,31,149,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,1,0,5,0,
  	30,8,0,10,0,12,0,33,9,0,1,0,1,0,1,1,1,1,1,1,1,2,1,2,1,2,1,2,1,3,1,3,1,
  	3,1,3,5,3,48,8,3,10,3,12,3,51,9,3,3,3,53,8,3,1,3,1,3,1,4,1,4,1,4,3,4,
  	60,8,4,1,4,1,4,1,5,5,5,65,8,5,10,5,12,5,68,9,5,1,6,1,6,1,7,1,7,1,7,1,
  	7,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,3,8,89,8,8,1,9,
  	1,9,3,9,93,8,9,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,5,10,104,
  	8,10,10,10,12,10,107,9,10,1,11,1,11,1,11,1,11,1,11,1,11,5,11,115,8,11,
  	10,11,12,11,118,9,11,3,11,120,8,11,1,11,1,11,1,11,1,11,1,11,1,11,3,11,
  	128,8,11,1,12,1,12,1,12,1,12,1,12,1,12,1,13,1,13,1,13,1,13,5,13,140,8,
  	13,10,13,12,13,143,9,13,3,13,145,8,13,1,13,1,13,1,13,0,1,20,14,0,2,4,
  	6,8,10,12,14,16,18,20,22,24,26,0,3,1,0,18,20,1,0,16,17,1,0,25,26,150,
  	0,31,1,0,0,0,2,36,1,0,0,0,4,39,1,0,0,0,6,43,1,0,0,0,8,56,1,0,0,0,10,66,
  	1,0,0,0,12,69,1,0,0,0,14,71,1,0,0,0,16,88,1,0,0,0,18,92,1,0,0,0,20,94,
  	1,0,0,0,22,127,1,0,0,0,24,129,1,0,0,0,26,135,1,0,0,0,28,30,3,2,1,0,29,
  	28,1,0,0,0,30,33,1,0,0,0,31,29,1,0,0,0,31,32,1,0,0,0,32,34,1,0,0,0,33,
  	31,1,0,0,0,34,35,5,0,0,1,35,1,1,0,0,0,36,37,3,4,2,0,37,38,3,8,4,0,38,
  	3,1,0,0,0,39,40,5,1,0,0,40,41,5,15,0,0,41,42,3,6,3,0,42,5,1,0,0,0,43,
  	52,5,2,0,0,44,49,5,15,0,0,45,46,5,3,0,0,46,48,5,15,0,0,47,45,1,0,0,0,
  	48,51,1,0,0,0,49,47,1,0,0,0,49,50,1,0,0,0,50,53,1,0,0,0,51,49,1,0,0,0,
  	52,44,1,0,0,0,52,53,1,0,0,0,53,54,1,0,0,0,54,55,5,4,0,0,55,7,1,0,0,0,
  	56,57,5,5,0,0,57,59,3,10,5,0,58,60,3,14,7,0,59,58,1,0,0,0,59,60,1,0,0,
  	0,60,61,1,0,0,0,61,62,5,6,0,0,62,9,1,0,0,0,63,65,3,12,6,0,64,63,1,0,0,
  	0,65,68,1,0,0,0,66,64,1,0,0,0,66,67,1,0,0,0,67,11,1,0,0,0,68,66,1,0,0,
  	0,69,70,3,16,8,0,70,13,1,0,0,0,71,72,5,7,0,0,72,73,3,18,9,0,73,74,5,8,
  	0,0,74,15,1,0,0,0,75,76,5,9,0,0,76,77,5,15,0,0,77,78,5,10,0,0,78,79,3,
  	18,9,0,79,80,5,8,0,0,80,89,1,0,0,0,81,82,5,9,0,0,82,83,5,15,0,0,83,84,
  	3,24,12,0,84,85,5,10,0,0,85,86,3,18,9,0,86,87,5,8,0,0,87,89,1,0,0,0,88,
  	75,1,0,0,0,88,81,1,0,0,0,89,17,1,0,0,0,90,93,3,20,10,0,91,93,3,20,10,
  	0,92,90,1,0,0,0,92,91,1,0,0,0,93,19,1,0,0,0,94,95,6,10,-1,0,95,96,3,22,
  	11,0,96,105,1,0,0,0,97,98,10,2,0,0,98,99,7,0,0,0,99,104,3,20,10,3,100,
  	101,10,1,0,0,101,102,7,1,0,0,102,104,3,20,10,2,103,97,1,0,0,0,103,100,
  	1,0,0,0,104,107,1,0,0,0,105,103,1,0,0,0,105,106,1,0,0,0,106,21,1,0,0,
  	0,107,105,1,0,0,0,108,128,3,26,13,0,109,110,5,15,0,0,110,119,5,2,0,0,
  	111,116,3,18,9,0,112,113,5,3,0,0,113,115,3,18,9,0,114,112,1,0,0,0,115,
  	118,1,0,0,0,116,114,1,0,0,0,116,117,1,0,0,0,117,120,1,0,0,0,118,116,1,
  	0,0,0,119,111,1,0,0,0,119,120,1,0,0,0,120,121,1,0,0,0,121,128,5,4,0,0,
  	122,128,5,15,0,0,123,124,5,2,0,0,124,125,3,18,9,0,125,126,5,4,0,0,126,
  	128,1,0,0,0,127,108,1,0,0,0,127,109,1,0,0,0,127,122,1,0,0,0,127,123,1,
  	0,0,0,128,23,1,0,0,0,129,130,5,11,0,0,130,131,5,25,0,0,131,132,5,3,0,
  	0,132,133,5,25,0,0,133,134,5,12,0,0,134,25,1,0,0,0,135,144,5,13,0,0,136,
  	141,7,2,0,0,137,138,5,3,0,0,138,140,7,2,0,0,139,137,1,0,0,0,140,143,1,
  	0,0,0,141,139,1,0,0,0,141,142,1,0,0,0,142,145,1,0,0,0,143,141,1,0,0,0,
  	144,136,1,0,0,0,144,145,1,0,0,0,145,146,1,0,0,0,146,147,5,14,0,0,147,
  	27,1,0,0,0,14,31,49,52,59,66,88,92,103,105,116,119,127,141,144
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
    setState(31);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PlutoParser::T__0) {
      setState(28);
      funcdef();
      setState(33);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(34);
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
    setState(36);
    func_dec();
    setState(37);
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

PlutoParser::ParametersContext* PlutoParser::Func_decContext::parameters() {
  return getRuleContext<PlutoParser::ParametersContext>(0);
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
    setState(39);
    match(PlutoParser::T__0);
    setState(40);
    antlrcpp::downCast<Func_decContext *>(_localctx)->func_name = match(PlutoParser::Identifier);
    setState(41);
    parameters();
   
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

std::vector<tree::TerminalNode *> PlutoParser::ParametersContext::Identifier() {
  return getTokens(PlutoParser::Identifier);
}

tree::TerminalNode* PlutoParser::ParametersContext::Identifier(size_t i) {
  return getToken(PlutoParser::Identifier, i);
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
    setState(43);
    match(PlutoParser::T__1);
    setState(52);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PlutoParser::Identifier) {
      setState(44);
      antlrcpp::downCast<ParametersContext *>(_localctx)->identifierToken = match(PlutoParser::Identifier);
      antlrcpp::downCast<ParametersContext *>(_localctx)->argument.push_back(antlrcpp::downCast<ParametersContext *>(_localctx)->identifierToken);
      setState(49);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == PlutoParser::T__2) {
        setState(45);
        match(PlutoParser::T__2);
        setState(46);
        antlrcpp::downCast<ParametersContext *>(_localctx)->identifierToken = match(PlutoParser::Identifier);
        antlrcpp::downCast<ParametersContext *>(_localctx)->argument.push_back(antlrcpp::downCast<ParametersContext *>(_localctx)->identifierToken);
        setState(51);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(54);
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
    setState(56);
    match(PlutoParser::T__4);
    setState(57);
    blockItemList();
    setState(59);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PlutoParser::T__6) {
      setState(58);
      return_stmt();
    }
    setState(61);
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

std::vector<PlutoParser::BlockItemContext *> PlutoParser::BlockItemListContext::blockItem() {
  return getRuleContexts<PlutoParser::BlockItemContext>();
}

PlutoParser::BlockItemContext* PlutoParser::BlockItemListContext::blockItem(size_t i) {
  return getRuleContext<PlutoParser::BlockItemContext>(i);
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
    setState(66);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PlutoParser::T__8) {
      setState(63);
      blockItem();
      setState(68);
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

//----------------- BlockItemContext ------------------------------------------------------------------

PlutoParser::BlockItemContext::BlockItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PlutoParser::ExpressionStatementContext* PlutoParser::BlockItemContext::expressionStatement() {
  return getRuleContext<PlutoParser::ExpressionStatementContext>(0);
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(69);
    expressionStatement();
   
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
    setState(71);
    match(PlutoParser::T__6);
    setState(72);
    expression();
    setState(73);
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


size_t PlutoParser::ExpressionStatementContext::getRuleIndex() const {
  return PlutoParser::RuleExpressionStatement;
}

void PlutoParser::ExpressionStatementContext::copyFrom(ExpressionStatementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Normal_var_declContext ------------------------------------------------------------------

PlutoParser::ExpressionContext* PlutoParser::Normal_var_declContext::expression() {
  return getRuleContext<PlutoParser::ExpressionContext>(0);
}

tree::TerminalNode* PlutoParser::Normal_var_declContext::Identifier() {
  return getToken(PlutoParser::Identifier, 0);
}

PlutoParser::Normal_var_declContext::Normal_var_declContext(ExpressionStatementContext *ctx) { copyFrom(ctx); }


std::any PlutoParser::Normal_var_declContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PlutoVisitor*>(visitor))
    return parserVisitor->visitNormal_var_decl(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Constant_var_declContext ------------------------------------------------------------------

PlutoParser::ExpressionContext* PlutoParser::Constant_var_declContext::expression() {
  return getRuleContext<PlutoParser::ExpressionContext>(0);
}

tree::TerminalNode* PlutoParser::Constant_var_declContext::Identifier() {
  return getToken(PlutoParser::Identifier, 0);
}

PlutoParser::Dim_valueContext* PlutoParser::Constant_var_declContext::dim_value() {
  return getRuleContext<PlutoParser::Dim_valueContext>(0);
}

PlutoParser::Constant_var_declContext::Constant_var_declContext(ExpressionStatementContext *ctx) { copyFrom(ctx); }


std::any PlutoParser::Constant_var_declContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PlutoVisitor*>(visitor))
    return parserVisitor->visitConstant_var_decl(this);
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
    setState(88);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<PlutoParser::Normal_var_declContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(75);
      match(PlutoParser::T__8);
      setState(76);
      antlrcpp::downCast<Normal_var_declContext *>(_localctx)->name = match(PlutoParser::Identifier);
      setState(77);
      match(PlutoParser::T__9);
      setState(78);
      expression();
      setState(79);
      match(PlutoParser::T__7);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<PlutoParser::Constant_var_declContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(81);
      match(PlutoParser::T__8);
      setState(82);
      antlrcpp::downCast<Constant_var_declContext *>(_localctx)->name = match(PlutoParser::Identifier);
      setState(83);
      antlrcpp::downCast<Constant_var_declContext *>(_localctx)->dim = dim_value();
      setState(84);
      match(PlutoParser::T__9);
      setState(85);
      expression();
      setState(86);
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
    setState(92);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(90);
      valueExpression(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(91);
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

    setState(95);
    primaryExpression();
    _ctx->stop = _input->LT(-1);
    setState(105);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(103);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<ArithmeticBinaryContext>(_tracker.createInstance<ValueExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleValueExpression);
          setState(97);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(98);
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
          setState(99);
          antlrcpp::downCast<ArithmeticBinaryContext *>(_localctx)->right = valueExpression(3);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<ArithmeticBinaryContext>(_tracker.createInstance<ValueExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleValueExpression);
          setState(100);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(101);
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
          setState(102);
          antlrcpp::downCast<ArithmeticBinaryContext *>(_localctx)->right = valueExpression(2);
          break;
        }

        default:
          break;
        } 
      }
      setState(107);
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
    setState(127);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<PlutoParser::ConstantDefaultContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(108);
      constant_vector();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<PlutoParser::FunctionCallContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(109);
      antlrcpp::downCast<FunctionCallContext *>(_localctx)->functionName = match(PlutoParser::Identifier);
      setState(110);
      match(PlutoParser::T__1);
      setState(119);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 40964) != 0)) {
        setState(111);
        antlrcpp::downCast<FunctionCallContext *>(_localctx)->expressionContext = expression();
        antlrcpp::downCast<FunctionCallContext *>(_localctx)->argument.push_back(antlrcpp::downCast<FunctionCallContext *>(_localctx)->expressionContext);
        setState(116);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PlutoParser::T__2) {
          setState(112);
          match(PlutoParser::T__2);
          setState(113);
          antlrcpp::downCast<FunctionCallContext *>(_localctx)->expressionContext = expression();
          antlrcpp::downCast<FunctionCallContext *>(_localctx)->argument.push_back(antlrcpp::downCast<FunctionCallContext *>(_localctx)->expressionContext);
          setState(118);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(121);
      match(PlutoParser::T__3);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<PlutoParser::ColumnReferenceContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(122);
      match(PlutoParser::Identifier);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<PlutoParser::ParenthesizedExpressionContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(123);
      match(PlutoParser::T__1);
      setState(124);
      expression();
      setState(125);
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
    setState(129);
    match(PlutoParser::T__10);
    setState(130);
    antlrcpp::downCast<Dim_valueContext *>(_localctx)->dim_x = match(PlutoParser::INTEGER_VALUE);
    setState(131);
    match(PlutoParser::T__2);
    setState(132);
    antlrcpp::downCast<Dim_valueContext *>(_localctx)->dim_y = match(PlutoParser::INTEGER_VALUE);
    setState(133);
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
    setState(135);
    match(PlutoParser::T__12);
    setState(144);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PlutoParser::INTEGER_VALUE

    || _la == PlutoParser::DECIMAL_DIGITS) {
      setState(136);
      antlrcpp::downCast<Constant_vectorContext *>(_localctx)->_tset319 = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == PlutoParser::INTEGER_VALUE

      || _la == PlutoParser::DECIMAL_DIGITS)) {
        antlrcpp::downCast<Constant_vectorContext *>(_localctx)->_tset319 = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      antlrcpp::downCast<Constant_vectorContext *>(_localctx)->vec.push_back(antlrcpp::downCast<Constant_vectorContext *>(_localctx)->_tset319);
      setState(141);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == PlutoParser::T__2) {
        setState(137);
        match(PlutoParser::T__2);
        setState(138);
        antlrcpp::downCast<Constant_vectorContext *>(_localctx)->_tset330 = _input->LT(1);
        _la = _input->LA(1);
        if (!(_la == PlutoParser::INTEGER_VALUE

        || _la == PlutoParser::DECIMAL_DIGITS)) {
          antlrcpp::downCast<Constant_vectorContext *>(_localctx)->_tset330 = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        antlrcpp::downCast<Constant_vectorContext *>(_localctx)->vec.push_back(antlrcpp::downCast<Constant_vectorContext *>(_localctx)->_tset330);
        setState(143);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(146);
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
