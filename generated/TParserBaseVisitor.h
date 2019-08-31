
// Generated from /home/fatemeh/Documents/antlr4-delta/runtime/Cpp/demo/TParser.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "TParserVisitor.h"


namespace antlrcpptest {

/**
 * This class provides an empty implementation of TParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  TParserBaseVisitor : public TParserVisitor {
public:

  virtual antlrcpp::Any visitModule(TParser::ModuleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModuleRoutines(TParser::ModuleRoutinesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMainRoutine(TParser::MainRoutineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSubRoutine(TParser::SubRoutineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProcedureDefinition(TParser::ProcedureDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProcedureName(TParser::ProcedureNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionDefinition(TParser::FunctionDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionName(TParser::FunctionNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModuleData(TParser::ModuleDataContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModuleName(TParser::ModuleNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDataList(TParser::DataListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArrayInitialisation(TParser::ArrayInitialisationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeDeclaration(TParser::TypeDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStructureDefinition(TParser::StructureDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEnumDefinition(TParser::EnumDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEnumValue(TParser::EnumValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariableDeclaration(TParser::VariableDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSignalDeclaration(TParser::SignalDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariableDeclarationInDataList(TParser::VariableDeclarationInDataListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariableListRest(TParser::VariableListRestContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariableInitialisation(TParser::VariableInitialisationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStructLiteral(TParser::StructLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStructElementList(TParser::StructElementListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStructElement(TParser::StructElementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFormalParameters(TParser::FormalParametersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameter(TParser::ParameterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRoutineBody(TParser::RoutineBodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRoutineDataSection(TParser::RoutineDataSectionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForwardDeclaration(TParser::ForwardDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFormalParametersWithType(TParser::FormalParametersWithTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameterWithType(TParser::ParameterWithTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameterCallType(TParser::ParameterCallTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitImportStatement(TParser::ImportStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariableName(TParser::VariableNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArrayVariableSuffix(TParser::ArrayVariableSuffixContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRoutineImplementationSection(TParser::RoutineImplementationSectionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatementList(TParser::StatementListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement(TParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAnalogOutputStatement(TParser::AnalogOutputStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAnalogInputStatement(TParser::AnalogInputStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSwitchBlockStatementGroups(TParser::SwitchBlockStatementGroupsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCaseLabel(TParser::CaseLabelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDefaultLabel(TParser::DefaultLabelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpressionList(TParser::ExpressionListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignmentExpression(TParser::AssignmentExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpression(TParser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRelationalOp(TParser::RelationalOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConditionalOrExpression(TParser::ConditionalOrExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExclusiveOrExpression(TParser::ExclusiveOrExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConditionalAndExpression(TParser::ConditionalAndExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAdditiveExpression(TParser::AdditiveExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMultiplicativeExpression(TParser::MultiplicativeExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGeometricExpression(TParser::GeometricExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnaryNotExpression(TParser::UnaryNotExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnaryPlusMinuxExpression(TParser::UnaryPlusMinuxExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPrimary(TParser::PrimaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParExpression(TParser::ParExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType(TParser::TypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeName(TParser::TypeNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPrimitiveType(TParser::PrimitiveTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArguments(TParser::ArgumentsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLiteral(TParser::LiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEnumElement(TParser::EnumElementContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace antlrcpptest
