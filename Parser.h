#ifndef PARSER_H
#define PARSER_H
#include"Lexer.h"
namespace Sticher{
    struct LinkedList{
        LinkedList* Next=NULL;
        table Container;
    };
class Parser
{
    public:
        Parser(std::vector<table>);
        ~Parser();
        bool ParserError;
        std::vector<LinkedList*> OutputParseForest();
    protected:

    private:
        //members
        unsigned int counter=0;
        bool Parse();
        void ShowSymbolTable();
        std::vector<table> UniformSymbolTable;
        std::vector<LinkedList*> ParseForest;
};
}
#endif // PARSER_H
