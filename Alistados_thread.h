#ifndef ALISTADOSTHREAD_H
#define ALISTADOSTHREAD_H
#include "Empacador.h"

class Alistados_Thread : public QThread{
public:
    Alistados_Thread(){};
    Alistados_Thread(QListWidget* a,ColaPedidos* b,Empacador_thread *c){
        this->pedidos_interfaz = a;
        this->Pedidos = b;
        this->empacador = c;
        this->empacador->start();
    }

    void run();

//private:
    QListWidget *pedidos_interfaz;
    void pausar(){running = false;}
    void reanudar(){running = true;}
    bool running;
    Empacador_thread *empacador;
    ColaPedidos *Pedidos;
    //Alistadores *alistadores;
};

#endif // ALISTADOS_THREAD_H
