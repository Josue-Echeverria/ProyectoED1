
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
    BalanceadorThread(Almacen *almacen, ColaPedidos* cola,ColaPedidos* colaa, QLabel* label_Balanceador, Fabricas * fab)
    {
        running = true;
        this->almacen = almacen;
        this->cola = cola;
        this->cola_alistos = colaa;
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
                    if(verificarAlisto(cola->verFrente()->pedido) != 0){
                        QThread::sleep(verificarAlisto(cola->verFrente()->pedido));
                    }
                    QThread::sleep(3);
                    label->clear();
                    this->cola_alistos->encolarPedido(cola->desencolar()->pedido);
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
        std::fstream file("C:/Users/Asus/Repositories/ProyectoED1/Productos.txt", std::ios::in | std::ios::out); // open file for reading and writing
        while(aux){
            Producto * enAlmacen = almacen ->existeProducto(aux->producto->codigo_producto);
            if(almacen->existeCant(enAlmacen, aux->producto->cantidad) == false){
                int cant = aux->producto->cantidad - almacen->cantEnAlmacen(enAlmacen);
                fabricas ->fabricar(enAlmacen->codigo_producto, cant);
                enAlmacen->cantidad = 0;
                duracion += cant * aux->producto->duracion_d_fabricacion;

            }else{
                std::ifstream file("C:/Users/Asus/Repositories/ProyectoED1/Productos.txt"); // open file for reading and writing
                std::string a = restar_cantidad_archivo(&file,aux->producto->cantidad,aux->producto->codigo_producto);
                file.close();
                std::ofstream filee("C:/Users/Asus/Repositories/ProyectoED1/Productos.txt"); // open file for reading and writing
                escribir(&filee,a);
                filee.close();
                enAlmacen->cantidad -= aux->producto->cantidad;
            }
            aux = aux->sig;
        }
        file.close();
        return duracion;
    }
private:
    bool running;
    ColaPedidos* cola;
    ColaPedidos* cola_alistos;
    QLabel* label;
    Almacen *almacen;
    Fabricas *fabricas;
};

#endif // BALANCEADORTHREAD_H
