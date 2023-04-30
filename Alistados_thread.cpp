#include "Alistados_thread.h"

void Alistados_Thread::run(){
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
                if(!this->empacador->ocupado && this->empacador->running)
                    this->Pedidos->frente->pedido->textoFactura += "Al empacador:\t"+this->Pedidos->frente->pedido->getTime() + "\n";

                    this->empacador->Pedido = this->Pedidos->desencolar()->pedido;
            }
        }
        std::this_thread::sleep_for(1000ms);
    }

}
