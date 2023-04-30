#include "Pedidos_Thread.h"


void Pedidos_Thread::run(){
    this->running = true;
    while(true){
        leer_pedidos(this->dir,this->Pedidos,this->Clientes,this->Almacen,this->pedidos_hechos);
        NodoPedido *tmp = Pedidos->frente;
        this->pedidos_interfaz->clear();
        while(tmp){
            this->pedidos_interfaz->addItem(QString::fromStdString(tmp->pedido->to_string()));
            tmp = tmp->sig;
        }
        std::this_thread::sleep_for(2000ms);
    }
}
