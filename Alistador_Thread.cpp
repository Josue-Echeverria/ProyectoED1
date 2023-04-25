#include "Alistador_Thread.h"

void Alistador_Thread::run(){
    this->running = true;
    while(true){
        if(!this->running){
            std::cout<<"Soy un alistador y me apagaron";
            std::this_thread::sleep_for(2000ms);
        } else {
            //this->alistadores_interfaz->setText("UWU");
            if(this->Pedidos != NULL){
                this->ocupado = true;
                //std::cout<<"AAAAAAAAAAA"<<std::endl;
                //std::cout<<"DDDDDDDDDDD"<<std::endl;
                NodoProducto *tmp = this->Pedidos->Productos->primero;
                int tiempo = 0;
                while(tmp){
                    std::string letra = tmp->producto->ubicacion;
                    //std::cout<<tmp->producto->ubicacion<<std::endl;
                    tiempo += 2*((letra[0]-65) + ((((letra[1]-48)*10) + (letra[2]-48))-1));
                    tmp = tmp->sig;
                }
                std::cout<<"que picha voy a durar: "<<std::to_string(tiempo)<<std::endl;
                std::chrono::milliseconds dur(tiempo*1000);
                std::this_thread::sleep_for(dur);
                std::cout<<"ALFIN SALI XD"<<std::endl;
            }
            this->ocupado = false;
            this->Pedidos = NULL;
        }
        std::this_thread::sleep_for(2000ms);
    }
}
