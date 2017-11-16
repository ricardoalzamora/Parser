#include "ListRules.h"

class Ejecutar{
public:
    int numOfRules = -1;
    char caracterForNewFinal = 48;
    ListRules *listRules[50];

    void imprimirReglas(){
        for(int i = 0; i <= numOfRules; i++){
            cout<<endl<<listRules[i]->getInitial()<<":"<<endl;
            for(int j = 0; j <= listRules[i]->getNumOfFinales(); j++){
                cout<<listRules[i]->getFinalPerPosition(j)<<" - ";
            }
        }
    }
    void deleteRecursionPerLeft(Ui::MainWindow *ui = NULL){
        string ruleFinalAuxFirst[50];
        int indexFirst = -1;
        string ruleFinalAuxSecond[50];
        int indexSecond = -1;
        for(int i = 0; i <= listRules[numOfRules]->getNumOfFinales(); i++){
            if(listRules[numOfRules]->getFinalPerPosition(i)[0] == listRules[numOfRules]->getInitial()[0]){
                if(listRules[numOfRules]->getFinalPerPosition(i) != ""){
                    ++indexFirst;
                    ruleFinalAuxFirst[indexFirst] = listRules[numOfRules]->getFinalPerPosition(i);
                }

            }else{
                if(listRules[numOfRules]->getFinalPerPosition(i) != ""){
                    ++indexSecond;
                    ruleFinalAuxSecond[indexSecond] = listRules[numOfRules]->getFinalPerPosition(i);
                }
            }
        }

        if(indexFirst != -1){
            listRules[numOfRules]->setNumOfFinales(-1);
            for(int i = 0; i <= indexSecond; i++){
                listRules[numOfRules]->addToListFinal(ruleFinalAuxSecond[i]);
            }
            for(int i = 0; i <= indexSecond; i++){
                listRules[numOfRules]->addToListFinal(ruleFinalAuxSecond[i] + std::to_string((char)caracterForNewFinal).substr(1));
            }
            string newRuleView = listRules[numOfRules]->getInitial() + "->";
            for(int i = 0; i <= listRules[numOfRules]->getNumOfFinales(); i++){
                newRuleView.append(listRules[numOfRules]->getFinalPerPosition(i));
                if(i != listRules[numOfRules]->getNumOfFinales()){
                    newRuleView.append("|");
                }
            }
            ui->listWidget->addItem(QString::fromStdString(newRuleView));

            if(indexSecond != -1){
                ++numOfRules;
                listRules[numOfRules] = new ListRules(std::to_string(caracterForNewFinal).substr(1));
                for(int i = 0; i <= indexFirst; i++){
                    listRules[numOfRules]->addToListFinal(ruleFinalAuxFirst[i].substr(1));
                }
                for(int i = 0; i <= indexFirst; i++){
                    listRules[numOfRules]->addToListFinal(ruleFinalAuxFirst[i].substr(1) + std::to_string((char)caracterForNewFinal).substr(1));
                }
                newRuleView = listRules[numOfRules]->getInitial() + "->";
                for(int i = 0; i <= listRules[numOfRules]->getNumOfFinales(); i++){
                    newRuleView.append(listRules[numOfRules]->getFinalPerPosition(i));
                    if(i != listRules[numOfRules]->getNumOfFinales()){
                        newRuleView.append("|");
                    }
                }
                ui->listWidget->addItem(QString::fromStdString(newRuleView));
            }
        }else{
            string newRule = listRules[numOfRules]->getInitial() + "->";
            for(int i = 0; i <= listRules[numOfRules]->getNumOfFinales(); i++){
                newRule.append(listRules[numOfRules]->getFinalPerPosition(i));
                if(i != listRules[numOfRules]->getNumOfFinales()){
                    newRule.append("|");
                }
            }
            ui->listWidget->addItem(QString::fromStdString(newRule));
        }

    }
    void separatePartsOfRule(string rule, Ui::MainWindow *ui = NULL){
        int last = 0;
        bool o = false;
        for(int i = 0; i < rule.length(); i++){
            if(rule[i] == '-' && rule[i+1] == '>'){
                ++numOfRules;
                listRules[numOfRules] = new ListRules(rule.substr(0, i));
                last = i + 2;
            }
            if((i == rule.length() - 1)){
                listRules[numOfRules]->addToListFinal(rule.substr(last));
                last = i;
            }
            if(rule[i] == '|' ){
                listRules[numOfRules]->addToListFinal(rule.substr(last, i - last));
                last = i + 1;
                o = true;
            }
        }
        deleteRecursionPerLeft(ui);

    }

    string validInsideString(string wordKey, char caracter){
        for(int i = 0; i < wordKey.length(); i++){
            if(wordKey[i] == caracter){
                return std::to_string(caracter);
            }
        }
        return "";
    }

    bool runRecursion(string word, string root, bool isRoot = true){
        if(isRoot){
            root = listRules[0]->getInitial();
        }

        for(int i = 0; i <= numOfRules ; i++){

            if((isRoot) || listRules[i]->getInitial() == root){
                for(int j = 0; j <= listRules[i]->getNumOfFinales(); j++){
                    string scannResult = validInsideString(listRules[i]->getFinalPerPosition(j), word[0]);
                    if(scannResult != ""){
                        if(word.length() == 1){
                            return true;
                        }
                        if(runRecursion(word.substr(1), scannResult, false)){
                            return true;
                        }
                    }else{
                        if(word.length() == 1){
                            return false;
                        }
                    }
                }
            }
        }
    }
};

