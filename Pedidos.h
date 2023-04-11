#include "Almacen.h"

struct Pedidos
{

    int numero_pedido;
    string codigo_cliente;
    int contador_productos = 0;

    Producto *Productos;

    Pedidos(){};
    Pedidos(int numero_pedido_entrada,string codigo_cliente_entrada,int num_productos) {
        numero_pedido = numero_pedido_entrada;
        codigo_cliente = codigo_cliente_entrada;
        Productos = new Producto[num_productos];
    }
    void aniadir_producto(string,int);

};

Pedidos *leer_pedidos(Cliente*,int);
void goto_archivos_erroneos(string);
