#ifndef PEDIDOS_H
#define PEDIDOS_H
#include "Almacen.h"
#include<iostream>
#include <fstream>
#include <ctime>

struct Pedidos
{
    int numero_pedido;
    Cliente* Cliente;
    int contador_productos = 0;
    std::string factura;
    std::string textoFactura;
    ListaProductos *Productos;

    Pedidos(){};
    Pedidos(int numero_pedido_entrada,struct Cliente *C) {
        numero_pedido = numero_pedido_entrada;
        Cliente = C;
        std::string factura = "";
        std::string textoFactura = "";
        Productos = new ListaProductos();
    }
    void aniadir_producto(std::string,int);
    std::string to_string();
    void crearFactura(void);
    void llegoBalanceador(void);
    std::string getTime(void);
    void txtFactura(void);

};
Pedidos *leer_archivo_pedido(std::string ,ListaClientes* ,Almacen* );

void goto_archivos_erroneos(std::string);

#endif
