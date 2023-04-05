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
    Cliente *a = leerClientes();

    for (int i = 0;i<16; i++){
        s += a[i].to_string();
    }
    console->setText(QString::fromStdString(s));

}

MainWindow::~MainWindow()
{
    delete ui;
}

