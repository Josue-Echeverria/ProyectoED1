#include "ListaClientes.h"

struct Producto{
    string codigo_producto;
    int cantidad;
    int duracion_d_fabricacion;
    char categoria;
    string ubicacion;
    Producto(){
        string codigo_producto = "";
        int cantidad = 0 ;
        int duracion_d_fabricacion = 0;
        char categoria;
        string ubicacion = "";
    };
    Producto(string codigo_producto_entrada,int cantidad_entrada){
        cantidad = cantidad_entrada;
        codigo_producto = codigo_producto_entrada;
    }
    Producto(string codigo_producto_entrada,int cantidad_entrada,int duracion_entrada,char categoria_entrada,string posicion_entrada){
        cantidad = cantidad_entrada;
        codigo_producto = codigo_producto_entrada;
        duracion_d_fabricacion = duracion_entrada;
        categoria = categoria_entrada;
        ubicacion = posicion_entrada;
    }
    string to_string_in_pedido(){
        return codigo_producto+"\n"+std::to_string(cantidad);
    }
    string to_string_in_almacen(){
        return codigo_producto+"\n"+to_string(cantidad)+"\n"+to_string(duracion_d_fabricacion)+"\n"+categoria+"\n"+ubicacion;
    }
};
