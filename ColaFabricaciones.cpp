#include"ColaFabricaciones.h"

bool ColaPedidos::vacia (void)
{
    return frente == NULL;
}

void ColaPedidos::encolarPedido (Pedidos * p){
    if (vacia())
        frente = new NodoPedido (p);
    else
    {
        NodoPedido* actual = frente;
        NodoPedido* nuevo = new NodoPedido (p);
        while (actual->sig != NULL)
            actual = actual->sig;
        actual->sig = nuevo;
    }
}
void ColaPedidos::encolarPedido_x_prioridad (Pedidos * p){
    if (vacia())
        frente = new NodoPedido (p);
    else
    {
        NodoPedido* actual = frente;
        NodoPedido* nuevo = new NodoPedido (p);

        int counter = 0;
        while (actual->sig != NULL){
            if((actual->sig->pedido->prioridad) < (p->prioridad))
                break;
            actual = actual->sig;
            counter++;
        }
        //If para cuando el pedido de entrada sea mayor al pedido del frente
        if(((actual->pedido->prioridad) < (p->prioridad))&(counter == 0)){
            nuevo->sig = actual;
            frente = nuevo;
        } else {
            nuevo->sig = actual->sig;
            actual->sig = nuevo;
        }
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
    std::cout << "Frente->";
    NodoPedido *tmp = frente;
    while (tmp != NULL)
    {
        std::cout << tmp->pedido->prioridad << "-" ;  //hacer el imprimir
        tmp = tmp->sig;
    }
    std::cout << ">Final" << std::endl;
}

NodoPedido* ColaPedidos::verFrente()
{
    return frente;
}

void leer_pedidos(ColaPedidos *pedidos,ListaClientes* Clientes,Almacen *almacen){
    QDir dir("C:/Users/Asus/Repositories/ProyectoED1/Pedidos");
    if (dir.exists())
    {
        QStringList files = dir.entryList(QDir::Files | QDir::NoDotAndDotDot);
        Pedidos *Leido;
        for (const QString& file : files){
            //std::cout << file.toStdString() << std::endl;
            Leido = leer_archivo_pedido(file.toStdString(),Clientes,almacen);
            if(Leido == NULL)
                continue;
            pedidos->encolarPedido_x_prioridad(Leido);
            //pedidos->imprimir();
        }
    }
}
