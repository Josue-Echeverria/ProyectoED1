#ifndef FABRICA_H
#define FABRICA_H
#include <iostream>
#include <QtCore>
#include <QDebug>
#include <QLabel>
#include "Almacen.h"

using namespace std;
struct nodoFab{
    Producto *prod;
    int cant;
    nodoFab *sig;
    nodoFab(Producto *prod, int cant){
        this->prod = prod;
        this->cant = cant;
        sig = NULL;
    }
};

struct colaFab{
    nodoFab *frente;
    colaFab()
    {
        frente = NULL;
    }

    void encolarFabrica (Producto * prod, int cant);
    nodoFab* desencolar (void);
    nodoFab* verFrente(void);
    bool vacia(void);
    int cantEnCola(void);
    bool existe(Producto * prod);
};

class FabricaThread : public QThread
{
public:
    FabricaThread(Almacen* almacen, QLabel* labelFab, string cod)
    {
        running = true;
        this->almacen = almacen;
        this->label = labelFab;
        this->codigo = cod;
        this->cola = new colaFab();
    }

    void run()
    {
        while(true){
            while(running){
                QThread::sleep(1);
                if(!cola->vacia()){
                    nodoFab *primer = cola->verFrente();
                    int tiempo = primer->prod->duracion_d_fabricacion * primer->cant;
                    while(tiempo >= 0){
                        if(!running){
                            QThread::sleep(1);
                        }else{
                            QString qstr = QString::fromStdString(primer->prod->codigo_producto);
                            label->setText(qstr + "\n" + QString::number(tiempo) + " segundos");
                            tiempo--;
                            QThread::sleep(1);
                        }
                    }
                    cola->desencolar();
                    label->setText("Fabrica " + QString::fromStdString(codigo));
                }
                QThread::sleep(1);
            }
            QThread::sleep(1);
        }
    }

    void pausar(){
        running = false;
    }
    void reanudar(){
        running = true;
    }
    Almacen *getAlmacen(){
        return almacen;
    }
    colaFab *getCola(){
        return cola;
    }
    bool getRunning(){
        return running;
    }
private:
    string codigo;
    bool running;
    Almacen* almacen;
    QLabel* label;
    colaFab * cola;
};

struct Fabricas{
    FabricaThread *arrayFabrica [3];
    Fabricas(Almacen *almacen, QLabel *labelFabA, QLabel *labelFabB, QLabel *labelFabC, QLabel *labelFabCom){
        arrayFabrica [0] = new FabricaThread(almacen, labelFabA, "A");
        arrayFabrica [1] = new FabricaThread(almacen, labelFabB, "B");
        arrayFabrica [2] = new FabricaThread(almacen, labelFabC, "C");
        arrayFabrica [3] = new FabricaThread(almacen, labelFabCom, "COM");
        arrayFabrica [0]->start();
        arrayFabrica [1]->start();
        arrayFabrica [2]->start();
        arrayFabrica [3]->start();
    }
    int menorCola(int uno, int dos);
    void fabricar(Producto * prod, int cant);
    void detenerFabrica(int fab){arrayFabrica[fab]->pausar();};
    void reanudarFabrica(int fab){arrayFabrica[fab]->reanudar();};
    bool existeProd(Producto * prod);
};



#endif // FABRICA_H
