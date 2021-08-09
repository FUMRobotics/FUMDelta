
// Generated from /home/fatemeh/Documents/antlr4-delta/runtime/Cpp/demo/TParser.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "TParser.h"


namespace antlrcpptest {

/**
 * This class defines an abstract visitor for a parse tree
 * produced by TParser.
 */
class  TParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by TParser.
   */
    virtual antlrcpp::Any visitModule(TParser::ModuleContext *context) = 0;

    virtual antlrcpp::Any visitModuleRoutines(TParser::ModuleRoutinesContext *context) = 0;

    virtual antlrcpp::Any visitMainRoutine(TParser::MainRoutineContext *context) = 0;

    virtual antlrcpp::Any visitSubRoutine(TParser::SubRoutineContext *context) = 0;

    virtual antlrcpp::Any visitProcedureDefinition(TParser::ProcedureDefinitionContext *context) = 0;

    virtual antlrcpp::Any visitProcedureName(TParser::ProcedureNameContext *context) = 0;

    virtual antlrcpp::Any visitFunctionDefinition(TParser::FunctionDefinitionContext *context) = 0;

    virtual antlrcpp::Any visitFunctionName(TParser::FunctionNameContext *context) = 0;

    virtual antlrcpp::Any visitModuleData(TParser::ModuleDataContext *context) = 0;

    virtual antlrcpp::Any visitModuleName(TParser::ModuleNameContext *context) = 0;

    virtual antlrcpp::Any visitDataList(TParser::DataListContext *context) = 0;

    virtual antlrcpp::Any visitArrayInitialisation(TParser::ArrayInitialisationContext *context) = 0;

    virtual antlrcpp::Any visitTypeDeclaration(TParser::TypeDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitStructureDefinition(TParser::StructureDefinitionContext *context) = 0;

    virtual antlrcpp::Any visitEnumDefinition(TParser::EnumDefinitionContext *context) = 0;

    virtual antlrcpp::Any visitEnumValue(TParser::EnumValueContext *context) = 0;

    virtual antlrcpp::Any visitVariableDeclaration(TParser::VariableDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitSignalDeclaration(TParser::SignalDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitVariableDeclarationInDataList(TParser::VariableDeclarationInDataListContext *context) = 0;

    virtual antlrcpp::Any visitVariableListRest(TParser::VariableListRestContext *context) = 0;

    virtual antlrcpp::Any visitVariableInitialisation(TParser::VariableInitialisationContext *context) = 0;

    virtual antlrcpp::Any visitStructLiteral(TParser::StructLiteralContext *context) = 0;

    virtual antlrcpp::Any visitStructElementList(TParser::StructElementListContext *context) = 0;

    virtual antlrcpp::Any visitStructElement(TParser::StructElementContext *context) = 0;

    virtual antlrcpp::Any visitFormalParameters(TParser::FormalParametersContext *context) = 0;

    virtual antlrcpp::Any visitParameter(TParser::ParameterContext *context) = 0;

    virtual antlrcpp::Any visitRoutineBody(TParser::RoutineBodyContext *context) = 0;

    virtual antlrcpp::Any visitRoutineDataSection(TParser::RoutineDataSectionContext *context) = 0;

    virtual antlrcpp::Any visitForwardDeclaration(TParser::ForwardDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitFormalParametersWithType(TParser::FormalParametersWithTypeContext *context) = 0;

    virtual antlrcpp::Any visitParameterWithType(TParser::ParameterWithTypeContext *context) = 0;

    virtual antlrcpp::Any visitParameterCallType(TParser::ParameterCallTypeContext *context) = 0;

    virtual antlrcpp::Any visitImportStatement(TParser::ImportStatementContext *context) = 0;

    virtual antlrcpp::Any visitVariableName(TParser::VariableNameContext *context) = 0;

    virtual antlrcpp::Any visitArrayVariableSuffix(TParser::ArrayVariableSuffixContext *context) = 0;

    virtual antlrcpp::Any visitRoutineImplementationSection(TParser::RoutineImplementationSectionContext *context) = 0;

    virtual antlrcpp::Any visitStatementList(TParser::StatementListContext *context) = 0;

    virtual antlrcpp::Any visitStatement(TParser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitAnalogOutputStatement(TParser::AnalogOutputStatementContext *context) = 0;

    virtual antlrcpp::Any visitAnalogInputStatement(TParser::AnalogInputStatementContext *context) = 0;

    virtual antlrcpp::Any visitSwitchBlockStatementGroups(TParser::SwitchBlockStatementGroupsContext *context) = 0;

    virtual antlrcpp::Any visitCaseLabel(TParser::CaseLabelContext *context) = 0;

    virtual antlrcpp::Any visitDefaultLabel(TParser::DefaultLabelContext *context) = 0;

    virtual antlrcpp::Any visitExpressionList(TParser::ExpressionListContext *context) = 0;

    virtual antlrcpp::Any visitAssignmentExpression(TParser::AssignmentExpressionContext *context) = 0;

    virtual antlrcpp::Any visitExpression(TParser::ExpressionContext *context) = 0;

    virtual antlrcpp::Any visitRelationalOp(TParser::RelationalOpContext *context) = 0;

    virtual antlrcpp::Any visitConditionalOrExpression(TParser::ConditionalOrExpressionContext *context) = 0;

    virtual antlrcpp::Any visitExclusiveOrExpression(TParser::ExclusiveOrExpressionContext *context) = 0;

    virtual antlrcpp::Any visitConditionalAndExpression(TParser::ConditionalAndExpressionContext *context) = 0;

    virtual antlrcpp::Any visitAdditiveExpression(TParser::AdditiveExpressionContext *context) = 0;

    virtual antlrcpp::Any visitMultiplicativeExpression(TParser::MultiplicativeExpressionContext *context) = 0;

    virtual antlrcpp::Any visitGeometricExpression(TParser::GeometricExpressionContext *context) = 0;

    virtual antlrcpp::Any visitUnaryNotExpression(TParser::UnaryNotExpressionContext *context) = 0;

    virtual antlrcpp::Any visitUnaryPlusMinuxExpression(TParser::UnaryPlusMinuxExpressionContext *context) = 0;

    virtual antlrcpp::Any visitPrimary(TParser::PrimaryContext *context) = 0;

    virtual antlrcpp::Any visitParExpression(TParser::ParExpressionContext *context) = 0;

    virtual antlrcpp::Any visitType(TParser::TypeContext *context) = 0;

    virtual antlrcpp::Any visitTypeName(TParser::TypeNameContext *context) = 0;

    virtual antlrcpp::Any visitPrimitiveType(TParser::PrimitiveTypeContext *context) = 0;

    virtual antlrcpp::Any visitArguments(TParser::ArgumentsContext *context) = 0;

    virtual antlrcpp::Any visitLiteral(TParser::LiteralContext *context) = 0;

    virtual antlrcpp::Any visitEnumElement(TParser::EnumElementContext *context) = 0;


};

}  // namespace antlrcpptest
