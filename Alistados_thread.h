#ifndef ALISTADOSTHREAD_H
#define ALISTADOSTHREAD_H
#include "Alistos_Thread.h"

class Alistados_Thread : public QThread{
public:
    Alistados_Thread(){};
    Alistados_Thread(QListWidget* a,ColaPedidos* b){
        this->pedidos_interfaz = a;
        this->Pedidos = b;
    }

    void run();

//private:
    QListWidget *pedidos_interfaz;
    bool running;
    ColaPedidos *Pedidos;
    //Alistadores *alistadores;
};

#endif // ALISTADOS_THREAD_H
