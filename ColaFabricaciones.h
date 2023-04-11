#include <iostream>
#include <fstream>
#include <cstring>
#include <QDebug>
using namespace std;

struct NodoPedido{
    Pedido *pedido;
    NodoPedido* sig;
    // constructores
    Nodo(Pedido * p)
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
    void encolarPedido (Pedido *p);
    NodoPedido* desencolar (void);
    NodoPedido* verFrente(void);
    bool vacia(void);
    void imprimir(void);

};


