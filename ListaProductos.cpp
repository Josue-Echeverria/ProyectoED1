#include "ListaProductos.h"

bool ListaProductos::vacia(){
    return primero == NULL;
}

std::string ListaProductos::to_string_pedido(){
    NodoProducto *tmp = primero;
    std::string str = "";
    while(tmp){
        str += tmp->producto->to_string_in_pedido()+"\n";
        tmp = tmp->sig;
    }
    return str;
}

std::string ListaProductos::to_string_nombres(){
    NodoProducto *tmp = primero;
    std::string str = "";
    while(tmp){
        str += tmp->producto->codigo_producto+"\t"+std::to_string(tmp->producto->cantidad)+"\n";
        tmp = tmp->sig;
    }
    return str;
}


void ListaProductos::insertar(Producto *p){
    if (vacia())
        primero = new NodoProducto (p);
    else
    {
        NodoProducto* actual = primero;
        NodoProducto* nuevo = new NodoProducto (p);
        while (actual->sig != NULL)
            actual = actual->sig;
        actual->sig = nuevo;
    }
}

