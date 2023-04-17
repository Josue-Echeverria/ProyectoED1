
#include "ListaClientes.h"

bool ListaClientes::vacia(){
    return primero == NULL;
}

void ListaClientes::insertar(Cliente *p){
    if (vacia())
        primero = new NodoCliente (p);
    else
    {
        NodoCliente* actual = primero;
        NodoCliente* nuevo = new NodoCliente (p);
        while (actual->sig != NULL)
            actual = actual->sig;
        actual->sig = nuevo;
    }
}



ListaClientes* leerClientes(ifstream *archivoClientes){

    string str = "";
    if (!archivoClientes->is_open()) {
        std::cerr << "Failed to open Clientes file!" << std::endl;
    }
    ListaClientes *Clientes = new ListaClientes();
    string* linea;
    //Se recorre el array para leer cada una de las lineas de informacion sobre los clientes
    while(getline(*archivoClientes,str)){
        std::cout<<str<<std::endl;
        //Se parte la linea actual en un array de strings
        linea= adv_tokenizer(str,9);
        if (linea == NULL){ //If en caso que en el archivo haya una linea con formato incorrecto
            continue;
        }
        //Se crea el nuevo cliente con los pararmetros de esa linea del archivo
        try {
            stoi(linea[2]);
        } catch (...) {
            continue;
        }
        Clientes->insertar(new Cliente(linea[0],linea[1],stoi(linea[2])));
    }

    return Clientes;
}

int ListaClientes::prioridad_cliente(string codigo){
    NodoCliente *tmp = primero;
    while(tmp){
        if(tmp->client->Codigo == codigo)
            return tmp->client->Prioridad;
        tmp = tmp->sig;
    }
    return -1;
}
