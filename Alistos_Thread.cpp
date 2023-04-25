#include "Alistos_Thread.h"


int Alistos_Thread::buscar_alistador_libre(){
    int i;
    for(i = 0; i<6;i++){
        if(!alistadores->arrayAlistador[i]->ocupado){
            return i;
        }
    }
    return -1;
}

void Alistos_Thread::run(){
    this->running = true;
    while(true){
        if(!this->running){
            //std::cout<<"Soy la cola de alistos y me apagaron"<<std::endl;
            std::this_thread::sleep_for(1000ms);
        } else {
            //std::cout<<"Soy la cola de alistos "<<std::endl;
            if(!this->Pedidos->vacia()){
                NodoPedido *tmp = this->Pedidos->frente;
                while(tmp){
                    this->alistos_interfaz->addItem(QString::fromStdString(tmp->pedido->to_string()));
                    tmp = tmp->sig;
                }
                int posicion_alistador = buscar_alistador_libre();
                //std::cout<<"Antes del if "<<std::endl;
                if(!(posicion_alistador==-1)){
                    //std::cout<<"Despues del if "<<std::endl;
                    this->alistadores->arrayAlistador[posicion_alistador]->Pedidos = this->Pedidos->desencolar()->pedido;
                }
            }
            this->alistos_interfaz->clear();

            std::this_thread::sleep_for(2000ms);
        }
    }
}


