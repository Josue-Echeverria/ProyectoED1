#ifndef ALISTADORTHREAD_H
#define ALISTADORTHREAD_H
#include "Pedidos_Thread.h"
#include <QLabel>

class Alistador_Thread : public QThread{
public:
    Alistador_Thread(){
        this->Pedidos = NULL;

    }
    Alistador_Thread(QLabel* a,Almacen* c,ColaPedidos* d){
        this->Almacen = c;
        this->alistadores_interfaz = a;
        //this->alistadores_interfaz->setText("HOLAAAA");
        this->Pedidos = NULL;
        this->Pedidos_listos = d;
    }
    void run();

//private:
    void pausar(){running = false;}
    void reanudar(){running = true;}
    QLabel* alistadores_interfaz;
    bool running;
    bool ocupado;
    Pedidos *Pedidos;
    ColaPedidos *Pedidos_listos;
    Almacen *Almacen;
};

struct Alistadores{
    Alistador_Thread *arrayAlistador[6];

    Alistadores(Almacen* c,ColaPedidos* d,QLabel *e,QLabel *f,QLabel *g,QLabel *h,QLabel *i,QLabel *j){
        arrayAlistador[0] = new Alistador_Thread(e,c,d);
        arrayAlistador[1] = new Alistador_Thread(f,c,d);
        arrayAlistador[2] = new Alistador_Thread(g,c,d);
        arrayAlistador[3] = new Alistador_Thread(h,c,d);
        arrayAlistador[4] = new Alistador_Thread(i,c,d);
        arrayAlistador[5] = new Alistador_Thread(j,c,d);
        arrayAlistador[0]->start();
        arrayAlistador[1]->start();
        arrayAlistador[2]->start();
        arrayAlistador[3]->start();
        arrayAlistador[4]->start();
        arrayAlistador[5]->start();
    }
};

#endif
