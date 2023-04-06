#include "Cliente.h"

struct Pedidos
{

    int numero_pedido;
    string codigo_cliente;

    struct Producto{
        string codigo_producto;
        int cantidad;
    };

    Pedidos() {}
};
Pedidos *leer_pedidos();

