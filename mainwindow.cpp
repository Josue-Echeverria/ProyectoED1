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
    //findChild<QTextBrowser*>("textBrowser")->setText("HOLA");
/*
    Alistador_Thread *arrayAlistador[6];
    arrayAlistador[0] = new Alistador_Thread(findChild<QTextBrowser*>("textBrowser"),Almacen,Pedidos_listos);
    arrayAlistador[1] = new Alistador_Thread(findChild<QTextBrowser*>("textBrowser_alistador2"),Almacen,Pedidos_listos);
    arrayAlistador[2] = new Alistador_Thread(findChild<QTextBrowser*>("textBrowser_alistador3"),Almacen,Pedidos_listos);
    arrayAlistador[3] = new Alistador_Thread(findChild<QTextBrowser*>("textBrowser_alistador4"),Almacen,Pedidos_listos);
    arrayAlistador[4] = new Alistador_Thread(findChild<QTextBrowser*>("textBrowser_alistador5"),Almacen,Pedidos_listos);
    arrayAlistador[5] = new Alistador_Thread(findChild<QTextBrowser*>("textBrowser_alistador6"),Almacen,Pedidos_listos);
    arrayAlistador[0]->start();
    arrayAlistador[1]->start();
    arrayAlistador[2]->start();
    arrayAlistador[3]->start();
    arrayAlistador[4]->start();
    arrayAlistador[5]->start();
*/

    alistadores_thread = new Alistadores(Almacen,Pedidos_listos,findChild<QLabel*>("label_alistador1"),findChild<QLabel*>("label_alistador2"),findChild<QLabel*>("label_alistador3"),findChild<QLabel*>("label_alistador4"),findChild<QLabel*>("label_alistador5"),findChild<QLabel*>("label_alistador6"));
    alistos_thread = new Alistos_Thread(Alistos_n_pantalla,Pedidos_alistos,Almacen,alistadores_thread);
    alistos_thread->start();

    QListWidget *Alistados_n_pantalla = findChild<QListWidget*>("listWidget_alistados");
    ColaPedidos *Pedidos_facturar = new ColaPedidos();
    empacador = new Empacador_thread(Pedidos_facturar,findChild<QLabel*>("label_empacador"));
    alistados_thread = new Alistados_Thread(Alistados_n_pantalla,Pedidos_listos,empacador);
    alistados_thread->start();
    facturador = new Facturador_thread(findChild<QLabel*>("label_facturador"));
    facturar_thread = new Facturar_Thread(findChild<QListWidget*>("listWidget_facturar"),Pedidos_facturar,facturador);
    facturar_thread->start();
/**/
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
/*
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
*/


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



void MainWindow::on_pushButton_deteneralistos_clicked()
{

    if(alistos_thread->running){
        alistos_thread->pausar();
        ui->pushButton_deteneralistos->setText("Reanudar");
    } else {
        alistos_thread->reanudar();
        ui->pushButton_deteneralistos->setText("Detener");
    }
}


void MainWindow::on_pushButton_deteneralistados_clicked()
{
    {
        if(alistados_thread->running){
            alistados_thread->pausar();
            ui->pushButton_deteneralistados->setText("Reanudar");
        } else {
            alistados_thread->reanudar();
            ui->pushButton_deteneralistados->setText("Detener");
        }
    }

}


void MainWindow::on_pushButton_deteneralistador_clicked()
{
    int index = ui->groupBox_alistadores->findChild<QTabWidget*>("tabWidget_alistadores")->currentIndex();
    switch(index){
    case 0:
        alistos_thread->alistadores->arrayAlistador[0]->pausar();
        break;
    case 1:
        alistos_thread->alistadores->arrayAlistador[1]->pausar();
        break;
    case 2:
        alistos_thread->alistadores->arrayAlistador[2]->pausar();
        break;
    case 3:
        alistos_thread->alistadores->arrayAlistador[3]->pausar();
        break;
    case 4:
        alistos_thread->alistadores->arrayAlistador[4]->pausar();
        break;
    case 5:
        alistos_thread->alistadores->arrayAlistador[5]->pausar();
        break;
    }

}


void MainWindow::on_pushButton_deteneralistador_2_clicked()
{
    int index = ui->groupBox_alistadores->findChild<QTabWidget*>("tabWidget_alistadores")->currentIndex();
    switch(index){
    case 0:
        alistos_thread->alistadores->arrayAlistador[0]->reanudar();
        break;
    case 1:
        alistos_thread->alistadores->arrayAlistador[1]->reanudar();
        break;
    case 2:
        alistos_thread->alistadores->arrayAlistador[2]->reanudar();
        break;
    case 3:
        alistos_thread->alistadores->arrayAlistador[3]->reanudar();
        break;
    case 4:
        alistos_thread->alistadores->arrayAlistador[4]->reanudar();
        break;
    case 5:
        alistos_thread->alistadores->arrayAlistador[5]->reanudar();
        break;
    }
}


void MainWindow::on_pushButton_detenerempacador_clicked()
{
    if(empacador->running){
        empacador->pausar();
        ui->pushButton_detenerempacador->setText("Reanudar");
    } else {
        empacador->reanudar();
        ui->pushButton_detenerempacador->setText("Detener");
    }
}


void MainWindow::on_pushButton_detenerfacturador_clicked()
{
    if(facturador->running){
        facturador->pausar();
        ui->pushButton_detenerfacturador->setText("Reanudar");
    } else {
        facturador->reanudar();
        ui->pushButton_detenerfacturador->setText("Detener");
    }
}

