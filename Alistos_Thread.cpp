#include "Alistos_Thread.h"


int Alistos_Thread::buscar_alistador_libre(){
    int i;
    for(i = 0; i<6;i++){
        if(!alistadores->arrayAlistador[i]->ocupado && alistadores->arrayAlistador[i]->running){
            return i;
        }
    }
    return -1;
}

void Alistos_Thread::run(){
    this->running = true;
    while(true){
        this->alistos_interfaz->clear();
        if(!this->Pedidos->vacia()){
            NodoPedido *tmp = this->Pedidos->frente;
            while(tmp){
                this->alistos_interfaz->addItem(QString::fromStdString(tmp->pedido->to_string()));
                tmp = tmp->sig;
            }
            std::this_thread::sleep_for(1000ms);
            if(!this->running){
                std::this_thread::sleep_for(1000ms);
            } else {
                //std::cout<<"Soy la cola de alistos "<<std::endl;
                int posicion_alistador = buscar_alistador_libre();
                //std::cout<<"Antes del if "<<std::endl;
                if(!(posicion_alistador==-1)){
                    this->alistadores->arrayAlistador[posicion_alistador]->Pedidos = this->Pedidos->desencolar()->pedido;
                }
            }
        }
        std::this_thread::sleep_for(1000ms);
    }
}


