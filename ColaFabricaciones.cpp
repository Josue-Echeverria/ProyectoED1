#include"ColaFabricaciones.h"

bool ColaPedidos::vacia (void)
{
    if (frente == NULL)
        return true;
    else
        return false;
}

void ColaPedidos::encolarPedido (Pedido * p){
    if (vacia())
        frente = new NodoPedido (p);
    else
    {
        NodoPedido* actual = frente;
        while (actual->sig != NULL)
            actual = actual->sig;
        NodoPedido* nuevo = new NodoPedido (p);
        actual->sig = nuevo;
    }
}

NodoPedido* ColaPedidos::desencolar(void)
{
    if (vacia())
    {
        return NULL;
    }
    else
    {
        NodoPedido* borrado = frente;
        frente = frente->sig;
        borrado->sig = NULL;
        return borrado;
    }
}

void ColaPedidos::imprimir(void)
{
    cout << "Frente" << endl;
    NodoPedido *tmp = frente;
    while (tmp != NULL)
    {
        cout << tmp->pedido->imprimir() << "-" << endl;  //hacer el imprimir
        tmp = tmp->sig;
    }
    cout << "Final" << endl;
}

NodoPedido* ColaPedidos::verFrente()
{
    return frente;
}



