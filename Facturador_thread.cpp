#include "Facturador_thread.h"

void Facturador_thread::run(){
    this->running = true;
    while(true){
        if(!this->running){
            std::this_thread::sleep_for(1000ms);
        } else {
            //this->Facturador_interfaz->clear();
            if(this->Pedido != NULL){
                this->ocupado = true;
                /*ESTO DEBERIA DE IMPRIMIR ALGO DE LA FACTURA NOSE LOL
                 *this->Facturador_interfaz->setText(QString::fromStdString(Pedido->to_string())+"\nProducto\tCantidad\n"+QString::fromStdString(Pedido->Productos->to_string_nombres()));
                 *
                */
                this->Facturador_interfaz->setText(QString::fromStdString(Pedido->to_string()));

            }
            this->Pedido = NULL;
            this->ocupado = false;
        }
        std::this_thread::sleep_for(1000ms);
    }
}
