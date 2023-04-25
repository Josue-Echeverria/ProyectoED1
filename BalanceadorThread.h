
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
    BalanceadorThread(Almacen *almacen, ColaPedidos* cola, QLabel* label_Balanceador, Fabricas * fab)
    {
        running = true;
        this->cola = cola;
        this->label = label_Balanceador;
        this->fabricas = fab;
    }

    void run()
    {
        while (true)
        {
            while(running){
                if(!cola->vacia()){
                    QString qstr = QString::fromStdString(cola->verFrente()->pedido->to_string());
                    label->setText(qstr);
                    almacen->imprimirMa();
                    std::cout<<"llego12"<<std::endl;
                    if(verificarAlisto(cola->verFrente()->pedido) != 0){
                        std::cout<<"llego1"<<std::endl;
                        QThread::sleep(verificarAlisto(cola->verFrente()->pedido));
                    }
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
    int verificarAlisto(Pedidos *ped){
        NodoProducto *aux = ped->Productos->primero;
        int duracion = 0;
        while(aux){
            Producto * enAlmacen = almacen ->existeProducto(aux->producto->codigo_producto);
            enAlmacen->to_string_in_almacen();
            if(almacen->existeCant(enAlmacen, aux->producto->cantidad) == false){
                std::cout<<"llego3"<<std::endl;
                int cant = aux->producto->cantidad - almacen->cantEnAlmacen(enAlmacen);
                fabricas ->fabricar(enAlmacen->codigo_producto, cant);
                enAlmacen->cantidad = 0;
                duracion += cant * aux->producto->duracion_d_fabricacion;
            }else{
                enAlmacen->cantidad -= aux->producto->cantidad;
            }
            aux = aux->sig;
        }
        return duracion;
    }
private:
    bool running;
    ColaPedidos* cola;
    QLabel* label;
    Almacen *almacen;
    Fabricas *fabricas;
};

#endif // BALANCEADORTHREAD_H
