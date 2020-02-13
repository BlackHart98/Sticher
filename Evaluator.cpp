#include "Evaluator.h"
using namespace Sticher;
bool Evaluator::EvaluationError=false;
Evaluator::Evaluator(std::vector<LinkedList*> ParseForest)
{
    this->ParseForest=ParseForest;
}
Evaluator::~Evaluator()
{
    Clean();
}
void Evaluator::Derive(std::string Goal, std::string InputString)
{
    int i,j;
    Input=InputString;
    Goalstring=Goal;
    IsValidstring=false;
    if(Goalstring != "" && Input !="")
    {
        if(true)
        {
            if(isLeftHandNonterminal(Goalstring))
            {
                GoalSymbol.Token=Goalstring;
                GoalSymbol.TokenType=NONTERMINAL;
            }
            else
                EvaluationError=true;
            if(!EvaluationError)
            {
                ToSymbol(Input);
                do
                {
                    i=Length(RightHandSymbol);
                    Reduce();
                    j=Length(RightHandSymbol);
                    Reduce();
                }while(i > j && j>Length(RightHandSymbol));
                if(RightHandSymbol->Container.Token==Goalstring && Length(RightHandSymbol)==1)
                {
                    IsValidstring=true;
                    std::cout<<"true."<<std::endl;
                }
                else
                {
                    IsValidstring=false;
                    std::cout<<"false."<<std::endl;
                }
            }
        }
    }
}
bool Evaluator::isLeftHandNonterminal(std::string x)
{
    bool found=false;
    int i=0;
    while(!found && i<ParseForest.size())
    {
        if(x==ParseForest[i]->Container.Token)
        {
            found=true;
        }
        i++;
    }
    return found;
}
int Evaluator::Length(LinkedList* x)
{
    int i=0;
    while(x!=NULL)
    {
        i++;
        x=x->Next;
    }
    return i;
}
void Evaluator::Traverse(LinkedList* CurrentNode)
{
    if(CurrentNode!=NULL)
    {
        Traverse(CurrentNode->Next);
    }
}
void Evaluator::ToSymbol(std::string x)
{
    int i=0;
    LinkedList* StaticNode=new LinkedList;
    LinkedList* DynamicNode=StaticNode;
    if(i<Input.length())
    {

        DynamicNode->Container.Token=Input[i];
        DynamicNode->Container.TokenType=TERMINAL;
        i++;
        while(i<Input.length())
        {
            DynamicNode->Next=new LinkedList;
            DynamicNode->Next->Container.Token=Input[i];
            DynamicNode->Next->Container.TokenType=TERMINAL;
            DynamicNode=DynamicNode->Next;
            i++;
        }
        RightHandSymbol=StaticNode;
    }
}
void Evaluator::ShrinkInputSymbol()
{

}
bool Evaluator::CompareSymbol(LinkedList* x,LinkedList* y)
{
    int i=0;
    while(x!=NULL && y!=NULL)
    {
        if(x->Container.TokenType != y->Container.TokenType)
        {
            return false;
        }
        if(x->Container.TokenType ==NONTERMINAL)
        {
            if(x->Container.Token != y->Container.Token)
            {
                return false;
            }
            x=x->Next;
            i++;
        }
        if(y->Container.TokenType == TERMINAL)
        {
            for(int j=0; j < y->Container.Token.size(); j++)
            {
                if(x!=NULL)
                {
                   if(x->Container.Token[0] != y->Container.Token[j])
                    {
                        return false;
                    }
                    x=x->Next;
                    i++;
                }
            }

        }
        y=y->Next;
    }
    counter=i;
    return true;
}
 bool Evaluator::Evaluate()
 {
     for(int i=0;i<ParseForest.size();i++)
     {
        if(Length(RightHandSymbol) >= Length(ParseForest[i]->Next))
        {
            if(CompareSymbol(RightHandSymbol,ParseForest[i]->Next))
            {
                RightHandSymbol->Container.Token=ParseForest[i]->Container.Token;
                RightHandSymbol->Container.TokenType=ParseForest[i]->Container.TokenType;
                Replace(RightHandSymbol);
                return true;
            }
        }

     }
     return false;
 }
 bool Evaluator::Evaluate(LinkedList* x)
 {
      for(int i=0;i<ParseForest.size();i++)
     {
        if(Length(x) >= Length(ParseForest[i]->Next))
        {
            if(CompareSymbol(x,ParseForest[i]->Next))
            {
                x->Container.Token=ParseForest[i]->Container.Token;
                x->Container.TokenType=ParseForest[i]->Container.TokenType;
                Replace(x);
                return true;
            }
        }

     }
     return false;
 }
 void Evaluator::Reduce()
 {
     LinkedList* x;
     x=RightHandSymbol;
           while(x!=NULL)
            {
                if(Evaluate(x))
                {
                    Traverse(RightHandSymbol);
                    EvaluationError=false;
                }
                else
                {
                    x=x->Next;
                }
            }
 }
void Evaluator::Replace(LinkedList* x)
{
    int i=0;
    LinkedList* y=x;
    while(i<counter && x!=NULL)
    {
        y=y->Next;
        i++;
    }
    x->Next=y;
}
void Evaluator::Clean()
{
    ParseForest.clear();
}
bool Evaluator::IsValid()
{
    return IsValidstring;
}
std::string DeriveTerminal(std::string inputString)
{
 //   for(int i=0;i<(int)ParseForest.size();i++)
   // {

    //}
}
