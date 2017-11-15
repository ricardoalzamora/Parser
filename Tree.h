using namespace std;
const int VACIO = -1;
class Tree{
    private:

    string caracter;
    Tree *Childs[50];
    int numOfChildren;

    public:
    Tree(string caracter){
        this->caracter = caracter;
        numOfChildren = VACIO;
    }

    string getCaracter(){
        return caracter;
    }
    void setCaracter(string caracter){
        this->caracter = caracter;
    }

    int getNumOfChildren(){
        return numOfChildren;
    }

    void setNumOfChildren(int numOfChildren){
        this->numOfChildren = numOfChildren;
    }

    void addToListChildren(string childName){
        ++numOfChildren;
        Childs[numOfChildren] = new Tree(childName);
    }

};