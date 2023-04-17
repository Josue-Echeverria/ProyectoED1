#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*
     * TO DO:
     * si alguno de los archivos tiene un formato incorrecto no deberia de salir la interfaz(deberua de salir un mesaje de error
     *
     */

 //  console->setText(QString::fromStdString(s));

}

MainWindow::~MainWindow()
{
    delete ui;
}



