
#include "mainwindow.h"
#include <QApplication>

#include <QFile>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    ifstream archivoProductos("C:/Users/Asus/Repositories/ProyectoED1/Productos.txt");
    Almacen *Almacen = leer_productos(&archivoProductos);
    archivoProductos.close();

    ifstream archivoClientes("C:/Users/Asus/Repositories/ProyectoED1/Clientes.txt");
    ListaClientes *Clientes = leerClientes(&archivoClientes);
    archivoClientes.close();



    ColaPedidos *Pedidos = leer_pedidos(Clientes,Almacen);
    Pedidos->imprimir();

/*
    QListWidget *Pedidos_n_pantalla = findChild<QListWidget*>("listWidget_Pedidos");
    NodoPedido *tmp = Pedidos->frente;
    while(tmp){
        Pedidos_n_pantalla->addItem(QString::fromStdString(to_string(tmp->pedido->prioridad)));
        tmp = tmp->sig;
    }*/

    w.show();


    return a.exec();
}
