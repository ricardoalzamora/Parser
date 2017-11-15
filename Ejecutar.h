#include "ui_mainwindow.h"
#include "ListRules.h"
#include "Tree.h"

class Ejecutar{
public:
    int numOfRules = -1;
    int caracterForNewFinal = 128;
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
        /*for(int i = 0; i <= numOfRules; i++){
            cout<<listRules[i]->getInitial()<<listRules[i]->getInitial().length()<<endl;
            for(int j = 0; j <= listRules[i]->getnumOfFinales(); j++){
                cout<<listRules[i]->getFinalPerPosition(j)<<endl;
            }
            cout<<listRules[i]->getnumOfFinales();
        }*/

    }

    void deleteRecursionPerLeft(Ui::MainWindow *ui = NULL){
        for(int i = 0; i <= numOfRules; i++){
            string itemToListView = listRules[i]->getInitial() + "->";
            for(int j = 0; j <= listRules[i]->getnumOfFinales(); j++){

                if(listRules[i]->getInitial()[0] == listRules[i]->getFinalPerPosition(j)[0]){
                    listRules[i]->setFinalPerPosition(j
                    , listRules[i]->getFinalPerPosition(j).substr(1, listRules[i]->getFinalPerPosition(j).length())
                    + (char)caracterForNewFinal);
                    caracterForNewFinal++;
                }
                itemToListView.append(listRules[i]->getFinalPerPosition(j));
                if(j < listRules[i]->getnumOfFinales() - 1){
                    itemToListView.append("|");
                }
            }

            ui->listWidget->addItem(QString::fromStdString(itemToListView));

        }
    }

    bool runRecursion(string word, int index){
        for(int i = 0; i <= numOfRules; i++){
            for(int j = 0; j <= listRules[i]->getnumOfFinales(); j++){

            }
        }
    }
};

