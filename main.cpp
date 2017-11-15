#include "mainwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    //separatePartsOfRule("S->a|ah|j");
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    return a.exec();

}
