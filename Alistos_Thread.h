#ifndef ALISTOSTHREAD_H
#define ALISTOSTHREAD_H
#include "Alistador_Thread.h"

class Alistos_Thread : public QThread{
public:
    Alistos_Thread(){};
    Alistos_Thread(QListWidget* a,ColaPedidos* b,Almacen* c, Alistadores *d){
        this->Almacen = c;
        this->alistos_interfaz = a;
        this->Pedidos = b;
        this->alistadores = d;
        running = true;
        //alistadores[1]->running = false;

    }

    void run();
    void pausar(){this->running = false;}
    void reanudar(){this->running = true;}

    Alistadores* alistadores;
    QListWidget* alistos_interfaz;
    bool running;
    ColaPedidos *Pedidos;
    Almacen *Almacen;
    void buscar_en_almacen();
    void alistar_pedidos();
    int buscar_alistador_libre();
};
#endif
