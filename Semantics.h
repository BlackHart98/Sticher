#ifndef SEMANTICS_H
#define SEMANTICS_H
#include"Parser.h"
#include<map>
namespace Sticher{
class Semantics
{
    public:
        Semantics();
        ~Semantics();
        bool SemanticError;
        std::map<std::string,LinkedList*> ProductionRule;
    protected:

    private:
        void ShowParseForest();
        void Traverse(LinkedList*);
        std::vector<LinkedList*> ParseForest;
};
}
#endif // SEMANTICS_H
