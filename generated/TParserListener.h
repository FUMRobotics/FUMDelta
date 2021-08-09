
// Generated from /home/fatemeh/Documents/antlr4-delta/runtime/Cpp/demo/TParser.g4 by ANTLR 4.7.2

#pragma once
#include "antlr4-runtime.h"
#include "TParser.h"
#include <QDebug>
#include <QString>

namespace antlrcpptest {

/**
 * This interface defines an abstract listener for a parse tree produced by TParser.
 */
class  TParserListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterModule(TParser::ModuleContext *ctx) = 0;
  virtual void exitModule(TParser::ModuleContext *ctx) = 0;

  virtual void enterModuleRoutines(TParser::ModuleRoutinesContext *ctx) = 0;
  virtual void exitModuleRoutines(TParser::ModuleRoutinesContext *ctx) = 0;

  virtual void enterMainRoutine(TParser::MainRoutineContext *ctx) = 0;
  virtual void exitMainRoutine(TParser::MainRoutineContext *ctx) = 0;

  virtual void enterSubRoutine(TParser::SubRoutineContext *ctx) = 0;
  virtual void exitSubRoutine(TParser::SubRoutineContext *ctx) = 0;

  virtual void enterProcedureDefinition(TParser::ProcedureDefinitionContext *ctx) = 0;
  virtual void exitProcedureDefinition(TParser::ProcedureDefinitionContext *ctx) = 0;

  virtual void enterProcedureName(TParser::ProcedureNameContext *ctx) = 0;
  virtual void exitProcedureName(TParser::ProcedureNameContext *ctx) = 0;

  virtual void enterFunctionDefinition(TParser::FunctionDefinitionContext *ctx) = 0;
  virtual void exitFunctionDefinition(TParser::FunctionDefinitionContext *ctx) = 0;

  virtual void enterFunctionName(TParser::FunctionNameContext *ctx) = 0;
  virtual void exitFunctionName(TParser::FunctionNameContext *ctx) = 0;

  virtual void enterModuleData(TParser::ModuleDataContext *ctx) = 0;
  virtual void exitModuleData(TParser::ModuleDataContext *ctx) = 0;

  virtual void enterModuleName(TParser::ModuleNameContext *ctx) = 0;
  virtual void exitModuleName(TParser::ModuleNameContext *ctx) = 0;

  virtual void enterDataList(TParser::DataListContext *ctx) = 0;
  virtual void exitDataList(TParser::DataListContext *ctx) = 0;

  virtual void enterArrayInitialisation(TParser::ArrayInitialisationContext *ctx) = 0;
  virtual void exitArrayInitialisation(TParser::ArrayInitialisationContext *ctx) = 0;

  virtual void enterTypeDeclaration(TParser::TypeDeclarationContext *ctx) = 0;
  virtual void exitTypeDeclaration(TParser::TypeDeclarationContext *ctx) = 0;

  virtual void enterStructureDefinition(TParser::StructureDefinitionContext *ctx) = 0;
  virtual void exitStructureDefinition(TParser::StructureDefinitionContext *ctx) = 0;

  virtual void enterEnumDefinition(TParser::EnumDefinitionContext *ctx) = 0;
  virtual void exitEnumDefinition(TParser::EnumDefinitionContext *ctx) = 0;

  virtual void enterEnumValue(TParser::EnumValueContext *ctx) = 0;
  virtual void exitEnumValue(TParser::EnumValueContext *ctx) = 0;

  virtual void enterVariableDeclaration(TParser::VariableDeclarationContext *ctx) = 0;
  virtual void exitVariableDeclaration(TParser::VariableDeclarationContext *ctx) = 0;

  virtual void enterSignalDeclaration(TParser::SignalDeclarationContext *ctx) = 0;
  virtual void exitSignalDeclaration(TParser::SignalDeclarationContext *ctx) = 0;

  virtual void enterVariableDeclarationInDataList(TParser::VariableDeclarationInDataListContext *ctx) = 0;
  virtual void exitVariableDeclarationInDataList(TParser::VariableDeclarationInDataListContext *ctx) = 0;

  virtual void enterVariableListRest(TParser::VariableListRestContext *ctx) = 0;
  virtual void exitVariableListRest(TParser::VariableListRestContext *ctx) = 0;

  virtual void enterVariableInitialisation(TParser::VariableInitialisationContext *ctx) = 0;
  virtual void exitVariableInitialisation(TParser::VariableInitialisationContext *ctx) = 0;

  virtual void enterStructLiteral(TParser::StructLiteralContext *ctx) = 0;
  virtual void exitStructLiteral(TParser::StructLiteralContext *ctx) = 0;

  virtual void enterStructElementList(TParser::StructElementListContext *ctx) = 0;
  virtual void exitStructElementList(TParser::StructElementListContext *ctx) = 0;

  virtual void enterStructElement(TParser::StructElementContext *ctx) = 0;
  virtual void exitStructElement(TParser::StructElementContext *ctx) = 0;

  virtual void enterFormalParameters(TParser::FormalParametersContext *ctx) = 0;
  virtual void exitFormalParameters(TParser::FormalParametersContext *ctx) = 0;

  virtual void enterParameter(TParser::ParameterContext *ctx) = 0;
  virtual void exitParameter(TParser::ParameterContext *ctx) = 0;

  virtual void enterRoutineBody(TParser::RoutineBodyContext *ctx) = 0;
  virtual void exitRoutineBody(TParser::RoutineBodyContext *ctx) = 0;

  virtual void enterRoutineDataSection(TParser::RoutineDataSectionContext *ctx) = 0;
  virtual void exitRoutineDataSection(TParser::RoutineDataSectionContext *ctx) = 0;

  virtual void enterForwardDeclaration(TParser::ForwardDeclarationContext *ctx) = 0;
  virtual void exitForwardDeclaration(TParser::ForwardDeclarationContext *ctx) = 0;

  virtual void enterFormalParametersWithType(TParser::FormalParametersWithTypeContext *ctx) = 0;
  virtual void exitFormalParametersWithType(TParser::FormalParametersWithTypeContext *ctx) = 0;

  virtual void enterParameterWithType(TParser::ParameterWithTypeContext *ctx) = 0;
  virtual void exitParameterWithType(TParser::ParameterWithTypeContext *ctx) = 0;

  virtual void enterParameterCallType(TParser::ParameterCallTypeContext *ctx) = 0;
  virtual void exitParameterCallType(TParser::ParameterCallTypeContext *ctx) = 0;

  virtual void enterImportStatement(TParser::ImportStatementContext *ctx) = 0;
  virtual void exitImportStatement(TParser::ImportStatementContext *ctx) = 0;

  virtual void enterVariableName(TParser::VariableNameContext *ctx) = 0;
  virtual void exitVariableName(TParser::VariableNameContext *ctx) = 0;

  virtual void enterArrayVariableSuffix(TParser::ArrayVariableSuffixContext *ctx) = 0;
  virtual void exitArrayVariableSuffix(TParser::ArrayVariableSuffixContext *ctx) = 0;

  virtual void enterRoutineImplementationSection(TParser::RoutineImplementationSectionContext *ctx) = 0;
  virtual void exitRoutineImplementationSection(TParser::RoutineImplementationSectionContext *ctx) = 0;

  virtual void enterStatementList(TParser::StatementListContext *ctx) = 0;
  virtual void exitStatementList(TParser::StatementListContext *ctx) = 0;

  virtual void enterStatement(TParser::StatementContext *ctx) = 0;
  virtual void exitStatement(TParser::StatementContext *ctx) = 0;

  virtual void enterAnalogOutputStatement(TParser::AnalogOutputStatementContext *ctx) = 0;
  virtual void exitAnalogOutputStatement(TParser::AnalogOutputStatementContext *ctx) = 0;

  virtual void enterAnalogInputStatement(TParser::AnalogInputStatementContext *ctx) = 0;
  virtual void exitAnalogInputStatement(TParser::AnalogInputStatementContext *ctx) = 0;

  virtual void enterSwitchBlockStatementGroups(TParser::SwitchBlockStatementGroupsContext *ctx) = 0;
  virtual void exitSwitchBlockStatementGroups(TParser::SwitchBlockStatementGroupsContext *ctx) = 0;

  virtual void enterCaseLabel(TParser::CaseLabelContext *ctx) = 0;
  virtual void exitCaseLabel(TParser::CaseLabelContext *ctx) = 0;

  virtual void enterDefaultLabel(TParser::DefaultLabelContext *ctx) = 0;
  virtual void exitDefaultLabel(TParser::DefaultLabelContext *ctx) = 0;

  virtual void enterExpressionList(TParser::ExpressionListContext *ctx) = 0;
  virtual void exitExpressionList(TParser::ExpressionListContext *ctx) = 0;

  virtual void enterAssignmentExpression(TParser::AssignmentExpressionContext *ctx) = 0;
  virtual void exitAssignmentExpression(TParser::AssignmentExpressionContext *ctx) = 0;

  virtual void enterExpression(TParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(TParser::ExpressionContext *ctx) = 0;

  virtual void enterRelationalOp(TParser::RelationalOpContext *ctx) = 0;
  virtual void exitRelationalOp(TParser::RelationalOpContext *ctx) = 0;

  virtual void enterConditionalOrExpression(TParser::ConditionalOrExpressionContext *ctx) = 0;
  virtual void exitConditionalOrExpression(TParser::ConditionalOrExpressionContext *ctx) = 0;

  virtual void enterExclusiveOrExpression(TParser::ExclusiveOrExpressionContext *ctx) = 0;
  virtual void exitExclusiveOrExpression(TParser::ExclusiveOrExpressionContext *ctx) = 0;

  virtual void enterConditionalAndExpression(TParser::ConditionalAndExpressionContext *ctx) = 0;
  virtual void exitConditionalAndExpression(TParser::ConditionalAndExpressionContext *ctx) = 0;

  virtual void enterAdditiveExpression(TParser::AdditiveExpressionContext *ctx) = 0;
  virtual void exitAdditiveExpression(TParser::AdditiveExpressionContext *ctx) = 0;

  virtual void enterMultiplicativeExpression(TParser::MultiplicativeExpressionContext *ctx) = 0;
  virtual void exitMultiplicativeExpression(TParser::MultiplicativeExpressionContext *ctx) = 0;

  virtual void enterGeometricExpression(TParser::GeometricExpressionContext *ctx) = 0;
  virtual void exitGeometricExpression(TParser::GeometricExpressionContext *ctx) = 0;

  virtual void enterUnaryNotExpression(TParser::UnaryNotExpressionContext *ctx) = 0;
  virtual void exitUnaryNotExpression(TParser::UnaryNotExpressionContext *ctx) = 0;

  virtual void enterUnaryPlusMinuxExpression(TParser::UnaryPlusMinuxExpressionContext *ctx) = 0;
  virtual void exitUnaryPlusMinuxExpression(TParser::UnaryPlusMinuxExpressionContext *ctx) = 0;

  virtual void enterPrimary(TParser::PrimaryContext *ctx) = 0;
  virtual void exitPrimary(TParser::PrimaryContext *ctx) = 0;

  virtual void enterParExpression(TParser::ParExpressionContext *ctx) = 0;
  virtual void exitParExpression(TParser::ParExpressionContext *ctx) = 0;

  virtual void enterType(TParser::TypeContext *ctx) = 0;
  virtual void exitType(TParser::TypeContext *ctx) = 0;

  virtual void enterTypeName(TParser::TypeNameContext *ctx) = 0;
  virtual void exitTypeName(TParser::TypeNameContext *ctx) = 0;

  virtual void enterPrimitiveType(TParser::PrimitiveTypeContext *ctx) = 0;
  virtual void exitPrimitiveType(TParser::PrimitiveTypeContext *ctx) = 0;

  virtual void enterArguments(TParser::ArgumentsContext *ctx) = 0;
  virtual void exitArguments(TParser::ArgumentsContext *ctx) = 0;

  virtual void enterLiteral(TParser::LiteralContext *ctx) = 0;
  virtual void exitLiteral(TParser::LiteralContext *ctx) = 0;

  virtual void enterEnumElement(TParser::EnumElementContext *ctx) = 0;
  virtual void exitEnumElement(TParser::EnumElementContext *ctx) = 0;


};

}  // namespace antlrcpptest
