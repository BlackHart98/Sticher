#include<iostream>
#include<fstream>
#include"Evaluator.h"
#include<vector>

int main(int argc,char** argv)
{
    std::ifstream file("English_Language.bnf");
    std::string Englang;
    if(!file)
    {
        std::cout<<"The file was not found or failed to initialize\n";
    }
	else
    {
        char c;
        while(file.get(c))
        {
            Englang+=c;
        }
        Sticher::Lexer CFG(Englang);
        Sticher::Parser PSR(CFG.OutputSymbolTable());
        Sticher::Evaluator EVAL(PSR.OutputParseForest());
        EVAL.Derive("sentence","every human is mortal");
       // EVAL.Derive("proper_noun","socrates");
    }
    return 0;
}
