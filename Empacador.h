#ifndef EMPACADOR_H
#define EMPACADOR_H
#include "Alistos_Thread.h"

class Empacador_thread : public QThread
{
public:
    Empacador_thread(ColaPedidos *b,QLabel *c){
        this->Facturar = b;
        this->empacador_interfaz = c;
        this->ocupado = false;
    }
    void run();
//Variables
    bool ocupado;
    QLabel *empacador_interfaz;
    Pedidos *Pedido = NULL;
    ColaPedidos *Facturar;
    void pausar(){running = false;}
    void reanudar(){running = true;}
    bool running;


    };
#endif // EMPACADOR_H
