#include "Almacen.h"

struct Pedidos
{

    int numero_pedido;
    Cliente* Cliente;
    int contador_productos = 0;

    ListaProductos *Productos;

    Pedidos(){};
    Pedidos(int numero_pedido_entrada,struct Cliente *C) {
        numero_pedido = numero_pedido_entrada;
        Cliente = C;
        Productos = new ListaProductos();
    }
    void aniadir_producto(std::string,int);
    std::string to_string();


};
Pedidos *leer_archivo_pedido(std::string ,ListaClientes* ,Almacen* );

void goto_archivos_erroneos(std::string);
