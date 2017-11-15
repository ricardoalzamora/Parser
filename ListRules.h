class ListRules{
    private:
    string initial;
    string listFinal[50];
    int numOfFinales;

    public:
    ListRules(string initial){
        this->initial = initial;
        numOfFinales = VACIO;
    }

    string getInitial(){
        return initial;
    }

    string* GetListFinal(){
        return listFinal;
    }

    void addToListFinal(string nameOfNewFinal){
        ++numOfFinales;
        listFinal[numOfFinales] = nameOfNewFinal;
    }

};
