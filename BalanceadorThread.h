
#ifndef BALANCEADORTHREAD_H
#define BALANCEADORTHREAD_H
#include"Fabrica.h"
#include <QtCore>
#include <QDebug>
#include <QLabel>

#include "ColaFabricaciones.h"

class BalanceadorThread : public QThread
{
public:
    BalanceadorThread(Almacen *almacen, ColaPedidos* cola, QLabel* label_Balanceador)
    {
        running = false;
        this->cola = cola;
        this->label = label_Balanceador;
    }

    void run()
    {
        while (true)
        {
            while(running){
                if(!cola->vacia()){
                    QString qstr = QString::fromStdString(cola->verFrente()->pedido->to_string());
                    label->setText(qstr);

                    almacen->existeProducto(cola->verFrente()->cod)->cantidad += cola->verFrente()->cant / almacen->existeProducto(cola->verFrente()->cod)->duracion_d_fabricacion;
                    cola->desencolar();
                }
                QThread::sleep(1);
            }
            QThread::sleep(1);
        }
    }
    void pausar(){
        running = false;
    }
    void reanudar(){
        running = true;
    }
    bool verificarAlisto(Pedidos *ped){
        NodoProducto *aux = ped->Productos->primero;
        while(aux){

            aux = aux->sig;
        }
    }
private:
    bool running;
    ColaPedidos* cola;
    QLabel* label;
    Almacen *almacen;
    Fabricas *fabricas;
};

#endif // BALANCEADORTHREAD_H
