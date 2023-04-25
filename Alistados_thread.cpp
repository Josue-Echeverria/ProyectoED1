#include "Alistados_thread.h"

void Alistados_Thread::run(){
    this->running = true;
    while(true){
        NodoPedido *tmp = Pedidos->frente;
        this->pedidos_interfaz->clear();
        while(tmp){
            this->pedidos_interfaz->addItem(QString::fromStdString(tmp->pedido->to_string()));
            tmp = tmp->sig;
        }
        std::this_thread::sleep_for(2000ms);
    }
}
