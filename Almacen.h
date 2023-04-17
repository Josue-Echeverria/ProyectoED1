#include "ListaProductos.h"

struct Almacen
{
    Producto *matriz_productos[10][26];
    Almacen() {
        for(int i = 0; i <10;i++){
            for(int j = 0;j<26;j++){
                matriz_productos[i][j] = new Producto();
            }
        }
    }
    void instertar_producto(string,int,int,char,string);
    Producto *existeProducto(string);
    bool existeCant(Producto *, int);
    void modificarCant(Producto *, int);
};
Almacen *leer_productos(ifstream*);
