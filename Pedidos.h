#include "Almacen.h"

struct Pedidos
{

    int numero_pedido;
    std::string codigo_cliente;
    int prioridad;
    int contador_productos = 0;

    ListaProductos *Productos;

    Pedidos(){};
    Pedidos(int numero_pedido_entrada,std::string codigo_cliente_entrada,int prioridad_entrada) {
        numero_pedido = numero_pedido_entrada;
        codigo_cliente = codigo_cliente_entrada;

        Productos = new ListaProductos();
        prioridad = prioridad_entrada;
    }
    void aniadir_producto(std::string,int);


};
Pedidos *leer_archivo_pedido(std::string ,ListaClientes* ,Almacen* );

void goto_archivos_erroneos(std::string);
