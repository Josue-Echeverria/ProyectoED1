#include "Pedidos_Thread.h"


void Pedidos_Thread::run(){
    this->running = true;
    while(true){
        std::cout<<"i am reading hir"<<std::endl;
        leer_pedidos(this->Pedidos,this->Clientes,this->Almacen);
        NodoPedido *tmp = Pedidos->frente;
        while(tmp){
            this->pedidos_interfaz->addItem(QString::fromStdString(std::to_string(tmp->pedido->prioridad)));
            tmp = tmp->sig;
        }
        std::this_thread::sleep_for(5000ms);
    }
}
