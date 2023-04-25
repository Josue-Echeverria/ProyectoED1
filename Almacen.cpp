#include "Almacen.h"
#include <bits/stdc++.h>
void Almacen::instertar_producto(std::string codigo_entrada,int cantidad_entrada,int duracion_entrada,char categoria_entrada,std::string posicion_entrada){
    int letra = posicion_entrada[0]-65;
    int num1 = (posicion_entrada[1]-48)*10;
    int num2 = posicion_entrada[2]-48;
    if (num1+num2-1 >= 0 & num1+num2-1 <=9)
        matriz_productos[num1+num2-1][letra] = new Producto(codigo_entrada,cantidad_entrada,duracion_entrada,categoria_entrada,posicion_entrada);
    //std::cout<<matriz_productos[num1+num2][letra]->to_string_in_almacen()<<std::endl;
}



int validacion(std::string *linea){
    try{// Se confirma que los datos de la cantidad y la duracion de fabricacion del producto sean numeros
        if(stoi(linea[2])<0 || stoi(linea[1])<0)
            return -1;
    }catch(...){
        return -1;
    }
    //Confirma que la categoria del producto sea A,B,C
    if (!(linea[3][0]>=65&linea[3][0]<=67))
        return -2;
    //Confirma que la posicion en el almacen tenga el formato valido
    if(!((linea[4][0]>=65&linea[4][0]<=90)&(linea[4][1]>=48&linea[4][1]<=57)&(linea[4][2]>=48&linea[4][2]<=57)))
        return -3;
    return 0;
}

Almacen *leer_productos(std::ifstream *archivoProductos){
    if (!archivoProductos->is_open()) {
        std::cerr << "Failed to open Productos file!" << std::endl;
        return NULL;
    } else {
        std::string str = "";
        std::string *linea;
        int duracion_d_fabricacion;
        int cantidad;
        Almacen *almacen_2_return = new Almacen();
        //While para recorrer las lineas del archivo y leer los productos
        while(getline(*archivoProductos,str)){
            linea = adv_tokenizer(str,9);
            switch (validacion(linea)) {
            case -1:
                /*
                 * Aqui deberia de escribir el error de que la cantidad/duracion no es int o negativo
                 */
                break;
            case -2:
                /*
                 * Aqui deberia de escribir el error de que la categoria no es de tipo A,B,C
                 */
                break;
            case -3:
                /*
                 * Aqui deberia de escribir el error de que la posicion en la matriz no es valida
                 */
                break;

            }//Si no callo en un ninguno de los casos es por que retornó un 0 y la linea es valida
            almacen_2_return->instertar_producto(linea[0],stoi(linea[1]),stoi(linea[2]),linea[3][0],linea[4]);
            std::cout<<str<<std::endl;
            str.clear();
        }
        return almacen_2_return;
    }
}

Producto *Almacen::existeProducto(std::string codigo){
    for(int i = 0; i <10;i++){
        for(int j = 0;j<26;j++){
            if(matriz_productos[i][j]->codigo_producto == codigo){
                return matriz_productos[i][j];
            }
        }
    }
    return NULL;
}

bool Almacen::existeCant(Producto * prod, int cant){;
    if(prod->cantidad >= cant){
        return true;
    }
    return false;
}

void Almacen::modificarCant(Producto * prod, int cant){
    prod->cantidad -= cant;
}

int Almacen::cantEnAlmacen(Producto *prod){
    return prod->cantidad;
}

