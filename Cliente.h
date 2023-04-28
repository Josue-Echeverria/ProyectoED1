#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>
#include <fstream>
#include <cstring>
#include <QDebug>
#include <chrono>
#include <thread>
#include <filesystem>
#include <dirent.h>
#include <QtCore>
#include <QListWidget>
#include <QTabWidget>
#include <QPlainTextEdit>
#include <QTextBrowser>

using namespace std::chrono_literals;

struct Cliente{
    std::string Codigo;
    std::string Nombre;
    int Prioridad;

    Cliente(){
        std::string Codigo = "";
        std::string Nombre= "";
        int Prioridad = 0;
    }
    Cliente(std::string Codigo_entrada, std::string Nombre_entrada, int Prioridad_entrada){
        Codigo = Codigo_entrada;
        Nombre = Nombre_entrada;
        Prioridad = Prioridad_entrada;
    }
//DECLARACION D FUNCIONES:
    std::string to_string();
};
std::string read_all(std::ifstream);
void write_error(std::ofstream*,std::string,std::string);
int pos_d_cliente(std::string,Cliente*,int);
std::string *adv_tokenizer(std::string s, char del);

#endif
