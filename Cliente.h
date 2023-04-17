#include <iostream>
#include <fstream>
#include <cstring>
#include <QDebug>
#include <chrono>
#include <thread>
#include <filesystem>
#include <dirent.h>
#include <QtCore/QDir>
using namespace std;

struct Cliente{
    string Codigo;
    string Nombre;
    int Prioridad;

    Cliente(){
        string Codigo = "";
        string Nombre= "";
        int Prioridad = 0;
    }
    Cliente(string Codigo_entrada, string Nombre_entrada, int Prioridad_entrada){
        Codigo = Codigo_entrada;
        Nombre = Nombre_entrada;
        Prioridad = Prioridad_entrada;
    }
//DECLARACION D FUNCIONES:
    string to_string();
};

int pos_d_cliente(string,Cliente*,int);
string *adv_tokenizer(string s, char del);
