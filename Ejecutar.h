#include "ui_mainwindow.h"
#include "ListRules.h"
#include "Tree.h"
#include <string>

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
    void deleteRecursionPerLeftA(Ui::MainWindow *ui = NULL){
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
        deleteRecursionPerLeftA(ui);

        for(int i = 0; i <= numOfRules; i++){
            cout<<listRules[i]->getInitial()<<": "<<listRules[i]->getNumOfFinales()<<endl;
            for(int j = 0; j <= listRules[i]->getNumOfFinales(); j++){
                cout<<listRules[i]->getFinalPerPosition(j)<<endl;
            }
        }

    }

    bool runRecursion(string word, int index){
        for(int i = 0; i <= numOfRules; i++){
            for(int j = 0; j <= listRules[i]->getNumOfFinales(); j++){

            }
        }
    }
};

