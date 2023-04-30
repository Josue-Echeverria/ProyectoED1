#ifndef COLAFABRICACIONES_H
#define COLAFABRICACIONES_H
#include "Pedidos.h"


struct nodo{
    int valor;
    nodo *siguiente;
    nodo(){
        siguiente = NULL;
    }
    nodo(int val){
        this->valor = val;
        this->siguiente = NULL;
    }
};

struct lista_enteros{
    nodo *primero ;
    lista_enteros(){
        primero = NULL;
    }
    bool vacia(){
        return primero == NULL;
    }
    void insertar(int val){
        if (vacia()){
            primero = new nodo(val);
        } else {
            nodo* actual = primero;
            nodo* nuevo = new nodo (val);
            while (actual->siguiente != NULL)
                actual = actual->siguiente;
            actual->siguiente = nuevo;
        }
    }
    bool existe(int val){
        nodo *tmp = primero;
        while(tmp){
            if(tmp->valor == val)
                return true;
            tmp = tmp->siguiente;
        }
        return false;
    }
};




struct NodoPedido{
    Pedidos *pedido;
    NodoPedido* sig;
    // constructores
    NodoPedido(Pedidos * p)
    {
        pedido = p;
        sig = NULL;
    }
};
struct ColaPedidos{
    NodoPedido *frente;

    ColaPedidos()
    {
        frente = NULL;
    }

    // encabezados de funcion
    void encolarPedido (Pedidos *p);
    void encolarPedido_x_prioridad (Pedidos *p);
    NodoPedido* desencolar (void);
    NodoPedido* verFrente(void);
    bool vacia(void);
    void imprimir(void);
    Pedidos *buscar_pedido(int);
};
void leer_pedidos(QDir,ColaPedidos*,ListaClientes*,Almacen*,lista_enteros*);



#endif
