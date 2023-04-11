#include <iostream>
#include <fstream>
#include <cstring>
#include <QDebug>
#include <chrono>
#include <thread>

#include <dirent.h>
using namespace std;

struct Cliente{
    string Codigo;
    string Nombre;
    int Prioridad;

    Cliente(){}
    Cliente(string Codigo_entrada, string Nombre_entrada, int Prioridad_entrada){
        Codigo = Codigo_entrada;
        Nombre = Nombre_entrada;
        Prioridad = Prioridad_entrada;
    }
//DECLARACION D FUNCIONES:
    string to_string();
};
Cliente *leerClientes(int&);
string *split(string str,int);
int pos_d_cliente(string,Cliente*,int);

