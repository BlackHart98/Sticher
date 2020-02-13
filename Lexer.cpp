#include "Lexer.h"
using namespace Sticher;
bool Lexer::LexerError=false;
Lexer::Lexer(std::string x):Input(x)
{
    while(counter<Input.length()&& !Lexer::LexerError)
    {
        if(!isComment(Input) && !isWhitespace(Input) && !isTerminal(Input) && !isNonterminal(Input)
           && !isEvaluator(Input) && !isSeperator(Input) && !isDelimiter(Input))
        {
            Lexer::LexerError=true;

            std::cout<<"Error Detected\n";
        }
    }
    if(Lexer::LexerError)
    {
        Lexer::UniformSymbolTable.clear();
    }
}
Lexer::Lexer()
{

}
Lexer::~Lexer()
{
    //dtor
}
std::vector<table> Lexer::OutputSymbolTable()
{
    return UniformSymbolTable;
}
bool Lexer::isLetter(char x)
{
    if((x>='A' && x<='Z')||(x>='a' && x<='z')||x=='_' )
    {
        return true;
    }
    return false;
}
bool Lexer::isDigit(char x)
{
    if(x>=0 && x<=9)
    {
        return true;
    }
    return false;
}
bool Lexer::isNonterminal(std::string x)
{
    table SymbolRow;
    std::string Token="";
    int i=counter;
    if(x[i]=='<' && i<x.length())
    {
        i++;
        while(i<x.length()&& x[i]!='>')
        {
            Token+=x[i];
            i++;
        }
        if(x[i]=='>')
        {
            SymbolRow.Token=Token;
            SymbolRow.TokenType=NONTERMINAL;
            UniformSymbolTable.push_back(SymbolRow);
            i++;
            counter=i;
            return true;
        }
    }
    return false;
}
bool Lexer::isTerminal(std::string x)
{
    table SymbolRow;
    std::string Token="";
    int i=counter;
    if(x[i]=='[')
    {
        i++;
        while(i<(int)x.length() && x[i]!=']')
        {
            Token+=x[i];
            i++;
        }
        if(x[i]==']')
        {
            if(x[i+1] == ']')
            {
                Token+=x[i];
                SymbolRow.Token=Token;
                SymbolRow.TokenType=TERMINAL;
                UniformSymbolTable.push_back(SymbolRow);
                i+=2;
                counter=i;
                return true;
            }
            SymbolRow.Token=Token;
            SymbolRow.TokenType=TERMINAL;
            UniformSymbolTable.push_back(SymbolRow);
            i++;
            counter=i;
            return true;
        }
    }
    return false;
}
bool Lexer::isEvaluator(std::string x)
{
    table SymbolRow;
    std::string Token="";
    int i=counter;
    if(x[i]=='-' && i<x.length())
    {
        Token+=x[i];
        i++;
        if(x[i]=='-' && i<x.length())
        {
            Token+=x[i];
            i++;
            if(x[i]=='>')
            {
                Token+=x[i];
                SymbolRow.Token=Token;
                SymbolRow.TokenType=EVALUATOR;
                Lexer::UniformSymbolTable.push_back(SymbolRow);
                i++;
                counter=i;
                return true;
            }
        }
    }
    return false;
}

bool Lexer::isDelimiter(std::string x)
{
    table SymbolRow;
    std::string Token="";
    int i=counter;
    if(x[i]=='.')
    {
        Token+=x[i];
        SymbolRow.Token=Token;
        SymbolRow.TokenType=DELIMITER;
        UniformSymbolTable.push_back(SymbolRow);
        i++;
        counter=i;
        return true;
    }
    return false;
}
bool Lexer::isWhitespace(std::string x)
{
    if(x[counter]==' ' || x[counter]=='\n' || x[counter]=='\t')
    {
        counter++;
        return true;
    }
    return false;
}

bool Lexer::isSeperator(std::string x)
{
    table SymbolRow;
    std::string Token="";
    int i=counter;
    if(x[i]==',')
    {
        Token+=x[i];
        SymbolRow.Token=Token;
        SymbolRow.TokenType=SEPERATOR;
        UniformSymbolTable.push_back(SymbolRow);
        i++;
        counter=i;
        return true;
    }
    return false;
}
bool Lexer::isComment(std::string x)
{
    int i=counter;
    if(x[i]=='{' && i<x.length())
    {
        i++;
        while(i<x.length() && x[i]!='}')
        {
            i++;
        }
        if(x[i]=='}' && i<x.length())
        {
            i++;
            counter=i;
            return true;
        }
    }
    return false;
}
void Lexer::ShowSymbolTable()
{
    for(int i=0;i<UniformSymbolTable.size();i++)
    {
        std::cout<<Lexer::UniformSymbolTable[i].Token<<"   "<<Lexer::UniformSymbolTable[i].TokenType<<std::endl;
    }
}
void Lexer::Clean()
{
    UniformSymbolTable.clear();
}
