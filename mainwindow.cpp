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

    ejecutar.separatePartsOfRule(ui->lineEdit->text().toStdString());
    ui->listWidget->addItem(ui->lineEdit->text());
    ui->lineEdit->clear();

}

void MainWindow::on_pushButton_3_clicked()
{
    ui->listWidget->clear();
    ejecutar.deleteRecursionPerLeft(ui);
}
