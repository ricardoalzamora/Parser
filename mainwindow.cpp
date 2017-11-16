#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Ejecutar.h"

Ejecutar ejecutar = Ejecutar();

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->lineEdit->text() != ""){
        ejecutar.separatePartsOfRule(ui->lineEdit->text().toStdString(), ui);
        ui->lineEdit->clear();
    }
}

void MainWindow::on_validWordKeyBotton_clicked()
{
    if(ui->wordKeyLineEdit->text() != ""){
        if(ejecutar.runRecursion(ui->wordKeyLineEdit->text().toStdString(), "")){
            ui->aceptationLabel->setText("ACEPTADO");
            ui->aceptationLabel->setStyleSheet("background: green");
        }else{
            ui->aceptationLabel->setText("NO ACEPTADO");
            ui->aceptationLabel->setStyleSheet("background: red");
        }
    }

}
