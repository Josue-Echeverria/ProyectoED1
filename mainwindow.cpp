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

    std::ifstream archivoProductos("C:/Users/Asus/Repositories/ProyectoED1/Productos.txt");
    Almacen *Almacen = leer_productos(&archivoProductos);
    archivoProductos.close();

    std::ifstream archivoClientes("C:/Users/Asus/Repositories/ProyectoED1/Clientes.txt");
    ListaClientes *Clientes = leerClientes(&archivoClientes);
    archivoClientes.close();

    ColaPedidos *Pedidos = new ColaPedidos();

    QListWidget *Pedidos_n_pantalla = findChild<QListWidget*>("listWidget_Pedidos");
    pedidos_thread = new Pedidos_Thread(Pedidos_n_pantalla,Pedidos,Almacen,Clientes);
    pedidos_thread->start();
    fabricas_thread = new Fabricas(Almacen, findChild<QLabel*>("labelFabA"), findChild<QLabel*>("labelFabB"), findChild<QLabel*>("labelFabC"), findChild<QLabel*>("labelFabCom"));
    balanceador_thread = new BalanceadorThread(Almacen, Pedidos, findChild<QLabel*>("labelBalanceador"), fabricas_thread);
    balanceador_thread->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_detenerfabrica_a_clicked()
{
    if(fabricas_thread->arrayFabrica[0]->getRunning()){
        fabricas_thread->detenerFabrica(0);
        ui->pushButton_detenerfabrica_a->setText("Reanudar");
    }
    else{
        fabricas_thread->reanudarFabrica(0);
        ui->pushButton_detenerfabrica_a->setText("Detener");
    }
}


void MainWindow::on_pushButton_detenerfabrica_b_clicked()
{
    if(fabricas_thread->arrayFabrica[0]->getRunning()){
        fabricas_thread->detenerFabrica(1);
        ui->pushButton_detenerfabrica_a->setText("Reanudar");
    }
    else{
        fabricas_thread->reanudarFabrica(1);
        ui->pushButton_detenerfabrica_a->setText("Detener");
    }
}


void MainWindow::on_pushButton_detenerfabrica_c_clicked()
{
    if(fabricas_thread->arrayFabrica[0]->getRunning()){
        fabricas_thread->detenerFabrica(2);
        ui->pushButton_detenerfabrica_a->setText("Reanudar");
    }
    else{
        fabricas_thread->reanudarFabrica(2);
        ui->pushButton_detenerfabrica_a->setText("Detener");
    }
}


void MainWindow::on_pushButton_detenerfabrica_comodin_clicked()
{
    if(fabricas_thread->arrayFabrica[0]->getRunning()){
        fabricas_thread->detenerFabrica(3);
        ui->pushButton_detenerfabrica_a->setText("Reanudar");
    }
    else{
        fabricas_thread->reanudarFabrica(3);
        ui->pushButton_detenerfabrica_a->setText("Detener");
    }
}


