#ifndef PEDIDOSTHREAD_H
#define PEDIDOSTHREAD_H
#include "ColaFabricaciones.h"


class Pedidos_Thread : public QThread{
public:
    Pedidos_Thread(){};
    Pedidos_Thread(QListWidget* a,ColaPedidos* b,Almacen* c,ListaClientes* d,lista_enteros* e){
        this->Almacen = c;
        this->Clientes = d;
        this->pedidos_interfaz = a;
        this->Pedidos = b;
        this->dir = QDir("C:/Users/hdani/OneDrive/Escritorio/Tec semestre 1/datos/proyecto1/mio/Pedidos/");
        this->pedidos_hechos = e;
    }

    void run();

//private:
    lista_enteros *pedidos_hechos;
    QListWidget *pedidos_interfaz;
    bool running;
    ColaPedidos *Pedidos;
    Almacen *Almacen;
    QDir dir;
    ListaClientes *Clientes;
};
#endif
