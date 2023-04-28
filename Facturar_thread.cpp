#include "Facturar_thread.h"

void Facturar_Thread::run(){
    this->running = true;
    while(true){
        this->pedidos_interfaz->clear();
        if(Pedidos->frente){
            NodoPedido *tmp = Pedidos->frente;
            while(tmp){
                this->pedidos_interfaz->addItem(QString::fromStdString(tmp->pedido->to_string()));
                tmp = tmp->sig;
            }
            std::this_thread::sleep_for(1000ms);
            if(!this->running){
                std::this_thread::sleep_for(1000ms);
            } else {

                if(!this->facturador->ocupado && this->facturador->running)
                    this->facturador->Pedido = this->Pedidos->desencolar()->pedido;
            }
        }
        std::this_thread::sleep_for(1000ms);
    }
}
