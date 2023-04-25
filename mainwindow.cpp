#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>

MainWindow::~MainWindow()
{
    delete ui;
}

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

    ColaPedidos *Pedidos_alistos = new ColaPedidos();

    fabricas_thread = new Fabricas(Almacen, findChild<QLabel*>("labelFabA"), findChild<QLabel*>("labelFabB"), findChild<QLabel*>("labelFabC"), findChild<QLabel*>("labelFabCom"));
    balanceador_thread = new BalanceadorThread(Almacen, Pedidos,Pedidos_alistos, findChild<QLabel*>("labelBalanceador"), fabricas_thread);
    balanceador_thread->start();

    QListWidget *Alistos_n_pantalla = findChild<QListWidget*>("listWidget_alistos");
    ColaPedidos *Pedidos_listos = new ColaPedidos();
    findChild<QTextBrowser*>("textBrowser_alistador1")->setText("HOLA");

    alistadores_thread = new Alistadores(Almacen,Pedidos_listos,findChild<QTextBrowser*>("textBrowser_alistador1"),findChild<QTextBrowser*>("textBrowser_alistador2"),findChild<QTextBrowser*>("textBrowser_alistador3"),findChild<QTextBrowser*>("textBrowser_alistador4"),findChild<QTextBrowser*>("textBrowser_alistador5"),findChild<QTextBrowser*>("textBrowser_alistador6"));
    alistos_thread = new Alistos_Thread(Alistos_n_pantalla,Pedidos_alistos,Almacen,alistadores_thread);//findChild<QTextBrowser*>("textBrowser_alistador1"),findChild<QTextBrowser*>("textBrowser_alistador2"),findChild<QTextBrowser*>("textBrowser_alistador3"),findChild<QTextBrowser*>("textBrowser_alistador4"),findChild<QTextBrowser*>("textBrowser_alistador5"),findChild<QTextBrowser*>("textBrowser_alistador6"));
    alistos_thread->start();

    QListWidget *Alistados_n_pantalla = findChild<QListWidget*>("listWidget_alistados");


    alistados_thread = new Alistados_Thread(Alistados_n_pantalla,Pedidos_listos);
    alistados_thread->start();

   // QTabWidget *Alistadores_n_pantalla = findChild<QTabWidget*>("tabWidget_alistadores");
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

void MainWindow::on_pushButton_deteneralistos_clicked(bool checked){
    if(alistos_thread->running){
        this->ui->pushButton_deteneralistos->setText(QString::fromStdString("Reanudar"));
        alistos_thread->pausar();
    }
    else{
        this->ui->pushButton_deteneralistos->setText(QString::fromStdString("Detener"));
        alistos_thread->reanudar();
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


