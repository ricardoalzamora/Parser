#include <iostream>
using namespace  std;

class ListRules{
    private:
    string initial;
    string listFinal[50];
    int numOfFinales;

    public:
    ListRules(string initial){
        this->initial = initial;
        numOfFinales = 0;
    }

    string getInitial(){
        return initial;
    }

    string* getListFinal(){
        return listFinal;
    }

    int getnumOfFinales(){
        return numOfFinales;
    }

    string getFinalPerPosition(int position){
        if(position < numOfFinales){
            return listFinal [position];
        }else{
            return "";
        }
    }

    void addToListFinal(string nameOfNewFinal){        
        listFinal[numOfFinales] = nameOfNewFinal;
        numOfFinales++;
    }

};
