#include "Pedidos_Thread.h"


void Pedidos_Thread::run(){
    this->running = true;
    while(true){
        std::cout<<"i am reading hir"<<std::endl;
        leer_pedidos(this->dir,this->Pedidos,this->Clientes,this->Almacen);
        NodoPedido *tmp = Pedidos->frente;
        this->pedidos_interfaz->clear();
        while(tmp){
            this->pedidos_interfaz->addItem(QString::fromStdString(tmp->pedido->to_string()));
            tmp = tmp->sig;
        }
        std::this_thread::sleep_for(5000ms);
    }
}
