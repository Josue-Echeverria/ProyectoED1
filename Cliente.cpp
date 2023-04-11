#include "Cliente.h"


//DEFINICION D FUNCIONES DE CLASE CLIENTE--------------------------------------------------------------------

string Cliente::to_string(){
    return "Codigo: "+Codigo+"\nNombre: "+Nombre+"\nPrioridad: "+std::to_string(Prioridad)+"\n";
}

//----------------------------------------------------------------------------------------------


/*Funcion para partir un string cada vez que haya un tab
Entrada: La string a partir
Salida: Array de los strings separados por tabs
*/
string* split(string str,int n_datos){
    string *lista = new string[n_datos];
    string word = "";
    int counter = 0;
    //Se itera a travez de la string caracter por caracter
    //Se revisa cada uno de ellos buscando un tab
    for (char x : str){
        //Se confirma que es un tab comparando el caracter con un 9(codigo ascii del tab)
        if (x == 9){
            if(word == ""){//Encaso de que algun dato este vacio no se retorna null ´para no tomar en cuenta esa linea
                return NULL;
            } else {
                //Cada vez que se encuetre un tab almacenara en el array los caracteres acumulados
                lista[counter] = word;
                //std::cout<<word<<std::endl;
                counter++;
                word = "";
            }
        } else {
            //Si no es un tab se acumula el caracter en un string
            word = word + x;
        }
       // std::cout<<x<<std::endl;
    }
    lista[counter] = word;
    //std::cout<<word<<std::endl;
    return lista;
}


/*+Funcion para leer el archivo de clientes
+El archivo de clientes debe estar en el mismo directorio y se debe llamar "Clientes.txt"
+Devuelve un array de Clientes
*/
Cliente* leerClientes(int &numero_d_clientes){
    int counter = 0;
    string str = "";
    //Se recorre el archivo para contar el numero de lineas y crear un array con el num de lineas del archivo
    //Esto porque se supones que cada linea es un cliente
    ifstream archivoClientes("C:/Users/Asus/Repositories/ProyectoED1/Clientes.txt");
    if (!archivoClientes.is_open()) {
        std::cerr << "Failed to open Clientes file!" << std::endl;
    }
    while(getline(archivoClientes,str)){
        counter++;
    }
    Cliente *Clientes = new Cliente[counter];
    numero_d_clientes = counter;

    //Se devuelve el puntero del archivo al inicio para recorrerlo una vez mas
    archivoClientes.clear();
    archivoClientes.seekg(0, std::ios::beg);
    counter = 0;
    string* linea;
    //Se recorre el array para leer cada una de las lineas de informacion sobre los clientes
    while(getline(archivoClientes,str)){
        std::cout<<str<<std::endl;
        //Se parte la linea actual en un array de strings
        linea = split(str,3);
        if (linea == NULL){ //If en caso que en el archivo haya una linea con formato incorrecto
            continue;
        }
        //Se crea el nuevo cliente con los pararmetros de esa linea del archivo
        try {
            stoi(linea[2]);
        } catch (...) {
            continue;
        }
        Clientes[counter] = Cliente(linea[0],linea[1],stoi(linea[2]));
        counter++;
    }
    archivoClientes.close();
    return Clientes;
}

int pos_d_cliente(string nombre_x_buscar,Cliente* Clientes,int largo){
    if(Clientes){// Confirma que el array de clientes no sea NULL
        for(int i = 0;i<largo;i++){
            if (Clientes[i].Codigo == nombre_x_buscar){
                return i;
            }
        }
    }
    return -1;
}
