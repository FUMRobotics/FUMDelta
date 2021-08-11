#include "ptpPosMovementStatement.h"
#include "iostream"

ptpPosMovementStatement::ptpPosMovementStatement(double XValue, double YValue, double ZValue, double AValue, double BValue, double CValue)
{
    type = "ptpAxisMovementStatement";
    parameters["X"] = XValue;
    parameters["Y"] = YValue;
    parameters["Z"] = ZValue;
    parameters["A"] = AValue;
    parameters["B"] = BValue;
    parameters["C"] = CValue;
}

void ptpPosMovementStatement::setParameters(double XValue, double YValue, double ZValue, double AValue, double BValue, double CValue)
{
    parameters["X"] = XValue;
    parameters["Y"] = YValue;
    parameters["Z"] = ZValue;
    parameters["A"] = AValue;
    parameters["B"] = BValue;
    parameters["C"] = CValue;
}

std::map<std::string, double> ptpPosMovementStatement::getParameters(){

    return parameters;
}

void ptpPosMovementStatement::printParameters(){

    std::map<std::string, double>::iterator itr;
    for(itr=parameters.begin(); itr != parameters.end(); itr++)
            std::cout<<"the value of parameter"<<itr->first<<" is "<<itr->second<<std::endl;
}

void ptpPosMovementStatement::executeStatement()
{
    //execute ptp-pos movement statement
}



