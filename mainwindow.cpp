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



}

MainWindow::~MainWindow()
{
    delete ui;
}
