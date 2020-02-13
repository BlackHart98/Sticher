#ifndef EVALUATOR_H
#define EVALUATOR_H

#include"Semantics.h"
namespace Sticher{
class Evaluator
{
    public:
        Evaluator(std::vector<LinkedList*>);
        ~Evaluator();
        static bool EvaluationError;
        void Clean();
        bool IsValid();//return if std::string is parse
        void Derive(std::string, std::string);
        std::string DeriveTerminal(std::string);
    protected:

    private:
        //members
        LinkedList* RightHandSymbol;
        table GoalSymbol;
        std::string Input;
        std::string Goalstring;
        bool IsValidstring;
        int counter;
        //methods
        bool isLeftHandNonterminal(std::string);
        int Length(LinkedList*);
        void Traverse(LinkedList*);
        void ToSymbol(std::string);//this function can only be used once
        void ShrinkInputSymbol();
        bool CompareSymbol(LinkedList*,LinkedList*);
        bool Evaluate();
        bool Evaluate(LinkedList*);// Evaluates the given std::string to the goal std::string
        void Reduce();
        bool CompareSymbolEx(LinkedList*,LinkedList*,int*);//This is an extension of the comparison function
        void Replace(LinkedList*);
        std::vector<LinkedList*> ParseForest;

};
}

#endif // EVALUATOR_H
