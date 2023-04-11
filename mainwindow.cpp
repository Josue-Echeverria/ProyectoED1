#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    string s = "";
    QTextBrowser *console = findChild<QTextBrowser*>("textBrowser");
    int numero_d_clientes = 0;
    //
    std::cout<<"HOLA"<<std::endl;
    leer_productos();
Cliente *a = leerClientes(numero_d_clientes);
    leer_pedidos(a,numero_d_clientes);
   for (int i = 0;i<numero_d_clientes; i++){
        s += a[i].to_string();
    }

    console->setText(QString::fromStdString(s));

}

MainWindow::~MainWindow()
{
    delete ui;
}

