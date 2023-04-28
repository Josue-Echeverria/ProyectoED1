#ifndef FACTURAR_THREAD_H
#define FACTURAR_THREAD_H

#include "Alistados_thread.h"

class Facturador_thread : public QThread
{
public:
    Facturador_thread(QLabel *c){
        this->Facturador_interfaz = c;
        this->ocupado = false;
    }
    void run();
//Variables
    bool ocupado;
    QLabel *Facturador_interfaz;
    Pedidos *Pedido = NULL;
    void pausar(){running = false;}
    void reanudar(){running = true;}
    bool running;


    };

#endif // FACTURADOR_THREAD_H
