#include "Empacador.h"

void Empacador_thread::run(){
    this->running = true;
    while(true){
        if(!this->running){
            std::this_thread::sleep_for(1000ms);
        } else {
            this->empacador_interfaz->clear();
            if(this->Pedido != NULL){
                this->ocupado = true;
                this->empacador_interfaz->setText(QString::fromStdString(Pedido->to_string())+"\nProducto\tCantidad\n"+QString::fromStdString(Pedido->Productos->to_string_nombres()));
                this->Facturar->encolarPedido(this->Pedido);
            }
            this->Pedido = NULL;
            this->ocupado = false;
        }
        std::this_thread::sleep_for(1000ms);
    }
}
