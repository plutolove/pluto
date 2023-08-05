
// Generated from ./src/parser/Pluto.g4 by ANTLR 4.12.0


#include "PlutoLexer.h"


using namespace antlr4;

using namespace pluto;


using namespace antlr4;

namespace {

struct PlutoLexerStaticData final {
  PlutoLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  PlutoLexerStaticData(const PlutoLexerStaticData&) = delete;
  PlutoLexerStaticData(PlutoLexerStaticData&&) = delete;
  PlutoLexerStaticData& operator=(const PlutoLexerStaticData&) = delete;
  PlutoLexerStaticData& operator=(PlutoLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag plutolexerLexerOnceFlag;
PlutoLexerStaticData *plutolexerLexerStaticData = nullptr;

void plutolexerLexerInitialize() {
  assert(plutolexerLexerStaticData == nullptr);
  auto staticData = std::make_unique<PlutoLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "T__8", 
      "T__9", "T__10", "T__11", "Identifier", "VAR", "RETURN", "PLUS", "MINUS", 
      "ASTERISK", "SLASH", "PERCENT", "TILDE", "AMPERSAND", "PIPE", "HAT", 
      "INTEGER_VALUE", "DECIMAL_DIGITS", "DIGIT", "IdentifierNondigit", 
      "Nondigit", "SIMPLE_COMMENT", "BRACKETED_EMPTY_COMMENT", "BRACKETED_COMMENT", 
      "WS", "UNRECOGNIZED"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'def'", "'('", "','", "')'", "'{'", "'}'", "';'", "'='", "'<'", 
      "'>'", "'['", "']'", "", "'var'", "'return'", "'+'", "'-'", "'*'", 
      "'/'", "'%'", "'~'", "'&'", "'|'", "'^'", "", "", "", "'/**/'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "Identifier", 
      "VAR", "RETURN", "PLUS", "MINUS", "ASTERISK", "SLASH", "PERCENT", 
      "TILDE", "AMPERSAND", "PIPE", "HAT", "INTEGER_VALUE", "DECIMAL_DIGITS", 
      "SIMPLE_COMMENT", "BRACKETED_EMPTY_COMMENT", "BRACKETED_COMMENT", 
      "WS", "UNRECOGNIZED"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,31,213,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,1,0,1,0,1,0,1,
  	0,1,1,1,1,1,2,1,2,1,3,1,3,1,4,1,4,1,5,1,5,1,6,1,6,1,7,1,7,1,8,1,8,1,9,
  	1,9,1,10,1,10,1,11,1,11,1,12,1,12,1,12,5,12,99,8,12,10,12,12,12,102,9,
  	12,1,13,1,13,1,13,1,13,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,15,1,15,1,
  	16,1,16,1,17,1,17,1,18,1,18,1,19,1,19,1,20,1,20,1,21,1,21,1,22,1,22,1,
  	23,1,23,1,24,4,24,134,8,24,11,24,12,24,135,1,25,4,25,139,8,25,11,25,12,
  	25,140,1,25,1,25,5,25,145,8,25,10,25,12,25,148,9,25,1,25,1,25,4,25,152,
  	8,25,11,25,12,25,153,3,25,156,8,25,1,26,1,26,1,27,1,27,1,28,1,28,1,29,
  	1,29,1,29,1,29,1,29,1,29,5,29,170,8,29,10,29,12,29,173,9,29,1,29,3,29,
  	176,8,29,1,29,3,29,179,8,29,1,29,1,29,1,30,1,30,1,30,1,30,1,30,1,30,1,
  	30,1,31,1,31,1,31,1,31,1,31,5,31,195,8,31,10,31,12,31,198,9,31,1,31,1,
  	31,1,31,1,31,1,31,1,32,4,32,206,8,32,11,32,12,32,207,1,32,1,32,1,33,1,
  	33,1,196,0,34,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,
  	12,25,13,27,14,29,15,31,16,33,17,35,18,37,19,39,20,41,21,43,22,45,23,
  	47,24,49,25,51,26,53,0,55,0,57,0,59,27,61,28,63,29,65,30,67,31,1,0,5,
  	1,0,48,57,3,0,65,90,95,95,97,122,2,0,10,10,13,13,1,0,43,43,3,0,9,10,13,
  	13,32,32,222,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,
  	0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,
  	0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,
  	1,0,0,0,0,33,1,0,0,0,0,35,1,0,0,0,0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,
  	0,0,0,43,1,0,0,0,0,45,1,0,0,0,0,47,1,0,0,0,0,49,1,0,0,0,0,51,1,0,0,0,
  	0,59,1,0,0,0,0,61,1,0,0,0,0,63,1,0,0,0,0,65,1,0,0,0,0,67,1,0,0,0,1,69,
  	1,0,0,0,3,73,1,0,0,0,5,75,1,0,0,0,7,77,1,0,0,0,9,79,1,0,0,0,11,81,1,0,
  	0,0,13,83,1,0,0,0,15,85,1,0,0,0,17,87,1,0,0,0,19,89,1,0,0,0,21,91,1,0,
  	0,0,23,93,1,0,0,0,25,95,1,0,0,0,27,103,1,0,0,0,29,107,1,0,0,0,31,114,
  	1,0,0,0,33,116,1,0,0,0,35,118,1,0,0,0,37,120,1,0,0,0,39,122,1,0,0,0,41,
  	124,1,0,0,0,43,126,1,0,0,0,45,128,1,0,0,0,47,130,1,0,0,0,49,133,1,0,0,
  	0,51,155,1,0,0,0,53,157,1,0,0,0,55,159,1,0,0,0,57,161,1,0,0,0,59,163,
  	1,0,0,0,61,182,1,0,0,0,63,189,1,0,0,0,65,205,1,0,0,0,67,211,1,0,0,0,69,
  	70,5,100,0,0,70,71,5,101,0,0,71,72,5,102,0,0,72,2,1,0,0,0,73,74,5,40,
  	0,0,74,4,1,0,0,0,75,76,5,44,0,0,76,6,1,0,0,0,77,78,5,41,0,0,78,8,1,0,
  	0,0,79,80,5,123,0,0,80,10,1,0,0,0,81,82,5,125,0,0,82,12,1,0,0,0,83,84,
  	5,59,0,0,84,14,1,0,0,0,85,86,5,61,0,0,86,16,1,0,0,0,87,88,5,60,0,0,88,
  	18,1,0,0,0,89,90,5,62,0,0,90,20,1,0,0,0,91,92,5,91,0,0,92,22,1,0,0,0,
  	93,94,5,93,0,0,94,24,1,0,0,0,95,100,3,55,27,0,96,99,3,55,27,0,97,99,3,
  	53,26,0,98,96,1,0,0,0,98,97,1,0,0,0,99,102,1,0,0,0,100,98,1,0,0,0,100,
  	101,1,0,0,0,101,26,1,0,0,0,102,100,1,0,0,0,103,104,5,118,0,0,104,105,
  	5,97,0,0,105,106,5,114,0,0,106,28,1,0,0,0,107,108,5,114,0,0,108,109,5,
  	101,0,0,109,110,5,116,0,0,110,111,5,117,0,0,111,112,5,114,0,0,112,113,
  	5,110,0,0,113,30,1,0,0,0,114,115,5,43,0,0,115,32,1,0,0,0,116,117,5,45,
  	0,0,117,34,1,0,0,0,118,119,5,42,0,0,119,36,1,0,0,0,120,121,5,47,0,0,121,
  	38,1,0,0,0,122,123,5,37,0,0,123,40,1,0,0,0,124,125,5,126,0,0,125,42,1,
  	0,0,0,126,127,5,38,0,0,127,44,1,0,0,0,128,129,5,124,0,0,129,46,1,0,0,
  	0,130,131,5,94,0,0,131,48,1,0,0,0,132,134,3,53,26,0,133,132,1,0,0,0,134,
  	135,1,0,0,0,135,133,1,0,0,0,135,136,1,0,0,0,136,50,1,0,0,0,137,139,3,
  	53,26,0,138,137,1,0,0,0,139,140,1,0,0,0,140,138,1,0,0,0,140,141,1,0,0,
  	0,141,142,1,0,0,0,142,146,5,46,0,0,143,145,3,53,26,0,144,143,1,0,0,0,
  	145,148,1,0,0,0,146,144,1,0,0,0,146,147,1,0,0,0,147,156,1,0,0,0,148,146,
  	1,0,0,0,149,151,5,46,0,0,150,152,3,53,26,0,151,150,1,0,0,0,152,153,1,
  	0,0,0,153,151,1,0,0,0,153,154,1,0,0,0,154,156,1,0,0,0,155,138,1,0,0,0,
  	155,149,1,0,0,0,156,52,1,0,0,0,157,158,7,0,0,0,158,54,1,0,0,0,159,160,
  	3,57,28,0,160,56,1,0,0,0,161,162,7,1,0,0,162,58,1,0,0,0,163,164,5,45,
  	0,0,164,165,5,45,0,0,165,171,1,0,0,0,166,167,5,92,0,0,167,170,5,10,0,
  	0,168,170,8,2,0,0,169,166,1,0,0,0,169,168,1,0,0,0,170,173,1,0,0,0,171,
  	169,1,0,0,0,171,172,1,0,0,0,172,175,1,0,0,0,173,171,1,0,0,0,174,176,5,
  	13,0,0,175,174,1,0,0,0,175,176,1,0,0,0,176,178,1,0,0,0,177,179,5,10,0,
  	0,178,177,1,0,0,0,178,179,1,0,0,0,179,180,1,0,0,0,180,181,6,29,0,0,181,
  	60,1,0,0,0,182,183,5,47,0,0,183,184,5,42,0,0,184,185,5,42,0,0,185,186,
  	5,47,0,0,186,187,1,0,0,0,187,188,6,30,0,0,188,62,1,0,0,0,189,190,5,47,
  	0,0,190,191,5,42,0,0,191,192,1,0,0,0,192,196,8,3,0,0,193,195,9,0,0,0,
  	194,193,1,0,0,0,195,198,1,0,0,0,196,197,1,0,0,0,196,194,1,0,0,0,197,199,
  	1,0,0,0,198,196,1,0,0,0,199,200,5,42,0,0,200,201,5,47,0,0,201,202,1,0,
  	0,0,202,203,6,31,0,0,203,64,1,0,0,0,204,206,7,4,0,0,205,204,1,0,0,0,206,
  	207,1,0,0,0,207,205,1,0,0,0,207,208,1,0,0,0,208,209,1,0,0,0,209,210,6,
  	32,0,0,210,66,1,0,0,0,211,212,9,0,0,0,212,68,1,0,0,0,14,0,98,100,135,
  	140,146,153,155,169,171,175,178,196,207,1,0,1,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  plutolexerLexerStaticData = staticData.release();
}

}

PlutoLexer::PlutoLexer(CharStream *input) : Lexer(input) {
  PlutoLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *plutolexerLexerStaticData->atn, plutolexerLexerStaticData->decisionToDFA, plutolexerLexerStaticData->sharedContextCache);
}

PlutoLexer::~PlutoLexer() {
  delete _interpreter;
}

std::string PlutoLexer::getGrammarFileName() const {
  return "Pluto.g4";
}

const std::vector<std::string>& PlutoLexer::getRuleNames() const {
  return plutolexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& PlutoLexer::getChannelNames() const {
  return plutolexerLexerStaticData->channelNames;
}

const std::vector<std::string>& PlutoLexer::getModeNames() const {
  return plutolexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& PlutoLexer::getVocabulary() const {
  return plutolexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView PlutoLexer::getSerializedATN() const {
  return plutolexerLexerStaticData->serializedATN;
}

const atn::ATN& PlutoLexer::getATN() const {
  return *plutolexerLexerStaticData->atn;
}




void PlutoLexer::initialize() {
  ::antlr4::internal::call_once(plutolexerLexerOnceFlag, plutolexerLexerInitialize);
}
