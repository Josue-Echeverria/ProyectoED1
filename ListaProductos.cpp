#include "ListaProductos.h"

bool ListaProductos::vacia(){
    return primero == NULL;
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

