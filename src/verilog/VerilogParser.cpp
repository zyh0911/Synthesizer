
// Generated from C:/Users/admin/Desktop/USTGZ/LOgic/ass1/src/Verilog.g4 by ANTLR 4.13.1


#include "VerilogListener.h"
#include "VerilogVisitor.h"

#include "VerilogParser.h"


using namespace antlrcpp;
using namespace verilog;

using namespace antlr4;

namespace {

struct VerilogParserStaticData final {
  VerilogParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  VerilogParserStaticData(const VerilogParserStaticData&) = delete;
  VerilogParserStaticData(VerilogParserStaticData&&) = delete;
  VerilogParserStaticData& operator=(const VerilogParserStaticData&) = delete;
  VerilogParserStaticData& operator=(VerilogParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag verilogParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
VerilogParserStaticData *verilogParserStaticData = nullptr;

void verilogParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (verilogParserStaticData != nullptr) {
    return;
  }
#else
  assert(verilogParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<VerilogParserStaticData>(
    std::vector<std::string>{
      "startRule", "expression", "constant"
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
  	4,1,30,58,2,0,7,0,2,1,7,1,2,2,7,2,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,3,1,19,8,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,1,42,8,1,10,1,12,1,45,9,1,1,2,
  	1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,3,2,56,8,2,1,2,0,1,2,3,0,2,4,0,4,1,0,
  	3,4,1,0,5,7,1,0,8,9,1,0,10,15,68,0,6,1,0,0,0,2,18,1,0,0,0,4,55,1,0,0,
  	0,6,7,3,2,1,0,7,8,5,0,0,1,8,1,1,0,0,0,9,10,6,1,-1,0,10,11,5,1,0,0,11,
  	12,3,2,1,0,12,13,5,2,0,0,13,19,1,0,0,0,14,15,7,0,0,0,15,19,3,2,1,10,16,
  	19,3,4,2,0,17,19,5,24,0,0,18,9,1,0,0,0,18,14,1,0,0,0,18,16,1,0,0,0,18,
  	17,1,0,0,0,19,43,1,0,0,0,20,21,10,9,0,0,21,22,7,1,0,0,22,42,3,2,1,10,
  	23,24,10,8,0,0,24,25,7,2,0,0,25,42,3,2,1,9,26,27,10,7,0,0,27,28,7,3,0,
  	0,28,42,3,2,1,8,29,30,10,6,0,0,30,31,5,16,0,0,31,42,3,2,1,7,32,33,10,
  	5,0,0,33,34,5,17,0,0,34,42,3,2,1,6,35,36,10,4,0,0,36,37,5,18,0,0,37,42,
  	3,2,1,5,38,39,10,3,0,0,39,40,5,19,0,0,40,42,3,2,1,4,41,20,1,0,0,0,41,
  	23,1,0,0,0,41,26,1,0,0,0,41,29,1,0,0,0,41,32,1,0,0,0,41,35,1,0,0,0,41,
  	38,1,0,0,0,42,45,1,0,0,0,43,41,1,0,0,0,43,44,1,0,0,0,44,3,1,0,0,0,45,
  	43,1,0,0,0,46,56,5,25,0,0,47,48,5,20,0,0,48,56,5,26,0,0,49,50,5,21,0,
  	0,50,56,5,27,0,0,51,52,5,22,0,0,52,56,5,28,0,0,53,54,5,23,0,0,54,56,5,
  	29,0,0,55,46,1,0,0,0,55,47,1,0,0,0,55,49,1,0,0,0,55,51,1,0,0,0,55,53,
  	1,0,0,0,56,5,1,0,0,0,4,18,41,43,55
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  verilogParserStaticData = staticData.release();
}

}

VerilogParser::VerilogParser(TokenStream *input) : VerilogParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

VerilogParser::VerilogParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  VerilogParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *verilogParserStaticData->atn, verilogParserStaticData->decisionToDFA, verilogParserStaticData->sharedContextCache, options);
}

VerilogParser::~VerilogParser() {
  delete _interpreter;
}

const atn::ATN& VerilogParser::getATN() const {
  return *verilogParserStaticData->atn;
}

std::string VerilogParser::getGrammarFileName() const {
  return "Verilog.g4";
}

const std::vector<std::string>& VerilogParser::getRuleNames() const {
  return verilogParserStaticData->ruleNames;
}

const dfa::Vocabulary& VerilogParser::getVocabulary() const {
  return verilogParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView VerilogParser::getSerializedATN() const {
  return verilogParserStaticData->serializedATN;
}


//----------------- StartRuleContext ------------------------------------------------------------------

VerilogParser::StartRuleContext::StartRuleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

VerilogParser::ExpressionContext* VerilogParser::StartRuleContext::expression() {
  return getRuleContext<VerilogParser::ExpressionContext>(0);
}

tree::TerminalNode* VerilogParser::StartRuleContext::EOF() {
  return getToken(VerilogParser::EOF, 0);
}


size_t VerilogParser::StartRuleContext::getRuleIndex() const {
  return VerilogParser::RuleStartRule;
}

void VerilogParser::StartRuleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VerilogListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStartRule(this);
}

void VerilogParser::StartRuleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VerilogListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStartRule(this);
}


std::any VerilogParser::StartRuleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VerilogVisitor*>(visitor))
    return parserVisitor->visitStartRule(this);
  else
    return visitor->visitChildren(this);
}

VerilogParser::StartRuleContext* VerilogParser::startRule() {
  StartRuleContext *_localctx = _tracker.createInstance<StartRuleContext>(_ctx, getState());
  enterRule(_localctx, 0, VerilogParser::RuleStartRule);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(6);
    expression(0);
    setState(7);
    match(VerilogParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

VerilogParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t VerilogParser::ExpressionContext::getRuleIndex() const {
  return VerilogParser::RuleExpression;
}

void VerilogParser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- AndExprContext ------------------------------------------------------------------

std::vector<VerilogParser::ExpressionContext *> VerilogParser::AndExprContext::expression() {
  return getRuleContexts<VerilogParser::ExpressionContext>();
}

VerilogParser::ExpressionContext* VerilogParser::AndExprContext::expression(size_t i) {
  return getRuleContext<VerilogParser::ExpressionContext>(i);
}

VerilogParser::AndExprContext::AndExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void VerilogParser::AndExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VerilogListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAndExpr(this);
}
void VerilogParser::AndExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VerilogListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAndExpr(this);
}

std::any VerilogParser::AndExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VerilogVisitor*>(visitor))
    return parserVisitor->visitAndExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IdExprContext ------------------------------------------------------------------

tree::TerminalNode* VerilogParser::IdExprContext::ID() {
  return getToken(VerilogParser::ID, 0);
}

VerilogParser::IdExprContext::IdExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void VerilogParser::IdExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VerilogListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdExpr(this);
}
void VerilogParser::IdExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VerilogListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdExpr(this);
}

std::any VerilogParser::IdExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VerilogVisitor*>(visitor))
    return parserVisitor->visitIdExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MulDivModExprContext ------------------------------------------------------------------

std::vector<VerilogParser::ExpressionContext *> VerilogParser::MulDivModExprContext::expression() {
  return getRuleContexts<VerilogParser::ExpressionContext>();
}

VerilogParser::ExpressionContext* VerilogParser::MulDivModExprContext::expression(size_t i) {
  return getRuleContext<VerilogParser::ExpressionContext>(i);
}

VerilogParser::MulDivModExprContext::MulDivModExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void VerilogParser::MulDivModExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VerilogListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMulDivModExpr(this);
}
void VerilogParser::MulDivModExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VerilogListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMulDivModExpr(this);
}

std::any VerilogParser::MulDivModExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VerilogVisitor*>(visitor))
    return parserVisitor->visitMulDivModExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ConstantExprContext ------------------------------------------------------------------

VerilogParser::ConstantContext* VerilogParser::ConstantExprContext::constant() {
  return getRuleContext<VerilogParser::ConstantContext>(0);
}

VerilogParser::ConstantExprContext::ConstantExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void VerilogParser::ConstantExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VerilogListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstantExpr(this);
}
void VerilogParser::ConstantExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VerilogListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstantExpr(this);
}

std::any VerilogParser::ConstantExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VerilogVisitor*>(visitor))
    return parserVisitor->visitConstantExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NotExprContext ------------------------------------------------------------------

VerilogParser::ExpressionContext* VerilogParser::NotExprContext::expression() {
  return getRuleContext<VerilogParser::ExpressionContext>(0);
}

VerilogParser::NotExprContext::NotExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void VerilogParser::NotExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VerilogListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNotExpr(this);
}
void VerilogParser::NotExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VerilogListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNotExpr(this);
}

std::any VerilogParser::NotExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VerilogVisitor*>(visitor))
    return parserVisitor->visitNotExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RelationalExprContext ------------------------------------------------------------------

std::vector<VerilogParser::ExpressionContext *> VerilogParser::RelationalExprContext::expression() {
  return getRuleContexts<VerilogParser::ExpressionContext>();
}

VerilogParser::ExpressionContext* VerilogParser::RelationalExprContext::expression(size_t i) {
  return getRuleContext<VerilogParser::ExpressionContext>(i);
}

VerilogParser::RelationalExprContext::RelationalExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void VerilogParser::RelationalExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VerilogListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelationalExpr(this);
}
void VerilogParser::RelationalExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VerilogListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelationalExpr(this);
}

std::any VerilogParser::RelationalExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VerilogVisitor*>(visitor))
    return parserVisitor->visitRelationalExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParenExprContext ------------------------------------------------------------------

VerilogParser::ExpressionContext* VerilogParser::ParenExprContext::expression() {
  return getRuleContext<VerilogParser::ExpressionContext>(0);
}

VerilogParser::ParenExprContext::ParenExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void VerilogParser::ParenExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VerilogListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParenExpr(this);
}
void VerilogParser::ParenExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VerilogListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParenExpr(this);
}

std::any VerilogParser::ParenExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VerilogVisitor*>(visitor))
    return parserVisitor->visitParenExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AddSubExprContext ------------------------------------------------------------------

std::vector<VerilogParser::ExpressionContext *> VerilogParser::AddSubExprContext::expression() {
  return getRuleContexts<VerilogParser::ExpressionContext>();
}

VerilogParser::ExpressionContext* VerilogParser::AddSubExprContext::expression(size_t i) {
  return getRuleContext<VerilogParser::ExpressionContext>(i);
}

VerilogParser::AddSubExprContext::AddSubExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void VerilogParser::AddSubExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VerilogListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAddSubExpr(this);
}
void VerilogParser::AddSubExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VerilogListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAddSubExpr(this);
}

std::any VerilogParser::AddSubExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VerilogVisitor*>(visitor))
    return parserVisitor->visitAddSubExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- OrExprContext ------------------------------------------------------------------

std::vector<VerilogParser::ExpressionContext *> VerilogParser::OrExprContext::expression() {
  return getRuleContexts<VerilogParser::ExpressionContext>();
}

VerilogParser::ExpressionContext* VerilogParser::OrExprContext::expression(size_t i) {
  return getRuleContext<VerilogParser::ExpressionContext>(i);
}

VerilogParser::OrExprContext::OrExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void VerilogParser::OrExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VerilogListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOrExpr(this);
}
void VerilogParser::OrExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VerilogListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOrExpr(this);
}

std::any VerilogParser::OrExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VerilogVisitor*>(visitor))
    return parserVisitor->visitOrExpr(this);
  else
    return visitor->visitChildren(this);
}

VerilogParser::ExpressionContext* VerilogParser::expression() {
   return expression(0);
}

VerilogParser::ExpressionContext* VerilogParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  VerilogParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  VerilogParser::ExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, VerilogParser::RuleExpression, precedence);

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
    setState(18);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case VerilogParser::T__0: {
        _localctx = _tracker.createInstance<ParenExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(10);
        match(VerilogParser::T__0);
        setState(11);
        expression(0);
        setState(12);
        match(VerilogParser::T__1);
        break;
      }

      case VerilogParser::T__2:
      case VerilogParser::T__3: {
        _localctx = _tracker.createInstance<NotExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(14);
        _la = _input->LA(1);
        if (!(_la == VerilogParser::T__2

        || _la == VerilogParser::T__3)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(15);
        expression(10);
        break;
      }

      case VerilogParser::T__19:
      case VerilogParser::T__20:
      case VerilogParser::T__21:
      case VerilogParser::T__22:
      case VerilogParser::INTEGER: {
        _localctx = _tracker.createInstance<ConstantExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(16);
        constant();
        break;
      }

      case VerilogParser::ID: {
        _localctx = _tracker.createInstance<IdExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(17);
        match(VerilogParser::ID);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(43);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(41);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MulDivModExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(20);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(21);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 224) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(22);
          expression(10);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<AddSubExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(23);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(24);
          _la = _input->LA(1);
          if (!(_la == VerilogParser::T__7

          || _la == VerilogParser::T__8)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(25);
          expression(9);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<RelationalExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(26);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(27);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 64512) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(28);
          expression(8);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<AndExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(29);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(30);
          match(VerilogParser::T__15);
          setState(31);
          expression(7);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<OrExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(32);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(33);
          match(VerilogParser::T__16);
          setState(34);
          expression(6);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<AndExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(35);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(36);
          match(VerilogParser::T__17);
          setState(37);
          expression(5);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<OrExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(38);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(39);
          match(VerilogParser::T__18);
          setState(40);
          expression(4);
          break;
        }

        default:
          break;
        } 
      }
      setState(45);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
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

VerilogParser::ConstantContext::ConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* VerilogParser::ConstantContext::INTEGER() {
  return getToken(VerilogParser::INTEGER, 0);
}

tree::TerminalNode* VerilogParser::ConstantContext::BINARY() {
  return getToken(VerilogParser::BINARY, 0);
}

tree::TerminalNode* VerilogParser::ConstantContext::OCTAL() {
  return getToken(VerilogParser::OCTAL, 0);
}

tree::TerminalNode* VerilogParser::ConstantContext::DECIMAL() {
  return getToken(VerilogParser::DECIMAL, 0);
}

tree::TerminalNode* VerilogParser::ConstantContext::HEX() {
  return getToken(VerilogParser::HEX, 0);
}


size_t VerilogParser::ConstantContext::getRuleIndex() const {
  return VerilogParser::RuleConstant;
}

void VerilogParser::ConstantContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VerilogListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstant(this);
}

void VerilogParser::ConstantContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VerilogListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstant(this);
}


std::any VerilogParser::ConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VerilogVisitor*>(visitor))
    return parserVisitor->visitConstant(this);
  else
    return visitor->visitChildren(this);
}

VerilogParser::ConstantContext* VerilogParser::constant() {
  ConstantContext *_localctx = _tracker.createInstance<ConstantContext>(_ctx, getState());
  enterRule(_localctx, 4, VerilogParser::RuleConstant);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(55);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case VerilogParser::INTEGER: {
        enterOuterAlt(_localctx, 1);
        setState(46);
        match(VerilogParser::INTEGER);
        break;
      }

      case VerilogParser::T__19: {
        enterOuterAlt(_localctx, 2);
        setState(47);
        match(VerilogParser::T__19);
        setState(48);
        match(VerilogParser::BINARY);
        break;
      }

      case VerilogParser::T__20: {
        enterOuterAlt(_localctx, 3);
        setState(49);
        match(VerilogParser::T__20);
        setState(50);
        match(VerilogParser::OCTAL);
        break;
      }

      case VerilogParser::T__21: {
        enterOuterAlt(_localctx, 4);
        setState(51);
        match(VerilogParser::T__21);
        setState(52);
        match(VerilogParser::DECIMAL);
        break;
      }

      case VerilogParser::T__22: {
        enterOuterAlt(_localctx, 5);
        setState(53);
        match(VerilogParser::T__22);
        setState(54);
        match(VerilogParser::HEX);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool VerilogParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return expressionSempred(antlrcpp::downCast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool VerilogParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 9);
    case 1: return precpred(_ctx, 8);
    case 2: return precpred(_ctx, 7);
    case 3: return precpred(_ctx, 6);
    case 4: return precpred(_ctx, 5);
    case 5: return precpred(_ctx, 4);
    case 6: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

void VerilogParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  verilogParserInitialize();
#else
  ::antlr4::internal::call_once(verilogParserOnceFlag, verilogParserInitialize);
#endif
}
