
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
        this->colaHold = new ColaPedidos();
    }

    void run()
    {
        while (true)
        {
            while(running){
                QThread::sleep(1);
                std::cout<<cola->vacia()<<" colita"<<std::endl;
                if(!cola->vacia()){
                    QString qstr = QString::fromStdString(cola->verFrente()->pedido->to_string());
                    label->setText(qstr);
                    cola->verFrente()->pedido->textoFactura += "Balanceador:\t" + cola->verFrente()->pedido->getTime() + "\n";
                    QThread::sleep(1);
                    if(running){
                        if(verificarAlisto(cola->verFrente()->pedido) != 0){
                            colaHold->encolarPedido(cola->desencolar()->pedido);
                        }else{
                            label->setText("Analizando Pedidos en cola");
                            cola->verFrente()->pedido->textoFactura += "A alisto:\t" + cola->verFrente()->pedido->getTime() + "\n";
                            this->cola_alistos->encolarPedido(cola->desencolar()->pedido);
                        }
                    }
                }

                if(!colaHold->vacia()){
                    QString qstr = QString::fromStdString(colaHold->verFrente()->pedido->to_string());
                    label->setText(qstr);
                    QThread::sleep(1);
                    if(running){
                        if(!verificarHold(colaHold->verFrente()->pedido)){
                            cola->verFrente()->pedido->textoFactura += "A alisto:\t" + cola->verFrente()->pedido->getTime() + "\n";
                            this->cola_alistos->encolarPedido(colaHold->desencolar()->pedido);
                        }
                    }
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
    bool getRunning(){
        return running;
    }
    int verificarAlisto(Pedidos *ped){
        NodoProducto *aux = ped->Productos->primero;
        int duracion = 0;
        std::fstream file("C:/Users/hdani/OneDrive/Escritorio/Tec semestre 1/datos/proyecto1/mio/Productos.txt", std::ios::in | std::ios::out); // open file for reading and writing
        while(aux){
            Producto * enAlmacen = almacen ->existeProducto(aux->producto->codigo_producto);
            if(!almacen->existeCant(enAlmacen, aux->producto->cantidad)){
                int cant = aux->producto->cantidad - almacen->cantEnAlmacen(enAlmacen);
                enAlmacen->cantidad = 0;
                fabricas ->fabricar(enAlmacen->codigo_producto, cant);
                duracion += cant * aux->producto->duracion_d_fabricacion;

            }else{
                std::ifstream file("C:/Users/hdani/OneDrive/Escritorio/Tec semestre 1/datos/proyecto1/mio/Productos.txt"); // open file for reading and writing
                std::string a = restar_cantidad_archivo(&file,aux->producto->cantidad,aux->producto->codigo_producto);
                file.close();
                std::ofstream filee("C:/Users/hdani/OneDrive/Escritorio/Tec semestre 1/datos/proyecto1/mio/Productos.txt"); // open file for reading and writing
                escribir(&filee,a);
                filee.close();
                enAlmacen->cantidad -= aux->producto->cantidad;
            }
            aux = aux->sig;
        }
        file.close();
        return duracion;
    }
    bool verificarHold(Pedidos *ped){
        NodoProducto *aux = ped->Productos->primero;
        while(aux){
            if(fabricas->existeProd(aux->producto->codigo_producto)){
                return true;
            }
            aux = aux->sig;
        }
        return false;
    }

private:
    bool running;
    ColaPedidos* cola;
    ColaPedidos* cola_alistos;
    QLabel* label;
    Almacen *almacen;
    Fabricas *fabricas;
    ColaPedidos* colaHold;
};

#endif // BALANCEADORTHREAD_H
