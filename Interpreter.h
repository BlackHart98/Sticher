#ifndef INTERPRETER_H
#define INTERPRETER_H
#include"Lexer.h"
namespace Sticher{
class Interpreter
{
    public:
        Interpreter();
        ~Interpreter();
        Sticher::Lexer b(std::string);
    protected:

    private:
};
}

#endif // INTERPRETER_H
