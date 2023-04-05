#include "Cliente.h"


//DEFINICION D FUNCIONES DE CLASE CLIENTE--------------------------------------------------------------------

string Cliente::to_string(){
    string str = "Codigo: "+Codigo+"\nNombre: "+Nombre+"\nPrioridad: "+std::to_string(Prioridad)+"\n";
    return str;
}

//----------------------------------------------------------------------------------------------


/*Funcion para partir un string cada vez que haya un tab
Entrada: La string a partir
Salida: Array de los strings separados por tabs
*/
string* split(string str){
    string *lista = new string[3];
    string word = "";
    int counter = 0;
    //Se itera a travez de la string caracter por caracter
    //Se revisa cada uno de ellos buscando un tab
    for (auto x : str){
        //Se confirma que es un tab comparando el caracter con un 9(codigo ascii del tab)
        if (x == 9){
            if(word == ""){//Encaso de que algun dato este vacio no se retorna null ´para no tomar en cuenta esa linea
                return NULL;
            } else {
                //Cada vez que se encuetre un tab almacenara en el array los caracteres acumulados
                lista[counter] = word;
                counter++;
                word = "";
            }
        } else {
            //Si no es un tab se acumula el caracter en un string
            word = word + x;
        }
    }
    lista[counter] = word;
   // for (int i = 0; i< 3; i++){
  //      std::cout<<lista[i]<<"->";
 //   }
    return lista;
}


/*+Funcion para leer el archivo de clientes
+El archivo de clientes debe estar en el mismo directorio y se debe llamar "Clientes.txt"
+Devuelve un array de Clientes
*/
Cliente* leerClientes(){
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
    //Se devuelve el puntero del archivo al inicio para recorrerlo una vez mas
    archivoClientes.clear();
    archivoClientes.seekg(0, std::ios::beg);
    counter = 0;
    string* linea;
    //Se recorre el array para leer cada una de las lineas de informacion sobre los clientes
    while(getline(archivoClientes,str)){
        std::cout<<str<<endl;
        //Se parte la linea actual en un array de strings
        linea = split(str);
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

