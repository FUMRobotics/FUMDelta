#include "linearMovementStatement.h"
#include "iostream"

linearMovementStatement::linearMovementStatement(double XValue, double YValue, double ZValue, double AValue, double BValue, double CValue)
{
    type = "linearMovementStatement";
    parameters["X"] = XValue;
    parameters["Y"] = YValue;
    parameters["Z"] = ZValue;
    parameters["A"] = AValue;
    parameters["B"] = BValue;
    parameters["C"] = CValue;
}

void linearMovementStatement::setParameters(double XValue, double YValue, double ZValue, double AValue, double BValue, double CValue)
{
    parameters["X"] = XValue;
    parameters["Y"] = YValue;
    parameters["Z"] = ZValue;
    parameters["A"] = AValue;
    parameters["B"] = BValue;
    parameters["C"] = CValue;
}

std::map<std::string, double> linearMovementStatement::getParameters(){

    return parameters;
}

void linearMovementStatement::printParameters(){

    std::map<std::string, double>::iterator itr;
    for(itr=parameters.begin(); itr != parameters.end(); itr++)
            std::cout<<"the value of parameter"<<itr->first<<" is "<<itr->second<<std::endl;
}

void linearMovementStatement::executeStatement()
{
    //execute linear movement statement
}
