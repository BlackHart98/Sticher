#ifndef LEXER_H
#define LEXER_H
#include<iostream>
#include<string>
#include<vector>
//using namespace std;
namespace Sticher{
    enum CategoriseOfToken{TERMINAL,NONTERMINAL,EVALUATOR,SEPERATOR,DELIMITER,OR_OPERATOR};
    typedef struct{
       std::string Token;
       CategoriseOfToken TokenType;
    } table;
class Lexer
{
    public:
        Lexer(std::string);
        Lexer();
        ~Lexer();
        static bool LexerError;
        std::vector<table> OutputSymbolTable();
        void Clean();
    protected:

    private:
        //members
        std::string Input;
        int counter=0;
        //methods
        bool isLetter(char);//Returns true if a letter is detected
        bool isDigit(char);//Returns true if a number is detected
        bool isNonterminal(std::string);//Returns true if a nonterminal std::string is detected
        bool isTerminal(std::string);//Returns true if a terminal std::string is detected
        bool isEvaluator(std::string);//Returns true if a evaluator is detected
        bool isDelimiter(std::string);//Returns true if a delimiter is detected
        bool isSeperator(std::string);//Returns true if a seperator is detected
        bool isWhitespace(std::string);//Returns true if a whitespace is detected
        bool isComment(std::string);//Returns true if a comment is detected
        bool isOr_Operator(std::string);//Returns true if an or operator is detected
        void ShowSymbolTable();//Displays the Uniform Symbol Table
        std::vector<table> UniformSymbolTable;
};
}
#endif // LEXER_H
