
// Generated from /home/fatemeh/Documents/antlr4-delta/runtime/Cpp/demo/TParser.g4 by ANTLR 4.7.2

#pragma once

#include "antlr4-runtime.h"
#include "TParserListener.h"
#include "generated/TLexer.h"
#include "statement.h"
#include "assignmentStatement.h"
#include "forStatement.h"
#include "ifStatement.h"
#include "whileStatement.h"
#include "linearMovementStatement.h"
#include "circularMovementStatement.h"
#include "ptpAxisMovementStatement.h"
#include "ptpPosMovementStatement.h"
#include "variable.h"
#include "boolVariable.h"
#include "intVariable.h"
#include "posVariable.h"
#include "scope.h"
#include <map>
#include <vector>

namespace antlrcpptest {

/*
 * This class provides an empty implementation of TParserListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */

class  TParserBaseListener : public TParserListener {
public:

  std::map<std::string, variable*> variablesSet;
  std::vector<scope*> scopes;
  int currScopeNum;

  virtual void enterModule(TParser::ModuleContext * ctx) override
  {
      scopes.push_back(new scope(NULL, "main"));
      currScopeNum = 0;
  }
  virtual void exitModule(TParser::ModuleContext * /*ctx*/) override { }

  virtual void enterModuleRoutines(TParser::ModuleRoutinesContext * /*ctx*/) override { }
  virtual void exitModuleRoutines(TParser::ModuleRoutinesContext * /*ctx*/) override { }

  virtual void enterMainRoutine(TParser::MainRoutineContext * /*ctx*/) override { }
  virtual void exitMainRoutine(TParser::MainRoutineContext * /*ctx*/) override { }

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

  virtual void enterVariableDeclaration(TParser::VariableDeclarationContext * ctx) override
  {
      std::string type = ctx->children[1]->getText();
      int i;
      if(type == "INT")
      {
          variablesSet[ctx->children[2]->getText()] = new intVariable();
          variablesSet[ctx->children[2]->getText()]->setName(ctx->children[2]->getText());
          variablesSet[ctx->children[2]->getText()]->setType("INT");
      }
      else if(type == "BOOLEAN")
      {
          variablesSet[ctx->children[2]->getText()] = new boolVariable();
          variablesSet[ctx->children[2]->getText()]->setName(ctx->children[2]->getText());
          variablesSet[ctx->children[2]->getText()]->setType("BOOLEAN");
      }
  }
  virtual void exitVariableDeclaration(TParser::VariableDeclarationContext * /*ctx*/) override { }

  virtual void enterSignalDeclaration(TParser::SignalDeclarationContext * /*ctx*/) override { }
  virtual void exitSignalDeclaration(TParser::SignalDeclarationContext * /*ctx*/) override { }

  virtual void enterVariableDeclarationInDataList(TParser::VariableDeclarationInDataListContext * /*ctx*/) override { }
  virtual void exitVariableDeclarationInDataList(TParser::VariableDeclarationInDataListContext * /*ctx*/) override { }

  virtual void enterVariableListRest(TParser::VariableListRestContext * ctx) override
  {
      std::string type = ctx->parent->children[1]->getText();
      int i;
      if(type == "INT")
      {
          for(i=1; i < ctx->children.size(); i+=2){
              variablesSet[ctx->children[i]->getText()] = new intVariable();
              variablesSet[ctx->children[i]->getText()]->setName(ctx->children[i]->getText());
              variablesSet[ctx->children[i]->getText()]->setType("INT");
          }
      }
      else if(type == "BOOLEAN")
      {
          for(i=1; i < ctx->children.size(); i+=2){
              variablesSet[ctx->children[i]->getText()] = new boolVariable();
              variablesSet[ctx->children[i]->getText()]->setName(ctx->children[i]->getText());
              variablesSet[ctx->children[i]->getText()]->setType("BOOLEAN");
          }
      }
  }
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

  virtual void enterStatement(TParser::StatementContext * ctx) override
  {
      statement* sta;
      if(ctx->children[0]->getText() == "FOR")
      {
          if(ctx->children[6]->getText() == "STEP")
          {
              sta = new forStatement(variablesSet[ctx->children[1]->getText()], stoi(ctx->children[3]->getText()), stoi(ctx->children[5]->getText()), stoi(ctx->children[7]->getText()));
          }
          else
          {
              sta = new forStatement(variablesSet[ctx->children[1]->getText()], stoi(ctx->children[3]->getText()), stoi(ctx->children[5]->getText()), 1);
          }

      }
      else if(ctx->children[0]->getText() == "WHILE")
      {

      }
      else if(ctx->children[0]->getText() == "IF")
      {
          if(variablesSet[ctx->children[1]->children[0]->getText()]->getType() == "INT")
          {
              sta = new ifStatement(variablesSet[ctx->children[1]->children[0]->getText()], ctx->children[1]->children[1]->getText(), stoi(ctx->children[1]->children[2]->getText()));
          }
          else if(variablesSet[ctx->children[1]->children[0]->getText()]->getType() == "BOOLEAN")
          {
              bool b;
              std::istringstream(ctx->children[1]->children[2]->getText()) >> std::boolalpha >> b;
              sta = new ifStatement(variablesSet[ctx->children[1]->children[0]->getText()], ctx->children[1]->children[1]->getText(), b);
          }
          else if(variablesSet[ctx->children[1]->children[0]->getText()]->getType() == "REAL")
          {
              sta = new ifStatement(variablesSet[ctx->children[1]->children[0]->getText()], ctx->children[1]->children[1]->getText(), stod(ctx->children[1]->children[2]->getText()));
          }

          static_cast<ifStatement*>(sta)->setHasElse(ctx->children.size() > 7);
      }
      else if(ctx->children[0]->getText() == "LIN")
      {
          sta = new linearMovementStatement(stod(ctx->children[1]->children[1]->children[0]->children[1]->getText()),
                                            stod(ctx->children[1]->children[1]->children[2]->children[1]->getText()),
                                            stod(ctx->children[1]->children[1]->children[4]->children[1]->getText()),
                                            stod(ctx->children[1]->children[1]->children[6]->children[1]->getText()),
                                            stod(ctx->children[1]->children[1]->children[8]->children[1]->getText()),
                                            stod(ctx->children[1]->children[1]->children[10]->children[1]->getText()));
      }
      else if(ctx->children[0]->getText() == "CIRC")
      {
          sta = new circularMovementStatement(static_cast<posVariable*>(variablesSet[ctx->children[1]->getText()]),
                                              static_cast<posVariable*>(variablesSet[ctx->children[3]->getText()]));
      }
      else if(ctx->children[0]->getText() == "PTP" && ctx->children[1]->children[1]->getText() == "POS")
      {
          sta = new ptpPosMovementStatement(stod(ctx->children[1]->children[3]->children[0]->children[1]->getText()),
                                            stod(ctx->children[1]->children[3]->children[2]->children[1]->getText()),
                                            stod(ctx->children[1]->children[3]->children[4]->children[1]->getText()),
                                            stod(ctx->children[1]->children[3]->children[6]->children[1]->getText()),
                                            stod(ctx->children[1]->children[3]->children[8]->children[1]->getText()),
                                            stod(ctx->children[1]->children[3]->children[10]->children[1]->getText()));

      }
      else if(ctx->children[0]->getText() == "PTP" && ctx->children[1]->children[1]->getText() == "AXIS")
      {
          sta = new ptpAxisMovementStatement(stod(ctx->children[1]->children[3]->children[0]->children[1]->getText()),
                                            stod(ctx->children[1]->children[3]->children[2]->children[1]->getText()),
                                            stod(ctx->children[1]->children[3]->children[4]->children[1]->getText()),
                                            stod(ctx->children[1]->children[3]->children[6]->children[1]->getText()));
      }
      else
      {
          if(variablesSet[ctx->children[0]->children[0]->getText()]->getType() == "INT")
          {
              sta = new assignmentStatement(variablesSet[ctx->children[0]->children[0]->getText()], stoi(ctx->children[0]->children[2]->getText()));
          }
          else if(variablesSet[ctx->children[0]->children[0]->getText()]->getType() == "REAL")
          {
              sta = new assignmentStatement(variablesSet[ctx->children[0]->children[0]->getText()], stod(ctx->children[0]->children[2]->getText()));

          }
          else if(variablesSet[ctx->children[0]->children[0]->getText()]->getType() == "BOOLEAN")
          {
              bool b;
              std::istringstream(ctx->children[0]->children[2]->getText()) >> std::boolalpha >> b;
              sta = new assignmentStatement(variablesSet[ctx->children[0]->children[0]->getText()], b);
          }
      }

      if(sta->getType() == "FOR")
      {
          scope* s =  new scope(scopes[currScopeNum], "FOR");
          scopes.push_back(s);
          currScopeNum++;
      }
      else if(sta->getType() == "WHILE")
      {
          scope* s =  new scope(scopes[currScopeNum], "WHILE");
          scopes.push_back(s);
          currScopeNum++;

      }
      else if(sta->getType() == "IF")
      {

      }
  }
  virtual void exitStatement(TParser::StatementContext * ctx) override
  {
      if(ctx->children[0]->getText() == "FOR")
      {
          std::vector<statement*> s = scopes[currScopeNum]->parent->statementsVector;
          std::vector<statement*> ss = scopes[currScopeNum]->statementsVector;
          static_cast<forStatement*>(s[s.size()])->setStatements(ss);
          s[s.size()]->executeStatement();
      }
      else if(ctx->children[0]->getText() == "WHILE" || ctx->children[0]->getText() == "IF")
      {
          std::vector<statement*> s = scopes[currScopeNum]->parent->statementsVector;
          std::vector<statement*> ss = scopes[currScopeNum]->statementsVector;
          static_cast<forStatement*>(s[s.size()])->setStatements(ss);
          s[s.size()]->executeStatement();
      }
      else if(ctx->children[0]->getText() == "IF")
      {

      }
  }

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

  virtual void enterAssignmentExpression(TParser::AssignmentExpressionContext * ctx) override
  {
      if(variablesSet[ctx->children[0]->getText()]->getType() == "INT")
      {
          variablesSet[ctx->children[0]->getText()]->setBoolValue(stoi(ctx->children[2]->getText()));
      }
      else if(variablesSet[ctx->children[0]->getText()]->getType() == "BOOLEAN"){
          bool b;
          std::istringstream(ctx->children[2]->getText()) >> std::boolalpha >> b;
          variablesSet[ctx->children[0]->getText()]->setBoolValue(b);
       }
  }
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

}
