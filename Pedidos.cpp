#include "Pedidos.h"
#define _POSIX_SOURCE

void Pedidos::aniadir_producto(string nombre_producto_entrada, int cantidad_entrada){
    Productos[contador_productos] = Producto(nombre_producto_entrada,cantidad_entrada);
    contador_productos++;
}
void goto_archivos_erroneos(string nombre_archivo){

}


Pedidos *leer_archivo_pedido(string nombre_archivo,Cliente* Clientes,int numero_d_clientes){
    int counter = 0;
    Pedidos *pedido_leido;
    string str = "";
    int numero_d_pedido;
    ifstream archivoPedidos("C:/Users/Asus/Repositories/ProyectoED1/Pedidos/"+nombre_archivo);
    if (!archivoPedidos.is_open()) {
        std::cerr << "Failed to open Pedido file!" << std::endl;
    } else {
        while(getline(archivoPedidos,str)){//Se lee el archivo para saber cuantos productos hay lol
            counter++;
        }
        //Se devuelve el puntero del archivo al inicio para recorrerlo una vez mas
        archivoPedidos.clear();
        archivoPedidos.seekg(0, std::ios::beg);
        try {
            getline(archivoPedidos,str);//Se saca la primera linea (numero de pedido)
            numero_d_pedido = stoi(str);//Se convierte a int y se almacena en su variable correspondiente
        } catch (...) {
            goto_archivos_erroneos(str);//Se manda el archivo a la dir con todos los archivos con errores
            return pedido_leido;// El numero de pedido no es un numero retorna null
        }
        getline(archivoPedidos,str);//Se saca la segunda linea del archivo(Codigo del cliente)
        if (pos_d_cliente(str,Clientes,numero_d_clientes) == -1){// Se confirma que el cliente realizando el pedido dentro de la lista de clientes
            std::cout<<"USUARIO INEXISTENTE"<<endl;
            goto_archivos_erroneos(str);//Se manda el archivo a la dir con todos los archivos con errores
        } else {
            // Las siguientes lineas de codigo se ejecutan cuado el archivo tiene
            // *Numero de pedido valido
            // *Codigo de clientes valido
            // Por lo tanto se leeran los productos para el pedido
            string* linea;
            pedido_leido = new Pedidos(numero_d_pedido,str,counter);
            //El siguiente while es para leer los productos que van con el pedido
            while(getline(archivoPedidos,str)){
                linea = split(str,2);
                if (linea == NULL) //If en caso que en el archivo haya una linea con formato incorrecto
                    continue;
                try {//Se confirma que lo que este despues del tab sea un numero
                    counter = stoi(linea[1]);
                } catch (...) {
                    continue;
                }
                //Se aniade el producto al pedido
                pedido_leido->aniadir_producto(linea[0],counter);
            }
        }
        archivoPedidos.close();
    }
//    const char* oldpath = ("C:/Users/Asus/Repositories/ProyectoED1/Pedidos/"+nombre_archivo).c_str();
//    const char* newpath = ("C:/Users/Asus/Repositories/ProyectoED1/Pedidos_Leidos/"+nombre_archivo).c_str();

//    if (rename(oldpath, newpath) != 0) {
//           perror("Error moving file");
//       }
    return pedido_leido;
}

Pedidos *leer_pedidos(Cliente* Clientes,int numero_d_clientes){
    Pedidos *pedidos = new Pedidos[1];
    DIR*  dir;
    struct dirent *ent;
    if ((dir = opendir("C:/Users/Asus/Repositories/ProyectoED1/Pedidos")) != NULL){
        while ((ent = readdir (dir)) != NULL) {
            std::cout << ent->d_name << std::endl;
            /*
             * Aqui deberia de agregar los pedidos a un struct de cola de pedidos
            */
            leer_archivo_pedido(ent->d_name,Clientes,numero_d_clientes);

        }
        closedir (dir);
    }
    return pedidos;
}
