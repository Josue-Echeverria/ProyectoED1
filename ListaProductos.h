#ifndef LISTAPRODUCTOS_H
#define LISTAPRODUCTOS_H
#include "Producto.h"

struct NodoProducto{
    Producto *producto;
    NodoProducto* sig;
    // constructores
    NodoProducto(Producto * p)
    {
        producto = p;
        sig = NULL;
    }
};
struct ListaProductos{
    NodoProducto *primero;

    ListaProductos()
    {
        primero = NULL;
    }

    // encabezados de funcion
    void insertar (Producto *p);
    bool vacia(void);
    void imprimir(void);

};

#endif
