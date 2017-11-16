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
        numOfFinales = -1;
    }

    string getInitial(){
        return initial;
    }

    void setInitial(string initial){
        this->initial = initial;
    }

    string* getListFinal(){
        return listFinal;
    }

    int getNumOfFinales(){
        return numOfFinales + 1;
    }

    void setNumOfFinales(int numOfFinales){
        this->numOfFinales = numOfFinales;
    }

    string getFinalPerPosition(int position){
        if(position <= numOfFinales){
            return listFinal [position];
        }else{
            return "";
        }
    }
    void setFinalPerPosition(int position, string newFinal){
        listFinal[position] = newFinal;
    }

    void addToListFinal(string nameOfNewFinal){
        numOfFinales++;
        listFinal[numOfFinales] = nameOfNewFinal;
    }

};
