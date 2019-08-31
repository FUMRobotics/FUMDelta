
// Generated from /home/fatemeh/Documents/antlr4-delta/runtime/Cpp/demo/TParser.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "TParserListener.h"


namespace antlrcpptest {

/**
 * This class provides an empty implementation of TParserListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  TParserBaseListener : public TParserListener {
public:

  virtual void enterModule(TParser::ModuleContext * ctx) override
    {
        std::cout<<"Entering module"<<std::endl;
        std::string text = ctx->getText();
    }
  virtual void exitModule(TParser::ModuleContext * ctx) override
    {
        std::cout<<"Exiting module"<<std::endl;
        std::cout<<ctx->getText()<<std::endl;
    }

  virtual void enterModuleRoutines(TParser::ModuleRoutinesContext * ctx) override
    {
        std::cout<<"Entering moduleRoutines"<<std::endl;
        std::cout<<ctx->getText()<<std::endl;
    }
  virtual void exitModuleRoutines(TParser::ModuleRoutinesContext * ctx) override
    {
        std::cout<<"Exiting moduleRoutines"<<std::endl;
        std::cout<<ctx->getText()<<std::endl;
    }

  virtual void enterMainRoutine(TParser::MainRoutineContext * ctx) override
    {
        std::cout<<"Entering mainRoutine"<<std::endl;
        std::cout<<ctx->getText()<<std::endl;
    }
  virtual void exitMainRoutine(TParser::MainRoutineContext * ctx) override
    {
        std::cout<<"Exiting mainRoutine"<<std::endl;
        std::cout<<ctx->getText()<<std::endl;
    }

  virtual void enterSubRoutine(TParser::SubRoutineContext * /*ctx*/) override { }
  virtual void exitSubRoutine(TParser::SubRoutineContext * /*ctx*/) override { }

  virtual void enterProcedureDefinition(TParser::ProcedureDefinitionContext * /*ctx*/) override { }
  virtual void exitProcedureDefinition(TParser::ProcedureDefinitionContext * /*ctx*/) override { }

  virtual void enterProcedureName(TParser::ProcedureNameContext * /*ctx*/) override { }
  virtual void exitProcedureName(TParser::ProcedureNameContext * /*ctx*/) override { }

  virtual void enterFunctionDefinition(TParser::FunctionDefinitionContext * /*ctx*/) override { }
  virtual void exitFunctionDefinition(TParser::FunctionDefinitionContext * /*ctx*/) override { }

  virtual void enterFunctionName(TParser::FunctionNameContext * /*ctx*/) override { }
  virtual void exitFunctionName(TParser::FunctionNameContext * /*ctx*/) override { }

  virtual void enterModuleData(TParser::ModuleDataContext * /*ctx*/) override { }
  virtual void exitModuleData(TParser::ModuleDataContext * /*ctx*/) override { }

  virtual void enterModuleName(TParser::ModuleNameContext * /*ctx*/) override { }
  virtual void exitModuleName(TParser::ModuleNameContext * /*ctx*/) override { }

  virtual void enterDataList(TParser::DataListContext * /*ctx*/) override { }
  virtual void exitDataList(TParser::DataListContext * /*ctx*/) override { }

  virtual void enterArrayInitialisation(TParser::ArrayInitialisationContext * /*ctx*/) override { }
  virtual void exitArrayInitialisation(TParser::ArrayInitialisationContext * /*ctx*/) override { }

  virtual void enterTypeDeclaration(TParser::TypeDeclarationContext * /*ctx*/) override { }
  virtual void exitTypeDeclaration(TParser::TypeDeclarationContext * /*ctx*/) override { }

  virtual void enterStructureDefinition(TParser::StructureDefinitionContext * /*ctx*/) override { }
  virtual void exitStructureDefinition(TParser::StructureDefinitionContext * /*ctx*/) override { }

  virtual void enterEnumDefinition(TParser::EnumDefinitionContext * /*ctx*/) override { }
  virtual void exitEnumDefinition(TParser::EnumDefinitionContext * /*ctx*/) override { }

  virtual void enterEnumValue(TParser::EnumValueContext * /*ctx*/) override { }
  virtual void exitEnumValue(TParser::EnumValueContext * /*ctx*/) override { }

  virtual void enterVariableDeclaration(TParser::VariableDeclarationContext * /*ctx*/) override { }
  virtual void exitVariableDeclaration(TParser::VariableDeclarationContext * /*ctx*/) override { }

  virtual void enterSignalDeclaration(TParser::SignalDeclarationContext * /*ctx*/) override { }
  virtual void exitSignalDeclaration(TParser::SignalDeclarationContext * /*ctx*/) override { }

  virtual void enterVariableDeclarationInDataList(TParser::VariableDeclarationInDataListContext * /*ctx*/) override { }
  virtual void exitVariableDeclarationInDataList(TParser::VariableDeclarationInDataListContext * /*ctx*/) override { }

  virtual void enterVariableListRest(TParser::VariableListRestContext * /*ctx*/) override { }
  virtual void exitVariableListRest(TParser::VariableListRestContext * /*ctx*/) override { }

  virtual void enterVariableInitialisation(TParser::VariableInitialisationContext * /*ctx*/) override { }
  virtual void exitVariableInitialisation(TParser::VariableInitialisationContext * /*ctx*/) override { }

  virtual void enterStructLiteral(TParser::StructLiteralContext * /*ctx*/) override { }
  virtual void exitStructLiteral(TParser::StructLiteralContext * /*ctx*/) override { }

  virtual void enterStructElementList(TParser::StructElementListContext * /*ctx*/) override { }
  virtual void exitStructElementList(TParser::StructElementListContext * /*ctx*/) override { }

  virtual void enterStructElement(TParser::StructElementContext * /*ctx*/) override { }
  virtual void exitStructElement(TParser::StructElementContext * /*ctx*/) override { }

  virtual void enterFormalParameters(TParser::FormalParametersContext * /*ctx*/) override { }
  virtual void exitFormalParameters(TParser::FormalParametersContext * /*ctx*/) override { }

  virtual void enterParameter(TParser::ParameterContext * /*ctx*/) override { }
  virtual void exitParameter(TParser::ParameterContext * /*ctx*/) override { }

  virtual void enterRoutineBody(TParser::RoutineBodyContext * /*ctx*/) override { }
  virtual void exitRoutineBody(TParser::RoutineBodyContext * /*ctx*/) override { }

  virtual void enterRoutineDataSection(TParser::RoutineDataSectionContext * /*ctx*/) override { }
  virtual void exitRoutineDataSection(TParser::RoutineDataSectionContext * /*ctx*/) override { }

  virtual void enterForwardDeclaration(TParser::ForwardDeclarationContext * /*ctx*/) override { }
  virtual void exitForwardDeclaration(TParser::ForwardDeclarationContext * /*ctx*/) override { }

  virtual void enterFormalParametersWithType(TParser::FormalParametersWithTypeContext * /*ctx*/) override { }
  virtual void exitFormalParametersWithType(TParser::FormalParametersWithTypeContext * /*ctx*/) override { }

  virtual void enterParameterWithType(TParser::ParameterWithTypeContext * /*ctx*/) override { }
  virtual void exitParameterWithType(TParser::ParameterWithTypeContext * /*ctx*/) override { }

  virtual void enterParameterCallType(TParser::ParameterCallTypeContext * /*ctx*/) override { }
  virtual void exitParameterCallType(TParser::ParameterCallTypeContext * /*ctx*/) override { }

  virtual void enterImportStatement(TParser::ImportStatementContext * /*ctx*/) override { }
  virtual void exitImportStatement(TParser::ImportStatementContext * /*ctx*/) override { }

  virtual void enterVariableName(TParser::VariableNameContext * /*ctx*/) override { }
  virtual void exitVariableName(TParser::VariableNameContext * /*ctx*/) override { }

  virtual void enterArrayVariableSuffix(TParser::ArrayVariableSuffixContext * /*ctx*/) override { }
  virtual void exitArrayVariableSuffix(TParser::ArrayVariableSuffixContext * /*ctx*/) override { }

  virtual void enterRoutineImplementationSection(TParser::RoutineImplementationSectionContext * /*ctx*/) override { }
  virtual void exitRoutineImplementationSection(TParser::RoutineImplementationSectionContext * /*ctx*/) override { }

  virtual void enterStatementList(TParser::StatementListContext * /*ctx*/) override { }
  virtual void exitStatementList(TParser::StatementListContext * /*ctx*/) override { }

  virtual void enterStatement(TParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(TParser::StatementContext * /*ctx*/) override { }

  virtual void enterAnalogOutputStatement(TParser::AnalogOutputStatementContext * /*ctx*/) override { }
  virtual void exitAnalogOutputStatement(TParser::AnalogOutputStatementContext * /*ctx*/) override { }

  virtual void enterAnalogInputStatement(TParser::AnalogInputStatementContext * /*ctx*/) override { }
  virtual void exitAnalogInputStatement(TParser::AnalogInputStatementContext * /*ctx*/) override { }

  virtual void enterSwitchBlockStatementGroups(TParser::SwitchBlockStatementGroupsContext * /*ctx*/) override { }
  virtual void exitSwitchBlockStatementGroups(TParser::SwitchBlockStatementGroupsContext * /*ctx*/) override { }

  virtual void enterCaseLabel(TParser::CaseLabelContext * /*ctx*/) override { }
  virtual void exitCaseLabel(TParser::CaseLabelContext * /*ctx*/) override { }

  virtual void enterDefaultLabel(TParser::DefaultLabelContext * /*ctx*/) override { }
  virtual void exitDefaultLabel(TParser::DefaultLabelContext * /*ctx*/) override { }

  virtual void enterExpressionList(TParser::ExpressionListContext * /*ctx*/) override { }
  virtual void exitExpressionList(TParser::ExpressionListContext * /*ctx*/) override { }

  virtual void enterAssignmentExpression(TParser::AssignmentExpressionContext * /*ctx*/) override { }
  virtual void exitAssignmentExpression(TParser::AssignmentExpressionContext * /*ctx*/) override { }

  virtual void enterExpression(TParser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(TParser::ExpressionContext * /*ctx*/) override { }

  virtual void enterRelationalOp(TParser::RelationalOpContext * /*ctx*/) override { }
  virtual void exitRelationalOp(TParser::RelationalOpContext * /*ctx*/) override { }

  virtual void enterConditionalOrExpression(TParser::ConditionalOrExpressionContext * /*ctx*/) override { }
  virtual void exitConditionalOrExpression(TParser::ConditionalOrExpressionContext * /*ctx*/) override { }

  virtual void enterExclusiveOrExpression(TParser::ExclusiveOrExpressionContext * /*ctx*/) override { }
  virtual void exitExclusiveOrExpression(TParser::ExclusiveOrExpressionContext * /*ctx*/) override { }

  virtual void enterConditionalAndExpression(TParser::ConditionalAndExpressionContext * /*ctx*/) override { }
  virtual void exitConditionalAndExpression(TParser::ConditionalAndExpressionContext * /*ctx*/) override { }

  virtual void enterAdditiveExpression(TParser::AdditiveExpressionContext * /*ctx*/) override { }
  virtual void exitAdditiveExpression(TParser::AdditiveExpressionContext * /*ctx*/) override { }

  virtual void enterMultiplicativeExpression(TParser::MultiplicativeExpressionContext * /*ctx*/) override { }
  virtual void exitMultiplicativeExpression(TParser::MultiplicativeExpressionContext * /*ctx*/) override { }

  virtual void enterGeometricExpression(TParser::GeometricExpressionContext * /*ctx*/) override { }
  virtual void exitGeometricExpression(TParser::GeometricExpressionContext * /*ctx*/) override { }

  virtual void enterUnaryNotExpression(TParser::UnaryNotExpressionContext * /*ctx*/) override { }
  virtual void exitUnaryNotExpression(TParser::UnaryNotExpressionContext * /*ctx*/) override { }

  virtual void enterUnaryPlusMinuxExpression(TParser::UnaryPlusMinuxExpressionContext * /*ctx*/) override { }
  virtual void exitUnaryPlusMinuxExpression(TParser::UnaryPlusMinuxExpressionContext * /*ctx*/) override { }

  virtual void enterPrimary(TParser::PrimaryContext * /*ctx*/) override { }
  virtual void exitPrimary(TParser::PrimaryContext * /*ctx*/) override { }

  virtual void enterParExpression(TParser::ParExpressionContext * /*ctx*/) override { }
  virtual void exitParExpression(TParser::ParExpressionContext * /*ctx*/) override { }

  virtual void enterType(TParser::TypeContext * /*ctx*/) override { }
  virtual void exitType(TParser::TypeContext * /*ctx*/) override { }

  virtual void enterTypeName(TParser::TypeNameContext * /*ctx*/) override { }
  virtual void exitTypeName(TParser::TypeNameContext * /*ctx*/) override { }

  virtual void enterPrimitiveType(TParser::PrimitiveTypeContext * /*ctx*/) override { }
  virtual void exitPrimitiveType(TParser::PrimitiveTypeContext * /*ctx*/) override { }

  virtual void enterArguments(TParser::ArgumentsContext * /*ctx*/) override { }
  virtual void exitArguments(TParser::ArgumentsContext * /*ctx*/) override { }

  virtual void enterLiteral(TParser::LiteralContext * /*ctx*/) override { }
  virtual void exitLiteral(TParser::LiteralContext * /*ctx*/) override { }

  virtual void enterEnumElement(TParser::EnumElementContext * /*ctx*/) override { }
  virtual void exitEnumElement(TParser::EnumElementContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

}  // namespace antlrcpptest
