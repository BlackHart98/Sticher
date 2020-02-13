#include "Semantics.h"
using namespace Sticher;
Semantics::Semantics()
{
//    Sticher::Parser();
    if(!Parser::ParserError)
    {
        //ShowParseForest();
    }
}

Semantics::~Semantics()
{
    //dtor
}
void Semantics::Traverse(LinkedList* CurrentNode)
{
    if(CurrentNode!=NULL)
    {
        std::cout<<CurrentNode->Container.Token<<" ";
        Traverse(CurrentNode->Next);
    }
}
void Semantics::ShowParseForest()
{
    for(int i=0;i<ParseForest.size();i++)
    {
        Traverse(ParseForest[i]);
        std::cout<<std::endl;
    }
}
