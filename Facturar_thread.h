#ifndef FACTURADOR_THREAD_H
#define FACTURADOR_THREAD_H

#include "Facturador_thread.h"

class Facturar_Thread : public QThread{
public:
    Facturar_Thread(){};
    Facturar_Thread(QListWidget* a,ColaPedidos* b,Facturador_thread *c){
        this->pedidos_interfaz = a;
        this->Pedidos = b;
        this->facturador = c;
        this->facturador->start();
    }

    void run();

//private:
    QListWidget *pedidos_interfaz;
    void pausar(){running = false;}
    void reanudar(){running = true;}
    bool running;
    Facturador_thread *facturador;
    ColaPedidos *Pedidos;
    //Alistadores *alistadores;
};

#endif // FACTURADOR_THREAD_H
