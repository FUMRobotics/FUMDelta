#-------------------------------------------------
#
# Project created by QtCreator 2019-07-22T14:31:47
#
#-------------------------------------------------

QT       += core gui
QT += testlib
QT += concurrent
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport


TARGET = DeltaPlotter-01
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    qcustomplot.cpp \
    receiver.cpp \
    plothandler.cpp \
    sendcommand.cpp \
    trajectorysender.cpp \
    dialog_loadpoints.cpp \
    inversekinematicscore.cpp \
    sevensegment.cpp \
    dialog_take_drives_home.cpp \
    kinematicsexception.cpp \
    test/test.cpp \
    codeeditor.cpp \
    files.cpp \
    highlighter.cpp \
    search.cpp \
    utils/conversion.cpp \
    utils/templates.cpp \
    widgets/geisttextedit.cpp \
    generated/TParserVisitor.cpp \
    generated/TParserListener.cpp \
    generated/TParserBaseVisitor.cpp \
    generated/TParserBaseListener.cpp \
    generated/TParser.cpp \
    generated/TLexer.cpp \
    antlr4/runtime/Cpp/runtime/src/WritableToken.cpp \
    antlr4/runtime/Cpp/runtime/src/Vocabulary.cpp \
    antlr4/runtime/Cpp/runtime/src/UnbufferedTokenStream.cpp \
    antlr4/runtime/Cpp/runtime/src/UnbufferedCharStream.cpp \
    antlr4/runtime/Cpp/runtime/src/TokenStreamRewriter.cpp \
    antlr4/runtime/Cpp/runtime/src/TokenStream.cpp \
    antlr4/runtime/Cpp/runtime/src/TokenSource.cpp \
    antlr4/runtime/Cpp/runtime/src/Token.cpp \
    antlr4/runtime/Cpp/runtime/src/RuntimeMetaData.cpp \
    antlr4/runtime/Cpp/runtime/src/RuleContextWithAltNum.cpp \
    antlr4/runtime/Cpp/runtime/src/RuleContext.cpp \
    antlr4/runtime/Cpp/runtime/src/Recognizer.cpp \
    antlr4/runtime/Cpp/runtime/src/RecognitionException.cpp \
    antlr4/runtime/Cpp/runtime/src/ProxyErrorListener.cpp \
    antlr4/runtime/Cpp/runtime/src/ParserRuleContext.cpp \
    antlr4/runtime/Cpp/runtime/src/ParserInterpreter.cpp \
    antlr4/runtime/Cpp/runtime/src/Parser.cpp \
    antlr4/runtime/Cpp/runtime/src/NoViableAltException.cpp \
    antlr4/runtime/Cpp/runtime/src/ListTokenSource.cpp \
    antlr4/runtime/Cpp/runtime/src/LexerNoViableAltException.cpp \
    antlr4/runtime/Cpp/runtime/src/LexerInterpreter.cpp \
    antlr4/runtime/Cpp/runtime/src/Lexer.cpp \
    antlr4/runtime/Cpp/runtime/src/IntStream.cpp \
    antlr4/runtime/Cpp/runtime/src/InterpreterRuleContext.cpp \
    antlr4/runtime/Cpp/runtime/src/InputMismatchException.cpp \
    antlr4/runtime/Cpp/runtime/src/FailedPredicateException.cpp \
    antlr4/runtime/Cpp/runtime/src/Exceptions.cpp \
    antlr4/runtime/Cpp/runtime/src/DiagnosticErrorListener.cpp \
    antlr4/runtime/Cpp/runtime/src/DefaultErrorStrategy.cpp \
    antlr4/runtime/Cpp/runtime/src/ConsoleErrorListener.cpp \
    antlr4/runtime/Cpp/runtime/src/CommonTokenStream.cpp \
    antlr4/runtime/Cpp/runtime/src/CommonTokenFactory.cpp \
    antlr4/runtime/Cpp/runtime/src/CommonToken.cpp \
    antlr4/runtime/Cpp/runtime/src/CharStream.cpp \
    antlr4/runtime/Cpp/runtime/src/BufferedTokenStream.cpp \
    antlr4/runtime/Cpp/runtime/src/BaseErrorListener.cpp \
    antlr4/runtime/Cpp/runtime/src/BailErrorStrategy.cpp \
    antlr4/runtime/Cpp/runtime/src/ANTLRInputStream.cpp \
    antlr4/runtime/Cpp/runtime/src/ANTLRFileStream.cpp \
    antlr4/runtime/Cpp/runtime/src/ANTLRErrorStrategy.cpp \
    antlr4/runtime/Cpp/runtime/src/ANTLRErrorListener.cpp \
    antlr4/runtime/Cpp/runtime/src/tree/Trees.cpp \
    antlr4/runtime/Cpp/runtime/src/tree/TerminalNodeImpl.cpp \
    antlr4/runtime/Cpp/runtime/src/tree/TerminalNode.cpp \
    antlr4/runtime/Cpp/runtime/src/tree/ParseTreeWalker.cpp \
    antlr4/runtime/Cpp/runtime/src/tree/ParseTreeVisitor.cpp \
    antlr4/runtime/Cpp/runtime/src/tree/ParseTreeListener.cpp \
    antlr4/runtime/Cpp/runtime/src/tree/ParseTree.cpp \
    antlr4/runtime/Cpp/runtime/src/tree/IterativeParseTreeWalker.cpp \
    antlr4/runtime/Cpp/runtime/src/tree/ErrorNodeImpl.cpp \
    antlr4/runtime/Cpp/runtime/src/tree/ErrorNode.cpp \
    antlr4/runtime/Cpp/runtime/src/tree/xpath/XPathWildcardElement.cpp \
    antlr4/runtime/Cpp/runtime/src/tree/xpath/XPathWildcardAnywhereElement.cpp \
    antlr4/runtime/Cpp/runtime/src/tree/xpath/XPathTokenElement.cpp \
    antlr4/runtime/Cpp/runtime/src/tree/xpath/XPathTokenAnywhereElement.cpp \
    antlr4/runtime/Cpp/runtime/src/tree/xpath/XPathRuleElement.cpp \
    antlr4/runtime/Cpp/runtime/src/tree/xpath/XPathRuleAnywhereElement.cpp \
    antlr4/runtime/Cpp/runtime/src/tree/xpath/XPathLexerErrorListener.cpp \
    antlr4/runtime/Cpp/runtime/src/tree/xpath/XPathLexer.cpp \
    antlr4/runtime/Cpp/runtime/src/tree/xpath/XPathElement.cpp \
    antlr4/runtime/Cpp/runtime/src/tree/xpath/XPath.cpp \
    antlr4/runtime/Cpp/runtime/src/tree/pattern/TokenTagToken.cpp \
    antlr4/runtime/Cpp/runtime/src/tree/pattern/TextChunk.cpp \
    antlr4/runtime/Cpp/runtime/src/tree/pattern/TagChunk.cpp \
    antlr4/runtime/Cpp/runtime/src/tree/pattern/RuleTagToken.cpp \
    antlr4/runtime/Cpp/runtime/src/tree/pattern/ParseTreePatternMatcher.cpp \
    antlr4/runtime/Cpp/runtime/src/tree/pattern/ParseTreePattern.cpp \
    antlr4/runtime/Cpp/runtime/src/tree/pattern/ParseTreeMatch.cpp \
    antlr4/runtime/Cpp/runtime/src/tree/pattern/Chunk.cpp \
    antlr4/runtime/Cpp/runtime/src/support/StringUtils.cpp \
    antlr4/runtime/Cpp/runtime/src/support/guid.cpp \
    antlr4/runtime/Cpp/runtime/src/support/CPPUtils.cpp \
    antlr4/runtime/Cpp/runtime/src/support/Arrays.cpp \
    antlr4/runtime/Cpp/runtime/src/support/Any.cpp \
    antlr4/runtime/Cpp/runtime/src/misc/Predicate.cpp \
    antlr4/runtime/Cpp/runtime/src/misc/MurmurHash.cpp \
    antlr4/runtime/Cpp/runtime/src/misc/IntervalSet.cpp \
    antlr4/runtime/Cpp/runtime/src/misc/Interval.cpp \
    antlr4/runtime/Cpp/runtime/src/misc/InterpreterDataReader.cpp \
    antlr4/runtime/Cpp/runtime/src/dfa/LexerDFASerializer.cpp \
    antlr4/runtime/Cpp/runtime/src/dfa/DFAState.cpp \
    antlr4/runtime/Cpp/runtime/src/dfa/DFASerializer.cpp \
    antlr4/runtime/Cpp/runtime/src/dfa/DFA.cpp \
    antlr4/runtime/Cpp/runtime/src/atn/WildcardTransition.cpp \
    antlr4/runtime/Cpp/runtime/src/atn/Transition.cpp \
    antlr4/runtime/Cpp/runtime/src/atn/TokensStartState.cpp \
    antlr4/runtime/Cpp/runtime/src/atn/StarLoopEntryState.cpp \
    antlr4/runtime/Cpp/runtime/src/atn/StarLoopbackState.cpp \
    antlr4/runtime/Cpp/runtime/src/atn/StarBlockStartState.cpp \
    antlr4/runtime/Cpp/runtime/src/atn/SingletonPredictionContext.cpp \
    antlr4/runtime/Cpp/runtime/src/atn/SetTransition.cpp \
    antlr4/runtime/Cpp/runtime/src/atn/SemanticContext.cpp \
    antlr4/runtime/Cpp/runtime/src/atn/RuleTransition.cpp \
    antlr4/runtime/Cpp/runtime/src/atn/RuleStopState.cpp \
    antlr4/runtime/Cpp/runtime/src/atn/RuleStartState.cpp \
    antlr4/runtime/Cpp/runtime/src/atn/RangeTransition.cpp \
    antlr4/runtime/Cpp/runtime/src/atn/ProfilingATNSimulator.cpp \
    antlr4/runtime/Cpp/runtime/src/atn/PredictionMode.cpp \
    antlr4/runtime/Cpp/runtime/src/atn/PredictionContext.cpp \
    antlr4/runtime/Cpp/runtime/src/atn/PredicateTransition.cpp \
    antlr4/runtime/Cpp/runtime/src/atn/PredicateEvalInfo.cpp \
    antlr4/runtime/Cpp/runtime/src/atn/PrecedencePredicateTransition.cpp \
    antlr4/runtime/Cpp/runtime/src/atn/PlusLoopbackState.cpp \
    antlr4/runtime/Cpp/runtime/src/atn/PlusBlockStartState.cpp \
    antlr4/runtime/Cpp/runtime/src/atn/ParserATNSimulator.cpp \
    antlr4/runtime/Cpp/runtime/src/atn/ParseInfo.cpp \
    antlr4/runtime/Cpp/runtime/src/atn/OrderedATNConfigSet.cpp \
    antlr4/runtime/Cpp/runtime/src/atn/NotSetTransition.cpp \
    antlr4/runtime/Cpp/runtime/src/atn/LoopEndState.cpp \
    antlr4/runtime/Cpp/runtime/src/atn/LookaheadEventInfo.cpp \
    antlr4/runtime/Cpp/runtime/src/atn/LL1Analyzer.cpp \
    antlr4/runtime/Cpp/runtime/src/atn/LexerTypeAction.cpp \
    antlr4/runtime/Cpp/runtime/src/atn/LexerSkipAction.cpp \
    antlr4/runtime/Cpp/runtime/src/atn/LexerPushModeAction.cpp \
    antlr4/runtime/Cpp/runtime/src/atn/LexerPopModeAction.cpp \
    antlr4/runtime/Cpp/runtime/src/atn/LexerMoreAction.cpp \
    antlr4/runtime/Cpp/runtime/src/atn/LexerModeAction.cpp \
    antlr4/runtime/Cpp/runtime/src/atn/LexerIndexedCustomAction.cpp \
    antlr4/runtime/Cpp/runtime/src/atn/LexerCustomAction.cpp \
    antlr4/runtime/Cpp/runtime/src/atn/LexerChannelAction.cpp \
    antlr4/runtime/Cpp/runtime/src/atn/LexerATNSimulator.cpp \
    antlr4/runtime/Cpp/runtime/src/atn/LexerATNConfig.cpp \
    antlr4/runtime/Cpp/runtime/src/atn/LexerActionExecutor.cpp \
    antlr4/runtime/Cpp/runtime/src/atn/LexerAction.cpp \
    antlr4/runtime/Cpp/runtime/src/atn/ErrorInfo.cpp \
    antlr4/runtime/Cpp/runtime/src/atn/EpsilonTransition.cpp \
    antlr4/runtime/Cpp/runtime/src/atn/EmptyPredictionContext.cpp \
    antlr4/runtime/Cpp/runtime/src/atn/DecisionState.cpp \
    antlr4/runtime/Cpp/runtime/src/atn/DecisionInfo.cpp \
    antlr4/runtime/Cpp/runtime/src/atn/DecisionEventInfo.cpp \
    antlr4/runtime/Cpp/runtime/src/atn/ContextSensitivityInfo.cpp \
    antlr4/runtime/Cpp/runtime/src/atn/BlockStartState.cpp \
    antlr4/runtime/Cpp/runtime/src/atn/BlockEndState.cpp \
    antlr4/runtime/Cpp/runtime/src/atn/BasicState.cpp \
    antlr4/runtime/Cpp/runtime/src/atn/BasicBlockStartState.cpp \
    antlr4/runtime/Cpp/runtime/src/atn/AtomTransition.cpp \
    antlr4/runtime/Cpp/runtime/src/atn/ATNState.cpp \
    antlr4/runtime/Cpp/runtime/src/atn/ATNSimulator.cpp \
    antlr4/runtime/Cpp/runtime/src/atn/ATNSerializer.cpp \
    antlr4/runtime/Cpp/runtime/src/atn/ATNDeserializer.cpp \
    antlr4/runtime/Cpp/runtime/src/atn/ATNDeserializationOptions.cpp \
    antlr4/runtime/Cpp/runtime/src/atn/ATNConfigSet.cpp \
    antlr4/runtime/Cpp/runtime/src/atn/ATNConfig.cpp \
    antlr4/runtime/Cpp/runtime/src/atn/ATN.cpp \
    antlr4/runtime/Cpp/runtime/src/atn/ArrayPredictionContext.cpp \
    antlr4/runtime/Cpp/runtime/src/atn/AmbiguityInfo.cpp \
    antlr4/runtime/Cpp/runtime/src/atn/ActionTransition.cpp \
    antlr4/runtime/Cpp/runtime/src/atn/AbstractPredicateTransition.cpp \
    interpretercore.cpp \
    statement.cpp \
    variable.cpp \
    intVariable.cpp \
    boolVariable.cpp \
    block.cpp \
    posVariable.cpp \
    conditionalBlock.cpp \
    assignmentStatement.cpp \
    linearMovementStatement.cpp \
    ptpPosMovementStatement.cpp \
    ptpAxisMovementStatement.cpp \
    circularMovementStatement.cpp \
    forStatement.cpp \
    whileStatement.cpp \
    ifStatement.cpp \
    realVariable.cpp \
    scope.cpp
    robotstate.cpp

HEADERS += \
        mainwindow.h \
    qcustomplot.h \
    receiver.h \
    plothandler.h \
    sendcommand.h \
    trajectorysender.h \
    dialog_loadpoints.h \
    inversekinematicscore.h \
    sevensegment.h \
    kinematicsexception.h\
    dialog_take_drives_home.h \
    codeeditor.h \
    files.h \
    highlighter.h \
    search.h \
    utils/conversion.h \
    utils/templates.h \
    widgets/geisttextedit.h \
    generated/TParserVisitor.h \
    generated/TParserListener.h \
    generated/TParserBaseVisitor.h \
    generated/TParserBaseListener.h \
    generated/TParser.h \
    generated/TLexer.h \
    antlr4/runtime/Cpp/runtime/src/WritableToken.h \
    antlr4/runtime/Cpp/runtime/src/Vocabulary.h \
    antlr4/runtime/Cpp/runtime/src/UnbufferedTokenStream.h \
    antlr4/runtime/Cpp/runtime/src/UnbufferedCharStream.h \
    antlr4/runtime/Cpp/runtime/src/TokenStreamRewriter.h \
    antlr4/runtime/Cpp/runtime/src/TokenStream.h \
    antlr4/runtime/Cpp/runtime/src/TokenSource.h \
    antlr4/runtime/Cpp/runtime/src/TokenFactory.h \
    antlr4/runtime/Cpp/runtime/src/Token.h \
    antlr4/runtime/Cpp/runtime/src/RuntimeMetaData.h \
    antlr4/runtime/Cpp/runtime/src/RuleContextWithAltNum.h \
    antlr4/runtime/Cpp/runtime/src/RuleContext.h \
    antlr4/runtime/Cpp/runtime/src/Recognizer.h \
    antlr4/runtime/Cpp/runtime/src/RecognitionException.h \
    antlr4/runtime/Cpp/runtime/src/ProxyErrorListener.h \
    antlr4/runtime/Cpp/runtime/src/ParserRuleContext.h \
    antlr4/runtime/Cpp/runtime/src/ParserInterpreter.h \
    antlr4/runtime/Cpp/runtime/src/Parser.h \
    antlr4/runtime/Cpp/runtime/src/NoViableAltException.h \
    antlr4/runtime/Cpp/runtime/src/ListTokenSource.h \
    antlr4/runtime/Cpp/runtime/src/LexerNoViableAltException.h \
    antlr4/runtime/Cpp/runtime/src/LexerInterpreter.h \
    antlr4/runtime/Cpp/runtime/src/Lexer.h \
    antlr4/runtime/Cpp/runtime/src/IntStream.h \
    antlr4/runtime/Cpp/runtime/src/InterpreterRuleContext.h \
    antlr4/runtime/Cpp/runtime/src/InputMismatchException.h \
    antlr4/runtime/Cpp/runtime/src/FailedPredicateException.h \
    antlr4/runtime/Cpp/runtime/src/Exceptions.h \
    antlr4/runtime/Cpp/runtime/src/DiagnosticErrorListener.h \
    antlr4/runtime/Cpp/runtime/src/DefaultErrorStrategy.h \
    antlr4/runtime/Cpp/runtime/src/ConsoleErrorListener.h \
    antlr4/runtime/Cpp/runtime/src/CommonTokenStream.h \
    antlr4/runtime/Cpp/runtime/src/CommonTokenFactory.h \
    antlr4/runtime/Cpp/runtime/src/CommonToken.h \
    antlr4/runtime/Cpp/runtime/src/CharStream.h \
    antlr4/runtime/Cpp/runtime/src/BufferedTokenStream.h \
    antlr4/runtime/Cpp/runtime/src/BaseErrorListener.h \
    antlr4/runtime/Cpp/runtime/src/BailErrorStrategy.h \
    antlr4/runtime/Cpp/runtime/src/ANTLRInputStream.h \
    antlr4/runtime/Cpp/runtime/src/ANTLRFileStream.h \
    antlr4/runtime/Cpp/runtime/src/ANTLRErrorStrategy.h \
    antlr4/runtime/Cpp/runtime/src/ANTLRErrorListener.h \
    antlr4/runtime/Cpp/runtime/src/antlr4-runtime.h \
    antlr4/runtime/Cpp/runtime/src/antlr4-common.h \
    antlr4/runtime/Cpp/runtime/src/tree/Trees.h \
    antlr4/runtime/Cpp/runtime/src/tree/TerminalNodeImpl.h \
    antlr4/runtime/Cpp/runtime/src/tree/TerminalNode.h \
    antlr4/runtime/Cpp/runtime/src/tree/ParseTreeWalker.h \
    antlr4/runtime/Cpp/runtime/src/tree/ParseTreeVisitor.h \
    antlr4/runtime/Cpp/runtime/src/tree/ParseTreeProperty.h \
    antlr4/runtime/Cpp/runtime/src/tree/ParseTreeListener.h \
    antlr4/runtime/Cpp/runtime/src/tree/ParseTree.h \
    antlr4/runtime/Cpp/runtime/src/tree/IterativeParseTreeWalker.h \
    antlr4/runtime/Cpp/runtime/src/tree/ErrorNodeImpl.h \
    antlr4/runtime/Cpp/runtime/src/tree/ErrorNode.h \
    antlr4/runtime/Cpp/runtime/src/tree/AbstractParseTreeVisitor.h \
    antlr4/runtime/Cpp/runtime/src/tree/xpath/XPathWildcardElement.h \
    antlr4/runtime/Cpp/runtime/src/tree/xpath/XPathWildcardAnywhereElement.h \
    antlr4/runtime/Cpp/runtime/src/tree/xpath/XPathTokenElement.h \
    antlr4/runtime/Cpp/runtime/src/tree/xpath/XPathTokenAnywhereElement.h \
    antlr4/runtime/Cpp/runtime/src/tree/xpath/XPathRuleElement.h \
    antlr4/runtime/Cpp/runtime/src/tree/xpath/XPathRuleAnywhereElement.h \
    antlr4/runtime/Cpp/runtime/src/tree/xpath/XPathLexerErrorListener.h \
    antlr4/runtime/Cpp/runtime/src/tree/xpath/XPathLexer.h \
    antlr4/runtime/Cpp/runtime/src/tree/xpath/XPathElement.h \
    antlr4/runtime/Cpp/runtime/src/tree/xpath/XPath.h \
    antlr4/runtime/Cpp/runtime/src/tree/pattern/TokenTagToken.h \
    antlr4/runtime/Cpp/runtime/src/tree/pattern/TextChunk.h \
    antlr4/runtime/Cpp/runtime/src/tree/pattern/TagChunk.h \
    antlr4/runtime/Cpp/runtime/src/tree/pattern/RuleTagToken.h \
    antlr4/runtime/Cpp/runtime/src/tree/pattern/ParseTreePatternMatcher.h \
    antlr4/runtime/Cpp/runtime/src/tree/pattern/ParseTreePattern.h \
    antlr4/runtime/Cpp/runtime/src/tree/pattern/ParseTreeMatch.h \
    antlr4/runtime/Cpp/runtime/src/tree/pattern/Chunk.h \
    antlr4/runtime/Cpp/runtime/src/support/StringUtils.h \
    antlr4/runtime/Cpp/runtime/src/support/guid.h \
    antlr4/runtime/Cpp/runtime/src/support/Declarations.h \
    antlr4/runtime/Cpp/runtime/src/support/CPPUtils.h \
    antlr4/runtime/Cpp/runtime/src/support/BitSet.h \
    antlr4/runtime/Cpp/runtime/src/support/Arrays.h \
    antlr4/runtime/Cpp/runtime/src/support/Any.h \
    antlr4/runtime/Cpp/runtime/src/misc/Predicate.h \
    antlr4/runtime/Cpp/runtime/src/misc/MurmurHash.h \
    antlr4/runtime/Cpp/runtime/src/misc/IntervalSet.h \
    antlr4/runtime/Cpp/runtime/src/misc/Interval.h \
    antlr4/runtime/Cpp/runtime/src/misc/InterpreterDataReader.h \
    antlr4/runtime/Cpp/runtime/src/dfa/LexerDFASerializer.h \
    antlr4/runtime/Cpp/runtime/src/dfa/DFAState.h \
    antlr4/runtime/Cpp/runtime/src/dfa/DFASerializer.h \
    antlr4/runtime/Cpp/runtime/src/dfa/DFA.h \
    antlr4/runtime/Cpp/runtime/src/atn/WildcardTransition.h \
    antlr4/runtime/Cpp/runtime/src/atn/Transition.h \
    antlr4/runtime/Cpp/runtime/src/atn/TokensStartState.h \
    antlr4/runtime/Cpp/runtime/src/atn/StarLoopEntryState.h \
    antlr4/runtime/Cpp/runtime/src/atn/StarLoopbackState.h \
    antlr4/runtime/Cpp/runtime/src/atn/StarBlockStartState.h \
    antlr4/runtime/Cpp/runtime/src/atn/SingletonPredictionContext.h \
    antlr4/runtime/Cpp/runtime/src/atn/SetTransition.h \
    antlr4/runtime/Cpp/runtime/src/atn/SemanticContext.h \
    antlr4/runtime/Cpp/runtime/src/atn/RuleTransition.h \
    antlr4/runtime/Cpp/runtime/src/atn/RuleStopState.h \
    antlr4/runtime/Cpp/runtime/src/atn/RuleStartState.h \
    antlr4/runtime/Cpp/runtime/src/atn/RangeTransition.h \
    antlr4/runtime/Cpp/runtime/src/atn/ProfilingATNSimulator.h \
    antlr4/runtime/Cpp/runtime/src/atn/PredictionMode.h \
    antlr4/runtime/Cpp/runtime/src/atn/PredictionContext.h \
    antlr4/runtime/Cpp/runtime/src/atn/PredicateTransition.h \
    antlr4/runtime/Cpp/runtime/src/atn/PredicateEvalInfo.h \
    antlr4/runtime/Cpp/runtime/src/atn/PrecedencePredicateTransition.h \
    antlr4/runtime/Cpp/runtime/src/atn/PlusLoopbackState.h \
    antlr4/runtime/Cpp/runtime/src/atn/PlusBlockStartState.h \
    antlr4/runtime/Cpp/runtime/src/atn/ParserATNSimulator.h \
    antlr4/runtime/Cpp/runtime/src/atn/ParseInfo.h \
    antlr4/runtime/Cpp/runtime/src/atn/OrderedATNConfigSet.h \
    antlr4/runtime/Cpp/runtime/src/atn/NotSetTransition.h \
    antlr4/runtime/Cpp/runtime/src/atn/LoopEndState.h \
    antlr4/runtime/Cpp/runtime/src/atn/LookaheadEventInfo.h \
    antlr4/runtime/Cpp/runtime/src/atn/LL1Analyzer.h \
    antlr4/runtime/Cpp/runtime/src/atn/LexerTypeAction.h \
    antlr4/runtime/Cpp/runtime/src/atn/LexerSkipAction.h \
    antlr4/runtime/Cpp/runtime/src/atn/LexerPushModeAction.h \
    antlr4/runtime/Cpp/runtime/src/atn/LexerPopModeAction.h \
    antlr4/runtime/Cpp/runtime/src/atn/LexerMoreAction.h \
    antlr4/runtime/Cpp/runtime/src/atn/LexerModeAction.h \
    antlr4/runtime/Cpp/runtime/src/atn/LexerIndexedCustomAction.h \
    antlr4/runtime/Cpp/runtime/src/atn/LexerCustomAction.h \
    antlr4/runtime/Cpp/runtime/src/atn/LexerChannelAction.h \
    antlr4/runtime/Cpp/runtime/src/atn/LexerATNSimulator.h \
    antlr4/runtime/Cpp/runtime/src/atn/LexerATNConfig.h \
    antlr4/runtime/Cpp/runtime/src/atn/LexerActionType.h \
    antlr4/runtime/Cpp/runtime/src/atn/LexerActionExecutor.h \
    antlr4/runtime/Cpp/runtime/src/atn/LexerAction.h \
    antlr4/runtime/Cpp/runtime/src/atn/ErrorInfo.h \
    antlr4/runtime/Cpp/runtime/src/atn/EpsilonTransition.h \
    antlr4/runtime/Cpp/runtime/src/atn/EmptyPredictionContext.h \
    antlr4/runtime/Cpp/runtime/src/atn/DecisionState.h \
    antlr4/runtime/Cpp/runtime/src/atn/DecisionInfo.h \
    antlr4/runtime/Cpp/runtime/src/atn/DecisionEventInfo.h \
    antlr4/runtime/Cpp/runtime/src/atn/ContextSensitivityInfo.h \
    antlr4/runtime/Cpp/runtime/src/atn/BlockStartState.h \
    antlr4/runtime/Cpp/runtime/src/atn/BlockEndState.h \
    antlr4/runtime/Cpp/runtime/src/atn/BasicState.h \
    antlr4/runtime/Cpp/runtime/src/atn/BasicBlockStartState.h \
    antlr4/runtime/Cpp/runtime/src/atn/AtomTransition.h \
    antlr4/runtime/Cpp/runtime/src/atn/ATNType.h \
    antlr4/runtime/Cpp/runtime/src/atn/ATNState.h \
    antlr4/runtime/Cpp/runtime/src/atn/ATNSimulator.h \
    antlr4/runtime/Cpp/runtime/src/atn/ATNSerializer.h \
    antlr4/runtime/Cpp/runtime/src/atn/ATNDeserializer.h \
    antlr4/runtime/Cpp/runtime/src/atn/ATNDeserializationOptions.h \
    antlr4/runtime/Cpp/runtime/src/atn/ATNConfigSet.h \
    antlr4/runtime/Cpp/runtime/src/atn/ATNConfig.h \
    antlr4/runtime/Cpp/runtime/src/atn/ATN.h \
    antlr4/runtime/Cpp/runtime/src/atn/ArrayPredictionContext.h \
    antlr4/runtime/Cpp/runtime/src/atn/AmbiguityInfo.h \
    antlr4/runtime/Cpp/runtime/src/atn/ActionTransition.h \
    antlr4/runtime/Cpp/runtime/src/atn/AbstractPredicateTransition.h \
    interpretercore.h \
    statement.h \
    variable.h \
    intVariable.h \
    boolVariable.h \
    block.h \
    posVariable.h \
    conditionalBlock.h \
    assignmentStatement.h \
    linearMovementStatement.h \
    circularMovementStatement.h \
    ptpAxisMovementStatement.h \
    ptpPosMovementStatement.h \
    forStatement.h \
    whileStatement.h \
    ifStatement.h \
    realVariable.h \
    scope.h
    robotstate.h

FORMS += \
    dialog_loadpoints.ui \
    dialog_take_drives_home.ui \
    mainwindow.ui \
    codeeditor.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += qrcfile.qrc

DISTFILES += \
    generated/TParser.tokens \
    generated/TParser.interp \
    generated/TLexer.tokens \
    generated/TLexer.interp \
    antlr4/runtime/Cpp/runtime/src/tree/xpath/XPathLexer.tokens \
    antlr4/runtime/Cpp/runtime/src/tree/xpath/XPathLexer.g4 \
    antlr4/runtime/Cpp/runtime/src/atn/Makefile

INCLUDEPATH +=eigen/
INCLUDEPATH +=antlr4/runtime/Cpp/runtime/src/
INCLUDEPATH+=generated/
