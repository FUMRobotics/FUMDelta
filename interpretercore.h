#ifndef INTERPRETERCORE_H
#define INTERPRETERCORE_H
#include <QString>

class InterpreterCore
{
public:
    InterpreterCore();
    int base();
    int parsText(QString s);
};

#endif // INTERPRETERCORE_H
