
// Generated from /home/fatemeh/Documents/antlr4-delta/runtime/Cpp/demo/TParser.g4 by ANTLR 4.7.2

#include "TParserListener.h"
#include "TParserVisitor.h"
#include "TParser.h"

using namespace antlrcpp;
using namespace antlrcpptest;
using namespace antlr4;

TParser::TParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

TParser::~TParser() {
  delete _interpreter;
}

std::string TParser::getGrammarFileName() const {
  return "TParser.g4";
}

const std::vector<std::string>& TParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& TParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ModuleContext ------------------------------------------------------------------

TParser::ModuleContext::ModuleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TParser::ModuleContext::EOF() {
  return getToken(TParser::EOF, 0);
}

TParser::ModuleDataContext* TParser::ModuleContext::moduleData() {
  return getRuleContext<TParser::ModuleDataContext>(0);
}

TParser::ModuleRoutinesContext* TParser::ModuleContext::moduleRoutines() {
  return getRuleContext<TParser::ModuleRoutinesContext>(0);
}


size_t TParser::ModuleContext::getRuleIndex() const {
  return TParser::RuleModule;
}

void TParser::ModuleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterModule(this);
}

void TParser::ModuleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitModule(this);
}


antlrcpp::Any TParser::ModuleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitModule(this);
  else
    return visitor->visitChildren(this);
}

TParser::ModuleContext* TParser::module() {
  ModuleContext *_localctx = _tracker.createInstance<ModuleContext>(_ctx, getState());
  enterRule(_localctx, 0, TParser::RuleModule);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(128);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TParser::DEFDAT: {
        setState(126);
        moduleData();
        break;
      }

      case TParser::DEF:
      case TParser::DEFFCT:
      case TParser::GLOBAL: {
        setState(127);
        moduleRoutines();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(130);
    match(TParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ModuleRoutinesContext ------------------------------------------------------------------

TParser::ModuleRoutinesContext::ModuleRoutinesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TParser::MainRoutineContext* TParser::ModuleRoutinesContext::mainRoutine() {
  return getRuleContext<TParser::MainRoutineContext>(0);
}

std::vector<TParser::SubRoutineContext *> TParser::ModuleRoutinesContext::subRoutine() {
  return getRuleContexts<TParser::SubRoutineContext>();
}

TParser::SubRoutineContext* TParser::ModuleRoutinesContext::subRoutine(size_t i) {
  return getRuleContext<TParser::SubRoutineContext>(i);
}

std::vector<tree::TerminalNode *> TParser::ModuleRoutinesContext::NEWLINE() {
  return getTokens(TParser::NEWLINE);
}

tree::TerminalNode* TParser::ModuleRoutinesContext::NEWLINE(size_t i) {
  return getToken(TParser::NEWLINE, i);
}


size_t TParser::ModuleRoutinesContext::getRuleIndex() const {
  return TParser::RuleModuleRoutines;
}

void TParser::ModuleRoutinesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterModuleRoutines(this);
}

void TParser::ModuleRoutinesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitModuleRoutines(this);
}


antlrcpp::Any TParser::ModuleRoutinesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitModuleRoutines(this);
  else
    return visitor->visitChildren(this);
}

TParser::ModuleRoutinesContext* TParser::moduleRoutines() {
  ModuleRoutinesContext *_localctx = _tracker.createInstance<ModuleRoutinesContext>(_ctx, getState());
  enterRule(_localctx, 2, TParser::RuleModuleRoutines);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(132);
    mainRoutine();
    setState(137);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 49) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 49)) & ((1ULL << (TParser::DEF - 49))
      | (1ULL << (TParser::DEFFCT - 49))
      | (1ULL << (TParser::GLOBAL - 49))
      | (1ULL << (TParser::NEWLINE - 49)))) != 0)) {
      setState(135);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case TParser::DEF:
        case TParser::DEFFCT:
        case TParser::GLOBAL: {
          setState(133);
          subRoutine();
          break;
        }

        case TParser::NEWLINE: {
          setState(134);
          match(TParser::NEWLINE);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(139);
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

//----------------- MainRoutineContext ------------------------------------------------------------------

TParser::MainRoutineContext::MainRoutineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TParser::ProcedureDefinitionContext* TParser::MainRoutineContext::procedureDefinition() {
  return getRuleContext<TParser::ProcedureDefinitionContext>(0);
}

TParser::FunctionDefinitionContext* TParser::MainRoutineContext::functionDefinition() {
  return getRuleContext<TParser::FunctionDefinitionContext>(0);
}


size_t TParser::MainRoutineContext::getRuleIndex() const {
  return TParser::RuleMainRoutine;
}

void TParser::MainRoutineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMainRoutine(this);
}

void TParser::MainRoutineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMainRoutine(this);
}


antlrcpp::Any TParser::MainRoutineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitMainRoutine(this);
  else
    return visitor->visitChildren(this);
}

TParser::MainRoutineContext* TParser::mainRoutine() {
  MainRoutineContext *_localctx = _tracker.createInstance<MainRoutineContext>(_ctx, getState());
  enterRule(_localctx, 4, TParser::RuleMainRoutine);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(142);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(140);
      procedureDefinition();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(141);
      functionDefinition();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SubRoutineContext ------------------------------------------------------------------

TParser::SubRoutineContext::SubRoutineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TParser::ProcedureDefinitionContext* TParser::SubRoutineContext::procedureDefinition() {
  return getRuleContext<TParser::ProcedureDefinitionContext>(0);
}

TParser::FunctionDefinitionContext* TParser::SubRoutineContext::functionDefinition() {
  return getRuleContext<TParser::FunctionDefinitionContext>(0);
}


size_t TParser::SubRoutineContext::getRuleIndex() const {
  return TParser::RuleSubRoutine;
}

void TParser::SubRoutineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubRoutine(this);
}

void TParser::SubRoutineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubRoutine(this);
}


antlrcpp::Any TParser::SubRoutineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitSubRoutine(this);
  else
    return visitor->visitChildren(this);
}

TParser::SubRoutineContext* TParser::subRoutine() {
  SubRoutineContext *_localctx = _tracker.createInstance<SubRoutineContext>(_ctx, getState());
  enterRule(_localctx, 6, TParser::RuleSubRoutine);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(146);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(144);
      procedureDefinition();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(145);
      functionDefinition();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProcedureDefinitionContext ------------------------------------------------------------------

TParser::ProcedureDefinitionContext::ProcedureDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TParser::ProcedureDefinitionContext::DEF() {
  return getToken(TParser::DEF, 0);
}

TParser::ProcedureNameContext* TParser::ProcedureDefinitionContext::procedureName() {
  return getRuleContext<TParser::ProcedureNameContext>(0);
}

TParser::FormalParametersContext* TParser::ProcedureDefinitionContext::formalParameters() {
  return getRuleContext<TParser::FormalParametersContext>(0);
}

tree::TerminalNode* TParser::ProcedureDefinitionContext::NEWLINE() {
  return getToken(TParser::NEWLINE, 0);
}

TParser::RoutineBodyContext* TParser::ProcedureDefinitionContext::routineBody() {
  return getRuleContext<TParser::RoutineBodyContext>(0);
}

tree::TerminalNode* TParser::ProcedureDefinitionContext::END() {
  return getToken(TParser::END, 0);
}

tree::TerminalNode* TParser::ProcedureDefinitionContext::GLOBAL() {
  return getToken(TParser::GLOBAL, 0);
}


size_t TParser::ProcedureDefinitionContext::getRuleIndex() const {
  return TParser::RuleProcedureDefinition;
}

void TParser::ProcedureDefinitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProcedureDefinition(this);
}

void TParser::ProcedureDefinitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProcedureDefinition(this);
}


antlrcpp::Any TParser::ProcedureDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitProcedureDefinition(this);
  else
    return visitor->visitChildren(this);
}

TParser::ProcedureDefinitionContext* TParser::procedureDefinition() {
  ProcedureDefinitionContext *_localctx = _tracker.createInstance<ProcedureDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 8, TParser::RuleProcedureDefinition);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(149);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TParser::GLOBAL) {
      setState(148);
      match(TParser::GLOBAL);
    }
    setState(151);
    match(TParser::DEF);
    setState(152);
    procedureName();
    setState(153);
    formalParameters();
    setState(154);
    match(TParser::NEWLINE);
    setState(155);
    routineBody();
    setState(156);
    match(TParser::END);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProcedureNameContext ------------------------------------------------------------------

TParser::ProcedureNameContext::ProcedureNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TParser::ProcedureNameContext::IDENTIFIER() {
  return getToken(TParser::IDENTIFIER, 0);
}


size_t TParser::ProcedureNameContext::getRuleIndex() const {
  return TParser::RuleProcedureName;
}

void TParser::ProcedureNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProcedureName(this);
}

void TParser::ProcedureNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProcedureName(this);
}


antlrcpp::Any TParser::ProcedureNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitProcedureName(this);
  else
    return visitor->visitChildren(this);
}

TParser::ProcedureNameContext* TParser::procedureName() {
  ProcedureNameContext *_localctx = _tracker.createInstance<ProcedureNameContext>(_ctx, getState());
  enterRule(_localctx, 10, TParser::RuleProcedureName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(158);
    match(TParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionDefinitionContext ------------------------------------------------------------------

TParser::FunctionDefinitionContext::FunctionDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TParser::FunctionDefinitionContext::DEFFCT() {
  return getToken(TParser::DEFFCT, 0);
}

TParser::TypeContext* TParser::FunctionDefinitionContext::type() {
  return getRuleContext<TParser::TypeContext>(0);
}

TParser::FunctionNameContext* TParser::FunctionDefinitionContext::functionName() {
  return getRuleContext<TParser::FunctionNameContext>(0);
}

TParser::FormalParametersContext* TParser::FunctionDefinitionContext::formalParameters() {
  return getRuleContext<TParser::FormalParametersContext>(0);
}

tree::TerminalNode* TParser::FunctionDefinitionContext::NEWLINE() {
  return getToken(TParser::NEWLINE, 0);
}

TParser::RoutineBodyContext* TParser::FunctionDefinitionContext::routineBody() {
  return getRuleContext<TParser::RoutineBodyContext>(0);
}

tree::TerminalNode* TParser::FunctionDefinitionContext::ENDFCT() {
  return getToken(TParser::ENDFCT, 0);
}

tree::TerminalNode* TParser::FunctionDefinitionContext::GLOBAL() {
  return getToken(TParser::GLOBAL, 0);
}


size_t TParser::FunctionDefinitionContext::getRuleIndex() const {
  return TParser::RuleFunctionDefinition;
}

void TParser::FunctionDefinitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionDefinition(this);
}

void TParser::FunctionDefinitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionDefinition(this);
}


antlrcpp::Any TParser::FunctionDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitFunctionDefinition(this);
  else
    return visitor->visitChildren(this);
}

TParser::FunctionDefinitionContext* TParser::functionDefinition() {
  FunctionDefinitionContext *_localctx = _tracker.createInstance<FunctionDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 12, TParser::RuleFunctionDefinition);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(161);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TParser::GLOBAL) {
      setState(160);
      match(TParser::GLOBAL);
    }
    setState(163);
    match(TParser::DEFFCT);
    setState(164);
    type();
    setState(165);
    functionName();
    setState(166);
    formalParameters();
    setState(167);
    match(TParser::NEWLINE);
    setState(168);
    routineBody();
    setState(169);
    match(TParser::ENDFCT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionNameContext ------------------------------------------------------------------

TParser::FunctionNameContext::FunctionNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TParser::FunctionNameContext::IDENTIFIER() {
  return getToken(TParser::IDENTIFIER, 0);
}


size_t TParser::FunctionNameContext::getRuleIndex() const {
  return TParser::RuleFunctionName;
}

void TParser::FunctionNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionName(this);
}

void TParser::FunctionNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionName(this);
}


antlrcpp::Any TParser::FunctionNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitFunctionName(this);
  else
    return visitor->visitChildren(this);
}

TParser::FunctionNameContext* TParser::functionName() {
  FunctionNameContext *_localctx = _tracker.createInstance<FunctionNameContext>(_ctx, getState());
  enterRule(_localctx, 14, TParser::RuleFunctionName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(171);
    match(TParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ModuleDataContext ------------------------------------------------------------------

TParser::ModuleDataContext::ModuleDataContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TParser::ModuleDataContext::DEFDAT() {
  return getToken(TParser::DEFDAT, 0);
}

TParser::ModuleNameContext* TParser::ModuleDataContext::moduleName() {
  return getRuleContext<TParser::ModuleNameContext>(0);
}

std::vector<tree::TerminalNode *> TParser::ModuleDataContext::NEWLINE() {
  return getTokens(TParser::NEWLINE);
}

tree::TerminalNode* TParser::ModuleDataContext::NEWLINE(size_t i) {
  return getToken(TParser::NEWLINE, i);
}

TParser::DataListContext* TParser::ModuleDataContext::dataList() {
  return getRuleContext<TParser::DataListContext>(0);
}

tree::TerminalNode* TParser::ModuleDataContext::ENDDAT() {
  return getToken(TParser::ENDDAT, 0);
}

tree::TerminalNode* TParser::ModuleDataContext::PUBLIC() {
  return getToken(TParser::PUBLIC, 0);
}


size_t TParser::ModuleDataContext::getRuleIndex() const {
  return TParser::RuleModuleData;
}

void TParser::ModuleDataContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterModuleData(this);
}

void TParser::ModuleDataContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitModuleData(this);
}


antlrcpp::Any TParser::ModuleDataContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitModuleData(this);
  else
    return visitor->visitChildren(this);
}

TParser::ModuleDataContext* TParser::moduleData() {
  ModuleDataContext *_localctx = _tracker.createInstance<ModuleDataContext>(_ctx, getState());
  enterRule(_localctx, 16, TParser::RuleModuleData);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(173);
    match(TParser::DEFDAT);
    setState(174);
    moduleName();
    setState(176);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TParser::PUBLIC) {
      setState(175);
      match(TParser::PUBLIC);
    }
    setState(178);
    match(TParser::NEWLINE);
    setState(179);
    dataList();
    setState(180);
    match(TParser::ENDDAT);
    setState(184);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TParser::NEWLINE) {
      setState(181);
      match(TParser::NEWLINE);
      setState(186);
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

//----------------- ModuleNameContext ------------------------------------------------------------------

TParser::ModuleNameContext::ModuleNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TParser::ModuleNameContext::IDENTIFIER() {
  return getToken(TParser::IDENTIFIER, 0);
}


size_t TParser::ModuleNameContext::getRuleIndex() const {
  return TParser::RuleModuleName;
}

void TParser::ModuleNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterModuleName(this);
}

void TParser::ModuleNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitModuleName(this);
}


antlrcpp::Any TParser::ModuleNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitModuleName(this);
  else
    return visitor->visitChildren(this);
}

TParser::ModuleNameContext* TParser::moduleName() {
  ModuleNameContext *_localctx = _tracker.createInstance<ModuleNameContext>(_ctx, getState());
  enterRule(_localctx, 18, TParser::RuleModuleName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(187);
    match(TParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DataListContext ------------------------------------------------------------------

TParser::DataListContext::DataListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> TParser::DataListContext::NEWLINE() {
  return getTokens(TParser::NEWLINE);
}

tree::TerminalNode* TParser::DataListContext::NEWLINE(size_t i) {
  return getToken(TParser::NEWLINE, i);
}

std::vector<TParser::ForwardDeclarationContext *> TParser::DataListContext::forwardDeclaration() {
  return getRuleContexts<TParser::ForwardDeclarationContext>();
}

TParser::ForwardDeclarationContext* TParser::DataListContext::forwardDeclaration(size_t i) {
  return getRuleContext<TParser::ForwardDeclarationContext>(i);
}

std::vector<TParser::TypeDeclarationContext *> TParser::DataListContext::typeDeclaration() {
  return getRuleContexts<TParser::TypeDeclarationContext>();
}

TParser::TypeDeclarationContext* TParser::DataListContext::typeDeclaration(size_t i) {
  return getRuleContext<TParser::TypeDeclarationContext>(i);
}

std::vector<TParser::VariableDeclarationInDataListContext *> TParser::DataListContext::variableDeclarationInDataList() {
  return getRuleContexts<TParser::VariableDeclarationInDataListContext>();
}

TParser::VariableDeclarationInDataListContext* TParser::DataListContext::variableDeclarationInDataList(size_t i) {
  return getRuleContext<TParser::VariableDeclarationInDataListContext>(i);
}

std::vector<TParser::ArrayInitialisationContext *> TParser::DataListContext::arrayInitialisation() {
  return getRuleContexts<TParser::ArrayInitialisationContext>();
}

TParser::ArrayInitialisationContext* TParser::DataListContext::arrayInitialisation(size_t i) {
  return getRuleContext<TParser::ArrayInitialisationContext>(i);
}

std::vector<TParser::ImportStatementContext *> TParser::DataListContext::importStatement() {
  return getRuleContexts<TParser::ImportStatementContext>();
}

TParser::ImportStatementContext* TParser::DataListContext::importStatement(size_t i) {
  return getRuleContext<TParser::ImportStatementContext>(i);
}


size_t TParser::DataListContext::getRuleIndex() const {
  return TParser::RuleDataList;
}

void TParser::DataListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDataList(this);
}

void TParser::DataListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDataList(this);
}


antlrcpp::Any TParser::DataListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitDataList(this);
  else
    return visitor->visitChildren(this);
}

TParser::DataListContext* TParser::dataList() {
  DataListContext *_localctx = _tracker.createInstance<DataListContext>(_ctx, getState());
  enterRule(_localctx, 20, TParser::RuleDataList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(207);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << TParser::BOOL)
      | (1ULL << TParser::CHAR)
      | (1ULL << TParser::CONST)
      | (1ULL << TParser::DECL)
      | (1ULL << TParser::ENUM))) != 0) || ((((_la - 65) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 65)) & ((1ULL << (TParser::EXT - 65))
      | (1ULL << (TParser::EXTFCT - 65))
      | (1ULL << (TParser::GLOBAL - 65))
      | (1ULL << (TParser::IMPORT - 65))
      | (1ULL << (TParser::INT - 65))
      | (1ULL << (TParser::REAL - 65))
      | (1ULL << (TParser::SIGNAL - 65))
      | (1ULL << (TParser::STRUC - 65))
      | (1ULL << (TParser::NEWLINE - 65))
      | (1ULL << (TParser::IDENTIFIER - 65)))) != 0)) {
      setState(205);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
      case 1: {
        setState(189);
        match(TParser::NEWLINE);
        break;
      }

      case 2: {
        setState(190);
        forwardDeclaration();
        setState(191);
        match(TParser::NEWLINE);
        break;
      }

      case 3: {
        setState(193);
        typeDeclaration();
        setState(194);
        match(TParser::NEWLINE);
        break;
      }

      case 4: {
        setState(196);
        variableDeclarationInDataList();
        setState(197);
        match(TParser::NEWLINE);
        break;
      }

      case 5: {
        setState(199);
        arrayInitialisation();
        setState(200);
        match(TParser::NEWLINE);
        break;
      }

      case 6: {
        setState(202);
        importStatement();
        setState(203);
        match(TParser::NEWLINE);
        break;
      }

      }
      setState(209);
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

//----------------- ArrayInitialisationContext ------------------------------------------------------------------

TParser::ArrayInitialisationContext::ArrayInitialisationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TParser::ArrayInitialisationContext::IDENTIFIER() {
  return getToken(TParser::IDENTIFIER, 0);
}

TParser::ArrayVariableSuffixContext* TParser::ArrayInitialisationContext::arrayVariableSuffix() {
  return getRuleContext<TParser::ArrayVariableSuffixContext>(0);
}

tree::TerminalNode* TParser::ArrayInitialisationContext::ASSIGN() {
  return getToken(TParser::ASSIGN, 0);
}

TParser::UnaryPlusMinuxExpressionContext* TParser::ArrayInitialisationContext::unaryPlusMinuxExpression() {
  return getRuleContext<TParser::UnaryPlusMinuxExpressionContext>(0);
}


size_t TParser::ArrayInitialisationContext::getRuleIndex() const {
  return TParser::RuleArrayInitialisation;
}

void TParser::ArrayInitialisationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayInitialisation(this);
}

void TParser::ArrayInitialisationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayInitialisation(this);
}


antlrcpp::Any TParser::ArrayInitialisationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitArrayInitialisation(this);
  else
    return visitor->visitChildren(this);
}

TParser::ArrayInitialisationContext* TParser::arrayInitialisation() {
  ArrayInitialisationContext *_localctx = _tracker.createInstance<ArrayInitialisationContext>(_ctx, getState());
  enterRule(_localctx, 22, TParser::RuleArrayInitialisation);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(210);
    match(TParser::IDENTIFIER);
    setState(211);
    arrayVariableSuffix();
    setState(212);
    match(TParser::ASSIGN);
    setState(213);
    unaryPlusMinuxExpression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeDeclarationContext ------------------------------------------------------------------

TParser::TypeDeclarationContext::TypeDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TParser::StructureDefinitionContext* TParser::TypeDeclarationContext::structureDefinition() {
  return getRuleContext<TParser::StructureDefinitionContext>(0);
}

TParser::EnumDefinitionContext* TParser::TypeDeclarationContext::enumDefinition() {
  return getRuleContext<TParser::EnumDefinitionContext>(0);
}


size_t TParser::TypeDeclarationContext::getRuleIndex() const {
  return TParser::RuleTypeDeclaration;
}

void TParser::TypeDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeDeclaration(this);
}

void TParser::TypeDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeDeclaration(this);
}


antlrcpp::Any TParser::TypeDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitTypeDeclaration(this);
  else
    return visitor->visitChildren(this);
}

TParser::TypeDeclarationContext* TParser::typeDeclaration() {
  TypeDeclarationContext *_localctx = _tracker.createInstance<TypeDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 24, TParser::RuleTypeDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(217);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(215);
      structureDefinition();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(216);
      enumDefinition();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StructureDefinitionContext ------------------------------------------------------------------

TParser::StructureDefinitionContext::StructureDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TParser::StructureDefinitionContext::STRUC() {
  return getToken(TParser::STRUC, 0);
}

TParser::TypeNameContext* TParser::StructureDefinitionContext::typeName() {
  return getRuleContext<TParser::TypeNameContext>(0);
}

std::vector<TParser::TypeContext *> TParser::StructureDefinitionContext::type() {
  return getRuleContexts<TParser::TypeContext>();
}

TParser::TypeContext* TParser::StructureDefinitionContext::type(size_t i) {
  return getRuleContext<TParser::TypeContext>(i);
}

std::vector<TParser::VariableNameContext *> TParser::StructureDefinitionContext::variableName() {
  return getRuleContexts<TParser::VariableNameContext>();
}

TParser::VariableNameContext* TParser::StructureDefinitionContext::variableName(size_t i) {
  return getRuleContext<TParser::VariableNameContext>(i);
}

std::vector<TParser::VariableListRestContext *> TParser::StructureDefinitionContext::variableListRest() {
  return getRuleContexts<TParser::VariableListRestContext>();
}

TParser::VariableListRestContext* TParser::StructureDefinitionContext::variableListRest(size_t i) {
  return getRuleContext<TParser::VariableListRestContext>(i);
}

tree::TerminalNode* TParser::StructureDefinitionContext::GLOBAL() {
  return getToken(TParser::GLOBAL, 0);
}

std::vector<tree::TerminalNode *> TParser::StructureDefinitionContext::COMMA() {
  return getTokens(TParser::COMMA);
}

tree::TerminalNode* TParser::StructureDefinitionContext::COMMA(size_t i) {
  return getToken(TParser::COMMA, i);
}


size_t TParser::StructureDefinitionContext::getRuleIndex() const {
  return TParser::RuleStructureDefinition;
}

void TParser::StructureDefinitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStructureDefinition(this);
}

void TParser::StructureDefinitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStructureDefinition(this);
}


antlrcpp::Any TParser::StructureDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitStructureDefinition(this);
  else
    return visitor->visitChildren(this);
}

TParser::StructureDefinitionContext* TParser::structureDefinition() {
  StructureDefinitionContext *_localctx = _tracker.createInstance<StructureDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 26, TParser::RuleStructureDefinition);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(220);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TParser::GLOBAL) {
      setState(219);
      match(TParser::GLOBAL);
    }
    setState(222);
    match(TParser::STRUC);
    setState(223);
    typeName();
    setState(224);
    type();
    setState(225);
    variableName();
    setState(226);
    variableListRest();
    setState(234);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TParser::COMMA) {
      setState(227);
      match(TParser::COMMA);
      setState(228);
      type();
      setState(229);
      variableName();
      setState(230);
      variableListRest();
      setState(236);
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

//----------------- EnumDefinitionContext ------------------------------------------------------------------

TParser::EnumDefinitionContext::EnumDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TParser::EnumDefinitionContext::ENUM() {
  return getToken(TParser::ENUM, 0);
}

TParser::TypeNameContext* TParser::EnumDefinitionContext::typeName() {
  return getRuleContext<TParser::TypeNameContext>(0);
}

std::vector<TParser::EnumValueContext *> TParser::EnumDefinitionContext::enumValue() {
  return getRuleContexts<TParser::EnumValueContext>();
}

TParser::EnumValueContext* TParser::EnumDefinitionContext::enumValue(size_t i) {
  return getRuleContext<TParser::EnumValueContext>(i);
}

tree::TerminalNode* TParser::EnumDefinitionContext::GLOBAL() {
  return getToken(TParser::GLOBAL, 0);
}

std::vector<tree::TerminalNode *> TParser::EnumDefinitionContext::COMMA() {
  return getTokens(TParser::COMMA);
}

tree::TerminalNode* TParser::EnumDefinitionContext::COMMA(size_t i) {
  return getToken(TParser::COMMA, i);
}


size_t TParser::EnumDefinitionContext::getRuleIndex() const {
  return TParser::RuleEnumDefinition;
}

void TParser::EnumDefinitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnumDefinition(this);
}

void TParser::EnumDefinitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnumDefinition(this);
}


antlrcpp::Any TParser::EnumDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitEnumDefinition(this);
  else
    return visitor->visitChildren(this);
}

TParser::EnumDefinitionContext* TParser::enumDefinition() {
  EnumDefinitionContext *_localctx = _tracker.createInstance<EnumDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 28, TParser::RuleEnumDefinition);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(238);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TParser::GLOBAL) {
      setState(237);
      match(TParser::GLOBAL);
    }
    setState(240);
    match(TParser::ENUM);
    setState(241);
    typeName();
    setState(242);
    enumValue();
    setState(247);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TParser::COMMA) {
      setState(243);
      match(TParser::COMMA);
      setState(244);
      enumValue();
      setState(249);
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

//----------------- EnumValueContext ------------------------------------------------------------------

TParser::EnumValueContext::EnumValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TParser::EnumValueContext::IDENTIFIER() {
  return getToken(TParser::IDENTIFIER, 0);
}


size_t TParser::EnumValueContext::getRuleIndex() const {
  return TParser::RuleEnumValue;
}

void TParser::EnumValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnumValue(this);
}

void TParser::EnumValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnumValue(this);
}


antlrcpp::Any TParser::EnumValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitEnumValue(this);
  else
    return visitor->visitChildren(this);
}

TParser::EnumValueContext* TParser::enumValue() {
  EnumValueContext *_localctx = _tracker.createInstance<EnumValueContext>(_ctx, getState());
  enterRule(_localctx, 30, TParser::RuleEnumValue);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(250);
    match(TParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableDeclarationContext ------------------------------------------------------------------

TParser::VariableDeclarationContext::VariableDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TParser::TypeContext* TParser::VariableDeclarationContext::type() {
  return getRuleContext<TParser::TypeContext>(0);
}

TParser::VariableNameContext* TParser::VariableDeclarationContext::variableName() {
  return getRuleContext<TParser::VariableNameContext>(0);
}

TParser::VariableListRestContext* TParser::VariableDeclarationContext::variableListRest() {
  return getRuleContext<TParser::VariableListRestContext>(0);
}

TParser::SignalDeclarationContext* TParser::VariableDeclarationContext::signalDeclaration() {
  return getRuleContext<TParser::SignalDeclarationContext>(0);
}

tree::TerminalNode* TParser::VariableDeclarationContext::DECL() {
  return getToken(TParser::DECL, 0);
}


size_t TParser::VariableDeclarationContext::getRuleIndex() const {
  return TParser::RuleVariableDeclaration;
}

void TParser::VariableDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariableDeclaration(this);
}

void TParser::VariableDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariableDeclaration(this);
}


antlrcpp::Any TParser::VariableDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitVariableDeclaration(this);
  else
    return visitor->visitChildren(this);
}

TParser::VariableDeclarationContext* TParser::variableDeclaration() {
  VariableDeclarationContext *_localctx = _tracker.createInstance<VariableDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 32, TParser::RuleVariableDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(253);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TParser::DECL) {
      setState(252);
      match(TParser::DECL);
    }
    setState(260);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TParser::BOOL:
      case TParser::CHAR:
      case TParser::INT:
      case TParser::REAL:
      case TParser::IDENTIFIER: {
        setState(255);
        type();
        setState(256);
        variableName();
        setState(257);
        variableListRest();
        break;
      }

      case TParser::SIGNAL: {
        setState(259);
        signalDeclaration();
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

//----------------- SignalDeclarationContext ------------------------------------------------------------------

TParser::SignalDeclarationContext::SignalDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

//tree::TerminalNode* TParser::SignalDeclarationContext::SIGNAL() {
//  return getToken(TParser::SIGNAL, 0);
//}

tree::TerminalNode* TParser::SignalDeclarationContext::IDENTIFIER() {
  return getToken(TParser::IDENTIFIER, 0);
}

std::vector<TParser::PrimaryContext *> TParser::SignalDeclarationContext::primary() {
  return getRuleContexts<TParser::PrimaryContext>();
}

TParser::PrimaryContext* TParser::SignalDeclarationContext::primary(size_t i) {
  return getRuleContext<TParser::PrimaryContext>(i);
}

tree::TerminalNode* TParser::SignalDeclarationContext::TO() {
  return getToken(TParser::TO, 0);
}


size_t TParser::SignalDeclarationContext::getRuleIndex() const {
  return TParser::RuleSignalDeclaration;
}

void TParser::SignalDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignalDeclaration(this);
}

void TParser::SignalDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignalDeclaration(this);
}


antlrcpp::Any TParser::SignalDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitSignalDeclaration(this);
  else
    return visitor->visitChildren(this);
}

TParser::SignalDeclarationContext* TParser::signalDeclaration() {
  SignalDeclarationContext *_localctx = _tracker.createInstance<SignalDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 34, TParser::RuleSignalDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(262);
    match(TParser::SIGNAL);
    setState(263);
    match(TParser::IDENTIFIER);
    setState(264);
    primary();
    setState(267);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TParser::TO) {
      setState(265);
      match(TParser::TO);
      setState(266);
      primary();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableDeclarationInDataListContext ------------------------------------------------------------------

TParser::VariableDeclarationInDataListContext::VariableDeclarationInDataListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TParser::TypeContext* TParser::VariableDeclarationInDataListContext::type() {
  return getRuleContext<TParser::TypeContext>(0);
}

TParser::VariableNameContext* TParser::VariableDeclarationInDataListContext::variableName() {
  return getRuleContext<TParser::VariableNameContext>(0);
}

TParser::SignalDeclarationContext* TParser::VariableDeclarationInDataListContext::signalDeclaration() {
  return getRuleContext<TParser::SignalDeclarationContext>(0);
}

tree::TerminalNode* TParser::VariableDeclarationInDataListContext::DECL() {
  return getToken(TParser::DECL, 0);
}

tree::TerminalNode* TParser::VariableDeclarationInDataListContext::GLOBAL() {
  return getToken(TParser::GLOBAL, 0);
}

tree::TerminalNode* TParser::VariableDeclarationInDataListContext::CONST() {
  return getToken(TParser::CONST, 0);
}

TParser::VariableListRestContext* TParser::VariableDeclarationInDataListContext::variableListRest() {
  return getRuleContext<TParser::VariableListRestContext>(0);
}

TParser::VariableInitialisationContext* TParser::VariableDeclarationInDataListContext::variableInitialisation() {
  return getRuleContext<TParser::VariableInitialisationContext>(0);
}


size_t TParser::VariableDeclarationInDataListContext::getRuleIndex() const {
  return TParser::RuleVariableDeclarationInDataList;
}

void TParser::VariableDeclarationInDataListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariableDeclarationInDataList(this);
}

void TParser::VariableDeclarationInDataListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariableDeclarationInDataList(this);
}


antlrcpp::Any TParser::VariableDeclarationInDataListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitVariableDeclarationInDataList(this);
  else
    return visitor->visitChildren(this);
}

TParser::VariableDeclarationInDataListContext* TParser::variableDeclarationInDataList() {
  VariableDeclarationInDataListContext *_localctx = _tracker.createInstance<VariableDeclarationInDataListContext>(_ctx, getState());
  enterRule(_localctx, 36, TParser::RuleVariableDeclarationInDataList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(270);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TParser::DECL) {
      setState(269);
      match(TParser::DECL);
    }
    setState(273);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TParser::GLOBAL) {
      setState(272);
      match(TParser::GLOBAL);
    }
    setState(276);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TParser::CONST) {
      setState(275);
      match(TParser::CONST);
    }
    setState(285);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TParser::BOOL:
      case TParser::CHAR:
      case TParser::INT:
      case TParser::REAL:
      case TParser::IDENTIFIER: {
        setState(278);
        type();
        setState(279);
        variableName();
        setState(282);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case TParser::COMMA:
          case TParser::NEWLINE: {
            setState(280);
            variableListRest();
            break;
          }

          case TParser::ASSIGN: {
            setState(281);
            variableInitialisation();
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        break;
      }

      case TParser::SIGNAL: {
        setState(284);
        signalDeclaration();
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

//----------------- VariableListRestContext ------------------------------------------------------------------

TParser::VariableListRestContext::VariableListRestContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> TParser::VariableListRestContext::COMMA() {
  return getTokens(TParser::COMMA);
}

tree::TerminalNode* TParser::VariableListRestContext::COMMA(size_t i) {
  return getToken(TParser::COMMA, i);
}

std::vector<TParser::VariableNameContext *> TParser::VariableListRestContext::variableName() {
  return getRuleContexts<TParser::VariableNameContext>();
}

TParser::VariableNameContext* TParser::VariableListRestContext::variableName(size_t i) {
  return getRuleContext<TParser::VariableNameContext>(i);
}


size_t TParser::VariableListRestContext::getRuleIndex() const {
  return TParser::RuleVariableListRest;
}

void TParser::VariableListRestContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariableListRest(this);
}

void TParser::VariableListRestContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariableListRest(this);
}


antlrcpp::Any TParser::VariableListRestContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitVariableListRest(this);
  else
    return visitor->visitChildren(this);
}

TParser::VariableListRestContext* TParser::variableListRest() {
  VariableListRestContext *_localctx = _tracker.createInstance<VariableListRestContext>(_ctx, getState());
  enterRule(_localctx, 38, TParser::RuleVariableListRest);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(291);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(287);
        match(TParser::COMMA);
        setState(288);
        variableName(); 
      }
      setState(293);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableInitialisationContext ------------------------------------------------------------------

TParser::VariableInitialisationContext::VariableInitialisationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TParser::VariableInitialisationContext::ASSIGN() {
  return getToken(TParser::ASSIGN, 0);
}

TParser::UnaryPlusMinuxExpressionContext* TParser::VariableInitialisationContext::unaryPlusMinuxExpression() {
  return getRuleContext<TParser::UnaryPlusMinuxExpressionContext>(0);
}


size_t TParser::VariableInitialisationContext::getRuleIndex() const {
  return TParser::RuleVariableInitialisation;
}

void TParser::VariableInitialisationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariableInitialisation(this);
}

void TParser::VariableInitialisationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariableInitialisation(this);
}


antlrcpp::Any TParser::VariableInitialisationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitVariableInitialisation(this);
  else
    return visitor->visitChildren(this);
}

TParser::VariableInitialisationContext* TParser::variableInitialisation() {
  VariableInitialisationContext *_localctx = _tracker.createInstance<VariableInitialisationContext>(_ctx, getState());
  enterRule(_localctx, 40, TParser::RuleVariableInitialisation);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(294);
    match(TParser::ASSIGN);
    setState(295);
    unaryPlusMinuxExpression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StructLiteralContext ------------------------------------------------------------------

TParser::StructLiteralContext::StructLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TParser::StructLiteralContext::LBRACE() {
  return getToken(TParser::LBRACE, 0);
}

TParser::StructElementListContext* TParser::StructLiteralContext::structElementList() {
  return getRuleContext<TParser::StructElementListContext>(0);
}

tree::TerminalNode* TParser::StructLiteralContext::RBRACE() {
  return getToken(TParser::RBRACE, 0);
}

TParser::TypeNameContext* TParser::StructLiteralContext::typeName() {
  return getRuleContext<TParser::TypeNameContext>(0);
}

tree::TerminalNode* TParser::StructLiteralContext::COLON() {
  return getToken(TParser::COLON, 0);
}


size_t TParser::StructLiteralContext::getRuleIndex() const {
  return TParser::RuleStructLiteral;
}

void TParser::StructLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStructLiteral(this);
}

void TParser::StructLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStructLiteral(this);
}


antlrcpp::Any TParser::StructLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitStructLiteral(this);
  else
    return visitor->visitChildren(this);
}

TParser::StructLiteralContext* TParser::structLiteral() {
  StructLiteralContext *_localctx = _tracker.createInstance<StructLiteralContext>(_ctx, getState());
  enterRule(_localctx, 42, TParser::RuleStructLiteral);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(297);
    match(TParser::LBRACE);
    setState(301);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
    case 1: {
      setState(298);
      typeName();
      setState(299);
      match(TParser::COLON);
      break;
    }

    }
    setState(303);
    structElementList();
    setState(304);
    match(TParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StructElementListContext ------------------------------------------------------------------

TParser::StructElementListContext::StructElementListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TParser::StructElementContext *> TParser::StructElementListContext::structElement() {
  return getRuleContexts<TParser::StructElementContext>();
}

TParser::StructElementContext* TParser::StructElementListContext::structElement(size_t i) {
  return getRuleContext<TParser::StructElementContext>(i);
}

std::vector<tree::TerminalNode *> TParser::StructElementListContext::COMMA() {
  return getTokens(TParser::COMMA);
}

tree::TerminalNode* TParser::StructElementListContext::COMMA(size_t i) {
  return getToken(TParser::COMMA, i);
}


size_t TParser::StructElementListContext::getRuleIndex() const {
  return TParser::RuleStructElementList;
}

void TParser::StructElementListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStructElementList(this);
}

void TParser::StructElementListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStructElementList(this);
}


antlrcpp::Any TParser::StructElementListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitStructElementList(this);
  else
    return visitor->visitChildren(this);
}

TParser::StructElementListContext* TParser::structElementList() {
  StructElementListContext *_localctx = _tracker.createInstance<StructElementListContext>(_ctx, getState());
  enterRule(_localctx, 44, TParser::RuleStructElementList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(306);
    structElement();
    setState(311);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TParser::COMMA) {
      setState(307);
      match(TParser::COMMA);
      setState(308);
      structElement();
      setState(313);
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

//----------------- StructElementContext ------------------------------------------------------------------

TParser::StructElementContext::StructElementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TParser::VariableNameContext* TParser::StructElementContext::variableName() {
  return getRuleContext<TParser::VariableNameContext>(0);
}

TParser::UnaryPlusMinuxExpressionContext* TParser::StructElementContext::unaryPlusMinuxExpression() {
  return getRuleContext<TParser::UnaryPlusMinuxExpressionContext>(0);
}


size_t TParser::StructElementContext::getRuleIndex() const {
  return TParser::RuleStructElement;
}

void TParser::StructElementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStructElement(this);
}

void TParser::StructElementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStructElement(this);
}


antlrcpp::Any TParser::StructElementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitStructElement(this);
  else
    return visitor->visitChildren(this);
}

TParser::StructElementContext* TParser::structElement() {
  StructElementContext *_localctx = _tracker.createInstance<StructElementContext>(_ctx, getState());
  enterRule(_localctx, 46, TParser::RuleStructElement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(314);
    variableName();
    setState(315);
    unaryPlusMinuxExpression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FormalParametersContext ------------------------------------------------------------------

TParser::FormalParametersContext::FormalParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TParser::FormalParametersContext::LPAREN() {
  return getToken(TParser::LPAREN, 0);
}

tree::TerminalNode* TParser::FormalParametersContext::RPAREN() {
  return getToken(TParser::RPAREN, 0);
}

std::vector<TParser::ParameterContext *> TParser::FormalParametersContext::parameter() {
  return getRuleContexts<TParser::ParameterContext>();
}

TParser::ParameterContext* TParser::FormalParametersContext::parameter(size_t i) {
  return getRuleContext<TParser::ParameterContext>(i);
}

std::vector<tree::TerminalNode *> TParser::FormalParametersContext::COMMA() {
  return getTokens(TParser::COMMA);
}

tree::TerminalNode* TParser::FormalParametersContext::COMMA(size_t i) {
  return getToken(TParser::COMMA, i);
}


size_t TParser::FormalParametersContext::getRuleIndex() const {
  return TParser::RuleFormalParameters;
}

void TParser::FormalParametersContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFormalParameters(this);
}

void TParser::FormalParametersContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFormalParameters(this);
}


antlrcpp::Any TParser::FormalParametersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitFormalParameters(this);
  else
    return visitor->visitChildren(this);
}

TParser::FormalParametersContext* TParser::formalParameters() {
  FormalParametersContext *_localctx = _tracker.createInstance<FormalParametersContext>(_ctx, getState());
  enterRule(_localctx, 48, TParser::RuleFormalParameters);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(317);
    match(TParser::LPAREN);
    setState(326);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TParser::IDENTIFIER) {
      setState(318);
      parameter();
      setState(323);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TParser::COMMA) {
        setState(319);
        match(TParser::COMMA);
        setState(320);
        parameter();
        setState(325);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(328);
    match(TParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterContext ------------------------------------------------------------------

TParser::ParameterContext::ParameterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TParser::VariableNameContext* TParser::ParameterContext::variableName() {
  return getRuleContext<TParser::VariableNameContext>(0);
}

TParser::ParameterCallTypeContext* TParser::ParameterContext::parameterCallType() {
  return getRuleContext<TParser::ParameterCallTypeContext>(0);
}


size_t TParser::ParameterContext::getRuleIndex() const {
  return TParser::RuleParameter;
}

void TParser::ParameterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameter(this);
}

void TParser::ParameterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameter(this);
}


antlrcpp::Any TParser::ParameterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitParameter(this);
  else
    return visitor->visitChildren(this);
}

TParser::ParameterContext* TParser::parameter() {
  ParameterContext *_localctx = _tracker.createInstance<ParameterContext>(_ctx, getState());
  enterRule(_localctx, 50, TParser::RuleParameter);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(330);
    variableName();
    setState(332);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TParser::COLON) {
      setState(331);
      parameterCallType();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RoutineBodyContext ------------------------------------------------------------------

TParser::RoutineBodyContext::RoutineBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TParser::RoutineDataSectionContext* TParser::RoutineBodyContext::routineDataSection() {
  return getRuleContext<TParser::RoutineDataSectionContext>(0);
}

TParser::RoutineImplementationSectionContext* TParser::RoutineBodyContext::routineImplementationSection() {
  return getRuleContext<TParser::RoutineImplementationSectionContext>(0);
}


size_t TParser::RoutineBodyContext::getRuleIndex() const {
  return TParser::RuleRoutineBody;
}

void TParser::RoutineBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRoutineBody(this);
}

void TParser::RoutineBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRoutineBody(this);
}


antlrcpp::Any TParser::RoutineBodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitRoutineBody(this);
  else
    return visitor->visitChildren(this);
}

TParser::RoutineBodyContext* TParser::routineBody() {
  RoutineBodyContext *_localctx = _tracker.createInstance<RoutineBodyContext>(_ctx, getState());
  enterRule(_localctx, 52, TParser::RuleRoutineBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(334);
    routineDataSection();
    setState(335);
    routineImplementationSection();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RoutineDataSectionContext ------------------------------------------------------------------

TParser::RoutineDataSectionContext::RoutineDataSectionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TParser::ForwardDeclarationContext *> TParser::RoutineDataSectionContext::forwardDeclaration() {
  return getRuleContexts<TParser::ForwardDeclarationContext>();
}

TParser::ForwardDeclarationContext* TParser::RoutineDataSectionContext::forwardDeclaration(size_t i) {
  return getRuleContext<TParser::ForwardDeclarationContext>(i);
}

std::vector<tree::TerminalNode *> TParser::RoutineDataSectionContext::NEWLINE() {
  return getTokens(TParser::NEWLINE);
}

tree::TerminalNode* TParser::RoutineDataSectionContext::NEWLINE(size_t i) {
  return getToken(TParser::NEWLINE, i);
}

std::vector<TParser::VariableDeclarationContext *> TParser::RoutineDataSectionContext::variableDeclaration() {
  return getRuleContexts<TParser::VariableDeclarationContext>();
}

TParser::VariableDeclarationContext* TParser::RoutineDataSectionContext::variableDeclaration(size_t i) {
  return getRuleContext<TParser::VariableDeclarationContext>(i);
}

std::vector<TParser::ImportStatementContext *> TParser::RoutineDataSectionContext::importStatement() {
  return getRuleContexts<TParser::ImportStatementContext>();
}

TParser::ImportStatementContext* TParser::RoutineDataSectionContext::importStatement(size_t i) {
  return getRuleContext<TParser::ImportStatementContext>(i);
}


size_t TParser::RoutineDataSectionContext::getRuleIndex() const {
  return TParser::RuleRoutineDataSection;
}

void TParser::RoutineDataSectionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRoutineDataSection(this);
}

void TParser::RoutineDataSectionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRoutineDataSection(this);
}


antlrcpp::Any TParser::RoutineDataSectionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitRoutineDataSection(this);
  else
    return visitor->visitChildren(this);
}

TParser::RoutineDataSectionContext* TParser::routineDataSection() {
  RoutineDataSectionContext *_localctx = _tracker.createInstance<RoutineDataSectionContext>(_ctx, getState());
  enterRule(_localctx, 54, TParser::RuleRoutineDataSection);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(350);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(348);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case TParser::EXT:
          case TParser::EXTFCT: {
            setState(337);
            forwardDeclaration();
            setState(338);
            match(TParser::NEWLINE);
            break;
          }

          case TParser::BOOL:
          case TParser::CHAR:
          case TParser::DECL:
          case TParser::INT:
          case TParser::REAL:
          case TParser::SIGNAL:
          case TParser::IDENTIFIER: {
            setState(340);
            variableDeclaration();
            setState(341);
            match(TParser::NEWLINE);
            break;
          }

          case TParser::NEWLINE: {
            setState(343);
            match(TParser::NEWLINE);
            setState(344);
            match(TParser::NEWLINE);
            break;
          }

          case TParser::IMPORT: {
            setState(345);
            importStatement();
            setState(346);
            match(TParser::NEWLINE);
            break;
          }

        default:
          throw NoViableAltException(this);
        } 
      }
      setState(352);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForwardDeclarationContext ------------------------------------------------------------------

TParser::ForwardDeclarationContext::ForwardDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TParser::ForwardDeclarationContext::EXT() {
  return getToken(TParser::EXT, 0);
}

TParser::ProcedureNameContext* TParser::ForwardDeclarationContext::procedureName() {
  return getRuleContext<TParser::ProcedureNameContext>(0);
}

TParser::FormalParametersWithTypeContext* TParser::ForwardDeclarationContext::formalParametersWithType() {
  return getRuleContext<TParser::FormalParametersWithTypeContext>(0);
}

tree::TerminalNode* TParser::ForwardDeclarationContext::EXTFCT() {
  return getToken(TParser::EXTFCT, 0);
}

TParser::TypeContext* TParser::ForwardDeclarationContext::type() {
  return getRuleContext<TParser::TypeContext>(0);
}

TParser::FunctionNameContext* TParser::ForwardDeclarationContext::functionName() {
  return getRuleContext<TParser::FunctionNameContext>(0);
}


size_t TParser::ForwardDeclarationContext::getRuleIndex() const {
  return TParser::RuleForwardDeclaration;
}

void TParser::ForwardDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForwardDeclaration(this);
}

void TParser::ForwardDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForwardDeclaration(this);
}


antlrcpp::Any TParser::ForwardDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitForwardDeclaration(this);
  else
    return visitor->visitChildren(this);
}

TParser::ForwardDeclarationContext* TParser::forwardDeclaration() {
  ForwardDeclarationContext *_localctx = _tracker.createInstance<ForwardDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 56, TParser::RuleForwardDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(362);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TParser::EXT: {
        enterOuterAlt(_localctx, 1);
        setState(353);
        match(TParser::EXT);
        setState(354);
        procedureName();
        setState(355);
        formalParametersWithType();
        break;
      }

      case TParser::EXTFCT: {
        enterOuterAlt(_localctx, 2);
        setState(357);
        match(TParser::EXTFCT);
        setState(358);
        type();
        setState(359);
        functionName();
        setState(360);
        formalParametersWithType();
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

//----------------- FormalParametersWithTypeContext ------------------------------------------------------------------

TParser::FormalParametersWithTypeContext::FormalParametersWithTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TParser::FormalParametersWithTypeContext::LPAREN() {
  return getToken(TParser::LPAREN, 0);
}

tree::TerminalNode* TParser::FormalParametersWithTypeContext::RPAREN() {
  return getToken(TParser::RPAREN, 0);
}

std::vector<TParser::ParameterWithTypeContext *> TParser::FormalParametersWithTypeContext::parameterWithType() {
  return getRuleContexts<TParser::ParameterWithTypeContext>();
}

TParser::ParameterWithTypeContext* TParser::FormalParametersWithTypeContext::parameterWithType(size_t i) {
  return getRuleContext<TParser::ParameterWithTypeContext>(i);
}

std::vector<tree::TerminalNode *> TParser::FormalParametersWithTypeContext::COMMA() {
  return getTokens(TParser::COMMA);
}

tree::TerminalNode* TParser::FormalParametersWithTypeContext::COMMA(size_t i) {
  return getToken(TParser::COMMA, i);
}


size_t TParser::FormalParametersWithTypeContext::getRuleIndex() const {
  return TParser::RuleFormalParametersWithType;
}

void TParser::FormalParametersWithTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFormalParametersWithType(this);
}

void TParser::FormalParametersWithTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFormalParametersWithType(this);
}


antlrcpp::Any TParser::FormalParametersWithTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitFormalParametersWithType(this);
  else
    return visitor->visitChildren(this);
}

TParser::FormalParametersWithTypeContext* TParser::formalParametersWithType() {
  FormalParametersWithTypeContext *_localctx = _tracker.createInstance<FormalParametersWithTypeContext>(_ctx, getState());
  enterRule(_localctx, 58, TParser::RuleFormalParametersWithType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(364);
    match(TParser::LPAREN);
    setState(373);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TParser::BOOL

    || _la == TParser::CHAR || ((((_la - 75) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 75)) & ((1ULL << (TParser::INT - 75))
      | (1ULL << (TParser::REAL - 75))
      | (1ULL << (TParser::IDENTIFIER - 75)))) != 0)) {
      setState(365);
      parameterWithType();
      setState(370);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TParser::COMMA) {
        setState(366);
        match(TParser::COMMA);
        setState(367);
        parameterWithType();
        setState(372);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(375);
    match(TParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterWithTypeContext ------------------------------------------------------------------

TParser::ParameterWithTypeContext::ParameterWithTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TParser::TypeContext* TParser::ParameterWithTypeContext::type() {
  return getRuleContext<TParser::TypeContext>(0);
}

TParser::ParameterCallTypeContext* TParser::ParameterWithTypeContext::parameterCallType() {
  return getRuleContext<TParser::ParameterCallTypeContext>(0);
}


size_t TParser::ParameterWithTypeContext::getRuleIndex() const {
  return TParser::RuleParameterWithType;
}

void TParser::ParameterWithTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameterWithType(this);
}

void TParser::ParameterWithTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameterWithType(this);
}


antlrcpp::Any TParser::ParameterWithTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitParameterWithType(this);
  else
    return visitor->visitChildren(this);
}

TParser::ParameterWithTypeContext* TParser::parameterWithType() {
  ParameterWithTypeContext *_localctx = _tracker.createInstance<ParameterWithTypeContext>(_ctx, getState());
  enterRule(_localctx, 60, TParser::RuleParameterWithType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(377);
    type();
    setState(379);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TParser::COLON) {
      setState(378);
      parameterCallType();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterCallTypeContext ------------------------------------------------------------------

TParser::ParameterCallTypeContext::ParameterCallTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TParser::ParameterCallTypeContext::COLON() {
  return getToken(TParser::COLON, 0);
}

tree::TerminalNode* TParser::ParameterCallTypeContext::IDENTIFIER() {
  return getToken(TParser::IDENTIFIER, 0);
}


size_t TParser::ParameterCallTypeContext::getRuleIndex() const {
  return TParser::RuleParameterCallType;
}

void TParser::ParameterCallTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameterCallType(this);
}

void TParser::ParameterCallTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameterCallType(this);
}


antlrcpp::Any TParser::ParameterCallTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitParameterCallType(this);
  else
    return visitor->visitChildren(this);
}

TParser::ParameterCallTypeContext* TParser::parameterCallType() {
  ParameterCallTypeContext *_localctx = _tracker.createInstance<ParameterCallTypeContext>(_ctx, getState());
  enterRule(_localctx, 62, TParser::RuleParameterCallType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(381);
    match(TParser::COLON);
    setState(382);
    match(TParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ImportStatementContext ------------------------------------------------------------------

TParser::ImportStatementContext::ImportStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TParser::ImportStatementContext::IMPORT() {
  return getToken(TParser::IMPORT, 0);
}

TParser::TypeContext* TParser::ImportStatementContext::type() {
  return getRuleContext<TParser::TypeContext>(0);
}

std::vector<TParser::VariableNameContext *> TParser::ImportStatementContext::variableName() {
  return getRuleContexts<TParser::VariableNameContext>();
}

TParser::VariableNameContext* TParser::ImportStatementContext::variableName(size_t i) {
  return getRuleContext<TParser::VariableNameContext>(i);
}

tree::TerminalNode* TParser::ImportStatementContext::IS() {
  return getToken(TParser::IS, 0);
}

tree::TerminalNode* TParser::ImportStatementContext::R1() {
  return getToken(TParser::R1, 0);
}

TParser::ModuleNameContext* TParser::ImportStatementContext::moduleName() {
  return getRuleContext<TParser::ModuleNameContext>(0);
}

tree::TerminalNode* TParser::ImportStatementContext::DIERESIS() {
  return getToken(TParser::DIERESIS, 0);
}


size_t TParser::ImportStatementContext::getRuleIndex() const {
  return TParser::RuleImportStatement;
}

void TParser::ImportStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportStatement(this);
}

void TParser::ImportStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportStatement(this);
}


antlrcpp::Any TParser::ImportStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitImportStatement(this);
  else
    return visitor->visitChildren(this);
}

TParser::ImportStatementContext* TParser::importStatement() {
  ImportStatementContext *_localctx = _tracker.createInstance<ImportStatementContext>(_ctx, getState());
  enterRule(_localctx, 64, TParser::RuleImportStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(384);
    match(TParser::IMPORT);
    setState(385);
    type();
    setState(386);
    variableName();
    setState(387);
    match(TParser::IS);
    setState(388);
    match(TParser::R1);
    setState(389);
    moduleName();
    setState(390);
    match(TParser::DIERESIS);
    setState(391);
    variableName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableNameContext ------------------------------------------------------------------

TParser::VariableNameContext::VariableNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TParser::VariableNameContext::IDENTIFIER() {
  return getToken(TParser::IDENTIFIER, 0);
}

TParser::ArrayVariableSuffixContext* TParser::VariableNameContext::arrayVariableSuffix() {
  return getRuleContext<TParser::ArrayVariableSuffixContext>(0);
}


size_t TParser::VariableNameContext::getRuleIndex() const {
  return TParser::RuleVariableName;
}

void TParser::VariableNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariableName(this);
}

void TParser::VariableNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariableName(this);
}


antlrcpp::Any TParser::VariableNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitVariableName(this);
  else
    return visitor->visitChildren(this);
}

TParser::VariableNameContext* TParser::variableName() {
  VariableNameContext *_localctx = _tracker.createInstance<VariableNameContext>(_ctx, getState());
  enterRule(_localctx, 66, TParser::RuleVariableName);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(393);
    match(TParser::IDENTIFIER);
    setState(395);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TParser::LBRACK) {
      setState(394);
      arrayVariableSuffix();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayVariableSuffixContext ------------------------------------------------------------------

TParser::ArrayVariableSuffixContext::ArrayVariableSuffixContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TParser::ArrayVariableSuffixContext::LBRACK() {
  return getToken(TParser::LBRACK, 0);
}

tree::TerminalNode* TParser::ArrayVariableSuffixContext::RBRACK() {
  return getToken(TParser::RBRACK, 0);
}

std::vector<TParser::ExpressionContext *> TParser::ArrayVariableSuffixContext::expression() {
  return getRuleContexts<TParser::ExpressionContext>();
}

TParser::ExpressionContext* TParser::ArrayVariableSuffixContext::expression(size_t i) {
  return getRuleContext<TParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> TParser::ArrayVariableSuffixContext::COMMA() {
  return getTokens(TParser::COMMA);
}

tree::TerminalNode* TParser::ArrayVariableSuffixContext::COMMA(size_t i) {
  return getToken(TParser::COMMA, i);
}


size_t TParser::ArrayVariableSuffixContext::getRuleIndex() const {
  return TParser::RuleArrayVariableSuffix;
}

void TParser::ArrayVariableSuffixContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayVariableSuffix(this);
}

void TParser::ArrayVariableSuffixContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayVariableSuffix(this);
}


antlrcpp::Any TParser::ArrayVariableSuffixContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitArrayVariableSuffix(this);
  else
    return visitor->visitChildren(this);
}

TParser::ArrayVariableSuffixContext* TParser::arrayVariableSuffix() {
  ArrayVariableSuffixContext *_localctx = _tracker.createInstance<ArrayVariableSuffixContext>(_ctx, getState());
  enterRule(_localctx, 68, TParser::RuleArrayVariableSuffix);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(397);
    match(TParser::LBRACK);
    setState(411);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << TParser::LPAREN)
      | (1ULL << TParser::LBRACE)
      | (1ULL << TParser::ADD)
      | (1ULL << TParser::SUB)
      | (1ULL << TParser::NUMBER)
      | (1ULL << TParser::B_NOT))) != 0) || ((((_la - 67) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 67)) & ((1ULL << (TParser::FALSE - 67))
      | (1ULL << (TParser::NOT - 67))
      | (1ULL << (TParser::TRUE - 67))
      | (1ULL << (TParser::CHARLITERAL - 67))
      | (1ULL << (TParser::STRINGLITERAL - 67))
      | (1ULL << (TParser::FLOATLITERAL - 67))
      | (1ULL << (TParser::INTLITERAL - 67))
      | (1ULL << (TParser::IDENTIFIER - 67)))) != 0)) {
      setState(398);
      expression();
      setState(409);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == TParser::COMMA) {
        setState(399);
        match(TParser::COMMA);
        setState(407);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << TParser::LPAREN)
          | (1ULL << TParser::LBRACE)
          | (1ULL << TParser::ADD)
          | (1ULL << TParser::SUB)
          | (1ULL << TParser::NUMBER)
          | (1ULL << TParser::B_NOT))) != 0) || ((((_la - 67) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 67)) & ((1ULL << (TParser::FALSE - 67))
          | (1ULL << (TParser::NOT - 67))
          | (1ULL << (TParser::TRUE - 67))
          | (1ULL << (TParser::CHARLITERAL - 67))
          | (1ULL << (TParser::STRINGLITERAL - 67))
          | (1ULL << (TParser::FLOATLITERAL - 67))
          | (1ULL << (TParser::INTLITERAL - 67))
          | (1ULL << (TParser::IDENTIFIER - 67)))) != 0)) {
          setState(400);
          expression();
          setState(405);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == TParser::COMMA) {
            setState(401);
            match(TParser::COMMA);
            setState(403);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if ((((_la & ~ 0x3fULL) == 0) &&
              ((1ULL << _la) & ((1ULL << TParser::LPAREN)
              | (1ULL << TParser::LBRACE)
              | (1ULL << TParser::ADD)
              | (1ULL << TParser::SUB)
              | (1ULL << TParser::NUMBER)
              | (1ULL << TParser::B_NOT))) != 0) || ((((_la - 67) & ~ 0x3fULL) == 0) &&
              ((1ULL << (_la - 67)) & ((1ULL << (TParser::FALSE - 67))
              | (1ULL << (TParser::NOT - 67))
              | (1ULL << (TParser::TRUE - 67))
              | (1ULL << (TParser::CHARLITERAL - 67))
              | (1ULL << (TParser::STRINGLITERAL - 67))
              | (1ULL << (TParser::FLOATLITERAL - 67))
              | (1ULL << (TParser::INTLITERAL - 67))
              | (1ULL << (TParser::IDENTIFIER - 67)))) != 0)) {
              setState(402);
              expression();
            }
          }
        }
      }
    }
    setState(413);
    match(TParser::RBRACK);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RoutineImplementationSectionContext ------------------------------------------------------------------

TParser::RoutineImplementationSectionContext::RoutineImplementationSectionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TParser::StatementListContext* TParser::RoutineImplementationSectionContext::statementList() {
  return getRuleContext<TParser::StatementListContext>(0);
}


size_t TParser::RoutineImplementationSectionContext::getRuleIndex() const {
  return TParser::RuleRoutineImplementationSection;
}

void TParser::RoutineImplementationSectionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRoutineImplementationSection(this);
}

void TParser::RoutineImplementationSectionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRoutineImplementationSection(this);
}


antlrcpp::Any TParser::RoutineImplementationSectionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitRoutineImplementationSection(this);
  else
    return visitor->visitChildren(this);
}

TParser::RoutineImplementationSectionContext* TParser::routineImplementationSection() {
  RoutineImplementationSectionContext *_localctx = _tracker.createInstance<RoutineImplementationSectionContext>(_ctx, getState());
  enterRule(_localctx, 70, TParser::RuleRoutineImplementationSection);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(415);
    statementList();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementListContext ------------------------------------------------------------------

TParser::StatementListContext::StatementListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TParser::StatementContext *> TParser::StatementListContext::statement() {
  return getRuleContexts<TParser::StatementContext>();
}

TParser::StatementContext* TParser::StatementListContext::statement(size_t i) {
  return getRuleContext<TParser::StatementContext>(i);
}


size_t TParser::StatementListContext::getRuleIndex() const {
  return TParser::RuleStatementList;
}

void TParser::StatementListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatementList(this);
}

void TParser::StatementListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatementList(this);
}


antlrcpp::Any TParser::StatementListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitStatementList(this);
  else
    return visitor->visitChildren(this);
}

TParser::StatementListContext* TParser::statementList() {
  StatementListContext *_localctx = _tracker.createInstance<StatementListContext>(_ctx, getState());
  enterRule(_localctx, 72, TParser::RuleStatementList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(420);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << TParser::LPAREN)
      | (1ULL << TParser::LBRACE)
      | (1ULL << TParser::ADD)
      | (1ULL << TParser::SUB)
      | (1ULL << TParser::NUMBER)
      | (1ULL << TParser::ANIN)
      | (1ULL << TParser::ANOUT)
      | (1ULL << TParser::B_NOT)
      | (1ULL << TParser::BRAKE)
      | (1ULL << TParser::CIRC_REL)
      | (1ULL << TParser::CIRC)
      | (1ULL << TParser::CONTINUE))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (TParser::EXIT - 64))
      | (1ULL << (TParser::FALSE - 64))
      | (1ULL << (TParser::FOR - 64))
      | (1ULL << (TParser::GLOBAL - 64))
      | (1ULL << (TParser::GOTO - 64))
      | (1ULL << (TParser::HALT - 64))
      | (1ULL << (TParser::IF - 64))
      | (1ULL << (TParser::INTERRUPT - 64))
      | (1ULL << (TParser::LIN_REL - 64))
      | (1ULL << (TParser::LIN - 64))
      | (1ULL << (TParser::LOOP - 64))
      | (1ULL << (TParser::NOT - 64))
      | (1ULL << (TParser::PTP_REL - 64))
      | (1ULL << (TParser::PTP - 64))
      | (1ULL << (TParser::REPEAT - 64))
      | (1ULL << (TParser::RETURN - 64))
      | (1ULL << (TParser::SWITCH - 64))
      | (1ULL << (TParser::TRIGGER - 64))
      | (1ULL << (TParser::TRUE - 64))
      | (1ULL << (TParser::WAIT - 64))
      | (1ULL << (TParser::WHILE - 64))
      | (1ULL << (TParser::NEWLINE - 64))
      | (1ULL << (TParser::CHARLITERAL - 64))
      | (1ULL << (TParser::STRINGLITERAL - 64))
      | (1ULL << (TParser::FLOATLITERAL - 64))
      | (1ULL << (TParser::INTLITERAL - 64))
      | (1ULL << (TParser::IDENTIFIER - 64)))) != 0)) {
      setState(417);
      statement();
      setState(422);
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

//----------------- StatementContext ------------------------------------------------------------------

TParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TParser::StatementContext::CONTINUE() {
  return getToken(TParser::CONTINUE, 0);
}

std::vector<tree::TerminalNode *> TParser::StatementContext::NEWLINE() {
  return getTokens(TParser::NEWLINE);
}

tree::TerminalNode* TParser::StatementContext::NEWLINE(size_t i) {
  return getToken(TParser::NEWLINE, i);
}

tree::TerminalNode* TParser::StatementContext::EXIT() {
  return getToken(TParser::EXIT, 0);
}

tree::TerminalNode* TParser::StatementContext::FOR() {
  return getToken(TParser::FOR, 0);
}

std::vector<tree::TerminalNode *> TParser::StatementContext::IDENTIFIER() {
  return getTokens(TParser::IDENTIFIER);
}

tree::TerminalNode* TParser::StatementContext::IDENTIFIER(size_t i) {
  return getToken(TParser::IDENTIFIER, i);
}

std::vector<tree::TerminalNode *> TParser::StatementContext::ASSIGN() {
  return getTokens(TParser::ASSIGN);
}

tree::TerminalNode* TParser::StatementContext::ASSIGN(size_t i) {
  return getToken(TParser::ASSIGN, i);
}

std::vector<TParser::ExpressionContext *> TParser::StatementContext::expression() {
  return getRuleContexts<TParser::ExpressionContext>();
}

TParser::ExpressionContext* TParser::StatementContext::expression(size_t i) {
  return getRuleContext<TParser::ExpressionContext>(i);
}

tree::TerminalNode* TParser::StatementContext::TO() {
  return getToken(TParser::TO, 0);
}

std::vector<TParser::StatementListContext *> TParser::StatementContext::statementList() {
  return getRuleContexts<TParser::StatementListContext>();
}

TParser::StatementListContext* TParser::StatementContext::statementList(size_t i) {
  return getRuleContext<TParser::StatementListContext>(i);
}

tree::TerminalNode* TParser::StatementContext::ENDFOR() {
  return getToken(TParser::ENDFOR, 0);
}

tree::TerminalNode* TParser::StatementContext::GOTO() {
  return getToken(TParser::GOTO, 0);
}

tree::TerminalNode* TParser::StatementContext::HALT() {
  return getToken(TParser::HALT, 0);
}

tree::TerminalNode* TParser::StatementContext::IF() {
  return getToken(TParser::IF, 0);
}

tree::TerminalNode* TParser::StatementContext::THEN() {
  return getToken(TParser::THEN, 0);
}

tree::TerminalNode* TParser::StatementContext::ENDIF() {
  return getToken(TParser::ENDIF, 0);
}

tree::TerminalNode* TParser::StatementContext::ELSE() {
  return getToken(TParser::ELSE, 0);
}

tree::TerminalNode* TParser::StatementContext::LOOP() {
  return getToken(TParser::LOOP, 0);
}

tree::TerminalNode* TParser::StatementContext::ENDLOOP() {
  return getToken(TParser::ENDLOOP, 0);
}

tree::TerminalNode* TParser::StatementContext::REPEAT() {
  return getToken(TParser::REPEAT, 0);
}

tree::TerminalNode* TParser::StatementContext::UNTIL() {
  return getToken(TParser::UNTIL, 0);
}

tree::TerminalNode* TParser::StatementContext::SWITCH() {
  return getToken(TParser::SWITCH, 0);
}

TParser::SwitchBlockStatementGroupsContext* TParser::StatementContext::switchBlockStatementGroups() {
  return getRuleContext<TParser::SwitchBlockStatementGroupsContext>(0);
}

tree::TerminalNode* TParser::StatementContext::ENDSWITCH() {
  return getToken(TParser::ENDSWITCH, 0);
}

tree::TerminalNode* TParser::StatementContext::WAIT() {
  return getToken(TParser::WAIT, 0);
}

tree::TerminalNode* TParser::StatementContext::SEC() {
  return getToken(TParser::SEC, 0);
}

tree::TerminalNode* TParser::StatementContext::WHILE() {
  return getToken(TParser::WHILE, 0);
}

tree::TerminalNode* TParser::StatementContext::ENDWHILE() {
  return getToken(TParser::ENDWHILE, 0);
}

tree::TerminalNode* TParser::StatementContext::RETURN() {
  return getToken(TParser::RETURN, 0);
}

TParser::AssignmentExpressionContext* TParser::StatementContext::assignmentExpression() {
  return getRuleContext<TParser::AssignmentExpressionContext>(0);
}

tree::TerminalNode* TParser::StatementContext::BRAKE() {
  return getToken(TParser::BRAKE, 0);
}

tree::TerminalNode* TParser::StatementContext::COLON() {
  return getToken(TParser::COLON, 0);
}

tree::TerminalNode* TParser::StatementContext::INTERRUPT() {
  return getToken(TParser::INTERRUPT, 0);
}

tree::TerminalNode* TParser::StatementContext::DECL() {
  return getToken(TParser::DECL, 0);
}

TParser::PrimaryContext* TParser::StatementContext::primary() {
  return getRuleContext<TParser::PrimaryContext>(0);
}

tree::TerminalNode* TParser::StatementContext::WHEN() {
  return getToken(TParser::WHEN, 0);
}

tree::TerminalNode* TParser::StatementContext::DO() {
  return getToken(TParser::DO, 0);
}

tree::TerminalNode* TParser::StatementContext::GLOBAL() {
  return getToken(TParser::GLOBAL, 0);
}

std::vector<TParser::GeometricExpressionContext *> TParser::StatementContext::geometricExpression() {
  return getRuleContexts<TParser::GeometricExpressionContext>();
}

TParser::GeometricExpressionContext* TParser::StatementContext::geometricExpression(size_t i) {
  return getRuleContext<TParser::GeometricExpressionContext>(i);
}

tree::TerminalNode* TParser::StatementContext::PTP() {
  return getToken(TParser::PTP, 0);
}

tree::TerminalNode* TParser::StatementContext::PTP_REL() {
  return getToken(TParser::PTP_REL, 0);
}

tree::TerminalNode* TParser::StatementContext::C_PTP() {
  return getToken(TParser::C_PTP, 0);
}

tree::TerminalNode* TParser::StatementContext::C_DIS() {
  return getToken(TParser::C_DIS, 0);
}

tree::TerminalNode* TParser::StatementContext::C_ORI() {
  return getToken(TParser::C_ORI, 0);
}

tree::TerminalNode* TParser::StatementContext::C_VEL() {
  return getToken(TParser::C_VEL, 0);
}

tree::TerminalNode* TParser::StatementContext::LIN() {
  return getToken(TParser::LIN, 0);
}

tree::TerminalNode* TParser::StatementContext::LIN_REL() {
  return getToken(TParser::LIN_REL, 0);
}

TParser::EnumElementContext* TParser::StatementContext::enumElement() {
  return getRuleContext<TParser::EnumElementContext>(0);
}

std::vector<tree::TerminalNode *> TParser::StatementContext::COMMA() {
  return getTokens(TParser::COMMA);
}

tree::TerminalNode* TParser::StatementContext::COMMA(size_t i) {
  return getToken(TParser::COMMA, i);
}

tree::TerminalNode* TParser::StatementContext::CIRC() {
  return getToken(TParser::CIRC, 0);
}

tree::TerminalNode* TParser::StatementContext::CIRC_REL() {
  return getToken(TParser::CIRC_REL, 0);
}

tree::TerminalNode* TParser::StatementContext::TRIGGER() {
  return getToken(TParser::TRIGGER, 0);
}

tree::TerminalNode* TParser::StatementContext::DELAY() {
  return getToken(TParser::DELAY, 0);
}

tree::TerminalNode* TParser::StatementContext::PRIO() {
  return getToken(TParser::PRIO, 0);
}

TParser::AnalogInputStatementContext* TParser::StatementContext::analogInputStatement() {
  return getRuleContext<TParser::AnalogInputStatementContext>(0);
}

TParser::AnalogOutputStatementContext* TParser::StatementContext::analogOutputStatement() {
  return getRuleContext<TParser::AnalogOutputStatementContext>(0);
}


size_t TParser::StatementContext::getRuleIndex() const {
  return TParser::RuleStatement;
}

void TParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void TParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}


antlrcpp::Any TParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

TParser::StatementContext* TParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 74, TParser::RuleStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(595);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 57, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(423);
      match(TParser::CONTINUE);
      setState(424);
      match(TParser::NEWLINE);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(425);
      match(TParser::EXIT);
      setState(426);
      match(TParser::NEWLINE);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(427);
      match(TParser::FOR);
      setState(428);
      match(TParser::IDENTIFIER);
      setState(429);
      match(TParser::ASSIGN);
      setState(430);
      expression();
      setState(431);
      match(TParser::TO);
      setState(432);
      expression();
      setState(435);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == TParser::IDENTIFIER) {
        setState(433);
        match(TParser::IDENTIFIER);
        setState(434);
        expression();
      }
      setState(437);
      match(TParser::NEWLINE);
      setState(438);
      statementList();
      setState(439);
      match(TParser::ENDFOR);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(441);
      match(TParser::GOTO);
      setState(442);
      match(TParser::IDENTIFIER);
      setState(443);
      match(TParser::NEWLINE);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(444);
      match(TParser::HALT);
      setState(445);
      match(TParser::NEWLINE);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(446);
      match(TParser::IF);
      setState(447);
      expression();
      setState(448);
      match(TParser::THEN);
      setState(449);
      match(TParser::NEWLINE);
      setState(450);
      statementList();
      setState(454);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == TParser::ELSE) {
        setState(451);
        match(TParser::ELSE);
        setState(452);
        match(TParser::NEWLINE);
        setState(453);
        statementList();
      }
      setState(456);
      match(TParser::ENDIF);
      setState(457);
      match(TParser::NEWLINE);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(459);
      match(TParser::LOOP);
      setState(460);
      match(TParser::NEWLINE);
      setState(461);
      statementList();
      setState(462);
      match(TParser::ENDLOOP);
      setState(463);
      match(TParser::NEWLINE);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(465);
      match(TParser::REPEAT);
      setState(466);
      match(TParser::NEWLINE);
      setState(467);
      statementList();
      setState(468);
      match(TParser::UNTIL);
      setState(469);
      expression();
      setState(470);
      match(TParser::NEWLINE);
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(472);
      match(TParser::SWITCH);
      setState(473);
      expression();
      setState(474);
      match(TParser::NEWLINE);
      setState(475);
      switchBlockStatementGroups();
      setState(476);
      match(TParser::ENDSWITCH);
      setState(477);
      match(TParser::NEWLINE);
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(479);
      match(TParser::WAIT);
      setState(480);
      match(TParser::FOR);
      setState(481);
      expression();
      setState(482);
      match(TParser::NEWLINE);
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(484);
      match(TParser::WAIT);
      setState(485);
      match(TParser::SEC);
      setState(486);
      expression();
      setState(487);
      match(TParser::NEWLINE);
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(489);
      match(TParser::WHILE);
      setState(490);
      expression();
      setState(491);
      match(TParser::NEWLINE);
      setState(492);
      statementList();
      setState(493);
      match(TParser::ENDWHILE);
      setState(494);
      match(TParser::NEWLINE);
      break;
    }

    case 13: {
      enterOuterAlt(_localctx, 13);
      setState(496);
      match(TParser::RETURN);
      setState(498);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << TParser::LPAREN)
        | (1ULL << TParser::LBRACE)
        | (1ULL << TParser::ADD)
        | (1ULL << TParser::SUB)
        | (1ULL << TParser::NUMBER)
        | (1ULL << TParser::B_NOT))) != 0) || ((((_la - 67) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 67)) & ((1ULL << (TParser::FALSE - 67))
        | (1ULL << (TParser::NOT - 67))
        | (1ULL << (TParser::TRUE - 67))
        | (1ULL << (TParser::CHARLITERAL - 67))
        | (1ULL << (TParser::STRINGLITERAL - 67))
        | (1ULL << (TParser::FLOATLITERAL - 67))
        | (1ULL << (TParser::INTLITERAL - 67))
        | (1ULL << (TParser::IDENTIFIER - 67)))) != 0)) {
        setState(497);
        assignmentExpression();
      }
      setState(500);
      match(TParser::NEWLINE);
      break;
    }

    case 14: {
      enterOuterAlt(_localctx, 14);
      setState(501);
      match(TParser::BRAKE);
      setState(503);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == TParser::IDENTIFIER) {
        setState(502);
        match(TParser::IDENTIFIER);
      }
      setState(505);
      match(TParser::NEWLINE);
      break;
    }

    case 15: {
      enterOuterAlt(_localctx, 15);
      setState(506);
      assignmentExpression();
      setState(507);
      match(TParser::NEWLINE);
      break;
    }

    case 16: {
      enterOuterAlt(_localctx, 16);
      setState(509);
      match(TParser::IDENTIFIER);
      setState(510);
      match(TParser::COLON);
      setState(511);
      match(TParser::NEWLINE);
      break;
    }

    case 17: {
      enterOuterAlt(_localctx, 17);
      setState(512);
      match(TParser::NEWLINE);
      break;
    }

    case 18: {
      enterOuterAlt(_localctx, 18);
      setState(514);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == TParser::GLOBAL) {
        setState(513);
        match(TParser::GLOBAL);
      }
      setState(516);
      match(TParser::INTERRUPT);
      setState(517);
      match(TParser::DECL);
      setState(518);
      primary();
      setState(519);
      match(TParser::WHEN);
      setState(520);
      expression();
      setState(521);
      match(TParser::DO);
      setState(522);
      assignmentExpression();
      setState(523);
      match(TParser::NEWLINE);
      break;
    }

    case 19: {
      enterOuterAlt(_localctx, 19);
      setState(525);
      match(TParser::INTERRUPT);
      setState(526);
      match(TParser::IDENTIFIER);
      setState(528);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << TParser::LPAREN)
        | (1ULL << TParser::LBRACE)
        | (1ULL << TParser::NUMBER))) != 0) || ((((_la - 67) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 67)) & ((1ULL << (TParser::FALSE - 67))
        | (1ULL << (TParser::TRUE - 67))
        | (1ULL << (TParser::CHARLITERAL - 67))
        | (1ULL << (TParser::STRINGLITERAL - 67))
        | (1ULL << (TParser::FLOATLITERAL - 67))
        | (1ULL << (TParser::INTLITERAL - 67))
        | (1ULL << (TParser::IDENTIFIER - 67)))) != 0)) {
        setState(527);
        primary();
      }
      setState(530);
      match(TParser::NEWLINE);
      break;
    }

    case 20: {
      enterOuterAlt(_localctx, 20);
      setState(531);
      _la = _input->LA(1);
      if (!(_la == TParser::PTP_REL

      || _la == TParser::PTP)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(532);
      geometricExpression();
      setState(537);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == TParser::C_PTP) {
        setState(533);
        match(TParser::C_PTP);
        setState(535);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << TParser::C_DIS)
          | (1ULL << TParser::C_ORI)
          | (1ULL << TParser::C_VEL))) != 0)) {
          setState(534);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << TParser::C_DIS)
            | (1ULL << TParser::C_ORI)
            | (1ULL << TParser::C_VEL))) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
        }
      }
      setState(539);
      match(TParser::NEWLINE);
      break;
    }

    case 21: {
      enterOuterAlt(_localctx, 21);
      setState(541);
      match(TParser::LIN);
      setState(542);
      geometricExpression();
      setState(544);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << TParser::C_DIS)
        | (1ULL << TParser::C_ORI)
        | (1ULL << TParser::C_VEL))) != 0)) {
        setState(543);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << TParser::C_DIS)
          | (1ULL << TParser::C_ORI)
          | (1ULL << TParser::C_VEL))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
      }
      setState(546);
      match(TParser::NEWLINE);
      break;
    }

    case 22: {
      enterOuterAlt(_localctx, 22);
      setState(548);
      match(TParser::LIN_REL);
      setState(549);
      geometricExpression();
      setState(551);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << TParser::C_DIS)
        | (1ULL << TParser::C_ORI)
        | (1ULL << TParser::C_VEL))) != 0)) {
        setState(550);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << TParser::C_DIS)
          | (1ULL << TParser::C_ORI)
          | (1ULL << TParser::C_VEL))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
      }
      setState(554);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == TParser::NUMBER) {
        setState(553);
        enumElement();
      }
      setState(556);
      match(TParser::NEWLINE);
      break;
    }

    case 23: {
      enterOuterAlt(_localctx, 23);
      setState(558);
      _la = _input->LA(1);
      if (!(_la == TParser::CIRC_REL

      || _la == TParser::CIRC)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(559);
      geometricExpression();
      setState(560);
      match(TParser::COMMA);
      setState(561);
      geometricExpression();
      setState(565);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == TParser::COMMA) {
        setState(562);
        match(TParser::COMMA);
        setState(563);
        match(TParser::IDENTIFIER);
        setState(564);
        primary();
      }
      setState(568);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << TParser::C_DIS)
        | (1ULL << TParser::C_ORI)
        | (1ULL << TParser::C_VEL))) != 0)) {
        setState(567);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << TParser::C_DIS)
          | (1ULL << TParser::C_ORI)
          | (1ULL << TParser::C_VEL))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
      }
      setState(570);
      match(TParser::NEWLINE);
      break;
    }

    case 24: {
      enterOuterAlt(_localctx, 24);
      setState(572);
      match(TParser::TRIGGER);
      setState(573);
      match(TParser::WHEN);

      setState(574);
      match(TParser::IDENTIFIER);
      setState(575);
      match(TParser::ASSIGN);
      setState(576);
      expression();
      setState(577);
      match(TParser::DELAY);
      setState(578);
      match(TParser::ASSIGN);
      setState(579);
      expression();
      setState(580);
      match(TParser::DO);
      setState(581);
      assignmentExpression();
      setState(585);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == TParser::PRIO) {
        setState(582);
        match(TParser::PRIO);
        setState(583);
        match(TParser::ASSIGN);
        setState(584);
        expression();
      }
      setState(587);
      match(TParser::NEWLINE);
      break;
    }

    case 25: {
      enterOuterAlt(_localctx, 25);
      setState(589);
      analogInputStatement();
      setState(590);
      match(TParser::NEWLINE);
      break;
    }

    case 26: {
      enterOuterAlt(_localctx, 26);
      setState(592);
      analogOutputStatement();
      setState(593);
      match(TParser::NEWLINE);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AnalogOutputStatementContext ------------------------------------------------------------------

TParser::AnalogOutputStatementContext::AnalogOutputStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TParser::AnalogOutputStatementContext::ANOUT() {
  return getToken(TParser::ANOUT, 0);
}

std::vector<tree::TerminalNode *> TParser::AnalogOutputStatementContext::IDENTIFIER() {
  return getTokens(TParser::IDENTIFIER);
}

tree::TerminalNode* TParser::AnalogOutputStatementContext::IDENTIFIER(size_t i) {
  return getToken(TParser::IDENTIFIER, i);
}

TParser::AssignmentExpressionContext* TParser::AnalogOutputStatementContext::assignmentExpression() {
  return getRuleContext<TParser::AssignmentExpressionContext>(0);
}

std::vector<tree::TerminalNode *> TParser::AnalogOutputStatementContext::ASSIGN() {
  return getTokens(TParser::ASSIGN);
}

tree::TerminalNode* TParser::AnalogOutputStatementContext::ASSIGN(size_t i) {
  return getToken(TParser::ASSIGN, i);
}

std::vector<TParser::LiteralContext *> TParser::AnalogOutputStatementContext::literal() {
  return getRuleContexts<TParser::LiteralContext>();
}

TParser::LiteralContext* TParser::AnalogOutputStatementContext::literal(size_t i) {
  return getRuleContext<TParser::LiteralContext>(i);
}


size_t TParser::AnalogOutputStatementContext::getRuleIndex() const {
  return TParser::RuleAnalogOutputStatement;
}

void TParser::AnalogOutputStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAnalogOutputStatement(this);
}

void TParser::AnalogOutputStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAnalogOutputStatement(this);
}


antlrcpp::Any TParser::AnalogOutputStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitAnalogOutputStatement(this);
  else
    return visitor->visitChildren(this);
}

TParser::AnalogOutputStatementContext* TParser::analogOutputStatement() {
  AnalogOutputStatementContext *_localctx = _tracker.createInstance<AnalogOutputStatementContext>(_ctx, getState());
  enterRule(_localctx, 76, TParser::RuleAnalogOutputStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(597);
    match(TParser::ANOUT);
    setState(610);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 59, _ctx)) {
    case 1: {
      setState(598);
      match(TParser::IDENTIFIER);
      setState(599);
      assignmentExpression();
      setState(605);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TParser::IDENTIFIER) {
        setState(600);
        match(TParser::IDENTIFIER);
        setState(601);
        match(TParser::ASSIGN);
        setState(602);
        literal();
        setState(607);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      break;
    }

    case 2: {
      setState(608);
      match(TParser::IDENTIFIER);
      setState(609);
      match(TParser::IDENTIFIER);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AnalogInputStatementContext ------------------------------------------------------------------

TParser::AnalogInputStatementContext::AnalogInputStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TParser::AnalogInputStatementContext::ANIN() {
  return getToken(TParser::ANIN, 0);
}

std::vector<tree::TerminalNode *> TParser::AnalogInputStatementContext::IDENTIFIER() {
  return getTokens(TParser::IDENTIFIER);
}

tree::TerminalNode* TParser::AnalogInputStatementContext::IDENTIFIER(size_t i) {
  return getToken(TParser::IDENTIFIER, i);
}

TParser::AssignmentExpressionContext* TParser::AnalogInputStatementContext::assignmentExpression() {
  return getRuleContext<TParser::AssignmentExpressionContext>(0);
}


size_t TParser::AnalogInputStatementContext::getRuleIndex() const {
  return TParser::RuleAnalogInputStatement;
}

void TParser::AnalogInputStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAnalogInputStatement(this);
}

void TParser::AnalogInputStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAnalogInputStatement(this);
}


antlrcpp::Any TParser::AnalogInputStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitAnalogInputStatement(this);
  else
    return visitor->visitChildren(this);
}

TParser::AnalogInputStatementContext* TParser::analogInputStatement() {
  AnalogInputStatementContext *_localctx = _tracker.createInstance<AnalogInputStatementContext>(_ctx, getState());
  enterRule(_localctx, 78, TParser::RuleAnalogInputStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(612);
    match(TParser::ANIN);
    setState(617);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 60, _ctx)) {
    case 1: {
      setState(613);
      match(TParser::IDENTIFIER);
      setState(614);
      assignmentExpression();
      break;
    }

    case 2: {
      setState(615);
      match(TParser::IDENTIFIER);
      setState(616);
      match(TParser::IDENTIFIER);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SwitchBlockStatementGroupsContext ------------------------------------------------------------------

TParser::SwitchBlockStatementGroupsContext::SwitchBlockStatementGroupsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> TParser::SwitchBlockStatementGroupsContext::NEWLINE() {
  return getTokens(TParser::NEWLINE);
}

tree::TerminalNode* TParser::SwitchBlockStatementGroupsContext::NEWLINE(size_t i) {
  return getToken(TParser::NEWLINE, i);
}

std::vector<TParser::CaseLabelContext *> TParser::SwitchBlockStatementGroupsContext::caseLabel() {
  return getRuleContexts<TParser::CaseLabelContext>();
}

TParser::CaseLabelContext* TParser::SwitchBlockStatementGroupsContext::caseLabel(size_t i) {
  return getRuleContext<TParser::CaseLabelContext>(i);
}

std::vector<TParser::StatementListContext *> TParser::SwitchBlockStatementGroupsContext::statementList() {
  return getRuleContexts<TParser::StatementListContext>();
}

TParser::StatementListContext* TParser::SwitchBlockStatementGroupsContext::statementList(size_t i) {
  return getRuleContext<TParser::StatementListContext>(i);
}

TParser::DefaultLabelContext* TParser::SwitchBlockStatementGroupsContext::defaultLabel() {
  return getRuleContext<TParser::DefaultLabelContext>(0);
}


size_t TParser::SwitchBlockStatementGroupsContext::getRuleIndex() const {
  return TParser::RuleSwitchBlockStatementGroups;
}

void TParser::SwitchBlockStatementGroupsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSwitchBlockStatementGroups(this);
}

void TParser::SwitchBlockStatementGroupsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSwitchBlockStatementGroups(this);
}


antlrcpp::Any TParser::SwitchBlockStatementGroupsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitSwitchBlockStatementGroups(this);
  else
    return visitor->visitChildren(this);
}

TParser::SwitchBlockStatementGroupsContext* TParser::switchBlockStatementGroups() {
  SwitchBlockStatementGroupsContext *_localctx = _tracker.createInstance<SwitchBlockStatementGroupsContext>(_ctx, getState());
  enterRule(_localctx, 80, TParser::RuleSwitchBlockStatementGroups);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(622);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TParser::NEWLINE) {
      setState(619);
      match(TParser::NEWLINE);
      setState(624);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(628); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(625);
      caseLabel();
      setState(626);
      statementList();
      setState(630); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == TParser::CASE);
    setState(635);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TParser::DEFAULT) {
      setState(632);
      defaultLabel();
      setState(633);
      statementList();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CaseLabelContext ------------------------------------------------------------------

TParser::CaseLabelContext::CaseLabelContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TParser::CaseLabelContext::CASE() {
  return getToken(TParser::CASE, 0);
}

std::vector<TParser::ExpressionContext *> TParser::CaseLabelContext::expression() {
  return getRuleContexts<TParser::ExpressionContext>();
}

TParser::ExpressionContext* TParser::CaseLabelContext::expression(size_t i) {
  return getRuleContext<TParser::ExpressionContext>(i);
}

tree::TerminalNode* TParser::CaseLabelContext::NEWLINE() {
  return getToken(TParser::NEWLINE, 0);
}

std::vector<tree::TerminalNode *> TParser::CaseLabelContext::COMMA() {
  return getTokens(TParser::COMMA);
}

tree::TerminalNode* TParser::CaseLabelContext::COMMA(size_t i) {
  return getToken(TParser::COMMA, i);
}


size_t TParser::CaseLabelContext::getRuleIndex() const {
  return TParser::RuleCaseLabel;
}

void TParser::CaseLabelContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCaseLabel(this);
}

void TParser::CaseLabelContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCaseLabel(this);
}


antlrcpp::Any TParser::CaseLabelContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitCaseLabel(this);
  else
    return visitor->visitChildren(this);
}

TParser::CaseLabelContext* TParser::caseLabel() {
  CaseLabelContext *_localctx = _tracker.createInstance<CaseLabelContext>(_ctx, getState());
  enterRule(_localctx, 82, TParser::RuleCaseLabel);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(637);
    match(TParser::CASE);
    setState(638);
    expression();
    setState(643);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TParser::COMMA) {
      setState(639);
      match(TParser::COMMA);
      setState(640);
      expression();
      setState(645);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(646);
    match(TParser::NEWLINE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DefaultLabelContext ------------------------------------------------------------------

TParser::DefaultLabelContext::DefaultLabelContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TParser::DefaultLabelContext::DEFAULT() {
  return getToken(TParser::DEFAULT, 0);
}

tree::TerminalNode* TParser::DefaultLabelContext::NEWLINE() {
  return getToken(TParser::NEWLINE, 0);
}


size_t TParser::DefaultLabelContext::getRuleIndex() const {
  return TParser::RuleDefaultLabel;
}

void TParser::DefaultLabelContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDefaultLabel(this);
}

void TParser::DefaultLabelContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDefaultLabel(this);
}


antlrcpp::Any TParser::DefaultLabelContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitDefaultLabel(this);
  else
    return visitor->visitChildren(this);
}

TParser::DefaultLabelContext* TParser::defaultLabel() {
  DefaultLabelContext *_localctx = _tracker.createInstance<DefaultLabelContext>(_ctx, getState());
  enterRule(_localctx, 84, TParser::RuleDefaultLabel);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(648);
    match(TParser::DEFAULT);
    setState(649);
    match(TParser::NEWLINE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionListContext ------------------------------------------------------------------

TParser::ExpressionListContext::ExpressionListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TParser::AssignmentExpressionContext *> TParser::ExpressionListContext::assignmentExpression() {
  return getRuleContexts<TParser::AssignmentExpressionContext>();
}

TParser::AssignmentExpressionContext* TParser::ExpressionListContext::assignmentExpression(size_t i) {
  return getRuleContext<TParser::AssignmentExpressionContext>(i);
}

std::vector<tree::TerminalNode *> TParser::ExpressionListContext::COMMA() {
  return getTokens(TParser::COMMA);
}

tree::TerminalNode* TParser::ExpressionListContext::COMMA(size_t i) {
  return getToken(TParser::COMMA, i);
}


size_t TParser::ExpressionListContext::getRuleIndex() const {
  return TParser::RuleExpressionList;
}

void TParser::ExpressionListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpressionList(this);
}

void TParser::ExpressionListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpressionList(this);
}


antlrcpp::Any TParser::ExpressionListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitExpressionList(this);
  else
    return visitor->visitChildren(this);
}

TParser::ExpressionListContext* TParser::expressionList() {
  ExpressionListContext *_localctx = _tracker.createInstance<ExpressionListContext>(_ctx, getState());
  enterRule(_localctx, 86, TParser::RuleExpressionList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(651);
    assignmentExpression();
    setState(656);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TParser::COMMA) {
      setState(652);
      match(TParser::COMMA);
      setState(653);
      assignmentExpression();
      setState(658);
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

//----------------- AssignmentExpressionContext ------------------------------------------------------------------

TParser::AssignmentExpressionContext::AssignmentExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TParser::ExpressionContext *> TParser::AssignmentExpressionContext::expression() {
  return getRuleContexts<TParser::ExpressionContext>();
}

TParser::ExpressionContext* TParser::AssignmentExpressionContext::expression(size_t i) {
  return getRuleContext<TParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> TParser::AssignmentExpressionContext::ASSIGN() {
  return getTokens(TParser::ASSIGN);
}

tree::TerminalNode* TParser::AssignmentExpressionContext::ASSIGN(size_t i) {
  return getToken(TParser::ASSIGN, i);
}


size_t TParser::AssignmentExpressionContext::getRuleIndex() const {
  return TParser::RuleAssignmentExpression;
}

void TParser::AssignmentExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignmentExpression(this);
}

void TParser::AssignmentExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignmentExpression(this);
}


antlrcpp::Any TParser::AssignmentExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitAssignmentExpression(this);
  else
    return visitor->visitChildren(this);
}

TParser::AssignmentExpressionContext* TParser::assignmentExpression() {
  AssignmentExpressionContext *_localctx = _tracker.createInstance<AssignmentExpressionContext>(_ctx, getState());
  enterRule(_localctx, 88, TParser::RuleAssignmentExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(659);
    expression();
    setState(664);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TParser::ASSIGN) {
      setState(660);
      match(TParser::ASSIGN);
      setState(661);
      expression();
      setState(666);
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

//----------------- ExpressionContext ------------------------------------------------------------------

TParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TParser::ConditionalOrExpressionContext *> TParser::ExpressionContext::conditionalOrExpression() {
  return getRuleContexts<TParser::ConditionalOrExpressionContext>();
}

TParser::ConditionalOrExpressionContext* TParser::ExpressionContext::conditionalOrExpression(size_t i) {
  return getRuleContext<TParser::ConditionalOrExpressionContext>(i);
}

std::vector<TParser::RelationalOpContext *> TParser::ExpressionContext::relationalOp() {
  return getRuleContexts<TParser::RelationalOpContext>();
}

TParser::RelationalOpContext* TParser::ExpressionContext::relationalOp(size_t i) {
  return getRuleContext<TParser::RelationalOpContext>(i);
}


size_t TParser::ExpressionContext::getRuleIndex() const {
  return TParser::RuleExpression;
}

void TParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void TParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}


antlrcpp::Any TParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}

TParser::ExpressionContext* TParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 90, TParser::RuleExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(667);
    conditionalOrExpression();
    setState(673);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << TParser::GT)
      | (1ULL << TParser::LT)
      | (1ULL << TParser::EQUAL)
      | (1ULL << TParser::LE)
      | (1ULL << TParser::GE)
      | (1ULL << TParser::NOT_EQUAL))) != 0)) {
      setState(668);
      relationalOp();
      setState(669);
      conditionalOrExpression();
      setState(675);
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

//----------------- RelationalOpContext ------------------------------------------------------------------

TParser::RelationalOpContext::RelationalOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TParser::RelationalOpContext::EQUAL() {
  return getToken(TParser::EQUAL, 0);
}

tree::TerminalNode* TParser::RelationalOpContext::NOT_EQUAL() {
  return getToken(TParser::NOT_EQUAL, 0);
}

tree::TerminalNode* TParser::RelationalOpContext::LE() {
  return getToken(TParser::LE, 0);
}

tree::TerminalNode* TParser::RelationalOpContext::GE() {
  return getToken(TParser::GE, 0);
}

tree::TerminalNode* TParser::RelationalOpContext::LT() {
  return getToken(TParser::LT, 0);
}

tree::TerminalNode* TParser::RelationalOpContext::GT() {
  return getToken(TParser::GT, 0);
}


size_t TParser::RelationalOpContext::getRuleIndex() const {
  return TParser::RuleRelationalOp;
}

void TParser::RelationalOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelationalOp(this);
}

void TParser::RelationalOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelationalOp(this);
}


antlrcpp::Any TParser::RelationalOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitRelationalOp(this);
  else
    return visitor->visitChildren(this);
}

TParser::RelationalOpContext* TParser::relationalOp() {
  RelationalOpContext *_localctx = _tracker.createInstance<RelationalOpContext>(_ctx, getState());
  enterRule(_localctx, 92, TParser::RuleRelationalOp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(676);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << TParser::GT)
      | (1ULL << TParser::LT)
      | (1ULL << TParser::EQUAL)
      | (1ULL << TParser::LE)
      | (1ULL << TParser::GE)
      | (1ULL << TParser::NOT_EQUAL))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConditionalOrExpressionContext ------------------------------------------------------------------

TParser::ConditionalOrExpressionContext::ConditionalOrExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TParser::ExclusiveOrExpressionContext *> TParser::ConditionalOrExpressionContext::exclusiveOrExpression() {
  return getRuleContexts<TParser::ExclusiveOrExpressionContext>();
}

TParser::ExclusiveOrExpressionContext* TParser::ConditionalOrExpressionContext::exclusiveOrExpression(size_t i) {
  return getRuleContext<TParser::ExclusiveOrExpressionContext>(i);
}

std::vector<tree::TerminalNode *> TParser::ConditionalOrExpressionContext::OR() {
  return getTokens(TParser::OR);
}

tree::TerminalNode* TParser::ConditionalOrExpressionContext::OR(size_t i) {
  return getToken(TParser::OR, i);
}

std::vector<tree::TerminalNode *> TParser::ConditionalOrExpressionContext::B_OR() {
  return getTokens(TParser::B_OR);
}

tree::TerminalNode* TParser::ConditionalOrExpressionContext::B_OR(size_t i) {
  return getToken(TParser::B_OR, i);
}


size_t TParser::ConditionalOrExpressionContext::getRuleIndex() const {
  return TParser::RuleConditionalOrExpression;
}

void TParser::ConditionalOrExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConditionalOrExpression(this);
}

void TParser::ConditionalOrExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConditionalOrExpression(this);
}


antlrcpp::Any TParser::ConditionalOrExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitConditionalOrExpression(this);
  else
    return visitor->visitChildren(this);
}

TParser::ConditionalOrExpressionContext* TParser::conditionalOrExpression() {
  ConditionalOrExpressionContext *_localctx = _tracker.createInstance<ConditionalOrExpressionContext>(_ctx, getState());
  enterRule(_localctx, 94, TParser::RuleConditionalOrExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(678);
    exclusiveOrExpression();
    setState(683);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TParser::B_OR

    || _la == TParser::OR) {
      setState(679);
      _la = _input->LA(1);
      if (!(_la == TParser::B_OR

      || _la == TParser::OR)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(680);
      exclusiveOrExpression();
      setState(685);
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

//----------------- ExclusiveOrExpressionContext ------------------------------------------------------------------

TParser::ExclusiveOrExpressionContext::ExclusiveOrExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TParser::ConditionalAndExpressionContext *> TParser::ExclusiveOrExpressionContext::conditionalAndExpression() {
  return getRuleContexts<TParser::ConditionalAndExpressionContext>();
}

TParser::ConditionalAndExpressionContext* TParser::ExclusiveOrExpressionContext::conditionalAndExpression(size_t i) {
  return getRuleContext<TParser::ConditionalAndExpressionContext>(i);
}

std::vector<tree::TerminalNode *> TParser::ExclusiveOrExpressionContext::EXOR() {
  return getTokens(TParser::EXOR);
}

tree::TerminalNode* TParser::ExclusiveOrExpressionContext::EXOR(size_t i) {
  return getToken(TParser::EXOR, i);
}

std::vector<tree::TerminalNode *> TParser::ExclusiveOrExpressionContext::B_EXOR() {
  return getTokens(TParser::B_EXOR);
}

tree::TerminalNode* TParser::ExclusiveOrExpressionContext::B_EXOR(size_t i) {
  return getToken(TParser::B_EXOR, i);
}


size_t TParser::ExclusiveOrExpressionContext::getRuleIndex() const {
  return TParser::RuleExclusiveOrExpression;
}

void TParser::ExclusiveOrExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExclusiveOrExpression(this);
}

void TParser::ExclusiveOrExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExclusiveOrExpression(this);
}


antlrcpp::Any TParser::ExclusiveOrExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitExclusiveOrExpression(this);
  else
    return visitor->visitChildren(this);
}

TParser::ExclusiveOrExpressionContext* TParser::exclusiveOrExpression() {
  ExclusiveOrExpressionContext *_localctx = _tracker.createInstance<ExclusiveOrExpressionContext>(_ctx, getState());
  enterRule(_localctx, 96, TParser::RuleExclusiveOrExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(686);
    conditionalAndExpression();
    setState(691);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TParser::B_EXOR || _la == TParser::EXOR) {
      setState(687);
      _la = _input->LA(1);
      if (!(_la == TParser::B_EXOR || _la == TParser::EXOR)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(688);
      conditionalAndExpression();
      setState(693);
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

//----------------- ConditionalAndExpressionContext ------------------------------------------------------------------

TParser::ConditionalAndExpressionContext::ConditionalAndExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TParser::AdditiveExpressionContext *> TParser::ConditionalAndExpressionContext::additiveExpression() {
  return getRuleContexts<TParser::AdditiveExpressionContext>();
}

TParser::AdditiveExpressionContext* TParser::ConditionalAndExpressionContext::additiveExpression(size_t i) {
  return getRuleContext<TParser::AdditiveExpressionContext>(i);
}

std::vector<tree::TerminalNode *> TParser::ConditionalAndExpressionContext::AND() {
  return getTokens(TParser::AND);
}

tree::TerminalNode* TParser::ConditionalAndExpressionContext::AND(size_t i) {
  return getToken(TParser::AND, i);
}

std::vector<tree::TerminalNode *> TParser::ConditionalAndExpressionContext::B_AND() {
  return getTokens(TParser::B_AND);
}

tree::TerminalNode* TParser::ConditionalAndExpressionContext::B_AND(size_t i) {
  return getToken(TParser::B_AND, i);
}


size_t TParser::ConditionalAndExpressionContext::getRuleIndex() const {
  return TParser::RuleConditionalAndExpression;
}

void TParser::ConditionalAndExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConditionalAndExpression(this);
}

void TParser::ConditionalAndExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConditionalAndExpression(this);
}


antlrcpp::Any TParser::ConditionalAndExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitConditionalAndExpression(this);
  else
    return visitor->visitChildren(this);
}

TParser::ConditionalAndExpressionContext* TParser::conditionalAndExpression() {
  ConditionalAndExpressionContext *_localctx = _tracker.createInstance<ConditionalAndExpressionContext>(_ctx, getState());
  enterRule(_localctx, 98, TParser::RuleConditionalAndExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(694);
    additiveExpression();
    setState(699);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TParser::AND

    || _la == TParser::B_AND) {
      setState(695);
      _la = _input->LA(1);
      if (!(_la == TParser::AND

      || _la == TParser::B_AND)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(696);
      additiveExpression();
      setState(701);
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

//----------------- AdditiveExpressionContext ------------------------------------------------------------------

TParser::AdditiveExpressionContext::AdditiveExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TParser::MultiplicativeExpressionContext *> TParser::AdditiveExpressionContext::multiplicativeExpression() {
  return getRuleContexts<TParser::MultiplicativeExpressionContext>();
}

TParser::MultiplicativeExpressionContext* TParser::AdditiveExpressionContext::multiplicativeExpression(size_t i) {
  return getRuleContext<TParser::MultiplicativeExpressionContext>(i);
}

std::vector<tree::TerminalNode *> TParser::AdditiveExpressionContext::ADD() {
  return getTokens(TParser::ADD);
}

tree::TerminalNode* TParser::AdditiveExpressionContext::ADD(size_t i) {
  return getToken(TParser::ADD, i);
}

std::vector<tree::TerminalNode *> TParser::AdditiveExpressionContext::SUB() {
  return getTokens(TParser::SUB);
}

tree::TerminalNode* TParser::AdditiveExpressionContext::SUB(size_t i) {
  return getToken(TParser::SUB, i);
}


size_t TParser::AdditiveExpressionContext::getRuleIndex() const {
  return TParser::RuleAdditiveExpression;
}

void TParser::AdditiveExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAdditiveExpression(this);
}

void TParser::AdditiveExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAdditiveExpression(this);
}


antlrcpp::Any TParser::AdditiveExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitAdditiveExpression(this);
  else
    return visitor->visitChildren(this);
}

TParser::AdditiveExpressionContext* TParser::additiveExpression() {
  AdditiveExpressionContext *_localctx = _tracker.createInstance<AdditiveExpressionContext>(_ctx, getState());
  enterRule(_localctx, 100, TParser::RuleAdditiveExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(702);
    multiplicativeExpression();
    setState(707);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TParser::ADD

    || _la == TParser::SUB) {
      setState(703);
      _la = _input->LA(1);
      if (!(_la == TParser::ADD

      || _la == TParser::SUB)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(704);
      multiplicativeExpression();
      setState(709);
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

//----------------- MultiplicativeExpressionContext ------------------------------------------------------------------

TParser::MultiplicativeExpressionContext::MultiplicativeExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TParser::GeometricExpressionContext *> TParser::MultiplicativeExpressionContext::geometricExpression() {
  return getRuleContexts<TParser::GeometricExpressionContext>();
}

TParser::GeometricExpressionContext* TParser::MultiplicativeExpressionContext::geometricExpression(size_t i) {
  return getRuleContext<TParser::GeometricExpressionContext>(i);
}

std::vector<tree::TerminalNode *> TParser::MultiplicativeExpressionContext::MUL() {
  return getTokens(TParser::MUL);
}

tree::TerminalNode* TParser::MultiplicativeExpressionContext::MUL(size_t i) {
  return getToken(TParser::MUL, i);
}

std::vector<tree::TerminalNode *> TParser::MultiplicativeExpressionContext::DIV() {
  return getTokens(TParser::DIV);
}

tree::TerminalNode* TParser::MultiplicativeExpressionContext::DIV(size_t i) {
  return getToken(TParser::DIV, i);
}


size_t TParser::MultiplicativeExpressionContext::getRuleIndex() const {
  return TParser::RuleMultiplicativeExpression;
}

void TParser::MultiplicativeExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultiplicativeExpression(this);
}

void TParser::MultiplicativeExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultiplicativeExpression(this);
}


antlrcpp::Any TParser::MultiplicativeExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitMultiplicativeExpression(this);
  else
    return visitor->visitChildren(this);
}

TParser::MultiplicativeExpressionContext* TParser::multiplicativeExpression() {
  MultiplicativeExpressionContext *_localctx = _tracker.createInstance<MultiplicativeExpressionContext>(_ctx, getState());
  enterRule(_localctx, 102, TParser::RuleMultiplicativeExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(710);
    geometricExpression();
    setState(715);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TParser::MUL

    || _la == TParser::DIV) {
      setState(711);
      _la = _input->LA(1);
      if (!(_la == TParser::MUL

      || _la == TParser::DIV)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(712);
      geometricExpression();
      setState(717);
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

//----------------- GeometricExpressionContext ------------------------------------------------------------------

TParser::GeometricExpressionContext::GeometricExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TParser::UnaryNotExpressionContext *> TParser::GeometricExpressionContext::unaryNotExpression() {
  return getRuleContexts<TParser::UnaryNotExpressionContext>();
}

TParser::UnaryNotExpressionContext* TParser::GeometricExpressionContext::unaryNotExpression(size_t i) {
  return getRuleContext<TParser::UnaryNotExpressionContext>(i);
}

std::vector<tree::TerminalNode *> TParser::GeometricExpressionContext::COLON() {
  return getTokens(TParser::COLON);
}

tree::TerminalNode* TParser::GeometricExpressionContext::COLON(size_t i) {
  return getToken(TParser::COLON, i);
}


size_t TParser::GeometricExpressionContext::getRuleIndex() const {
  return TParser::RuleGeometricExpression;
}

void TParser::GeometricExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGeometricExpression(this);
}

void TParser::GeometricExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGeometricExpression(this);
}


antlrcpp::Any TParser::GeometricExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitGeometricExpression(this);
  else
    return visitor->visitChildren(this);
}

TParser::GeometricExpressionContext* TParser::geometricExpression() {
  GeometricExpressionContext *_localctx = _tracker.createInstance<GeometricExpressionContext>(_ctx, getState());
  enterRule(_localctx, 104, TParser::RuleGeometricExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(718);
    unaryNotExpression();
    setState(723);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TParser::COLON) {
      setState(719);
      match(TParser::COLON);
      setState(720);
      unaryNotExpression();
      setState(725);
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

//----------------- UnaryNotExpressionContext ------------------------------------------------------------------

TParser::UnaryNotExpressionContext::UnaryNotExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TParser::UnaryNotExpressionContext::NOT() {
  return getToken(TParser::NOT, 0);
}

TParser::UnaryNotExpressionContext* TParser::UnaryNotExpressionContext::unaryNotExpression() {
  return getRuleContext<TParser::UnaryNotExpressionContext>(0);
}

tree::TerminalNode* TParser::UnaryNotExpressionContext::B_NOT() {
  return getToken(TParser::B_NOT, 0);
}

TParser::UnaryPlusMinuxExpressionContext* TParser::UnaryNotExpressionContext::unaryPlusMinuxExpression() {
  return getRuleContext<TParser::UnaryPlusMinuxExpressionContext>(0);
}


size_t TParser::UnaryNotExpressionContext::getRuleIndex() const {
  return TParser::RuleUnaryNotExpression;
}

void TParser::UnaryNotExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryNotExpression(this);
}

void TParser::UnaryNotExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryNotExpression(this);
}


antlrcpp::Any TParser::UnaryNotExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitUnaryNotExpression(this);
  else
    return visitor->visitChildren(this);
}

TParser::UnaryNotExpressionContext* TParser::unaryNotExpression() {
  UnaryNotExpressionContext *_localctx = _tracker.createInstance<UnaryNotExpressionContext>(_ctx, getState());
  enterRule(_localctx, 106, TParser::RuleUnaryNotExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(731);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TParser::NOT: {
        enterOuterAlt(_localctx, 1);
        setState(726);
        match(TParser::NOT);
        setState(727);
        unaryNotExpression();
        break;
      }

      case TParser::B_NOT: {
        enterOuterAlt(_localctx, 2);
        setState(728);
        match(TParser::B_NOT);
        setState(729);
        unaryNotExpression();
        break;
      }

      case TParser::LPAREN:
      case TParser::LBRACE:
      case TParser::ADD:
      case TParser::SUB:
      case TParser::NUMBER:
      case TParser::FALSE:
      case TParser::TRUE:
      case TParser::CHARLITERAL:
      case TParser::STRINGLITERAL:
      case TParser::FLOATLITERAL:
      case TParser::INTLITERAL:
      case TParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 3);
        setState(730);
        unaryPlusMinuxExpression();
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

//----------------- UnaryPlusMinuxExpressionContext ------------------------------------------------------------------

TParser::UnaryPlusMinuxExpressionContext::UnaryPlusMinuxExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TParser::UnaryPlusMinuxExpressionContext::ADD() {
  return getToken(TParser::ADD, 0);
}

TParser::UnaryPlusMinuxExpressionContext* TParser::UnaryPlusMinuxExpressionContext::unaryPlusMinuxExpression() {
  return getRuleContext<TParser::UnaryPlusMinuxExpressionContext>(0);
}

tree::TerminalNode* TParser::UnaryPlusMinuxExpressionContext::SUB() {
  return getToken(TParser::SUB, 0);
}

TParser::PrimaryContext* TParser::UnaryPlusMinuxExpressionContext::primary() {
  return getRuleContext<TParser::PrimaryContext>(0);
}


size_t TParser::UnaryPlusMinuxExpressionContext::getRuleIndex() const {
  return TParser::RuleUnaryPlusMinuxExpression;
}

void TParser::UnaryPlusMinuxExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryPlusMinuxExpression(this);
}

void TParser::UnaryPlusMinuxExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryPlusMinuxExpression(this);
}


antlrcpp::Any TParser::UnaryPlusMinuxExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitUnaryPlusMinuxExpression(this);
  else
    return visitor->visitChildren(this);
}

TParser::UnaryPlusMinuxExpressionContext* TParser::unaryPlusMinuxExpression() {
  UnaryPlusMinuxExpressionContext *_localctx = _tracker.createInstance<UnaryPlusMinuxExpressionContext>(_ctx, getState());
  enterRule(_localctx, 108, TParser::RuleUnaryPlusMinuxExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(738);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TParser::ADD: {
        enterOuterAlt(_localctx, 1);
        setState(733);
        match(TParser::ADD);
        setState(734);
        unaryPlusMinuxExpression();
        break;
      }

      case TParser::SUB: {
        enterOuterAlt(_localctx, 2);
        setState(735);
        match(TParser::SUB);
        setState(736);
        unaryPlusMinuxExpression();
        break;
      }

      case TParser::LPAREN:
      case TParser::LBRACE:
      case TParser::NUMBER:
      case TParser::FALSE:
      case TParser::TRUE:
      case TParser::CHARLITERAL:
      case TParser::STRINGLITERAL:
      case TParser::FLOATLITERAL:
      case TParser::INTLITERAL:
      case TParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 3);
        setState(737);
        primary();
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

//----------------- PrimaryContext ------------------------------------------------------------------

TParser::PrimaryContext::PrimaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TParser::ParExpressionContext* TParser::PrimaryContext::parExpression() {
  return getRuleContext<TParser::ParExpressionContext>(0);
}

std::vector<TParser::VariableNameContext *> TParser::PrimaryContext::variableName() {
  return getRuleContexts<TParser::VariableNameContext>();
}

TParser::VariableNameContext* TParser::PrimaryContext::variableName(size_t i) {
  return getRuleContext<TParser::VariableNameContext>(i);
}

std::vector<tree::TerminalNode *> TParser::PrimaryContext::DOT() {
  return getTokens(TParser::DOT);
}

tree::TerminalNode* TParser::PrimaryContext::DOT(size_t i) {
  return getToken(TParser::DOT, i);
}

TParser::ArgumentsContext* TParser::PrimaryContext::arguments() {
  return getRuleContext<TParser::ArgumentsContext>(0);
}

TParser::LiteralContext* TParser::PrimaryContext::literal() {
  return getRuleContext<TParser::LiteralContext>(0);
}


size_t TParser::PrimaryContext::getRuleIndex() const {
  return TParser::RulePrimary;
}

void TParser::PrimaryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimary(this);
}

void TParser::PrimaryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimary(this);
}


antlrcpp::Any TParser::PrimaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitPrimary(this);
  else
    return visitor->visitChildren(this);
}

TParser::PrimaryContext* TParser::primary() {
  PrimaryContext *_localctx = _tracker.createInstance<PrimaryContext>(_ctx, getState());
  enterRule(_localctx, 110, TParser::RulePrimary);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(753);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TParser::LPAREN: {
        enterOuterAlt(_localctx, 1);
        setState(740);
        parExpression();
        break;
      }

      case TParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 2);
        setState(741);
        variableName();
        setState(746);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == TParser::DOT) {
          setState(742);
          match(TParser::DOT);
          setState(743);
          variableName();
          setState(748);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(750);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == TParser::LPAREN) {
          setState(749);
          arguments();
        }
        break;
      }

      case TParser::LBRACE:
      case TParser::NUMBER:
      case TParser::FALSE:
      case TParser::TRUE:
      case TParser::CHARLITERAL:
      case TParser::STRINGLITERAL:
      case TParser::FLOATLITERAL:
      case TParser::INTLITERAL: {
        enterOuterAlt(_localctx, 3);
        setState(752);
        literal();
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

//----------------- ParExpressionContext ------------------------------------------------------------------

TParser::ParExpressionContext::ParExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TParser::ParExpressionContext::LPAREN() {
  return getToken(TParser::LPAREN, 0);
}

TParser::AssignmentExpressionContext* TParser::ParExpressionContext::assignmentExpression() {
  return getRuleContext<TParser::AssignmentExpressionContext>(0);
}

tree::TerminalNode* TParser::ParExpressionContext::RPAREN() {
  return getToken(TParser::RPAREN, 0);
}


size_t TParser::ParExpressionContext::getRuleIndex() const {
  return TParser::RuleParExpression;
}

void TParser::ParExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParExpression(this);
}

void TParser::ParExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParExpression(this);
}


antlrcpp::Any TParser::ParExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitParExpression(this);
  else
    return visitor->visitChildren(this);
}

TParser::ParExpressionContext* TParser::parExpression() {
  ParExpressionContext *_localctx = _tracker.createInstance<ParExpressionContext>(_ctx, getState());
  enterRule(_localctx, 112, TParser::RuleParExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(755);
    match(TParser::LPAREN);
    setState(756);
    assignmentExpression();
    setState(757);
    match(TParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

TParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TParser::PrimitiveTypeContext* TParser::TypeContext::primitiveType() {
  return getRuleContext<TParser::PrimitiveTypeContext>(0);
}

tree::TerminalNode* TParser::TypeContext::LBRACK() {
  return getToken(TParser::LBRACK, 0);
}

tree::TerminalNode* TParser::TypeContext::RBRACK() {
  return getToken(TParser::RBRACK, 0);
}

tree::TerminalNode* TParser::TypeContext::INTLITERAL() {
  return getToken(TParser::INTLITERAL, 0);
}

TParser::TypeNameContext* TParser::TypeContext::typeName() {
  return getRuleContext<TParser::TypeNameContext>(0);
}


size_t TParser::TypeContext::getRuleIndex() const {
  return TParser::RuleType;
}

void TParser::TypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType(this);
}

void TParser::TypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType(this);
}


antlrcpp::Any TParser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

TParser::TypeContext* TParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 114, TParser::RuleType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(775);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TParser::BOOL:
      case TParser::CHAR:
      case TParser::INT:
      case TParser::REAL: {
        enterOuterAlt(_localctx, 1);
        setState(759);
        primitiveType();
        setState(765);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == TParser::LBRACK) {
          setState(760);
          match(TParser::LBRACK);
          setState(762);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == TParser::INTLITERAL) {
            setState(761);
            match(TParser::INTLITERAL);
          }
          setState(764);
          match(TParser::RBRACK);
        }
        break;
      }

      case TParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 2);
        setState(767);
        typeName();
        setState(773);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == TParser::LBRACK) {
          setState(768);
          match(TParser::LBRACK);
          setState(770);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == TParser::INTLITERAL) {
            setState(769);
            match(TParser::INTLITERAL);
          }
          setState(772);
          match(TParser::RBRACK);
        }
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

//----------------- TypeNameContext ------------------------------------------------------------------

TParser::TypeNameContext::TypeNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TParser::TypeNameContext::IDENTIFIER() {
  return getToken(TParser::IDENTIFIER, 0);
}


size_t TParser::TypeNameContext::getRuleIndex() const {
  return TParser::RuleTypeName;
}

void TParser::TypeNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeName(this);
}

void TParser::TypeNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeName(this);
}


antlrcpp::Any TParser::TypeNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitTypeName(this);
  else
    return visitor->visitChildren(this);
}

TParser::TypeNameContext* TParser::typeName() {
  TypeNameContext *_localctx = _tracker.createInstance<TypeNameContext>(_ctx, getState());
  enterRule(_localctx, 116, TParser::RuleTypeName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(777);
    match(TParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrimitiveTypeContext ------------------------------------------------------------------

TParser::PrimitiveTypeContext::PrimitiveTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TParser::PrimitiveTypeContext::BOOL() {
  return getToken(TParser::BOOL, 0);
}

tree::TerminalNode* TParser::PrimitiveTypeContext::CHAR() {
  return getToken(TParser::CHAR, 0);
}

tree::TerminalNode* TParser::PrimitiveTypeContext::INT() {
  return getToken(TParser::INT, 0);
}

tree::TerminalNode* TParser::PrimitiveTypeContext::REAL() {
  return getToken(TParser::REAL, 0);
}


size_t TParser::PrimitiveTypeContext::getRuleIndex() const {
  return TParser::RulePrimitiveType;
}

void TParser::PrimitiveTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimitiveType(this);
}

void TParser::PrimitiveTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimitiveType(this);
}


antlrcpp::Any TParser::PrimitiveTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitPrimitiveType(this);
  else
    return visitor->visitChildren(this);
}

TParser::PrimitiveTypeContext* TParser::primitiveType() {
  PrimitiveTypeContext *_localctx = _tracker.createInstance<PrimitiveTypeContext>(_ctx, getState());
  enterRule(_localctx, 118, TParser::RulePrimitiveType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(779);
    _la = _input->LA(1);
    if (!(((((_la - 33) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 33)) & ((1ULL << (TParser::BOOL - 33))
      | (1ULL << (TParser::CHAR - 33))
      | (1ULL << (TParser::INT - 33))
      | (1ULL << (TParser::REAL - 33)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentsContext ------------------------------------------------------------------

TParser::ArgumentsContext::ArgumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TParser::ArgumentsContext::LPAREN() {
  return getToken(TParser::LPAREN, 0);
}

tree::TerminalNode* TParser::ArgumentsContext::RPAREN() {
  return getToken(TParser::RPAREN, 0);
}

TParser::ExpressionListContext* TParser::ArgumentsContext::expressionList() {
  return getRuleContext<TParser::ExpressionListContext>(0);
}


size_t TParser::ArgumentsContext::getRuleIndex() const {
  return TParser::RuleArguments;
}

void TParser::ArgumentsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArguments(this);
}

void TParser::ArgumentsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArguments(this);
}


antlrcpp::Any TParser::ArgumentsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitArguments(this);
  else
    return visitor->visitChildren(this);
}

TParser::ArgumentsContext* TParser::arguments() {
  ArgumentsContext *_localctx = _tracker.createInstance<ArgumentsContext>(_ctx, getState());
  enterRule(_localctx, 120, TParser::RuleArguments);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(781);
    match(TParser::LPAREN);
    setState(783);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << TParser::LPAREN)
      | (1ULL << TParser::LBRACE)
      | (1ULL << TParser::ADD)
      | (1ULL << TParser::SUB)
      | (1ULL << TParser::NUMBER)
      | (1ULL << TParser::B_NOT))) != 0) || ((((_la - 67) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 67)) & ((1ULL << (TParser::FALSE - 67))
      | (1ULL << (TParser::NOT - 67))
      | (1ULL << (TParser::TRUE - 67))
      | (1ULL << (TParser::CHARLITERAL - 67))
      | (1ULL << (TParser::STRINGLITERAL - 67))
      | (1ULL << (TParser::FLOATLITERAL - 67))
      | (1ULL << (TParser::INTLITERAL - 67))
      | (1ULL << (TParser::IDENTIFIER - 67)))) != 0)) {
      setState(782);
      expressionList();
    }
    setState(785);
    match(TParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiteralContext ------------------------------------------------------------------

TParser::LiteralContext::LiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TParser::LiteralContext::INTLITERAL() {
  return getToken(TParser::INTLITERAL, 0);
}

tree::TerminalNode* TParser::LiteralContext::FLOATLITERAL() {
  return getToken(TParser::FLOATLITERAL, 0);
}

tree::TerminalNode* TParser::LiteralContext::CHARLITERAL() {
  return getToken(TParser::CHARLITERAL, 0);
}

tree::TerminalNode* TParser::LiteralContext::STRINGLITERAL() {
  return getToken(TParser::STRINGLITERAL, 0);
}

TParser::StructLiteralContext* TParser::LiteralContext::structLiteral() {
  return getRuleContext<TParser::StructLiteralContext>(0);
}

tree::TerminalNode* TParser::LiteralContext::TRUE() {
  return getToken(TParser::TRUE, 0);
}

tree::TerminalNode* TParser::LiteralContext::FALSE() {
  return getToken(TParser::FALSE, 0);
}

TParser::EnumElementContext* TParser::LiteralContext::enumElement() {
  return getRuleContext<TParser::EnumElementContext>(0);
}


size_t TParser::LiteralContext::getRuleIndex() const {
  return TParser::RuleLiteral;
}

void TParser::LiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteral(this);
}

void TParser::LiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteral(this);
}


antlrcpp::Any TParser::LiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitLiteral(this);
  else
    return visitor->visitChildren(this);
}

TParser::LiteralContext* TParser::literal() {
  LiteralContext *_localctx = _tracker.createInstance<LiteralContext>(_ctx, getState());
  enterRule(_localctx, 122, TParser::RuleLiteral);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(795);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TParser::INTLITERAL: {
        enterOuterAlt(_localctx, 1);
        setState(787);
        match(TParser::INTLITERAL);
        break;
      }

      case TParser::FLOATLITERAL: {
        enterOuterAlt(_localctx, 2);
        setState(788);
        match(TParser::FLOATLITERAL);
        break;
      }

      case TParser::CHARLITERAL: {
        enterOuterAlt(_localctx, 3);
        setState(789);
        match(TParser::CHARLITERAL);
        break;
      }

      case TParser::STRINGLITERAL: {
        enterOuterAlt(_localctx, 4);
        setState(790);
        match(TParser::STRINGLITERAL);
        break;
      }

      case TParser::LBRACE: {
        enterOuterAlt(_localctx, 5);
        setState(791);
        structLiteral();
        break;
      }

      case TParser::TRUE: {
        enterOuterAlt(_localctx, 6);
        setState(792);
        match(TParser::TRUE);
        break;
      }

      case TParser::FALSE: {
        enterOuterAlt(_localctx, 7);
        setState(793);
        match(TParser::FALSE);
        break;
      }

      case TParser::NUMBER: {
        enterOuterAlt(_localctx, 8);
        setState(794);
        enumElement();
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

//----------------- EnumElementContext ------------------------------------------------------------------

TParser::EnumElementContext::EnumElementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TParser::EnumElementContext::NUMBER() {
  return getToken(TParser::NUMBER, 0);
}

tree::TerminalNode* TParser::EnumElementContext::IDENTIFIER() {
  return getToken(TParser::IDENTIFIER, 0);
}


size_t TParser::EnumElementContext::getRuleIndex() const {
  return TParser::RuleEnumElement;
}

void TParser::EnumElementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnumElement(this);
}

void TParser::EnumElementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnumElement(this);
}


antlrcpp::Any TParser::EnumElementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitEnumElement(this);
  else
    return visitor->visitChildren(this);
}

TParser::EnumElementContext* TParser::enumElement() {
  EnumElementContext *_localctx = _tracker.createInstance<EnumElementContext>(_ctx, getState());
  enterRule(_localctx, 124, TParser::RuleEnumElement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(797);
    match(TParser::NUMBER);
    setState(798);
    match(TParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> TParser::_decisionToDFA;
atn::PredictionContextCache TParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN TParser::_atn;
std::vector<uint16_t> TParser::_serializedATN;

std::vector<std::string> TParser::_ruleNames = {
  "module", "moduleRoutines", "mainRoutine", "subRoutine", "procedureDefinition", 
  "procedureName", "functionDefinition", "functionName", "moduleData", "moduleName", 
  "dataList", "arrayInitialisation", "typeDeclaration", "structureDefinition", 
  "enumDefinition", "enumValue", "variableDeclaration", "signalDeclaration", 
  "variableDeclarationInDataList", "variableListRest", "variableInitialisation", 
  "structLiteral", "structElementList", "structElement", "formalParameters", 
  "parameter", "routineBody", "routineDataSection", "forwardDeclaration", 
  "formalParametersWithType", "parameterWithType", "parameterCallType", 
  "importStatement", "variableName", "arrayVariableSuffix", "routineImplementationSection", 
  "statementList", "statement", "analogOutputStatement", "analogInputStatement", 
  "switchBlockStatementGroups", "caseLabel", "defaultLabel", "expressionList", 
  "assignmentExpression", "expression", "relationalOp", "conditionalOrExpression", 
  "exclusiveOrExpression", "conditionalAndExpression", "additiveExpression", 
  "multiplicativeExpression", "geometricExpression", "unaryNotExpression", 
  "unaryPlusMinuxExpression", "primary", "parExpression", "type", "typeName", 
  "primitiveType", "arguments", "literal", "enumElement"
};

std::vector<std::string> TParser::_literalNames = {
  "", "'('", "')'", "'{'", "'}'", "'['", "']'", "';'", "','", "'.'", "'='", 
  "'>'", "'<'", "':'", "'=='", "'<='", "'>='", "'<>'", "'+'", "'-'", "'*'", 
  "'/'", "'%'", "'#'", "'..'", "'/R1/'"
};

std::vector<std::string> TParser::_symbolicNames = {
  "", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "LBRACK", "RBRACK", "SEMI", 
  "COMMA", "DOT", "ASSIGN", "GT", "LT", "COLON", "EQUAL", "LE", "GE", "NOT_EQUAL", 
  "ADD", "SUB", "MUL", "DIV", "MOD", "NUMBER", "DIERESIS", "R1", "AND", 
  "ANIN", "ANOUT", "B_AND", "B_NOT", "B_OR", "B_EXOR", "BOOL", "BRAKE", 
  "C_DIS", "C_ORI", "C_PTP", "C_VEL", "CASE", "CAST_FROM", "CAST_TO", "CHAR", 
  "CIRC_REL", "CIRC", "CONST", "CONTINUE", "DELAY", "DECL", "DEF", "DEFAULT", 
  "DEFDAT", "DEFFCT", "DO", "ELSE", "END", "ENDDAT", "ENDFCT", "ENDFOR", 
  "ENDIF", "ENDLOOP", "ENDSWITCH", "ENDWHILE", "ENUM", "EXIT", "EXT", "EXTFCT", 
  "FALSE", "FOR", "GLOBAL", "GOTO", "HALT", "IF", "IMPORT", "INTERRUPT", 
  "INT", "IS", "LIN_REL", "LIN", "LOOP", "MAXIMUM", "MINIMUM", "NOT", "OR", 
  "PRIO", "PTP_REL", "PTP", "PUBLIC", "REAL", "REPEAT", "RETURN", "SEC", 
  "SIGNAL", "STRUC", "SWITCH", "THEN", "TO", "TRIGGER", "TRUE", "UNTIL", 
  "WAIT", "WHEN", "WHILE", "EXOR", "HEADERLINE", "WS", "NEWLINE", "LINE_COMMENT", 
  "CHARLITERAL", "STRINGLITERAL", "FLOATLITERAL", "INTLITERAL", "IDENTIFIER"
};

dfa::Vocabulary TParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> TParser::_tokenNames;

TParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x72, 0x323, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 
    0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 
    0x25, 0x4, 0x26, 0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 
    0x4, 0x29, 0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x4, 
    0x2c, 0x9, 0x2c, 0x4, 0x2d, 0x9, 0x2d, 0x4, 0x2e, 0x9, 0x2e, 0x4, 0x2f, 
    0x9, 0x2f, 0x4, 0x30, 0x9, 0x30, 0x4, 0x31, 0x9, 0x31, 0x4, 0x32, 0x9, 
    0x32, 0x4, 0x33, 0x9, 0x33, 0x4, 0x34, 0x9, 0x34, 0x4, 0x35, 0x9, 0x35, 
    0x4, 0x36, 0x9, 0x36, 0x4, 0x37, 0x9, 0x37, 0x4, 0x38, 0x9, 0x38, 0x4, 
    0x39, 0x9, 0x39, 0x4, 0x3a, 0x9, 0x3a, 0x4, 0x3b, 0x9, 0x3b, 0x4, 0x3c, 
    0x9, 0x3c, 0x4, 0x3d, 0x9, 0x3d, 0x4, 0x3e, 0x9, 0x3e, 0x4, 0x3f, 0x9, 
    0x3f, 0x4, 0x40, 0x9, 0x40, 0x3, 0x2, 0x3, 0x2, 0x5, 0x2, 0x83, 0xa, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x8a, 
    0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x8d, 0xb, 0x3, 0x3, 0x4, 0x3, 0x4, 0x5, 
    0x4, 0x91, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x95, 0xa, 0x5, 0x3, 
    0x6, 0x5, 0x6, 0x98, 0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x5, 0x8, 
    0xa4, 0xa, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x5, 0xa, 0xb3, 0xa, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x7, 0xa, 0xb9, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0xbc, 0xb, 0xa, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0xd0, 0xa, 0xc, 0xc, 0xc, 0xe, 
    0xc, 0xd3, 0xb, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0xdc, 0xa, 0xe, 0x3, 0xf, 0x5, 0xf, 0xdf, 
    0xa, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 
    0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x7, 0xf, 0xeb, 0xa, 0xf, 0xc, 
    0xf, 0xe, 0xf, 0xee, 0xb, 0xf, 0x3, 0x10, 0x5, 0x10, 0xf1, 0xa, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x7, 0x10, 0xf8, 
    0xa, 0x10, 0xc, 0x10, 0xe, 0x10, 0xfb, 0xb, 0x10, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x12, 0x5, 0x12, 0x100, 0xa, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0x107, 0xa, 0x12, 0x3, 0x13, 0x3, 0x13, 
    0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x5, 0x13, 0x10e, 0xa, 0x13, 0x3, 0x14, 
    0x5, 0x14, 0x111, 0xa, 0x14, 0x3, 0x14, 0x5, 0x14, 0x114, 0xa, 0x14, 
    0x3, 0x14, 0x5, 0x14, 0x117, 0xa, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x5, 0x14, 0x11d, 0xa, 0x14, 0x3, 0x14, 0x5, 0x14, 0x120, 
    0xa, 0x14, 0x3, 0x15, 0x3, 0x15, 0x7, 0x15, 0x124, 0xa, 0x15, 0xc, 0x15, 
    0xe, 0x15, 0x127, 0xb, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 
    0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0x130, 0xa, 0x17, 0x3, 0x17, 
    0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x7, 0x18, 0x138, 
    0xa, 0x18, 0xc, 0x18, 0xe, 0x18, 0x13b, 0xb, 0x18, 0x3, 0x19, 0x3, 0x19, 
    0x3, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x7, 0x1a, 0x144, 
    0xa, 0x1a, 0xc, 0x1a, 0xe, 0x1a, 0x147, 0xb, 0x1a, 0x5, 0x1a, 0x149, 
    0xa, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x5, 0x1b, 0x14f, 
    0xa, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 
    0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 
    0x3, 0x1d, 0x3, 0x1d, 0x7, 0x1d, 0x15f, 0xa, 0x1d, 0xc, 0x1d, 0xe, 0x1d, 
    0x162, 0xb, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 
    0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x5, 0x1e, 0x16d, 0xa, 0x1e, 
    0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x7, 0x1f, 0x173, 0xa, 0x1f, 
    0xc, 0x1f, 0xe, 0x1f, 0x176, 0xb, 0x1f, 0x5, 0x1f, 0x178, 0xa, 0x1f, 
    0x3, 0x1f, 0x3, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x5, 0x20, 0x17e, 0xa, 0x20, 
    0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 
    0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x23, 
    0x3, 0x23, 0x5, 0x23, 0x18e, 0xa, 0x23, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 
    0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x5, 0x24, 0x196, 0xa, 0x24, 0x5, 0x24, 
    0x198, 0xa, 0x24, 0x5, 0x24, 0x19a, 0xa, 0x24, 0x5, 0x24, 0x19c, 0xa, 
    0x24, 0x5, 0x24, 0x19e, 0xa, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x25, 
    0x3, 0x25, 0x3, 0x26, 0x7, 0x26, 0x1a5, 0xa, 0x26, 0xc, 0x26, 0xe, 0x26, 
    0x1a8, 0xb, 0x26, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 
    0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 
    0x27, 0x5, 0x27, 0x1b6, 0xa, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 
    0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 
    0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 
    0x3, 0x27, 0x5, 0x27, 0x1c9, 0xa, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 
    0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 
    0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 
    0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 
    0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 
    0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 
    0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 
    0x5, 0x27, 0x1f5, 0xa, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x5, 0x27, 
    0x1fa, 0xa, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 
    0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x5, 0x27, 0x205, 0xa, 0x27, 
    0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 
    0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x5, 0x27, 
    0x213, 0xa, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 
    0x5, 0x27, 0x21a, 0xa, 0x27, 0x5, 0x27, 0x21c, 0xa, 0x27, 0x3, 0x27, 
    0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x5, 0x27, 0x223, 0xa, 0x27, 
    0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x5, 0x27, 0x22a, 
    0xa, 0x27, 0x3, 0x27, 0x5, 0x27, 0x22d, 0xa, 0x27, 0x3, 0x27, 0x3, 0x27, 
    0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 
    0x27, 0x5, 0x27, 0x238, 0xa, 0x27, 0x3, 0x27, 0x5, 0x27, 0x23b, 0xa, 
    0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 
    0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 
    0x27, 0x3, 0x27, 0x3, 0x27, 0x5, 0x27, 0x24c, 0xa, 0x27, 0x3, 0x27, 
    0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 
    0x27, 0x5, 0x27, 0x256, 0xa, 0x27, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 
    0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x7, 0x28, 0x25e, 0xa, 0x28, 0xc, 0x28, 
    0xe, 0x28, 0x261, 0xb, 0x28, 0x3, 0x28, 0x3, 0x28, 0x5, 0x28, 0x265, 
    0xa, 0x28, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x5, 
    0x29, 0x26c, 0xa, 0x29, 0x3, 0x2a, 0x7, 0x2a, 0x26f, 0xa, 0x2a, 0xc, 
    0x2a, 0xe, 0x2a, 0x272, 0xb, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 
    0x6, 0x2a, 0x277, 0xa, 0x2a, 0xd, 0x2a, 0xe, 0x2a, 0x278, 0x3, 0x2a, 
    0x3, 0x2a, 0x3, 0x2a, 0x5, 0x2a, 0x27e, 0xa, 0x2a, 0x3, 0x2b, 0x3, 0x2b, 
    0x3, 0x2b, 0x3, 0x2b, 0x7, 0x2b, 0x284, 0xa, 0x2b, 0xc, 0x2b, 0xe, 0x2b, 
    0x287, 0xb, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 
    0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x7, 0x2d, 0x291, 0xa, 0x2d, 0xc, 0x2d, 
    0xe, 0x2d, 0x294, 0xb, 0x2d, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x7, 0x2e, 
    0x299, 0xa, 0x2e, 0xc, 0x2e, 0xe, 0x2e, 0x29c, 0xb, 0x2e, 0x3, 0x2f, 
    0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x7, 0x2f, 0x2a2, 0xa, 0x2f, 0xc, 0x2f, 
    0xe, 0x2f, 0x2a5, 0xb, 0x2f, 0x3, 0x30, 0x3, 0x30, 0x3, 0x31, 0x3, 0x31, 
    0x3, 0x31, 0x7, 0x31, 0x2ac, 0xa, 0x31, 0xc, 0x31, 0xe, 0x31, 0x2af, 
    0xb, 0x31, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x7, 0x32, 0x2b4, 0xa, 0x32, 
    0xc, 0x32, 0xe, 0x32, 0x2b7, 0xb, 0x32, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 
    0x7, 0x33, 0x2bc, 0xa, 0x33, 0xc, 0x33, 0xe, 0x33, 0x2bf, 0xb, 0x33, 
    0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x7, 0x34, 0x2c4, 0xa, 0x34, 0xc, 0x34, 
    0xe, 0x34, 0x2c7, 0xb, 0x34, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x7, 0x35, 
    0x2cc, 0xa, 0x35, 0xc, 0x35, 0xe, 0x35, 0x2cf, 0xb, 0x35, 0x3, 0x36, 
    0x3, 0x36, 0x3, 0x36, 0x7, 0x36, 0x2d4, 0xa, 0x36, 0xc, 0x36, 0xe, 0x36, 
    0x2d7, 0xb, 0x36, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 
    0x5, 0x37, 0x2de, 0xa, 0x37, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 
    0x3, 0x38, 0x5, 0x38, 0x2e5, 0xa, 0x38, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 
    0x3, 0x39, 0x7, 0x39, 0x2eb, 0xa, 0x39, 0xc, 0x39, 0xe, 0x39, 0x2ee, 
    0xb, 0x39, 0x3, 0x39, 0x5, 0x39, 0x2f1, 0xa, 0x39, 0x3, 0x39, 0x5, 0x39, 
    0x2f4, 0xa, 0x39, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3b, 
    0x3, 0x3b, 0x3, 0x3b, 0x5, 0x3b, 0x2fd, 0xa, 0x3b, 0x3, 0x3b, 0x5, 0x3b, 
    0x300, 0xa, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x5, 0x3b, 0x305, 
    0xa, 0x3b, 0x3, 0x3b, 0x5, 0x3b, 0x308, 0xa, 0x3b, 0x5, 0x3b, 0x30a, 
    0xa, 0x3b, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3e, 0x3, 
    0x3e, 0x5, 0x3e, 0x312, 0xa, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3f, 
    0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 
    0x3f, 0x5, 0x3f, 0x31e, 0xa, 0x3f, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 
    0x3, 0x40, 0x2, 0x2, 0x41, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 
    0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 
    0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 
    0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 0x58, 
    0x5a, 0x5c, 0x5e, 0x60, 0x62, 0x64, 0x66, 0x68, 0x6a, 0x6c, 0x6e, 0x70, 
    0x72, 0x74, 0x76, 0x78, 0x7a, 0x7c, 0x7e, 0x2, 0xc, 0x3, 0x2, 0x57, 
    0x58, 0x4, 0x2, 0x25, 0x26, 0x28, 0x28, 0x3, 0x2, 0x2d, 0x2e, 0x4, 0x2, 
    0xd, 0xe, 0x10, 0x13, 0x4, 0x2, 0x21, 0x21, 0x55, 0x55, 0x4, 0x2, 0x22, 
    0x22, 0x69, 0x69, 0x4, 0x2, 0x1c, 0x1c, 0x1f, 0x1f, 0x3, 0x2, 0x14, 
    0x15, 0x3, 0x2, 0x16, 0x17, 0x6, 0x2, 0x23, 0x23, 0x2c, 0x2c, 0x4d, 
    0x4d, 0x5a, 0x5a, 0x2, 0x360, 0x2, 0x82, 0x3, 0x2, 0x2, 0x2, 0x4, 0x86, 
    0x3, 0x2, 0x2, 0x2, 0x6, 0x90, 0x3, 0x2, 0x2, 0x2, 0x8, 0x94, 0x3, 0x2, 
    0x2, 0x2, 0xa, 0x97, 0x3, 0x2, 0x2, 0x2, 0xc, 0xa0, 0x3, 0x2, 0x2, 0x2, 
    0xe, 0xa3, 0x3, 0x2, 0x2, 0x2, 0x10, 0xad, 0x3, 0x2, 0x2, 0x2, 0x12, 
    0xaf, 0x3, 0x2, 0x2, 0x2, 0x14, 0xbd, 0x3, 0x2, 0x2, 0x2, 0x16, 0xd1, 
    0x3, 0x2, 0x2, 0x2, 0x18, 0xd4, 0x3, 0x2, 0x2, 0x2, 0x1a, 0xdb, 0x3, 
    0x2, 0x2, 0x2, 0x1c, 0xde, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xf0, 0x3, 0x2, 
    0x2, 0x2, 0x20, 0xfc, 0x3, 0x2, 0x2, 0x2, 0x22, 0xff, 0x3, 0x2, 0x2, 
    0x2, 0x24, 0x108, 0x3, 0x2, 0x2, 0x2, 0x26, 0x110, 0x3, 0x2, 0x2, 0x2, 
    0x28, 0x125, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x128, 0x3, 0x2, 0x2, 0x2, 0x2c, 
    0x12b, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x134, 0x3, 0x2, 0x2, 0x2, 0x30, 0x13c, 
    0x3, 0x2, 0x2, 0x2, 0x32, 0x13f, 0x3, 0x2, 0x2, 0x2, 0x34, 0x14c, 0x3, 
    0x2, 0x2, 0x2, 0x36, 0x150, 0x3, 0x2, 0x2, 0x2, 0x38, 0x160, 0x3, 0x2, 
    0x2, 0x2, 0x3a, 0x16c, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x16e, 0x3, 0x2, 0x2, 
    0x2, 0x3e, 0x17b, 0x3, 0x2, 0x2, 0x2, 0x40, 0x17f, 0x3, 0x2, 0x2, 0x2, 
    0x42, 0x182, 0x3, 0x2, 0x2, 0x2, 0x44, 0x18b, 0x3, 0x2, 0x2, 0x2, 0x46, 
    0x18f, 0x3, 0x2, 0x2, 0x2, 0x48, 0x1a1, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x1a6, 
    0x3, 0x2, 0x2, 0x2, 0x4c, 0x255, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x257, 0x3, 
    0x2, 0x2, 0x2, 0x50, 0x266, 0x3, 0x2, 0x2, 0x2, 0x52, 0x270, 0x3, 0x2, 
    0x2, 0x2, 0x54, 0x27f, 0x3, 0x2, 0x2, 0x2, 0x56, 0x28a, 0x3, 0x2, 0x2, 
    0x2, 0x58, 0x28d, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x295, 0x3, 0x2, 0x2, 0x2, 
    0x5c, 0x29d, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x2a6, 0x3, 0x2, 0x2, 0x2, 0x60, 
    0x2a8, 0x3, 0x2, 0x2, 0x2, 0x62, 0x2b0, 0x3, 0x2, 0x2, 0x2, 0x64, 0x2b8, 
    0x3, 0x2, 0x2, 0x2, 0x66, 0x2c0, 0x3, 0x2, 0x2, 0x2, 0x68, 0x2c8, 0x3, 
    0x2, 0x2, 0x2, 0x6a, 0x2d0, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x2dd, 0x3, 0x2, 
    0x2, 0x2, 0x6e, 0x2e4, 0x3, 0x2, 0x2, 0x2, 0x70, 0x2f3, 0x3, 0x2, 0x2, 
    0x2, 0x72, 0x2f5, 0x3, 0x2, 0x2, 0x2, 0x74, 0x309, 0x3, 0x2, 0x2, 0x2, 
    0x76, 0x30b, 0x3, 0x2, 0x2, 0x2, 0x78, 0x30d, 0x3, 0x2, 0x2, 0x2, 0x7a, 
    0x30f, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x31d, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x31f, 
    0x3, 0x2, 0x2, 0x2, 0x80, 0x83, 0x5, 0x12, 0xa, 0x2, 0x81, 0x83, 0x5, 
    0x4, 0x3, 0x2, 0x82, 0x80, 0x3, 0x2, 0x2, 0x2, 0x82, 0x81, 0x3, 0x2, 
    0x2, 0x2, 0x83, 0x84, 0x3, 0x2, 0x2, 0x2, 0x84, 0x85, 0x7, 0x2, 0x2, 
    0x3, 0x85, 0x3, 0x3, 0x2, 0x2, 0x2, 0x86, 0x8b, 0x5, 0x6, 0x4, 0x2, 
    0x87, 0x8a, 0x5, 0x8, 0x5, 0x2, 0x88, 0x8a, 0x7, 0x6c, 0x2, 0x2, 0x89, 
    0x87, 0x3, 0x2, 0x2, 0x2, 0x89, 0x88, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x8d, 
    0x3, 0x2, 0x2, 0x2, 0x8b, 0x89, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x8c, 0x3, 
    0x2, 0x2, 0x2, 0x8c, 0x5, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x8b, 0x3, 0x2, 
    0x2, 0x2, 0x8e, 0x91, 0x5, 0xa, 0x6, 0x2, 0x8f, 0x91, 0x5, 0xe, 0x8, 
    0x2, 0x90, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x90, 0x8f, 0x3, 0x2, 0x2, 0x2, 
    0x91, 0x7, 0x3, 0x2, 0x2, 0x2, 0x92, 0x95, 0x5, 0xa, 0x6, 0x2, 0x93, 
    0x95, 0x5, 0xe, 0x8, 0x2, 0x94, 0x92, 0x3, 0x2, 0x2, 0x2, 0x94, 0x93, 
    0x3, 0x2, 0x2, 0x2, 0x95, 0x9, 0x3, 0x2, 0x2, 0x2, 0x96, 0x98, 0x7, 
    0x47, 0x2, 0x2, 0x97, 0x96, 0x3, 0x2, 0x2, 0x2, 0x97, 0x98, 0x3, 0x2, 
    0x2, 0x2, 0x98, 0x99, 0x3, 0x2, 0x2, 0x2, 0x99, 0x9a, 0x7, 0x33, 0x2, 
    0x2, 0x9a, 0x9b, 0x5, 0xc, 0x7, 0x2, 0x9b, 0x9c, 0x5, 0x32, 0x1a, 0x2, 
    0x9c, 0x9d, 0x7, 0x6c, 0x2, 0x2, 0x9d, 0x9e, 0x5, 0x36, 0x1c, 0x2, 0x9e, 
    0x9f, 0x7, 0x39, 0x2, 0x2, 0x9f, 0xb, 0x3, 0x2, 0x2, 0x2, 0xa0, 0xa1, 
    0x7, 0x72, 0x2, 0x2, 0xa1, 0xd, 0x3, 0x2, 0x2, 0x2, 0xa2, 0xa4, 0x7, 
    0x47, 0x2, 0x2, 0xa3, 0xa2, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xa4, 0x3, 0x2, 
    0x2, 0x2, 0xa4, 0xa5, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xa6, 0x7, 0x36, 0x2, 
    0x2, 0xa6, 0xa7, 0x5, 0x74, 0x3b, 0x2, 0xa7, 0xa8, 0x5, 0x10, 0x9, 0x2, 
    0xa8, 0xa9, 0x5, 0x32, 0x1a, 0x2, 0xa9, 0xaa, 0x7, 0x6c, 0x2, 0x2, 0xaa, 
    0xab, 0x5, 0x36, 0x1c, 0x2, 0xab, 0xac, 0x7, 0x3b, 0x2, 0x2, 0xac, 0xf, 
    0x3, 0x2, 0x2, 0x2, 0xad, 0xae, 0x7, 0x72, 0x2, 0x2, 0xae, 0x11, 0x3, 
    0x2, 0x2, 0x2, 0xaf, 0xb0, 0x7, 0x35, 0x2, 0x2, 0xb0, 0xb2, 0x5, 0x14, 
    0xb, 0x2, 0xb1, 0xb3, 0x7, 0x59, 0x2, 0x2, 0xb2, 0xb1, 0x3, 0x2, 0x2, 
    0x2, 0xb2, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xb4, 0x3, 0x2, 0x2, 0x2, 
    0xb4, 0xb5, 0x7, 0x6c, 0x2, 0x2, 0xb5, 0xb6, 0x5, 0x16, 0xc, 0x2, 0xb6, 
    0xba, 0x7, 0x3a, 0x2, 0x2, 0xb7, 0xb9, 0x7, 0x6c, 0x2, 0x2, 0xb8, 0xb7, 
    0x3, 0x2, 0x2, 0x2, 0xb9, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xba, 0xb8, 0x3, 
    0x2, 0x2, 0x2, 0xba, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xbb, 0x13, 0x3, 0x2, 
    0x2, 0x2, 0xbc, 0xba, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xbe, 0x7, 0x72, 0x2, 
    0x2, 0xbe, 0x15, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xd0, 0x7, 0x6c, 0x2, 0x2, 
    0xc0, 0xc1, 0x5, 0x3a, 0x1e, 0x2, 0xc1, 0xc2, 0x7, 0x6c, 0x2, 0x2, 0xc2, 
    0xd0, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xc4, 0x5, 0x1a, 0xe, 0x2, 0xc4, 0xc5, 
    0x7, 0x6c, 0x2, 0x2, 0xc5, 0xd0, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xc7, 0x5, 
    0x26, 0x14, 0x2, 0xc7, 0xc8, 0x7, 0x6c, 0x2, 0x2, 0xc8, 0xd0, 0x3, 0x2, 
    0x2, 0x2, 0xc9, 0xca, 0x5, 0x18, 0xd, 0x2, 0xca, 0xcb, 0x7, 0x6c, 0x2, 
    0x2, 0xcb, 0xd0, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xcd, 0x5, 0x42, 0x22, 0x2, 
    0xcd, 0xce, 0x7, 0x6c, 0x2, 0x2, 0xce, 0xd0, 0x3, 0x2, 0x2, 0x2, 0xcf, 
    0xbf, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xc3, 
    0x3, 0x2, 0x2, 0x2, 0xcf, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xc9, 0x3, 
    0x2, 0x2, 0x2, 0xcf, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xd3, 0x3, 0x2, 
    0x2, 0x2, 0xd1, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xd2, 0x3, 0x2, 0x2, 
    0x2, 0xd2, 0x17, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd1, 0x3, 0x2, 0x2, 0x2, 
    0xd4, 0xd5, 0x7, 0x72, 0x2, 0x2, 0xd5, 0xd6, 0x5, 0x46, 0x24, 0x2, 0xd6, 
    0xd7, 0x7, 0xc, 0x2, 0x2, 0xd7, 0xd8, 0x5, 0x6e, 0x38, 0x2, 0xd8, 0x19, 
    0x3, 0x2, 0x2, 0x2, 0xd9, 0xdc, 0x5, 0x1c, 0xf, 0x2, 0xda, 0xdc, 0x5, 
    0x1e, 0x10, 0x2, 0xdb, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xda, 0x3, 0x2, 
    0x2, 0x2, 0xdc, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xdf, 0x7, 0x47, 0x2, 
    0x2, 0xde, 0xdd, 0x3, 0x2, 0x2, 0x2, 0xde, 0xdf, 0x3, 0x2, 0x2, 0x2, 
    0xdf, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xe1, 0x7, 0x5f, 0x2, 0x2, 0xe1, 
    0xe2, 0x5, 0x76, 0x3c, 0x2, 0xe2, 0xe3, 0x5, 0x74, 0x3b, 0x2, 0xe3, 
    0xe4, 0x5, 0x44, 0x23, 0x2, 0xe4, 0xec, 0x5, 0x28, 0x15, 0x2, 0xe5, 
    0xe6, 0x7, 0xa, 0x2, 0x2, 0xe6, 0xe7, 0x5, 0x74, 0x3b, 0x2, 0xe7, 0xe8, 
    0x5, 0x44, 0x23, 0x2, 0xe8, 0xe9, 0x5, 0x28, 0x15, 0x2, 0xe9, 0xeb, 
    0x3, 0x2, 0x2, 0x2, 0xea, 0xe5, 0x3, 0x2, 0x2, 0x2, 0xeb, 0xee, 0x3, 
    0x2, 0x2, 0x2, 0xec, 0xea, 0x3, 0x2, 0x2, 0x2, 0xec, 0xed, 0x3, 0x2, 
    0x2, 0x2, 0xed, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xee, 0xec, 0x3, 0x2, 0x2, 
    0x2, 0xef, 0xf1, 0x7, 0x47, 0x2, 0x2, 0xf0, 0xef, 0x3, 0x2, 0x2, 0x2, 
    0xf0, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xf2, 0x3, 0x2, 0x2, 0x2, 0xf2, 
    0xf3, 0x7, 0x41, 0x2, 0x2, 0xf3, 0xf4, 0x5, 0x76, 0x3c, 0x2, 0xf4, 0xf9, 
    0x5, 0x20, 0x11, 0x2, 0xf5, 0xf6, 0x7, 0xa, 0x2, 0x2, 0xf6, 0xf8, 0x5, 
    0x20, 0x11, 0x2, 0xf7, 0xf5, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xfb, 0x3, 0x2, 
    0x2, 0x2, 0xf9, 0xf7, 0x3, 0x2, 0x2, 0x2, 0xf9, 0xfa, 0x3, 0x2, 0x2, 
    0x2, 0xfa, 0x1f, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xf9, 0x3, 0x2, 0x2, 0x2, 
    0xfc, 0xfd, 0x7, 0x72, 0x2, 0x2, 0xfd, 0x21, 0x3, 0x2, 0x2, 0x2, 0xfe, 
    0x100, 0x7, 0x32, 0x2, 0x2, 0xff, 0xfe, 0x3, 0x2, 0x2, 0x2, 0xff, 0x100, 
    0x3, 0x2, 0x2, 0x2, 0x100, 0x106, 0x3, 0x2, 0x2, 0x2, 0x101, 0x102, 
    0x5, 0x74, 0x3b, 0x2, 0x102, 0x103, 0x5, 0x44, 0x23, 0x2, 0x103, 0x104, 
    0x5, 0x28, 0x15, 0x2, 0x104, 0x107, 0x3, 0x2, 0x2, 0x2, 0x105, 0x107, 
    0x5, 0x24, 0x13, 0x2, 0x106, 0x101, 0x3, 0x2, 0x2, 0x2, 0x106, 0x105, 
    0x3, 0x2, 0x2, 0x2, 0x107, 0x23, 0x3, 0x2, 0x2, 0x2, 0x108, 0x109, 0x7, 
    0x5e, 0x2, 0x2, 0x109, 0x10a, 0x7, 0x72, 0x2, 0x2, 0x10a, 0x10d, 0x5, 
    0x70, 0x39, 0x2, 0x10b, 0x10c, 0x7, 0x62, 0x2, 0x2, 0x10c, 0x10e, 0x5, 
    0x70, 0x39, 0x2, 0x10d, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x10d, 0x10e, 0x3, 
    0x2, 0x2, 0x2, 0x10e, 0x25, 0x3, 0x2, 0x2, 0x2, 0x10f, 0x111, 0x7, 0x32, 
    0x2, 0x2, 0x110, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x110, 0x111, 0x3, 0x2, 
    0x2, 0x2, 0x111, 0x113, 0x3, 0x2, 0x2, 0x2, 0x112, 0x114, 0x7, 0x47, 
    0x2, 0x2, 0x113, 0x112, 0x3, 0x2, 0x2, 0x2, 0x113, 0x114, 0x3, 0x2, 
    0x2, 0x2, 0x114, 0x116, 0x3, 0x2, 0x2, 0x2, 0x115, 0x117, 0x7, 0x2f, 
    0x2, 0x2, 0x116, 0x115, 0x3, 0x2, 0x2, 0x2, 0x116, 0x117, 0x3, 0x2, 
    0x2, 0x2, 0x117, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x118, 0x119, 0x5, 0x74, 
    0x3b, 0x2, 0x119, 0x11c, 0x5, 0x44, 0x23, 0x2, 0x11a, 0x11d, 0x5, 0x28, 
    0x15, 0x2, 0x11b, 0x11d, 0x5, 0x2a, 0x16, 0x2, 0x11c, 0x11a, 0x3, 0x2, 
    0x2, 0x2, 0x11c, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x11d, 0x120, 0x3, 0x2, 
    0x2, 0x2, 0x11e, 0x120, 0x5, 0x24, 0x13, 0x2, 0x11f, 0x118, 0x3, 0x2, 
    0x2, 0x2, 0x11f, 0x11e, 0x3, 0x2, 0x2, 0x2, 0x120, 0x27, 0x3, 0x2, 0x2, 
    0x2, 0x121, 0x122, 0x7, 0xa, 0x2, 0x2, 0x122, 0x124, 0x5, 0x44, 0x23, 
    0x2, 0x123, 0x121, 0x3, 0x2, 0x2, 0x2, 0x124, 0x127, 0x3, 0x2, 0x2, 
    0x2, 0x125, 0x123, 0x3, 0x2, 0x2, 0x2, 0x125, 0x126, 0x3, 0x2, 0x2, 
    0x2, 0x126, 0x29, 0x3, 0x2, 0x2, 0x2, 0x127, 0x125, 0x3, 0x2, 0x2, 0x2, 
    0x128, 0x129, 0x7, 0xc, 0x2, 0x2, 0x129, 0x12a, 0x5, 0x6e, 0x38, 0x2, 
    0x12a, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x12f, 0x7, 0x5, 0x2, 0x2, 0x12c, 
    0x12d, 0x5, 0x76, 0x3c, 0x2, 0x12d, 0x12e, 0x7, 0xf, 0x2, 0x2, 0x12e, 
    0x130, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x12c, 0x3, 0x2, 0x2, 0x2, 0x12f, 
    0x130, 0x3, 0x2, 0x2, 0x2, 0x130, 0x131, 0x3, 0x2, 0x2, 0x2, 0x131, 
    0x132, 0x5, 0x2e, 0x18, 0x2, 0x132, 0x133, 0x7, 0x6, 0x2, 0x2, 0x133, 
    0x2d, 0x3, 0x2, 0x2, 0x2, 0x134, 0x139, 0x5, 0x30, 0x19, 0x2, 0x135, 
    0x136, 0x7, 0xa, 0x2, 0x2, 0x136, 0x138, 0x5, 0x30, 0x19, 0x2, 0x137, 
    0x135, 0x3, 0x2, 0x2, 0x2, 0x138, 0x13b, 0x3, 0x2, 0x2, 0x2, 0x139, 
    0x137, 0x3, 0x2, 0x2, 0x2, 0x139, 0x13a, 0x3, 0x2, 0x2, 0x2, 0x13a, 
    0x2f, 0x3, 0x2, 0x2, 0x2, 0x13b, 0x139, 0x3, 0x2, 0x2, 0x2, 0x13c, 0x13d, 
    0x5, 0x44, 0x23, 0x2, 0x13d, 0x13e, 0x5, 0x6e, 0x38, 0x2, 0x13e, 0x31, 
    0x3, 0x2, 0x2, 0x2, 0x13f, 0x148, 0x7, 0x3, 0x2, 0x2, 0x140, 0x145, 
    0x5, 0x34, 0x1b, 0x2, 0x141, 0x142, 0x7, 0xa, 0x2, 0x2, 0x142, 0x144, 
    0x5, 0x34, 0x1b, 0x2, 0x143, 0x141, 0x3, 0x2, 0x2, 0x2, 0x144, 0x147, 
    0x3, 0x2, 0x2, 0x2, 0x145, 0x143, 0x3, 0x2, 0x2, 0x2, 0x145, 0x146, 
    0x3, 0x2, 0x2, 0x2, 0x146, 0x149, 0x3, 0x2, 0x2, 0x2, 0x147, 0x145, 
    0x3, 0x2, 0x2, 0x2, 0x148, 0x140, 0x3, 0x2, 0x2, 0x2, 0x148, 0x149, 
    0x3, 0x2, 0x2, 0x2, 0x149, 0x14a, 0x3, 0x2, 0x2, 0x2, 0x14a, 0x14b, 
    0x7, 0x4, 0x2, 0x2, 0x14b, 0x33, 0x3, 0x2, 0x2, 0x2, 0x14c, 0x14e, 0x5, 
    0x44, 0x23, 0x2, 0x14d, 0x14f, 0x5, 0x40, 0x21, 0x2, 0x14e, 0x14d, 0x3, 
    0x2, 0x2, 0x2, 0x14e, 0x14f, 0x3, 0x2, 0x2, 0x2, 0x14f, 0x35, 0x3, 0x2, 
    0x2, 0x2, 0x150, 0x151, 0x5, 0x38, 0x1d, 0x2, 0x151, 0x152, 0x5, 0x48, 
    0x25, 0x2, 0x152, 0x37, 0x3, 0x2, 0x2, 0x2, 0x153, 0x154, 0x5, 0x3a, 
    0x1e, 0x2, 0x154, 0x155, 0x7, 0x6c, 0x2, 0x2, 0x155, 0x15f, 0x3, 0x2, 
    0x2, 0x2, 0x156, 0x157, 0x5, 0x22, 0x12, 0x2, 0x157, 0x158, 0x7, 0x6c, 
    0x2, 0x2, 0x158, 0x15f, 0x3, 0x2, 0x2, 0x2, 0x159, 0x15a, 0x7, 0x6c, 
    0x2, 0x2, 0x15a, 0x15f, 0x7, 0x6c, 0x2, 0x2, 0x15b, 0x15c, 0x5, 0x42, 
    0x22, 0x2, 0x15c, 0x15d, 0x7, 0x6c, 0x2, 0x2, 0x15d, 0x15f, 0x3, 0x2, 
    0x2, 0x2, 0x15e, 0x153, 0x3, 0x2, 0x2, 0x2, 0x15e, 0x156, 0x3, 0x2, 
    0x2, 0x2, 0x15e, 0x159, 0x3, 0x2, 0x2, 0x2, 0x15e, 0x15b, 0x3, 0x2, 
    0x2, 0x2, 0x15f, 0x162, 0x3, 0x2, 0x2, 0x2, 0x160, 0x15e, 0x3, 0x2, 
    0x2, 0x2, 0x160, 0x161, 0x3, 0x2, 0x2, 0x2, 0x161, 0x39, 0x3, 0x2, 0x2, 
    0x2, 0x162, 0x160, 0x3, 0x2, 0x2, 0x2, 0x163, 0x164, 0x7, 0x43, 0x2, 
    0x2, 0x164, 0x165, 0x5, 0xc, 0x7, 0x2, 0x165, 0x166, 0x5, 0x3c, 0x1f, 
    0x2, 0x166, 0x16d, 0x3, 0x2, 0x2, 0x2, 0x167, 0x168, 0x7, 0x44, 0x2, 
    0x2, 0x168, 0x169, 0x5, 0x74, 0x3b, 0x2, 0x169, 0x16a, 0x5, 0x10, 0x9, 
    0x2, 0x16a, 0x16b, 0x5, 0x3c, 0x1f, 0x2, 0x16b, 0x16d, 0x3, 0x2, 0x2, 
    0x2, 0x16c, 0x163, 0x3, 0x2, 0x2, 0x2, 0x16c, 0x167, 0x3, 0x2, 0x2, 
    0x2, 0x16d, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x16e, 0x177, 0x7, 0x3, 0x2, 0x2, 
    0x16f, 0x174, 0x5, 0x3e, 0x20, 0x2, 0x170, 0x171, 0x7, 0xa, 0x2, 0x2, 
    0x171, 0x173, 0x5, 0x3e, 0x20, 0x2, 0x172, 0x170, 0x3, 0x2, 0x2, 0x2, 
    0x173, 0x176, 0x3, 0x2, 0x2, 0x2, 0x174, 0x172, 0x3, 0x2, 0x2, 0x2, 
    0x174, 0x175, 0x3, 0x2, 0x2, 0x2, 0x175, 0x178, 0x3, 0x2, 0x2, 0x2, 
    0x176, 0x174, 0x3, 0x2, 0x2, 0x2, 0x177, 0x16f, 0x3, 0x2, 0x2, 0x2, 
    0x177, 0x178, 0x3, 0x2, 0x2, 0x2, 0x178, 0x179, 0x3, 0x2, 0x2, 0x2, 
    0x179, 0x17a, 0x7, 0x4, 0x2, 0x2, 0x17a, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x17b, 
    0x17d, 0x5, 0x74, 0x3b, 0x2, 0x17c, 0x17e, 0x5, 0x40, 0x21, 0x2, 0x17d, 
    0x17c, 0x3, 0x2, 0x2, 0x2, 0x17d, 0x17e, 0x3, 0x2, 0x2, 0x2, 0x17e, 
    0x3f, 0x3, 0x2, 0x2, 0x2, 0x17f, 0x180, 0x7, 0xf, 0x2, 0x2, 0x180, 0x181, 
    0x7, 0x72, 0x2, 0x2, 0x181, 0x41, 0x3, 0x2, 0x2, 0x2, 0x182, 0x183, 
    0x7, 0x4b, 0x2, 0x2, 0x183, 0x184, 0x5, 0x74, 0x3b, 0x2, 0x184, 0x185, 
    0x5, 0x44, 0x23, 0x2, 0x185, 0x186, 0x7, 0x4e, 0x2, 0x2, 0x186, 0x187, 
    0x7, 0x1b, 0x2, 0x2, 0x187, 0x188, 0x5, 0x14, 0xb, 0x2, 0x188, 0x189, 
    0x7, 0x1a, 0x2, 0x2, 0x189, 0x18a, 0x5, 0x44, 0x23, 0x2, 0x18a, 0x43, 
    0x3, 0x2, 0x2, 0x2, 0x18b, 0x18d, 0x7, 0x72, 0x2, 0x2, 0x18c, 0x18e, 
    0x5, 0x46, 0x24, 0x2, 0x18d, 0x18c, 0x3, 0x2, 0x2, 0x2, 0x18d, 0x18e, 
    0x3, 0x2, 0x2, 0x2, 0x18e, 0x45, 0x3, 0x2, 0x2, 0x2, 0x18f, 0x19d, 0x7, 
    0x7, 0x2, 0x2, 0x190, 0x19b, 0x5, 0x5c, 0x2f, 0x2, 0x191, 0x199, 0x7, 
    0xa, 0x2, 0x2, 0x192, 0x197, 0x5, 0x5c, 0x2f, 0x2, 0x193, 0x195, 0x7, 
    0xa, 0x2, 0x2, 0x194, 0x196, 0x5, 0x5c, 0x2f, 0x2, 0x195, 0x194, 0x3, 
    0x2, 0x2, 0x2, 0x195, 0x196, 0x3, 0x2, 0x2, 0x2, 0x196, 0x198, 0x3, 
    0x2, 0x2, 0x2, 0x197, 0x193, 0x3, 0x2, 0x2, 0x2, 0x197, 0x198, 0x3, 
    0x2, 0x2, 0x2, 0x198, 0x19a, 0x3, 0x2, 0x2, 0x2, 0x199, 0x192, 0x3, 
    0x2, 0x2, 0x2, 0x199, 0x19a, 0x3, 0x2, 0x2, 0x2, 0x19a, 0x19c, 0x3, 
    0x2, 0x2, 0x2, 0x19b, 0x191, 0x3, 0x2, 0x2, 0x2, 0x19b, 0x19c, 0x3, 
    0x2, 0x2, 0x2, 0x19c, 0x19e, 0x3, 0x2, 0x2, 0x2, 0x19d, 0x190, 0x3, 
    0x2, 0x2, 0x2, 0x19d, 0x19e, 0x3, 0x2, 0x2, 0x2, 0x19e, 0x19f, 0x3, 
    0x2, 0x2, 0x2, 0x19f, 0x1a0, 0x7, 0x8, 0x2, 0x2, 0x1a0, 0x47, 0x3, 0x2, 
    0x2, 0x2, 0x1a1, 0x1a2, 0x5, 0x4a, 0x26, 0x2, 0x1a2, 0x49, 0x3, 0x2, 
    0x2, 0x2, 0x1a3, 0x1a5, 0x5, 0x4c, 0x27, 0x2, 0x1a4, 0x1a3, 0x3, 0x2, 
    0x2, 0x2, 0x1a5, 0x1a8, 0x3, 0x2, 0x2, 0x2, 0x1a6, 0x1a4, 0x3, 0x2, 
    0x2, 0x2, 0x1a6, 0x1a7, 0x3, 0x2, 0x2, 0x2, 0x1a7, 0x4b, 0x3, 0x2, 0x2, 
    0x2, 0x1a8, 0x1a6, 0x3, 0x2, 0x2, 0x2, 0x1a9, 0x1aa, 0x7, 0x30, 0x2, 
    0x2, 0x1aa, 0x256, 0x7, 0x6c, 0x2, 0x2, 0x1ab, 0x1ac, 0x7, 0x42, 0x2, 
    0x2, 0x1ac, 0x256, 0x7, 0x6c, 0x2, 0x2, 0x1ad, 0x1ae, 0x7, 0x46, 0x2, 
    0x2, 0x1ae, 0x1af, 0x7, 0x72, 0x2, 0x2, 0x1af, 0x1b0, 0x7, 0xc, 0x2, 
    0x2, 0x1b0, 0x1b1, 0x5, 0x5c, 0x2f, 0x2, 0x1b1, 0x1b2, 0x7, 0x62, 0x2, 
    0x2, 0x1b2, 0x1b5, 0x5, 0x5c, 0x2f, 0x2, 0x1b3, 0x1b4, 0x7, 0x72, 0x2, 
    0x2, 0x1b4, 0x1b6, 0x5, 0x5c, 0x2f, 0x2, 0x1b5, 0x1b3, 0x3, 0x2, 0x2, 
    0x2, 0x1b5, 0x1b6, 0x3, 0x2, 0x2, 0x2, 0x1b6, 0x1b7, 0x3, 0x2, 0x2, 
    0x2, 0x1b7, 0x1b8, 0x7, 0x6c, 0x2, 0x2, 0x1b8, 0x1b9, 0x5, 0x4a, 0x26, 
    0x2, 0x1b9, 0x1ba, 0x7, 0x3c, 0x2, 0x2, 0x1ba, 0x256, 0x3, 0x2, 0x2, 
    0x2, 0x1bb, 0x1bc, 0x7, 0x48, 0x2, 0x2, 0x1bc, 0x1bd, 0x7, 0x72, 0x2, 
    0x2, 0x1bd, 0x256, 0x7, 0x6c, 0x2, 0x2, 0x1be, 0x1bf, 0x7, 0x49, 0x2, 
    0x2, 0x1bf, 0x256, 0x7, 0x6c, 0x2, 0x2, 0x1c0, 0x1c1, 0x7, 0x4a, 0x2, 
    0x2, 0x1c1, 0x1c2, 0x5, 0x5c, 0x2f, 0x2, 0x1c2, 0x1c3, 0x7, 0x61, 0x2, 
    0x2, 0x1c3, 0x1c4, 0x7, 0x6c, 0x2, 0x2, 0x1c4, 0x1c8, 0x5, 0x4a, 0x26, 
    0x2, 0x1c5, 0x1c6, 0x7, 0x38, 0x2, 0x2, 0x1c6, 0x1c7, 0x7, 0x6c, 0x2, 
    0x2, 0x1c7, 0x1c9, 0x5, 0x4a, 0x26, 0x2, 0x1c8, 0x1c5, 0x3, 0x2, 0x2, 
    0x2, 0x1c8, 0x1c9, 0x3, 0x2, 0x2, 0x2, 0x1c9, 0x1ca, 0x3, 0x2, 0x2, 
    0x2, 0x1ca, 0x1cb, 0x7, 0x3d, 0x2, 0x2, 0x1cb, 0x1cc, 0x7, 0x6c, 0x2, 
    0x2, 0x1cc, 0x256, 0x3, 0x2, 0x2, 0x2, 0x1cd, 0x1ce, 0x7, 0x51, 0x2, 
    0x2, 0x1ce, 0x1cf, 0x7, 0x6c, 0x2, 0x2, 0x1cf, 0x1d0, 0x5, 0x4a, 0x26, 
    0x2, 0x1d0, 0x1d1, 0x7, 0x3e, 0x2, 0x2, 0x1d1, 0x1d2, 0x7, 0x6c, 0x2, 
    0x2, 0x1d2, 0x256, 0x3, 0x2, 0x2, 0x2, 0x1d3, 0x1d4, 0x7, 0x5b, 0x2, 
    0x2, 0x1d4, 0x1d5, 0x7, 0x6c, 0x2, 0x2, 0x1d5, 0x1d6, 0x5, 0x4a, 0x26, 
    0x2, 0x1d6, 0x1d7, 0x7, 0x65, 0x2, 0x2, 0x1d7, 0x1d8, 0x5, 0x5c, 0x2f, 
    0x2, 0x1d8, 0x1d9, 0x7, 0x6c, 0x2, 0x2, 0x1d9, 0x256, 0x3, 0x2, 0x2, 
    0x2, 0x1da, 0x1db, 0x7, 0x60, 0x2, 0x2, 0x1db, 0x1dc, 0x5, 0x5c, 0x2f, 
    0x2, 0x1dc, 0x1dd, 0x7, 0x6c, 0x2, 0x2, 0x1dd, 0x1de, 0x5, 0x52, 0x2a, 
    0x2, 0x1de, 0x1df, 0x7, 0x3f, 0x2, 0x2, 0x1df, 0x1e0, 0x7, 0x6c, 0x2, 
    0x2, 0x1e0, 0x256, 0x3, 0x2, 0x2, 0x2, 0x1e1, 0x1e2, 0x7, 0x66, 0x2, 
    0x2, 0x1e2, 0x1e3, 0x7, 0x46, 0x2, 0x2, 0x1e3, 0x1e4, 0x5, 0x5c, 0x2f, 
    0x2, 0x1e4, 0x1e5, 0x7, 0x6c, 0x2, 0x2, 0x1e5, 0x256, 0x3, 0x2, 0x2, 
    0x2, 0x1e6, 0x1e7, 0x7, 0x66, 0x2, 0x2, 0x1e7, 0x1e8, 0x7, 0x5d, 0x2, 
    0x2, 0x1e8, 0x1e9, 0x5, 0x5c, 0x2f, 0x2, 0x1e9, 0x1ea, 0x7, 0x6c, 0x2, 
    0x2, 0x1ea, 0x256, 0x3, 0x2, 0x2, 0x2, 0x1eb, 0x1ec, 0x7, 0x68, 0x2, 
    0x2, 0x1ec, 0x1ed, 0x5, 0x5c, 0x2f, 0x2, 0x1ed, 0x1ee, 0x7, 0x6c, 0x2, 
    0x2, 0x1ee, 0x1ef, 0x5, 0x4a, 0x26, 0x2, 0x1ef, 0x1f0, 0x7, 0x40, 0x2, 
    0x2, 0x1f0, 0x1f1, 0x7, 0x6c, 0x2, 0x2, 0x1f1, 0x256, 0x3, 0x2, 0x2, 
    0x2, 0x1f2, 0x1f4, 0x7, 0x5c, 0x2, 0x2, 0x1f3, 0x1f5, 0x5, 0x5a, 0x2e, 
    0x2, 0x1f4, 0x1f3, 0x3, 0x2, 0x2, 0x2, 0x1f4, 0x1f5, 0x3, 0x2, 0x2, 
    0x2, 0x1f5, 0x1f6, 0x3, 0x2, 0x2, 0x2, 0x1f6, 0x256, 0x7, 0x6c, 0x2, 
    0x2, 0x1f7, 0x1f9, 0x7, 0x24, 0x2, 0x2, 0x1f8, 0x1fa, 0x7, 0x72, 0x2, 
    0x2, 0x1f9, 0x1f8, 0x3, 0x2, 0x2, 0x2, 0x1f9, 0x1fa, 0x3, 0x2, 0x2, 
    0x2, 0x1fa, 0x1fb, 0x3, 0x2, 0x2, 0x2, 0x1fb, 0x256, 0x7, 0x6c, 0x2, 
    0x2, 0x1fc, 0x1fd, 0x5, 0x5a, 0x2e, 0x2, 0x1fd, 0x1fe, 0x7, 0x6c, 0x2, 
    0x2, 0x1fe, 0x256, 0x3, 0x2, 0x2, 0x2, 0x1ff, 0x200, 0x7, 0x72, 0x2, 
    0x2, 0x200, 0x201, 0x7, 0xf, 0x2, 0x2, 0x201, 0x256, 0x7, 0x6c, 0x2, 
    0x2, 0x202, 0x256, 0x7, 0x6c, 0x2, 0x2, 0x203, 0x205, 0x7, 0x47, 0x2, 
    0x2, 0x204, 0x203, 0x3, 0x2, 0x2, 0x2, 0x204, 0x205, 0x3, 0x2, 0x2, 
    0x2, 0x205, 0x206, 0x3, 0x2, 0x2, 0x2, 0x206, 0x207, 0x7, 0x4c, 0x2, 
    0x2, 0x207, 0x208, 0x7, 0x32, 0x2, 0x2, 0x208, 0x209, 0x5, 0x70, 0x39, 
    0x2, 0x209, 0x20a, 0x7, 0x67, 0x2, 0x2, 0x20a, 0x20b, 0x5, 0x5c, 0x2f, 
    0x2, 0x20b, 0x20c, 0x7, 0x37, 0x2, 0x2, 0x20c, 0x20d, 0x5, 0x5a, 0x2e, 
    0x2, 0x20d, 0x20e, 0x7, 0x6c, 0x2, 0x2, 0x20e, 0x256, 0x3, 0x2, 0x2, 
    0x2, 0x20f, 0x210, 0x7, 0x4c, 0x2, 0x2, 0x210, 0x212, 0x7, 0x72, 0x2, 
    0x2, 0x211, 0x213, 0x5, 0x70, 0x39, 0x2, 0x212, 0x211, 0x3, 0x2, 0x2, 
    0x2, 0x212, 0x213, 0x3, 0x2, 0x2, 0x2, 0x213, 0x214, 0x3, 0x2, 0x2, 
    0x2, 0x214, 0x256, 0x7, 0x6c, 0x2, 0x2, 0x215, 0x216, 0x9, 0x2, 0x2, 
    0x2, 0x216, 0x21b, 0x5, 0x6a, 0x36, 0x2, 0x217, 0x219, 0x7, 0x27, 0x2, 
    0x2, 0x218, 0x21a, 0x9, 0x3, 0x2, 0x2, 0x219, 0x218, 0x3, 0x2, 0x2, 
    0x2, 0x219, 0x21a, 0x3, 0x2, 0x2, 0x2, 0x21a, 0x21c, 0x3, 0x2, 0x2, 
    0x2, 0x21b, 0x217, 0x3, 0x2, 0x2, 0x2, 0x21b, 0x21c, 0x3, 0x2, 0x2, 
    0x2, 0x21c, 0x21d, 0x3, 0x2, 0x2, 0x2, 0x21d, 0x21e, 0x7, 0x6c, 0x2, 
    0x2, 0x21e, 0x256, 0x3, 0x2, 0x2, 0x2, 0x21f, 0x220, 0x7, 0x50, 0x2, 
    0x2, 0x220, 0x222, 0x5, 0x6a, 0x36, 0x2, 0x221, 0x223, 0x9, 0x3, 0x2, 
    0x2, 0x222, 0x221, 0x3, 0x2, 0x2, 0x2, 0x222, 0x223, 0x3, 0x2, 0x2, 
    0x2, 0x223, 0x224, 0x3, 0x2, 0x2, 0x2, 0x224, 0x225, 0x7, 0x6c, 0x2, 
    0x2, 0x225, 0x256, 0x3, 0x2, 0x2, 0x2, 0x226, 0x227, 0x7, 0x4f, 0x2, 
    0x2, 0x227, 0x229, 0x5, 0x6a, 0x36, 0x2, 0x228, 0x22a, 0x9, 0x3, 0x2, 
    0x2, 0x229, 0x228, 0x3, 0x2, 0x2, 0x2, 0x229, 0x22a, 0x3, 0x2, 0x2, 
    0x2, 0x22a, 0x22c, 0x3, 0x2, 0x2, 0x2, 0x22b, 0x22d, 0x5, 0x7e, 0x40, 
    0x2, 0x22c, 0x22b, 0x3, 0x2, 0x2, 0x2, 0x22c, 0x22d, 0x3, 0x2, 0x2, 
    0x2, 0x22d, 0x22e, 0x3, 0x2, 0x2, 0x2, 0x22e, 0x22f, 0x7, 0x6c, 0x2, 
    0x2, 0x22f, 0x256, 0x3, 0x2, 0x2, 0x2, 0x230, 0x231, 0x9, 0x4, 0x2, 
    0x2, 0x231, 0x232, 0x5, 0x6a, 0x36, 0x2, 0x232, 0x233, 0x7, 0xa, 0x2, 
    0x2, 0x233, 0x237, 0x5, 0x6a, 0x36, 0x2, 0x234, 0x235, 0x7, 0xa, 0x2, 
    0x2, 0x235, 0x236, 0x7, 0x72, 0x2, 0x2, 0x236, 0x238, 0x5, 0x70, 0x39, 
    0x2, 0x237, 0x234, 0x3, 0x2, 0x2, 0x2, 0x237, 0x238, 0x3, 0x2, 0x2, 
    0x2, 0x238, 0x23a, 0x3, 0x2, 0x2, 0x2, 0x239, 0x23b, 0x9, 0x3, 0x2, 
    0x2, 0x23a, 0x239, 0x3, 0x2, 0x2, 0x2, 0x23a, 0x23b, 0x3, 0x2, 0x2, 
    0x2, 0x23b, 0x23c, 0x3, 0x2, 0x2, 0x2, 0x23c, 0x23d, 0x7, 0x6c, 0x2, 
    0x2, 0x23d, 0x256, 0x3, 0x2, 0x2, 0x2, 0x23e, 0x23f, 0x7, 0x63, 0x2, 
    0x2, 0x23f, 0x240, 0x7, 0x67, 0x2, 0x2, 0x240, 0x241, 0x7, 0x72, 0x2, 
    0x2, 0x241, 0x242, 0x7, 0xc, 0x2, 0x2, 0x242, 0x243, 0x5, 0x5c, 0x2f, 
    0x2, 0x243, 0x244, 0x7, 0x31, 0x2, 0x2, 0x244, 0x245, 0x7, 0xc, 0x2, 
    0x2, 0x245, 0x246, 0x5, 0x5c, 0x2f, 0x2, 0x246, 0x247, 0x7, 0x37, 0x2, 
    0x2, 0x247, 0x24b, 0x5, 0x5a, 0x2e, 0x2, 0x248, 0x249, 0x7, 0x56, 0x2, 
    0x2, 0x249, 0x24a, 0x7, 0xc, 0x2, 0x2, 0x24a, 0x24c, 0x5, 0x5c, 0x2f, 
    0x2, 0x24b, 0x248, 0x3, 0x2, 0x2, 0x2, 0x24b, 0x24c, 0x3, 0x2, 0x2, 
    0x2, 0x24c, 0x24d, 0x3, 0x2, 0x2, 0x2, 0x24d, 0x24e, 0x7, 0x6c, 0x2, 
    0x2, 0x24e, 0x256, 0x3, 0x2, 0x2, 0x2, 0x24f, 0x250, 0x5, 0x50, 0x29, 
    0x2, 0x250, 0x251, 0x7, 0x6c, 0x2, 0x2, 0x251, 0x256, 0x3, 0x2, 0x2, 
    0x2, 0x252, 0x253, 0x5, 0x4e, 0x28, 0x2, 0x253, 0x254, 0x7, 0x6c, 0x2, 
    0x2, 0x254, 0x256, 0x3, 0x2, 0x2, 0x2, 0x255, 0x1a9, 0x3, 0x2, 0x2, 
    0x2, 0x255, 0x1ab, 0x3, 0x2, 0x2, 0x2, 0x255, 0x1ad, 0x3, 0x2, 0x2, 
    0x2, 0x255, 0x1bb, 0x3, 0x2, 0x2, 0x2, 0x255, 0x1be, 0x3, 0x2, 0x2, 
    0x2, 0x255, 0x1c0, 0x3, 0x2, 0x2, 0x2, 0x255, 0x1cd, 0x3, 0x2, 0x2, 
    0x2, 0x255, 0x1d3, 0x3, 0x2, 0x2, 0x2, 0x255, 0x1da, 0x3, 0x2, 0x2, 
    0x2, 0x255, 0x1e1, 0x3, 0x2, 0x2, 0x2, 0x255, 0x1e6, 0x3, 0x2, 0x2, 
    0x2, 0x255, 0x1eb, 0x3, 0x2, 0x2, 0x2, 0x255, 0x1f2, 0x3, 0x2, 0x2, 
    0x2, 0x255, 0x1f7, 0x3, 0x2, 0x2, 0x2, 0x255, 0x1fc, 0x3, 0x2, 0x2, 
    0x2, 0x255, 0x1ff, 0x3, 0x2, 0x2, 0x2, 0x255, 0x202, 0x3, 0x2, 0x2, 
    0x2, 0x255, 0x204, 0x3, 0x2, 0x2, 0x2, 0x255, 0x20f, 0x3, 0x2, 0x2, 
    0x2, 0x255, 0x215, 0x3, 0x2, 0x2, 0x2, 0x255, 0x21f, 0x3, 0x2, 0x2, 
    0x2, 0x255, 0x226, 0x3, 0x2, 0x2, 0x2, 0x255, 0x230, 0x3, 0x2, 0x2, 
    0x2, 0x255, 0x23e, 0x3, 0x2, 0x2, 0x2, 0x255, 0x24f, 0x3, 0x2, 0x2, 
    0x2, 0x255, 0x252, 0x3, 0x2, 0x2, 0x2, 0x256, 0x4d, 0x3, 0x2, 0x2, 0x2, 
    0x257, 0x264, 0x7, 0x1e, 0x2, 0x2, 0x258, 0x259, 0x7, 0x72, 0x2, 0x2, 
    0x259, 0x25f, 0x5, 0x5a, 0x2e, 0x2, 0x25a, 0x25b, 0x7, 0x72, 0x2, 0x2, 
    0x25b, 0x25c, 0x7, 0xc, 0x2, 0x2, 0x25c, 0x25e, 0x5, 0x7c, 0x3f, 0x2, 
    0x25d, 0x25a, 0x3, 0x2, 0x2, 0x2, 0x25e, 0x261, 0x3, 0x2, 0x2, 0x2, 
    0x25f, 0x25d, 0x3, 0x2, 0x2, 0x2, 0x25f, 0x260, 0x3, 0x2, 0x2, 0x2, 
    0x260, 0x265, 0x3, 0x2, 0x2, 0x2, 0x261, 0x25f, 0x3, 0x2, 0x2, 0x2, 
    0x262, 0x263, 0x7, 0x72, 0x2, 0x2, 0x263, 0x265, 0x7, 0x72, 0x2, 0x2, 
    0x264, 0x258, 0x3, 0x2, 0x2, 0x2, 0x264, 0x262, 0x3, 0x2, 0x2, 0x2, 
    0x265, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x266, 0x26b, 0x7, 0x1d, 0x2, 0x2, 
    0x267, 0x268, 0x7, 0x72, 0x2, 0x2, 0x268, 0x26c, 0x5, 0x5a, 0x2e, 0x2, 
    0x269, 0x26a, 0x7, 0x72, 0x2, 0x2, 0x26a, 0x26c, 0x7, 0x72, 0x2, 0x2, 
    0x26b, 0x267, 0x3, 0x2, 0x2, 0x2, 0x26b, 0x269, 0x3, 0x2, 0x2, 0x2, 
    0x26c, 0x51, 0x3, 0x2, 0x2, 0x2, 0x26d, 0x26f, 0x7, 0x6c, 0x2, 0x2, 
    0x26e, 0x26d, 0x3, 0x2, 0x2, 0x2, 0x26f, 0x272, 0x3, 0x2, 0x2, 0x2, 
    0x270, 0x26e, 0x3, 0x2, 0x2, 0x2, 0x270, 0x271, 0x3, 0x2, 0x2, 0x2, 
    0x271, 0x276, 0x3, 0x2, 0x2, 0x2, 0x272, 0x270, 0x3, 0x2, 0x2, 0x2, 
    0x273, 0x274, 0x5, 0x54, 0x2b, 0x2, 0x274, 0x275, 0x5, 0x4a, 0x26, 0x2, 
    0x275, 0x277, 0x3, 0x2, 0x2, 0x2, 0x276, 0x273, 0x3, 0x2, 0x2, 0x2, 
    0x277, 0x278, 0x3, 0x2, 0x2, 0x2, 0x278, 0x276, 0x3, 0x2, 0x2, 0x2, 
    0x278, 0x279, 0x3, 0x2, 0x2, 0x2, 0x279, 0x27d, 0x3, 0x2, 0x2, 0x2, 
    0x27a, 0x27b, 0x5, 0x56, 0x2c, 0x2, 0x27b, 0x27c, 0x5, 0x4a, 0x26, 0x2, 
    0x27c, 0x27e, 0x3, 0x2, 0x2, 0x2, 0x27d, 0x27a, 0x3, 0x2, 0x2, 0x2, 
    0x27d, 0x27e, 0x3, 0x2, 0x2, 0x2, 0x27e, 0x53, 0x3, 0x2, 0x2, 0x2, 0x27f, 
    0x280, 0x7, 0x29, 0x2, 0x2, 0x280, 0x285, 0x5, 0x5c, 0x2f, 0x2, 0x281, 
    0x282, 0x7, 0xa, 0x2, 0x2, 0x282, 0x284, 0x5, 0x5c, 0x2f, 0x2, 0x283, 
    0x281, 0x3, 0x2, 0x2, 0x2, 0x284, 0x287, 0x3, 0x2, 0x2, 0x2, 0x285, 
    0x283, 0x3, 0x2, 0x2, 0x2, 0x285, 0x286, 0x3, 0x2, 0x2, 0x2, 0x286, 
    0x288, 0x3, 0x2, 0x2, 0x2, 0x287, 0x285, 0x3, 0x2, 0x2, 0x2, 0x288, 
    0x289, 0x7, 0x6c, 0x2, 0x2, 0x289, 0x55, 0x3, 0x2, 0x2, 0x2, 0x28a, 
    0x28b, 0x7, 0x34, 0x2, 0x2, 0x28b, 0x28c, 0x7, 0x6c, 0x2, 0x2, 0x28c, 
    0x57, 0x3, 0x2, 0x2, 0x2, 0x28d, 0x292, 0x5, 0x5a, 0x2e, 0x2, 0x28e, 
    0x28f, 0x7, 0xa, 0x2, 0x2, 0x28f, 0x291, 0x5, 0x5a, 0x2e, 0x2, 0x290, 
    0x28e, 0x3, 0x2, 0x2, 0x2, 0x291, 0x294, 0x3, 0x2, 0x2, 0x2, 0x292, 
    0x290, 0x3, 0x2, 0x2, 0x2, 0x292, 0x293, 0x3, 0x2, 0x2, 0x2, 0x293, 
    0x59, 0x3, 0x2, 0x2, 0x2, 0x294, 0x292, 0x3, 0x2, 0x2, 0x2, 0x295, 0x29a, 
    0x5, 0x5c, 0x2f, 0x2, 0x296, 0x297, 0x7, 0xc, 0x2, 0x2, 0x297, 0x299, 
    0x5, 0x5c, 0x2f, 0x2, 0x298, 0x296, 0x3, 0x2, 0x2, 0x2, 0x299, 0x29c, 
    0x3, 0x2, 0x2, 0x2, 0x29a, 0x298, 0x3, 0x2, 0x2, 0x2, 0x29a, 0x29b, 
    0x3, 0x2, 0x2, 0x2, 0x29b, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x29c, 0x29a, 0x3, 
    0x2, 0x2, 0x2, 0x29d, 0x2a3, 0x5, 0x60, 0x31, 0x2, 0x29e, 0x29f, 0x5, 
    0x5e, 0x30, 0x2, 0x29f, 0x2a0, 0x5, 0x60, 0x31, 0x2, 0x2a0, 0x2a2, 0x3, 
    0x2, 0x2, 0x2, 0x2a1, 0x29e, 0x3, 0x2, 0x2, 0x2, 0x2a2, 0x2a5, 0x3, 
    0x2, 0x2, 0x2, 0x2a3, 0x2a1, 0x3, 0x2, 0x2, 0x2, 0x2a3, 0x2a4, 0x3, 
    0x2, 0x2, 0x2, 0x2a4, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x2a5, 0x2a3, 0x3, 0x2, 
    0x2, 0x2, 0x2a6, 0x2a7, 0x9, 0x5, 0x2, 0x2, 0x2a7, 0x5f, 0x3, 0x2, 0x2, 
    0x2, 0x2a8, 0x2ad, 0x5, 0x62, 0x32, 0x2, 0x2a9, 0x2aa, 0x9, 0x6, 0x2, 
    0x2, 0x2aa, 0x2ac, 0x5, 0x62, 0x32, 0x2, 0x2ab, 0x2a9, 0x3, 0x2, 0x2, 
    0x2, 0x2ac, 0x2af, 0x3, 0x2, 0x2, 0x2, 0x2ad, 0x2ab, 0x3, 0x2, 0x2, 
    0x2, 0x2ad, 0x2ae, 0x3, 0x2, 0x2, 0x2, 0x2ae, 0x61, 0x3, 0x2, 0x2, 0x2, 
    0x2af, 0x2ad, 0x3, 0x2, 0x2, 0x2, 0x2b0, 0x2b5, 0x5, 0x64, 0x33, 0x2, 
    0x2b1, 0x2b2, 0x9, 0x7, 0x2, 0x2, 0x2b2, 0x2b4, 0x5, 0x64, 0x33, 0x2, 
    0x2b3, 0x2b1, 0x3, 0x2, 0x2, 0x2, 0x2b4, 0x2b7, 0x3, 0x2, 0x2, 0x2, 
    0x2b5, 0x2b3, 0x3, 0x2, 0x2, 0x2, 0x2b5, 0x2b6, 0x3, 0x2, 0x2, 0x2, 
    0x2b6, 0x63, 0x3, 0x2, 0x2, 0x2, 0x2b7, 0x2b5, 0x3, 0x2, 0x2, 0x2, 0x2b8, 
    0x2bd, 0x5, 0x66, 0x34, 0x2, 0x2b9, 0x2ba, 0x9, 0x8, 0x2, 0x2, 0x2ba, 
    0x2bc, 0x5, 0x66, 0x34, 0x2, 0x2bb, 0x2b9, 0x3, 0x2, 0x2, 0x2, 0x2bc, 
    0x2bf, 0x3, 0x2, 0x2, 0x2, 0x2bd, 0x2bb, 0x3, 0x2, 0x2, 0x2, 0x2bd, 
    0x2be, 0x3, 0x2, 0x2, 0x2, 0x2be, 0x65, 0x3, 0x2, 0x2, 0x2, 0x2bf, 0x2bd, 
    0x3, 0x2, 0x2, 0x2, 0x2c0, 0x2c5, 0x5, 0x68, 0x35, 0x2, 0x2c1, 0x2c2, 
    0x9, 0x9, 0x2, 0x2, 0x2c2, 0x2c4, 0x5, 0x68, 0x35, 0x2, 0x2c3, 0x2c1, 
    0x3, 0x2, 0x2, 0x2, 0x2c4, 0x2c7, 0x3, 0x2, 0x2, 0x2, 0x2c5, 0x2c3, 
    0x3, 0x2, 0x2, 0x2, 0x2c5, 0x2c6, 0x3, 0x2, 0x2, 0x2, 0x2c6, 0x67, 0x3, 
    0x2, 0x2, 0x2, 0x2c7, 0x2c5, 0x3, 0x2, 0x2, 0x2, 0x2c8, 0x2cd, 0x5, 
    0x6a, 0x36, 0x2, 0x2c9, 0x2ca, 0x9, 0xa, 0x2, 0x2, 0x2ca, 0x2cc, 0x5, 
    0x6a, 0x36, 0x2, 0x2cb, 0x2c9, 0x3, 0x2, 0x2, 0x2, 0x2cc, 0x2cf, 0x3, 
    0x2, 0x2, 0x2, 0x2cd, 0x2cb, 0x3, 0x2, 0x2, 0x2, 0x2cd, 0x2ce, 0x3, 
    0x2, 0x2, 0x2, 0x2ce, 0x69, 0x3, 0x2, 0x2, 0x2, 0x2cf, 0x2cd, 0x3, 0x2, 
    0x2, 0x2, 0x2d0, 0x2d5, 0x5, 0x6c, 0x37, 0x2, 0x2d1, 0x2d2, 0x7, 0xf, 
    0x2, 0x2, 0x2d2, 0x2d4, 0x5, 0x6c, 0x37, 0x2, 0x2d3, 0x2d1, 0x3, 0x2, 
    0x2, 0x2, 0x2d4, 0x2d7, 0x3, 0x2, 0x2, 0x2, 0x2d5, 0x2d3, 0x3, 0x2, 
    0x2, 0x2, 0x2d5, 0x2d6, 0x3, 0x2, 0x2, 0x2, 0x2d6, 0x6b, 0x3, 0x2, 0x2, 
    0x2, 0x2d7, 0x2d5, 0x3, 0x2, 0x2, 0x2, 0x2d8, 0x2d9, 0x7, 0x54, 0x2, 
    0x2, 0x2d9, 0x2de, 0x5, 0x6c, 0x37, 0x2, 0x2da, 0x2db, 0x7, 0x20, 0x2, 
    0x2, 0x2db, 0x2de, 0x5, 0x6c, 0x37, 0x2, 0x2dc, 0x2de, 0x5, 0x6e, 0x38, 
    0x2, 0x2dd, 0x2d8, 0x3, 0x2, 0x2, 0x2, 0x2dd, 0x2da, 0x3, 0x2, 0x2, 
    0x2, 0x2dd, 0x2dc, 0x3, 0x2, 0x2, 0x2, 0x2de, 0x6d, 0x3, 0x2, 0x2, 0x2, 
    0x2df, 0x2e0, 0x7, 0x14, 0x2, 0x2, 0x2e0, 0x2e5, 0x5, 0x6e, 0x38, 0x2, 
    0x2e1, 0x2e2, 0x7, 0x15, 0x2, 0x2, 0x2e2, 0x2e5, 0x5, 0x6e, 0x38, 0x2, 
    0x2e3, 0x2e5, 0x5, 0x70, 0x39, 0x2, 0x2e4, 0x2df, 0x3, 0x2, 0x2, 0x2, 
    0x2e4, 0x2e1, 0x3, 0x2, 0x2, 0x2, 0x2e4, 0x2e3, 0x3, 0x2, 0x2, 0x2, 
    0x2e5, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x2e6, 0x2f4, 0x5, 0x72, 0x3a, 0x2, 
    0x2e7, 0x2ec, 0x5, 0x44, 0x23, 0x2, 0x2e8, 0x2e9, 0x7, 0xb, 0x2, 0x2, 
    0x2e9, 0x2eb, 0x5, 0x44, 0x23, 0x2, 0x2ea, 0x2e8, 0x3, 0x2, 0x2, 0x2, 
    0x2eb, 0x2ee, 0x3, 0x2, 0x2, 0x2, 0x2ec, 0x2ea, 0x3, 0x2, 0x2, 0x2, 
    0x2ec, 0x2ed, 0x3, 0x2, 0x2, 0x2, 0x2ed, 0x2f0, 0x3, 0x2, 0x2, 0x2, 
    0x2ee, 0x2ec, 0x3, 0x2, 0x2, 0x2, 0x2ef, 0x2f1, 0x5, 0x7a, 0x3e, 0x2, 
    0x2f0, 0x2ef, 0x3, 0x2, 0x2, 0x2, 0x2f0, 0x2f1, 0x3, 0x2, 0x2, 0x2, 
    0x2f1, 0x2f4, 0x3, 0x2, 0x2, 0x2, 0x2f2, 0x2f4, 0x5, 0x7c, 0x3f, 0x2, 
    0x2f3, 0x2e6, 0x3, 0x2, 0x2, 0x2, 0x2f3, 0x2e7, 0x3, 0x2, 0x2, 0x2, 
    0x2f3, 0x2f2, 0x3, 0x2, 0x2, 0x2, 0x2f4, 0x71, 0x3, 0x2, 0x2, 0x2, 0x2f5, 
    0x2f6, 0x7, 0x3, 0x2, 0x2, 0x2f6, 0x2f7, 0x5, 0x5a, 0x2e, 0x2, 0x2f7, 
    0x2f8, 0x7, 0x4, 0x2, 0x2, 0x2f8, 0x73, 0x3, 0x2, 0x2, 0x2, 0x2f9, 0x2ff, 
    0x5, 0x78, 0x3d, 0x2, 0x2fa, 0x2fc, 0x7, 0x7, 0x2, 0x2, 0x2fb, 0x2fd, 
    0x7, 0x71, 0x2, 0x2, 0x2fc, 0x2fb, 0x3, 0x2, 0x2, 0x2, 0x2fc, 0x2fd, 
    0x3, 0x2, 0x2, 0x2, 0x2fd, 0x2fe, 0x3, 0x2, 0x2, 0x2, 0x2fe, 0x300, 
    0x7, 0x8, 0x2, 0x2, 0x2ff, 0x2fa, 0x3, 0x2, 0x2, 0x2, 0x2ff, 0x300, 
    0x3, 0x2, 0x2, 0x2, 0x300, 0x30a, 0x3, 0x2, 0x2, 0x2, 0x301, 0x307, 
    0x5, 0x76, 0x3c, 0x2, 0x302, 0x304, 0x7, 0x7, 0x2, 0x2, 0x303, 0x305, 
    0x7, 0x71, 0x2, 0x2, 0x304, 0x303, 0x3, 0x2, 0x2, 0x2, 0x304, 0x305, 
    0x3, 0x2, 0x2, 0x2, 0x305, 0x306, 0x3, 0x2, 0x2, 0x2, 0x306, 0x308, 
    0x7, 0x8, 0x2, 0x2, 0x307, 0x302, 0x3, 0x2, 0x2, 0x2, 0x307, 0x308, 
    0x3, 0x2, 0x2, 0x2, 0x308, 0x30a, 0x3, 0x2, 0x2, 0x2, 0x309, 0x2f9, 
    0x3, 0x2, 0x2, 0x2, 0x309, 0x301, 0x3, 0x2, 0x2, 0x2, 0x30a, 0x75, 0x3, 
    0x2, 0x2, 0x2, 0x30b, 0x30c, 0x7, 0x72, 0x2, 0x2, 0x30c, 0x77, 0x3, 
    0x2, 0x2, 0x2, 0x30d, 0x30e, 0x9, 0xb, 0x2, 0x2, 0x30e, 0x79, 0x3, 0x2, 
    0x2, 0x2, 0x30f, 0x311, 0x7, 0x3, 0x2, 0x2, 0x310, 0x312, 0x5, 0x58, 
    0x2d, 0x2, 0x311, 0x310, 0x3, 0x2, 0x2, 0x2, 0x311, 0x312, 0x3, 0x2, 
    0x2, 0x2, 0x312, 0x313, 0x3, 0x2, 0x2, 0x2, 0x313, 0x314, 0x7, 0x4, 
    0x2, 0x2, 0x314, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x315, 0x31e, 0x7, 0x71, 
    0x2, 0x2, 0x316, 0x31e, 0x7, 0x70, 0x2, 0x2, 0x317, 0x31e, 0x7, 0x6e, 
    0x2, 0x2, 0x318, 0x31e, 0x7, 0x6f, 0x2, 0x2, 0x319, 0x31e, 0x5, 0x2c, 
    0x17, 0x2, 0x31a, 0x31e, 0x7, 0x64, 0x2, 0x2, 0x31b, 0x31e, 0x7, 0x45, 
    0x2, 0x2, 0x31c, 0x31e, 0x5, 0x7e, 0x40, 0x2, 0x31d, 0x315, 0x3, 0x2, 
    0x2, 0x2, 0x31d, 0x316, 0x3, 0x2, 0x2, 0x2, 0x31d, 0x317, 0x3, 0x2, 
    0x2, 0x2, 0x31d, 0x318, 0x3, 0x2, 0x2, 0x2, 0x31d, 0x319, 0x3, 0x2, 
    0x2, 0x2, 0x31d, 0x31a, 0x3, 0x2, 0x2, 0x2, 0x31d, 0x31b, 0x3, 0x2, 
    0x2, 0x2, 0x31d, 0x31c, 0x3, 0x2, 0x2, 0x2, 0x31e, 0x7d, 0x3, 0x2, 0x2, 
    0x2, 0x31f, 0x320, 0x7, 0x19, 0x2, 0x2, 0x320, 0x321, 0x7, 0x72, 0x2, 
    0x2, 0x321, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x58, 0x82, 0x89, 0x8b, 0x90, 
    0x94, 0x97, 0xa3, 0xb2, 0xba, 0xcf, 0xd1, 0xdb, 0xde, 0xec, 0xf0, 0xf9, 
    0xff, 0x106, 0x10d, 0x110, 0x113, 0x116, 0x11c, 0x11f, 0x125, 0x12f, 
    0x139, 0x145, 0x148, 0x14e, 0x15e, 0x160, 0x16c, 0x174, 0x177, 0x17d, 
    0x18d, 0x195, 0x197, 0x199, 0x19b, 0x19d, 0x1a6, 0x1b5, 0x1c8, 0x1f4, 
    0x1f9, 0x204, 0x212, 0x219, 0x21b, 0x222, 0x229, 0x22c, 0x237, 0x23a, 
    0x24b, 0x255, 0x25f, 0x264, 0x26b, 0x270, 0x278, 0x27d, 0x285, 0x292, 
    0x29a, 0x2a3, 0x2ad, 0x2b5, 0x2bd, 0x2c5, 0x2cd, 0x2d5, 0x2dd, 0x2e4, 
    0x2ec, 0x2f0, 0x2f3, 0x2fc, 0x2ff, 0x304, 0x307, 0x309, 0x311, 0x31d, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

TParser::Initializer TParser::_init;
