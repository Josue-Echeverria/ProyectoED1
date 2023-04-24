#ifndef FABRICA_H
#define FABRICA_H
#include <iostream>
#include <QtCore>
#include <QDebug>
#include <QLabel>
#include "Almacen.h"
using namespace std;
struct nodoFab{
    string cod;
    int cant;
    nodoFab(string cod, string cant){

    }
};

class FabricaThread : public QThread
{
public:
    FabricaThread(Almacen* almacen, QLabel* labelFab)
    {
        running = false;
        this->almacen = almacen;
        this->label = labelFab;
    }

    void run()
    {
        running = true;
        while (running)
        {
            label->setText();
            QThread::sleep(1);
        }
    }
private:
    string codigo;
    bool running;
    Almacen* almacen;
    QLabel* label;
};




#endif // FABRICA_H
