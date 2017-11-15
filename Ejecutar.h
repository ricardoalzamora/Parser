#include "ListRules.h"
#include "Tree.h"

class Ejecutar{
public:
    int numOfRules = -1;
    ListRules *listRules[50];

    void separatePartsOfRule(string rule){
        int last = 0;
        for(int i = 0; i < rule.length(); i++){
            if(rule[i] == '-' && rule[i+1] == '>'){
                ++numOfRules;
                listRules[numOfRules] = new ListRules(rule.substr(0, i));
                last = i + 2;
            }
            if((i == rule.length() - 1)){
                listRules[numOfRules]->addToListFinal(rule.substr(last, rule.length()));
                last = i;
            }
            if(rule[i] == '|' ){
                listRules[numOfRules]->addToListFinal(rule.substr(last, i - last));
                last = i + 1;
            }
        }
        for(int j = 0; j <= numOfRules; j++){
            system("clear");
            cout<<listRules[j]->getInitial()<<endl;
            for(int i = 0; i < listRules[j]->getnumOfFinales(); i++){
                cout<<listRules[j]->getFinalPerPosition(i)<<endl;
            }
            cout<<listRules[j]->getnumOfFinales();
        }

    }
};

