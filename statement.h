#ifndef STATEMENT_H
#define STATEMENT_H
#include <string>

class statement
{
public:
    std::string type;
    statement();
    void executeStatement();
    void setType(std::string sType);
    std::string getType();
};

#endif // STATEMENT_H
