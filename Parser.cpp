#include "Parser.h"
using namespace Sticher;
Parser::Parser(std::vector<table> SymbolTable):UniformSymbolTable(SymbolTable)
{
    if(UniformSymbolTable.size()>0)
    {
        Parser::ParserError=false;
        while(counter<UniformSymbolTable.size() && !Parser::ParserError)
        {
            if(!Parse())
            {
                Parser::ParserError=true;
            }
            counter++;
        }
    }
}

Parser::~Parser()
{
    //dtor
}
bool Parser::Parse()
{
    LinkedList* StaticNode=new LinkedList;
    LinkedList* DynamicNode=StaticNode;
    if(UniformSymbolTable[counter].TokenType!=NONTERMINAL)
    {
        delete DynamicNode;
        delete StaticNode;
        return false;
    }
    DynamicNode->Container=UniformSymbolTable[counter];
    counter++;
    if(counter>=UniformSymbolTable.size())
    {
        delete DynamicNode;
        delete StaticNode;
        return false;
    }
    if(UniformSymbolTable[counter].TokenType!=EVALUATOR)
    {
        delete DynamicNode;
        delete StaticNode;
        return false;
    }
    counter++;
    if(counter>=UniformSymbolTable.size())
    {
        delete DynamicNode;
        delete StaticNode;
        return false;
    }

    if(UniformSymbolTable[counter].TokenType!=NONTERMINAL && UniformSymbolTable[counter].TokenType!=TERMINAL)
    {
        delete DynamicNode;
        delete StaticNode;
        return false;
    }
    DynamicNode->Next=new LinkedList;
    DynamicNode->Next->Container=UniformSymbolTable[counter];
    counter++;
    while(UniformSymbolTable[counter].TokenType!=DELIMITER && counter<UniformSymbolTable.size())
    {
        DynamicNode=DynamicNode->Next;
        if(UniformSymbolTable[counter].TokenType!=SEPERATOR)
        {
            delete DynamicNode;
            delete StaticNode;
            return false;
        }
        counter++;
        if(counter>=UniformSymbolTable.size())
        {
            delete DynamicNode;
            delete StaticNode;
            return false;
        }
        if(UniformSymbolTable[counter].TokenType!=NONTERMINAL && UniformSymbolTable[counter].TokenType!=TERMINAL)
        {
            delete DynamicNode;
            delete StaticNode;
            return false;
        }
        DynamicNode->Next=new LinkedList;
        DynamicNode->Next->Container=UniformSymbolTable[counter];
        counter++;

    }
    if(UniformSymbolTable[counter].TokenType==DELIMITER)
    {
        Parser::ParseForest.push_back(StaticNode);
        return true;
    }
    return false;
}
void Parser::ShowSymbolTable()
{
    for(int i=0;i<UniformSymbolTable.size();i++)
    {
        std::cout<<UniformSymbolTable[i].Token<<"   "<<UniformSymbolTable[i].TokenType<<std::endl;
    }
}
std::vector<LinkedList*> Parser::OutputParseForest()
{
    return ParseForest;
}
