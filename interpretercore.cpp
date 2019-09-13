#include "interpretercore.h"
#include <string>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#undef emit
#undef SIGNAL
#include "antlr4-runtime.h"
#define emit
#include "generated/TLexer.h"
#include "generated/TParser.h"
#include "generated/TParserBaseListener.h"

using namespace antlrcpptest;
using namespace antlr4;

InterpreterCore::InterpreterCore()
{

}

int InterpreterCore::base()
{
    QFile file("/home/fatemeh/Documents/movement.txt");
    if(!file.open(QIODevice::ReadOnly)){
      qDebug("error");
    }
    QTextStream in(&file);
    QString s = in.readAll();
    ANTLRInputStream input( s.toStdString());
    TLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    tokens.fill();

    /*for (auto token : tokens.getTokens()) {

      //std::cout << token->toString() << std::endl;
      std::string text = token->getText();
      std::cout << text << std::endl;
    }*/

    TParser parser(&tokens);
    tree::ParseTree* tree = parser.module();

    //std::cout << tree->toStringTree(&parser) << std::endl << std::endl;

    TParserBaseListener* listener = new TParserBaseListener;
    tree::ParseTreeWalker* walker = new tree::ParseTreeWalker();
    walker->walk(listener, tree);

    return 0;
}
;
