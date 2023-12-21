
// Generated from C:/Users/admin/Desktop/USTGZ/LOgic/ass1/src/Verilog.g4 by ANTLR 4.13.1


#include "VerilogLexer.h"


using namespace antlr4;

using namespace verilog;


using namespace antlr4;

namespace {

struct VerilogLexerStaticData final {
  VerilogLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  VerilogLexerStaticData(const VerilogLexerStaticData&) = delete;
  VerilogLexerStaticData(VerilogLexerStaticData&&) = delete;
  VerilogLexerStaticData& operator=(const VerilogLexerStaticData&) = delete;
  VerilogLexerStaticData& operator=(VerilogLexerStaticData&&) = delete;

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

::antlr4::internal::OnceFlag veriloglexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
VerilogLexerStaticData *veriloglexerLexerStaticData = nullptr;

void veriloglexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (veriloglexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(veriloglexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<VerilogLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "T__8", 
      "T__9", "T__10", "T__11", "T__12", "T__13", "T__14", "T__15", "T__16", 
      "T__17", "T__18", "T__19", "T__20", "T__21", "T__22", "ID", "INTEGER", 
      "BINARY", "OCTAL", "DECIMAL", "HEX", "WS"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'('", "')'", "'~'", "'!'", "'*'", "'/'", "'%'", "'+'", "'-'", 
      "'=='", "'!='", "'<'", "'<='", "'>'", "'>='", "'&'", "'|'", "'&&'", 
      "'||'", "'2b'", "'8o'", "'10d'", "'16h'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "ID", "INTEGER", "BINARY", "OCTAL", "DECIMAL", 
      "HEX", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,30,158,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,1,0,1,0,1,1,1,1,1,2,1,2,1,3,1,3,1,4,1,4,1,5,1,5,1,6,1,
  	6,1,7,1,7,1,8,1,8,1,9,1,9,1,9,1,10,1,10,1,10,1,11,1,11,1,12,1,12,1,12,
  	1,13,1,13,1,14,1,14,1,14,1,15,1,15,1,16,1,16,1,17,1,17,1,17,1,18,1,18,
  	1,18,1,19,1,19,1,19,1,20,1,20,1,20,1,21,1,21,1,21,1,21,1,22,1,22,1,22,
  	1,22,1,23,1,23,5,23,122,8,23,10,23,12,23,125,9,23,1,24,4,24,128,8,24,
  	11,24,12,24,129,1,25,4,25,133,8,25,11,25,12,25,134,1,26,4,26,138,8,26,
  	11,26,12,26,139,1,27,4,27,143,8,27,11,27,12,27,144,1,28,4,28,148,8,28,
  	11,28,12,28,149,1,29,4,29,153,8,29,11,29,12,29,154,1,29,1,29,0,0,30,1,
  	1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,25,13,27,14,29,
  	15,31,16,33,17,35,18,37,19,39,20,41,21,43,22,45,23,47,24,49,25,51,26,
  	53,27,55,28,57,29,59,30,1,0,6,3,0,65,90,95,95,97,122,5,0,36,36,48,57,
  	65,90,95,95,97,122,1,0,48,57,1,0,48,55,3,0,48,57,65,70,97,102,3,0,9,10,
  	13,13,32,32,164,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,
  	0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,
  	0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,
  	31,1,0,0,0,0,33,1,0,0,0,0,35,1,0,0,0,0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,
  	0,0,0,0,43,1,0,0,0,0,45,1,0,0,0,0,47,1,0,0,0,0,49,1,0,0,0,0,51,1,0,0,
  	0,0,53,1,0,0,0,0,55,1,0,0,0,0,57,1,0,0,0,0,59,1,0,0,0,1,61,1,0,0,0,3,
  	63,1,0,0,0,5,65,1,0,0,0,7,67,1,0,0,0,9,69,1,0,0,0,11,71,1,0,0,0,13,73,
  	1,0,0,0,15,75,1,0,0,0,17,77,1,0,0,0,19,79,1,0,0,0,21,82,1,0,0,0,23,85,
  	1,0,0,0,25,87,1,0,0,0,27,90,1,0,0,0,29,92,1,0,0,0,31,95,1,0,0,0,33,97,
  	1,0,0,0,35,99,1,0,0,0,37,102,1,0,0,0,39,105,1,0,0,0,41,108,1,0,0,0,43,
  	111,1,0,0,0,45,115,1,0,0,0,47,119,1,0,0,0,49,127,1,0,0,0,51,132,1,0,0,
  	0,53,137,1,0,0,0,55,142,1,0,0,0,57,147,1,0,0,0,59,152,1,0,0,0,61,62,5,
  	40,0,0,62,2,1,0,0,0,63,64,5,41,0,0,64,4,1,0,0,0,65,66,5,126,0,0,66,6,
  	1,0,0,0,67,68,5,33,0,0,68,8,1,0,0,0,69,70,5,42,0,0,70,10,1,0,0,0,71,72,
  	5,47,0,0,72,12,1,0,0,0,73,74,5,37,0,0,74,14,1,0,0,0,75,76,5,43,0,0,76,
  	16,1,0,0,0,77,78,5,45,0,0,78,18,1,0,0,0,79,80,5,61,0,0,80,81,5,61,0,0,
  	81,20,1,0,0,0,82,83,5,33,0,0,83,84,5,61,0,0,84,22,1,0,0,0,85,86,5,60,
  	0,0,86,24,1,0,0,0,87,88,5,60,0,0,88,89,5,61,0,0,89,26,1,0,0,0,90,91,5,
  	62,0,0,91,28,1,0,0,0,92,93,5,62,0,0,93,94,5,61,0,0,94,30,1,0,0,0,95,96,
  	5,38,0,0,96,32,1,0,0,0,97,98,5,124,0,0,98,34,1,0,0,0,99,100,5,38,0,0,
  	100,101,5,38,0,0,101,36,1,0,0,0,102,103,5,124,0,0,103,104,5,124,0,0,104,
  	38,1,0,0,0,105,106,5,50,0,0,106,107,5,98,0,0,107,40,1,0,0,0,108,109,5,
  	56,0,0,109,110,5,111,0,0,110,42,1,0,0,0,111,112,5,49,0,0,112,113,5,48,
  	0,0,113,114,5,100,0,0,114,44,1,0,0,0,115,116,5,49,0,0,116,117,5,54,0,
  	0,117,118,5,104,0,0,118,46,1,0,0,0,119,123,7,0,0,0,120,122,7,1,0,0,121,
  	120,1,0,0,0,122,125,1,0,0,0,123,121,1,0,0,0,123,124,1,0,0,0,124,48,1,
  	0,0,0,125,123,1,0,0,0,126,128,7,2,0,0,127,126,1,0,0,0,128,129,1,0,0,0,
  	129,127,1,0,0,0,129,130,1,0,0,0,130,50,1,0,0,0,131,133,2,48,49,0,132,
  	131,1,0,0,0,133,134,1,0,0,0,134,132,1,0,0,0,134,135,1,0,0,0,135,52,1,
  	0,0,0,136,138,7,3,0,0,137,136,1,0,0,0,138,139,1,0,0,0,139,137,1,0,0,0,
  	139,140,1,0,0,0,140,54,1,0,0,0,141,143,7,2,0,0,142,141,1,0,0,0,143,144,
  	1,0,0,0,144,142,1,0,0,0,144,145,1,0,0,0,145,56,1,0,0,0,146,148,7,4,0,
  	0,147,146,1,0,0,0,148,149,1,0,0,0,149,147,1,0,0,0,149,150,1,0,0,0,150,
  	58,1,0,0,0,151,153,7,5,0,0,152,151,1,0,0,0,153,154,1,0,0,0,154,152,1,
  	0,0,0,154,155,1,0,0,0,155,156,1,0,0,0,156,157,6,29,0,0,157,60,1,0,0,0,
  	8,0,123,129,134,139,144,149,154,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  veriloglexerLexerStaticData = staticData.release();
}

}

VerilogLexer::VerilogLexer(CharStream *input) : Lexer(input) {
  VerilogLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *veriloglexerLexerStaticData->atn, veriloglexerLexerStaticData->decisionToDFA, veriloglexerLexerStaticData->sharedContextCache);
}

VerilogLexer::~VerilogLexer() {
  delete _interpreter;
}

std::string VerilogLexer::getGrammarFileName() const {
  return "Verilog.g4";
}

const std::vector<std::string>& VerilogLexer::getRuleNames() const {
  return veriloglexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& VerilogLexer::getChannelNames() const {
  return veriloglexerLexerStaticData->channelNames;
}

const std::vector<std::string>& VerilogLexer::getModeNames() const {
  return veriloglexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& VerilogLexer::getVocabulary() const {
  return veriloglexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView VerilogLexer::getSerializedATN() const {
  return veriloglexerLexerStaticData->serializedATN;
}

const atn::ATN& VerilogLexer::getATN() const {
  return *veriloglexerLexerStaticData->atn;
}




void VerilogLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  veriloglexerLexerInitialize();
#else
  ::antlr4::internal::call_once(veriloglexerLexerOnceFlag, veriloglexerLexerInitialize);
#endif
}
