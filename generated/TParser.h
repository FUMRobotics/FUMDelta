
// Generated from /home/fatemeh/Documents/antlr4-delta/runtime/Cpp/demo/TParser.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"


namespace antlrcpptest {


class  TParser : public antlr4::Parser {
public:
  enum {
    LPAREN = 1, RPAREN = 2, LBRACE = 3, RBRACE = 4, LBRACK = 5, RBRACK = 6, 
    SEMI = 7, COMMA = 8, DOT = 9, ASSIGN = 10, GT = 11, LT = 12, COLON = 13, 
    EQUAL = 14, LE = 15, GE = 16, NOT_EQUAL = 17, ADD = 18, SUB = 19, MUL = 20, 
    DIV = 21, MOD = 22, NUMBER = 23, DIERESIS = 24, R1 = 25, AND = 26, ANIN = 27, 
    ANOUT = 28, B_AND = 29, B_NOT = 30, B_OR = 31, B_EXOR = 32, BOOL = 33, 
    BRAKE = 34, C_DIS = 35, C_ORI = 36, C_PTP = 37, C_VEL = 38, CASE = 39, 
    CAST_FROM = 40, CAST_TO = 41, CHAR = 42, CIRC_REL = 43, CIRC = 44, CONST = 45, 
    CONTINUE = 46, DELAY = 47, DECL = 48, DEF = 49, DEFAULT = 50, DEFDAT = 51, 
    DEFFCT = 52, DO = 53, ELSE = 54, END = 55, ENDDAT = 56, ENDFCT = 57, 
    ENDFOR = 58, ENDIF = 59, ENDLOOP = 60, ENDSWITCH = 61, ENDWHILE = 62, 
    ENUM = 63, EXIT = 64, EXT = 65, EXTFCT = 66, FALSE = 67, FOR = 68, GLOBAL = 69, 
    GOTO = 70, HALT = 71, IF = 72, IMPORT = 73, INTERRUPT = 74, INT = 75, 
    IS = 76, LIN_REL = 77, LIN = 78, LOOP = 79, MAXIMUM = 80, MINIMUM = 81, 
    NOT = 82, OR = 83, PRIO = 84, PTP_REL = 85, PTP = 86, PUBLIC = 87, REAL = 88, 
    REPEAT = 89, RETURN = 90, SEC = 91, SIGNAL = 92, STRUC = 93, SWITCH = 94, 
    THEN = 95, TO = 96, TRIGGER = 97, TRUE = 98, UNTIL = 99, WAIT = 100, 
    WHEN = 101, WHILE = 102, EXOR = 103, HEADERLINE = 104, WS = 105, NEWLINE = 106, 
    LINE_COMMENT = 107, CHARLITERAL = 108, STRINGLITERAL = 109, FLOATLITERAL = 110, 
    INTLITERAL = 111, IDENTIFIER = 112
  };

  enum {
    RuleModule = 0, RuleModuleRoutines = 1, RuleMainRoutine = 2, RuleSubRoutine = 3, 
    RuleProcedureDefinition = 4, RuleProcedureName = 5, RuleFunctionDefinition = 6, 
    RuleFunctionName = 7, RuleModuleData = 8, RuleModuleName = 9, RuleDataList = 10, 
    RuleArrayInitialisation = 11, RuleTypeDeclaration = 12, RuleStructureDefinition = 13, 
    RuleEnumDefinition = 14, RuleEnumValue = 15, RuleVariableDeclaration = 16, 
    RuleSignalDeclaration = 17, RuleVariableDeclarationInDataList = 18, 
    RuleVariableListRest = 19, RuleVariableInitialisation = 20, RuleStructLiteral = 21, 
    RuleStructElementList = 22, RuleStructElement = 23, RuleFormalParameters = 24, 
    RuleParameter = 25, RuleRoutineBody = 26, RuleRoutineDataSection = 27, 
    RuleForwardDeclaration = 28, RuleFormalParametersWithType = 29, RuleParameterWithType = 30, 
    RuleParameterCallType = 31, RuleImportStatement = 32, RuleVariableName = 33, 
    RuleArrayVariableSuffix = 34, RuleRoutineImplementationSection = 35, 
    RuleStatementList = 36, RuleStatement = 37, RuleAnalogOutputStatement = 38, 
    RuleAnalogInputStatement = 39, RuleSwitchBlockStatementGroups = 40, 
    RuleCaseLabel = 41, RuleDefaultLabel = 42, RuleExpressionList = 43, 
    RuleAssignmentExpression = 44, RuleExpression = 45, RuleRelationalOp = 46, 
    RuleConditionalOrExpression = 47, RuleExclusiveOrExpression = 48, RuleConditionalAndExpression = 49, 
    RuleAdditiveExpression = 50, RuleMultiplicativeExpression = 51, RuleGeometricExpression = 52, 
    RuleUnaryNotExpression = 53, RuleUnaryPlusMinuxExpression = 54, RulePrimary = 55, 
    RuleParExpression = 56, RuleType = 57, RuleTypeName = 58, RulePrimitiveType = 59, 
    RuleArguments = 60, RuleLiteral = 61, RuleEnumElement = 62
  };

  TParser(antlr4::TokenStream *input);
  ~TParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class ModuleContext;
  class ModuleRoutinesContext;
  class MainRoutineContext;
  class SubRoutineContext;
  class ProcedureDefinitionContext;
  class ProcedureNameContext;
  class FunctionDefinitionContext;
  class FunctionNameContext;
  class ModuleDataContext;
  class ModuleNameContext;
  class DataListContext;
  class ArrayInitialisationContext;
  class TypeDeclarationContext;
  class StructureDefinitionContext;
  class EnumDefinitionContext;
  class EnumValueContext;
  class VariableDeclarationContext;
  class SignalDeclarationContext;
  class VariableDeclarationInDataListContext;
  class VariableListRestContext;
  class VariableInitialisationContext;
  class StructLiteralContext;
  class StructElementListContext;
  class StructElementContext;
  class FormalParametersContext;
  class ParameterContext;
  class RoutineBodyContext;
  class RoutineDataSectionContext;
  class ForwardDeclarationContext;
  class FormalParametersWithTypeContext;
  class ParameterWithTypeContext;
  class ParameterCallTypeContext;
  class ImportStatementContext;
  class VariableNameContext;
  class ArrayVariableSuffixContext;
  class RoutineImplementationSectionContext;
  class StatementListContext;
  class StatementContext;
  class AnalogOutputStatementContext;
  class AnalogInputStatementContext;
  class SwitchBlockStatementGroupsContext;
  class CaseLabelContext;
  class DefaultLabelContext;
  class ExpressionListContext;
  class AssignmentExpressionContext;
  class ExpressionContext;
  class RelationalOpContext;
  class ConditionalOrExpressionContext;
  class ExclusiveOrExpressionContext;
  class ConditionalAndExpressionContext;
  class AdditiveExpressionContext;
  class MultiplicativeExpressionContext;
  class GeometricExpressionContext;
  class UnaryNotExpressionContext;
  class UnaryPlusMinuxExpressionContext;
  class PrimaryContext;
  class ParExpressionContext;
  class TypeContext;
  class TypeNameContext;
  class PrimitiveTypeContext;
  class ArgumentsContext;
  class LiteralContext;
  class EnumElementContext; 

  class  ModuleContext : public antlr4::ParserRuleContext {
  public:
    ModuleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    ModuleDataContext *moduleData();
    ModuleRoutinesContext *moduleRoutines();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ModuleContext* module();

  class  ModuleRoutinesContext : public antlr4::ParserRuleContext {
  public:
    ModuleRoutinesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    MainRoutineContext *mainRoutine();
    std::vector<SubRoutineContext *> subRoutine();
    SubRoutineContext* subRoutine(size_t i);
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ModuleRoutinesContext* moduleRoutines();

  class  MainRoutineContext : public antlr4::ParserRuleContext {
  public:
    MainRoutineContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ProcedureDefinitionContext *procedureDefinition();
    FunctionDefinitionContext *functionDefinition();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MainRoutineContext* mainRoutine();

  class  SubRoutineContext : public antlr4::ParserRuleContext {
  public:
    SubRoutineContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ProcedureDefinitionContext *procedureDefinition();
    FunctionDefinitionContext *functionDefinition();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SubRoutineContext* subRoutine();

  class  ProcedureDefinitionContext : public antlr4::ParserRuleContext {
  public:
    ProcedureDefinitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DEF();
    ProcedureNameContext *procedureName();
    FormalParametersContext *formalParameters();
    antlr4::tree::TerminalNode *NEWLINE();
    RoutineBodyContext *routineBody();
    antlr4::tree::TerminalNode *END();
    antlr4::tree::TerminalNode *GLOBAL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProcedureDefinitionContext* procedureDefinition();

  class  ProcedureNameContext : public antlr4::ParserRuleContext {
  public:
    ProcedureNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProcedureNameContext* procedureName();

  class  FunctionDefinitionContext : public antlr4::ParserRuleContext {
  public:
    FunctionDefinitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DEFFCT();
    TypeContext *type();
    FunctionNameContext *functionName();
    FormalParametersContext *formalParameters();
    antlr4::tree::TerminalNode *NEWLINE();
    RoutineBodyContext *routineBody();
    antlr4::tree::TerminalNode *ENDFCT();
    antlr4::tree::TerminalNode *GLOBAL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionDefinitionContext* functionDefinition();

  class  FunctionNameContext : public antlr4::ParserRuleContext {
  public:
    FunctionNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionNameContext* functionName();

  class  ModuleDataContext : public antlr4::ParserRuleContext {
  public:
    ModuleDataContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DEFDAT();
    ModuleNameContext *moduleName();
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);
    DataListContext *dataList();
    antlr4::tree::TerminalNode *ENDDAT();
    antlr4::tree::TerminalNode *PUBLIC();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ModuleDataContext* moduleData();

  class  ModuleNameContext : public antlr4::ParserRuleContext {
  public:
    ModuleNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ModuleNameContext* moduleName();

  class  DataListContext : public antlr4::ParserRuleContext {
  public:
    DataListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);
    std::vector<ForwardDeclarationContext *> forwardDeclaration();
    ForwardDeclarationContext* forwardDeclaration(size_t i);
    std::vector<TypeDeclarationContext *> typeDeclaration();
    TypeDeclarationContext* typeDeclaration(size_t i);
    std::vector<VariableDeclarationInDataListContext *> variableDeclarationInDataList();
    VariableDeclarationInDataListContext* variableDeclarationInDataList(size_t i);
    std::vector<ArrayInitialisationContext *> arrayInitialisation();
    ArrayInitialisationContext* arrayInitialisation(size_t i);
    std::vector<ImportStatementContext *> importStatement();
    ImportStatementContext* importStatement(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DataListContext* dataList();

  class  ArrayInitialisationContext : public antlr4::ParserRuleContext {
  public:
    ArrayInitialisationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    ArrayVariableSuffixContext *arrayVariableSuffix();
    antlr4::tree::TerminalNode *ASSIGN();
    UnaryPlusMinuxExpressionContext *unaryPlusMinuxExpression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArrayInitialisationContext* arrayInitialisation();

  class  TypeDeclarationContext : public antlr4::ParserRuleContext {
  public:
    TypeDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StructureDefinitionContext *structureDefinition();
    EnumDefinitionContext *enumDefinition();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeDeclarationContext* typeDeclaration();

  class  StructureDefinitionContext : public antlr4::ParserRuleContext {
  public:
    StructureDefinitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STRUC();
    TypeNameContext *typeName();
    std::vector<TypeContext *> type();
    TypeContext* type(size_t i);
    std::vector<VariableNameContext *> variableName();
    VariableNameContext* variableName(size_t i);
    std::vector<VariableListRestContext *> variableListRest();
    VariableListRestContext* variableListRest(size_t i);
    antlr4::tree::TerminalNode *GLOBAL();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StructureDefinitionContext* structureDefinition();

  class  EnumDefinitionContext : public antlr4::ParserRuleContext {
  public:
    EnumDefinitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ENUM();
    TypeNameContext *typeName();
    std::vector<EnumValueContext *> enumValue();
    EnumValueContext* enumValue(size_t i);
    antlr4::tree::TerminalNode *GLOBAL();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EnumDefinitionContext* enumDefinition();

  class  EnumValueContext : public antlr4::ParserRuleContext {
  public:
    EnumValueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EnumValueContext* enumValue();

  class  VariableDeclarationContext : public antlr4::ParserRuleContext {
  public:
    VariableDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    VariableNameContext *variableName();
    VariableListRestContext *variableListRest();
    SignalDeclarationContext *signalDeclaration();
    antlr4::tree::TerminalNode *DECL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VariableDeclarationContext* variableDeclaration();

  class  SignalDeclarationContext : public antlr4::ParserRuleContext {
  public:
    SignalDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SIGNAL();
    antlr4::tree::TerminalNode *IDENTIFIER();
    std::vector<PrimaryContext *> primary();
    PrimaryContext* primary(size_t i);
    antlr4::tree::TerminalNode *TO();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SignalDeclarationContext* signalDeclaration();

  class  VariableDeclarationInDataListContext : public antlr4::ParserRuleContext {
  public:
    VariableDeclarationInDataListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    VariableNameContext *variableName();
    SignalDeclarationContext *signalDeclaration();
    antlr4::tree::TerminalNode *DECL();
    antlr4::tree::TerminalNode *GLOBAL();
    antlr4::tree::TerminalNode *CONST();
    VariableListRestContext *variableListRest();
    VariableInitialisationContext *variableInitialisation();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VariableDeclarationInDataListContext* variableDeclarationInDataList();

  class  VariableListRestContext : public antlr4::ParserRuleContext {
  public:
    VariableListRestContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    std::vector<VariableNameContext *> variableName();
    VariableNameContext* variableName(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VariableListRestContext* variableListRest();

  class  VariableInitialisationContext : public antlr4::ParserRuleContext {
  public:
    VariableInitialisationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ASSIGN();
    UnaryPlusMinuxExpressionContext *unaryPlusMinuxExpression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VariableInitialisationContext* variableInitialisation();

  class  StructLiteralContext : public antlr4::ParserRuleContext {
  public:
    StructLiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACE();
    StructElementListContext *structElementList();
    antlr4::tree::TerminalNode *RBRACE();
    TypeNameContext *typeName();
    antlr4::tree::TerminalNode *COLON();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StructLiteralContext* structLiteral();

  class  StructElementListContext : public antlr4::ParserRuleContext {
  public:
    StructElementListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<StructElementContext *> structElement();
    StructElementContext* structElement(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StructElementListContext* structElementList();

  class  StructElementContext : public antlr4::ParserRuleContext {
  public:
    StructElementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VariableNameContext *variableName();
    UnaryPlusMinuxExpressionContext *unaryPlusMinuxExpression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StructElementContext* structElement();

  class  FormalParametersContext : public antlr4::ParserRuleContext {
  public:
    FormalParametersContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    std::vector<ParameterContext *> parameter();
    ParameterContext* parameter(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FormalParametersContext* formalParameters();

  class  ParameterContext : public antlr4::ParserRuleContext {
  public:
    ParameterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VariableNameContext *variableName();
    ParameterCallTypeContext *parameterCallType();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParameterContext* parameter();

  class  RoutineBodyContext : public antlr4::ParserRuleContext {
  public:
    RoutineBodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    RoutineDataSectionContext *routineDataSection();
    RoutineImplementationSectionContext *routineImplementationSection();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RoutineBodyContext* routineBody();

  class  RoutineDataSectionContext : public antlr4::ParserRuleContext {
  public:
    RoutineDataSectionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ForwardDeclarationContext *> forwardDeclaration();
    ForwardDeclarationContext* forwardDeclaration(size_t i);
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);
    std::vector<VariableDeclarationContext *> variableDeclaration();
    VariableDeclarationContext* variableDeclaration(size_t i);
    std::vector<ImportStatementContext *> importStatement();
    ImportStatementContext* importStatement(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RoutineDataSectionContext* routineDataSection();

  class  ForwardDeclarationContext : public antlr4::ParserRuleContext {
  public:
    ForwardDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EXT();
    ProcedureNameContext *procedureName();
    FormalParametersWithTypeContext *formalParametersWithType();
    antlr4::tree::TerminalNode *EXTFCT();
    TypeContext *type();
    FunctionNameContext *functionName();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ForwardDeclarationContext* forwardDeclaration();

  class  FormalParametersWithTypeContext : public antlr4::ParserRuleContext {
  public:
    FormalParametersWithTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    std::vector<ParameterWithTypeContext *> parameterWithType();
    ParameterWithTypeContext* parameterWithType(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FormalParametersWithTypeContext* formalParametersWithType();

  class  ParameterWithTypeContext : public antlr4::ParserRuleContext {
  public:
    ParameterWithTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    ParameterCallTypeContext *parameterCallType();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParameterWithTypeContext* parameterWithType();

  class  ParameterCallTypeContext : public antlr4::ParserRuleContext {
  public:
    ParameterCallTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParameterCallTypeContext* parameterCallType();

  class  ImportStatementContext : public antlr4::ParserRuleContext {
  public:
    ImportStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IMPORT();
    TypeContext *type();
    std::vector<VariableNameContext *> variableName();
    VariableNameContext* variableName(size_t i);
    antlr4::tree::TerminalNode *IS();
    antlr4::tree::TerminalNode *R1();
    ModuleNameContext *moduleName();
    antlr4::tree::TerminalNode *DIERESIS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ImportStatementContext* importStatement();

  class  VariableNameContext : public antlr4::ParserRuleContext {
  public:
    VariableNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    ArrayVariableSuffixContext *arrayVariableSuffix();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VariableNameContext* variableName();

  class  ArrayVariableSuffixContext : public antlr4::ParserRuleContext {
  public:
    ArrayVariableSuffixContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACK();
    antlr4::tree::TerminalNode *RBRACK();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArrayVariableSuffixContext* arrayVariableSuffix();

  class  RoutineImplementationSectionContext : public antlr4::ParserRuleContext {
  public:
    RoutineImplementationSectionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StatementListContext *statementList();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RoutineImplementationSectionContext* routineImplementationSection();

  class  StatementListContext : public antlr4::ParserRuleContext {
  public:
    StatementListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementListContext* statementList();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CONTINUE();
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);
    antlr4::tree::TerminalNode *EXIT();
    antlr4::tree::TerminalNode *FOR();
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);
    std::vector<antlr4::tree::TerminalNode *> ASSIGN();
    antlr4::tree::TerminalNode* ASSIGN(size_t i);
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *TO();
    std::vector<StatementListContext *> statementList();
    StatementListContext* statementList(size_t i);
    antlr4::tree::TerminalNode *ENDFOR();
    antlr4::tree::TerminalNode *GOTO();
    antlr4::tree::TerminalNode *HALT();
    antlr4::tree::TerminalNode *IF();
    antlr4::tree::TerminalNode *THEN();
    antlr4::tree::TerminalNode *ENDIF();
    antlr4::tree::TerminalNode *ELSE();
    antlr4::tree::TerminalNode *LOOP();
    antlr4::tree::TerminalNode *ENDLOOP();
    antlr4::tree::TerminalNode *REPEAT();
    antlr4::tree::TerminalNode *UNTIL();
    antlr4::tree::TerminalNode *SWITCH();
    SwitchBlockStatementGroupsContext *switchBlockStatementGroups();
    antlr4::tree::TerminalNode *ENDSWITCH();
    antlr4::tree::TerminalNode *WAIT();
    antlr4::tree::TerminalNode *SEC();
    antlr4::tree::TerminalNode *WHILE();
    antlr4::tree::TerminalNode *ENDWHILE();
    antlr4::tree::TerminalNode *RETURN();
    AssignmentExpressionContext *assignmentExpression();
    antlr4::tree::TerminalNode *BRAKE();
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *INTERRUPT();
    antlr4::tree::TerminalNode *DECL();
    PrimaryContext *primary();
    antlr4::tree::TerminalNode *WHEN();
    antlr4::tree::TerminalNode *DO();
    antlr4::tree::TerminalNode *GLOBAL();
    std::vector<GeometricExpressionContext *> geometricExpression();
    GeometricExpressionContext* geometricExpression(size_t i);
    antlr4::tree::TerminalNode *PTP();
    antlr4::tree::TerminalNode *PTP_REL();
    antlr4::tree::TerminalNode *C_PTP();
    antlr4::tree::TerminalNode *C_DIS();
    antlr4::tree::TerminalNode *C_ORI();
    antlr4::tree::TerminalNode *C_VEL();
    antlr4::tree::TerminalNode *LIN();
    antlr4::tree::TerminalNode *LIN_REL();
    EnumElementContext *enumElement();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    antlr4::tree::TerminalNode *CIRC();
    antlr4::tree::TerminalNode *CIRC_REL();
    antlr4::tree::TerminalNode *TRIGGER();
    antlr4::tree::TerminalNode *DELAY();
    antlr4::tree::TerminalNode *PRIO();
    AnalogInputStatementContext *analogInputStatement();
    AnalogOutputStatementContext *analogOutputStatement();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementContext* statement();

  class  AnalogOutputStatementContext : public antlr4::ParserRuleContext {
  public:
    AnalogOutputStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ANOUT();
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);
    AssignmentExpressionContext *assignmentExpression();
    std::vector<antlr4::tree::TerminalNode *> ASSIGN();
    antlr4::tree::TerminalNode* ASSIGN(size_t i);
    std::vector<LiteralContext *> literal();
    LiteralContext* literal(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AnalogOutputStatementContext* analogOutputStatement();

  class  AnalogInputStatementContext : public antlr4::ParserRuleContext {
  public:
    AnalogInputStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ANIN();
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);
    AssignmentExpressionContext *assignmentExpression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AnalogInputStatementContext* analogInputStatement();

  class  SwitchBlockStatementGroupsContext : public antlr4::ParserRuleContext {
  public:
    SwitchBlockStatementGroupsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);
    std::vector<CaseLabelContext *> caseLabel();
    CaseLabelContext* caseLabel(size_t i);
    std::vector<StatementListContext *> statementList();
    StatementListContext* statementList(size_t i);
    DefaultLabelContext *defaultLabel();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SwitchBlockStatementGroupsContext* switchBlockStatementGroups();

  class  CaseLabelContext : public antlr4::ParserRuleContext {
  public:
    CaseLabelContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CASE();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *NEWLINE();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CaseLabelContext* caseLabel();

  class  DefaultLabelContext : public antlr4::ParserRuleContext {
  public:
    DefaultLabelContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DEFAULT();
    antlr4::tree::TerminalNode *NEWLINE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DefaultLabelContext* defaultLabel();

  class  ExpressionListContext : public antlr4::ParserRuleContext {
  public:
    ExpressionListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<AssignmentExpressionContext *> assignmentExpression();
    AssignmentExpressionContext* assignmentExpression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpressionListContext* expressionList();

  class  AssignmentExpressionContext : public antlr4::ParserRuleContext {
  public:
    AssignmentExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> ASSIGN();
    antlr4::tree::TerminalNode* ASSIGN(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AssignmentExpressionContext* assignmentExpression();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ConditionalOrExpressionContext *> conditionalOrExpression();
    ConditionalOrExpressionContext* conditionalOrExpression(size_t i);
    std::vector<RelationalOpContext *> relationalOp();
    RelationalOpContext* relationalOp(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpressionContext* expression();

  class  RelationalOpContext : public antlr4::ParserRuleContext {
  public:
    RelationalOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EQUAL();
    antlr4::tree::TerminalNode *NOT_EQUAL();
    antlr4::tree::TerminalNode *LE();
    antlr4::tree::TerminalNode *GE();
    antlr4::tree::TerminalNode *LT();
    antlr4::tree::TerminalNode *GT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RelationalOpContext* relationalOp();

  class  ConditionalOrExpressionContext : public antlr4::ParserRuleContext {
  public:
    ConditionalOrExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExclusiveOrExpressionContext *> exclusiveOrExpression();
    ExclusiveOrExpressionContext* exclusiveOrExpression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> OR();
    antlr4::tree::TerminalNode* OR(size_t i);
    std::vector<antlr4::tree::TerminalNode *> B_OR();
    antlr4::tree::TerminalNode* B_OR(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConditionalOrExpressionContext* conditionalOrExpression();

  class  ExclusiveOrExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExclusiveOrExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ConditionalAndExpressionContext *> conditionalAndExpression();
    ConditionalAndExpressionContext* conditionalAndExpression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> EXOR();
    antlr4::tree::TerminalNode* EXOR(size_t i);
    std::vector<antlr4::tree::TerminalNode *> B_EXOR();
    antlr4::tree::TerminalNode* B_EXOR(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExclusiveOrExpressionContext* exclusiveOrExpression();

  class  ConditionalAndExpressionContext : public antlr4::ParserRuleContext {
  public:
    ConditionalAndExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<AdditiveExpressionContext *> additiveExpression();
    AdditiveExpressionContext* additiveExpression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> AND();
    antlr4::tree::TerminalNode* AND(size_t i);
    std::vector<antlr4::tree::TerminalNode *> B_AND();
    antlr4::tree::TerminalNode* B_AND(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConditionalAndExpressionContext* conditionalAndExpression();

  class  AdditiveExpressionContext : public antlr4::ParserRuleContext {
  public:
    AdditiveExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<MultiplicativeExpressionContext *> multiplicativeExpression();
    MultiplicativeExpressionContext* multiplicativeExpression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> ADD();
    antlr4::tree::TerminalNode* ADD(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SUB();
    antlr4::tree::TerminalNode* SUB(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AdditiveExpressionContext* additiveExpression();

  class  MultiplicativeExpressionContext : public antlr4::ParserRuleContext {
  public:
    MultiplicativeExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<GeometricExpressionContext *> geometricExpression();
    GeometricExpressionContext* geometricExpression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> MUL();
    antlr4::tree::TerminalNode* MUL(size_t i);
    std::vector<antlr4::tree::TerminalNode *> DIV();
    antlr4::tree::TerminalNode* DIV(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MultiplicativeExpressionContext* multiplicativeExpression();

  class  GeometricExpressionContext : public antlr4::ParserRuleContext {
  public:
    GeometricExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<UnaryNotExpressionContext *> unaryNotExpression();
    UnaryNotExpressionContext* unaryNotExpression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COLON();
    antlr4::tree::TerminalNode* COLON(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GeometricExpressionContext* geometricExpression();

  class  UnaryNotExpressionContext : public antlr4::ParserRuleContext {
  public:
    UnaryNotExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NOT();
    UnaryNotExpressionContext *unaryNotExpression();
    antlr4::tree::TerminalNode *B_NOT();
    UnaryPlusMinuxExpressionContext *unaryPlusMinuxExpression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UnaryNotExpressionContext* unaryNotExpression();

  class  UnaryPlusMinuxExpressionContext : public antlr4::ParserRuleContext {
  public:
    UnaryPlusMinuxExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ADD();
    UnaryPlusMinuxExpressionContext *unaryPlusMinuxExpression();
    antlr4::tree::TerminalNode *SUB();
    PrimaryContext *primary();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UnaryPlusMinuxExpressionContext* unaryPlusMinuxExpression();

  class  PrimaryContext : public antlr4::ParserRuleContext {
  public:
    PrimaryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ParExpressionContext *parExpression();
    std::vector<VariableNameContext *> variableName();
    VariableNameContext* variableName(size_t i);
    std::vector<antlr4::tree::TerminalNode *> DOT();
    antlr4::tree::TerminalNode* DOT(size_t i);
    ArgumentsContext *arguments();
    LiteralContext *literal();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PrimaryContext* primary();

  class  ParExpressionContext : public antlr4::ParserRuleContext {
  public:
    ParExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAREN();
    AssignmentExpressionContext *assignmentExpression();
    antlr4::tree::TerminalNode *RPAREN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParExpressionContext* parExpression();

  class  TypeContext : public antlr4::ParserRuleContext {
  public:
    TypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PrimitiveTypeContext *primitiveType();
    antlr4::tree::TerminalNode *LBRACK();
    antlr4::tree::TerminalNode *RBRACK();
    antlr4::tree::TerminalNode *INTLITERAL();
    TypeNameContext *typeName();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeContext* type();

  class  TypeNameContext : public antlr4::ParserRuleContext {
  public:
    TypeNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeNameContext* typeName();

  class  PrimitiveTypeContext : public antlr4::ParserRuleContext {
  public:
    PrimitiveTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BOOL();
    antlr4::tree::TerminalNode *CHAR();
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *REAL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PrimitiveTypeContext* primitiveType();

  class  ArgumentsContext : public antlr4::ParserRuleContext {
  public:
    ArgumentsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    ExpressionListContext *expressionList();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArgumentsContext* arguments();

  class  LiteralContext : public antlr4::ParserRuleContext {
  public:
    LiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INTLITERAL();
    antlr4::tree::TerminalNode *FLOATLITERAL();
    antlr4::tree::TerminalNode *CHARLITERAL();
    antlr4::tree::TerminalNode *STRINGLITERAL();
    StructLiteralContext *structLiteral();
    antlr4::tree::TerminalNode *TRUE();
    antlr4::tree::TerminalNode *FALSE();
    EnumElementContext *enumElement();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LiteralContext* literal();

  class  EnumElementContext : public antlr4::ParserRuleContext {
  public:
    EnumElementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUMBER();
    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EnumElementContext* enumElement();


private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

}  // namespace antlrcpptest
