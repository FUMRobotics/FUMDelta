#include "ptpAxisMovementStatement.h"
#include "iostream"

ptpAxisMovementStatement::ptpAxisMovementStatement(double A1Value, double A2Value, double A3Value, double A4Value)
{
    type = "ptpAxisMovementStatement";
    parameters["A1"] = A1Value;
    parameters["A2"] = A2Value;
    parameters["A3"] = A3Value;
    parameters["A4"] = A4Value;

}

void ptpAxisMovementStatement::setParameters(double A1Value, double A2Value, double A3Value, double A4Value)
{
    parameters["A1"] = A1Value;
    parameters["A2"] = A2Value;
    parameters["A3"] = A3Value;
    parameters["A4"] = A4Value;
}

std::map<std::string, double> ptpAxisMovementStatement::getParameters(){

    return parameters;
}

void ptpAxisMovementStatement::printParameters(){

    std::map<std::string, double>::iterator itr;
    for(itr=parameters.begin(); itr != parameters.end(); itr++)
            std::cout<<"the value of parameter"<<itr->first<<" is "<<itr->second<<std::endl;
}

void ptpAxisMovementStatement::executeStatement()
{
    //execute ptp-axis movement statement
}



