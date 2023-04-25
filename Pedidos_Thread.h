#ifndef PEDIDOSTHREAD_H
#define PEDIDOSTHREAD_H
#include "ColaFabricaciones.h"


class Pedidos_Thread : public QThread{
public:
    Pedidos_Thread(){};
    Pedidos_Thread(QListWidget* a,ColaPedidos* b,Almacen* c,ListaClientes* d){
        this->Almacen = c;
        this->Clientes = d;
        this->pedidos_interfaz = a;
        this->Pedidos = b;
        this->dir = QDir("C:/Users/Asus/Repositories/ProyectoED1/Pedidos/");
    }

    void run();

//private:
    QListWidget *pedidos_interfaz;
    bool running;
    ColaPedidos *Pedidos;
    Almacen *Almacen;
    QDir dir;
    ListaClientes *Clientes;
};
#endif
