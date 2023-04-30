#include "Alistador_Thread.h"

void Alistador_Thread::run(){
    this->running = true;
    while(true){
        if(!this->running){
            std::this_thread::sleep_for(1000ms);
        } else {
            if(this->Pedidos != NULL){
                this->ocupado = true;
                NodoProducto *tmp = this->Pedidos->Productos->primero;
                int tiempo = 0;
                int resultado = 0;
                while(tmp){
                    std::string letra = tmp->producto->ubicacion;
                    //std::cout<<tmp->producto->ubicacion<<std::endl;
                    resultado = 2*((letra[0]-65) + ((((letra[1]-48)*10) + (letra[2]-48))-1));
                    tiempo += resultado;
                    this->Pedidos->textoFactura += tmp->producto->codigo_producto+"\t"+"Ubicacion:\t" + letra + " ("+std::to_string(resultado)+"segundos)"+"\n";
                    tmp = tmp->sig;
                }
                while(tiempo >= 0){
                    if(!this->running){
                        std::this_thread::sleep_for(1000ms);
                    } else {
                        this->alistadores_interfaz->setText("Alistando el pedido: \n"+QString::fromStdString(Pedidos->to_string())+"\nProductos\tUbicacion\n"+QString::fromStdString(Pedidos->Productos->to_string_pedido())+"Me queda " +QString::number(tiempo)+ "s para terminar.");
                        tiempo--;
                        std::this_thread::sleep_for(1000ms);
                    }
                }

                this->alistadores_interfaz->setText("(Desocupado)");
                this->Pedidos_listos->encolarPedido(Pedidos);
            }
            this->ocupado = false;
            this->Pedidos = NULL;
        }
        std::this_thread::sleep_for(1000ms);
    }
}
