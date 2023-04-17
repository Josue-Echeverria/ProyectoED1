#include "Pedidos.h"
#define _POSIX_SOURCE
/*
void Pedidos::aniadir_producto(string nombre_producto_entrada, int cantidad_entrada){
    Productos[contador_productos] = Producto(nombre_producto_entrada,cantidad_entrada);
    contador_productos++;
}*/
void goto_archivos_erroneos(string nombre_archivo){
 /*
  *
  * TO DO
  */

}


Pedidos *leer_archivo_pedido(string nombre_archivo,ListaClientes* Clientes,Almacen *almacen){
    int counter = 0;
    string str = "";
    int numero_d_pedido;
    Pedidos *pedido_leido;
    ifstream archivoPedidos("C:/Users/Asus/Repositories/ProyectoED1/Pedidos/"+nombre_archivo);
    if (!archivoPedidos.is_open()) {
        std::cerr << "Failed to open Pedido file!" << std::endl;
        return NULL;
    } else {
        try {
            getline(archivoPedidos,str);//Se saca la primera linea (numero de pedido)
            numero_d_pedido = stoi(str);//Se convierte a int y se almacena en su variable correspondiente
        } catch (...) {
            goto_archivos_erroneos(str);//Se manda el archivo a la dir con todos los archivos con errores
            return NULL;// El numero de pedido no es un numero retorna null
        }
        getline(archivoPedidos,str);//Se saca la segunda linea del archivo(Codigo del cliente)
        int pos = Clientes->prioridad_cliente(str);
        if (pos == -1){// Se confirma que el cliente realizando el pedido dentro de la lista de clientes
            std::cout<<"USUARIO INEXISTENTE"<<endl;
            goto_archivos_erroneos(str);//Se manda el archivo a la dir con todos los archivos con errores
            return NULL;
        } else {
            // Las siguientes lineas de codigo se ejecutan cuado el archivo tiene
            // *Numero de pedido valido
            // *Codigo de clientes valido
            // Por lo tanto se leeran los productos para el pedido
            string* linea;
            pedido_leido = new Pedidos(numero_d_pedido,str,pos);
            //El siguiente while es para leer los productos que van con el pedido
            while(getline(archivoPedidos,str)){
               // cout<<str<<endl;
                linea = adv_tokenizer(str,9);
                if (linea == NULL) //If en caso que en el archivo haya una linea con formato incorrecto
                    continue;
                try {//Se confirma que lo que este despues del tab sea un numero
                    counter = stoi(linea[1]);
                } catch (...) {
                    continue;
                }
                //Se aniade el producto al pedido
                pedido_leido->Productos->insertar(new Producto(linea[0],counter));
            }
            archivoPedidos.close();
            return pedido_leido;
        }
    }
//    const char* oldpath = ("C:/Users/Asus/Repositories/ProyectoED1/Pedidos/"+nombre_archivo).c_str();
//    const char* newpath = ("C:/Users/Asus/Repositories/ProyectoED1/Pedidos_Leidos/"+nombre_archivo).c_str();

//    if (rename(oldpath, newpath) != 0) {
//           perror("Error moving file");
//       }
}

