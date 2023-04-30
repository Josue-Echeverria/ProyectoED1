#include "Fabrica.h"

void colaFab::encolarFabrica (Producto * prod, int cant){
    if (vacia()){
        frente = new nodoFab (prod, cant);
    }
    else
    {
        nodoFab* actual = frente;
        while (actual->sig != NULL)
            actual = actual->sig;
        nodoFab* nuevo = new nodoFab (prod, cant);
        actual->sig = nuevo;
    }
}
nodoFab* colaFab::desencolar(void)
{
    if (vacia())
    {
        return NULL;
    }
    else
    {
        nodoFab* borrado = frente;
        frente = frente->sig;
        borrado->sig = NULL;
        return borrado;
    }
}

bool colaFab::vacia (void)
{
    if (frente == NULL)
        return true;
    else
        return false;
}

nodoFab* colaFab::verFrente()
{
    return frente;
}

int colaFab::cantEnCola(){
    int contador = 0;
    if(vacia())
        return contador;
    else{
        nodoFab* actual = frente;
        while (actual){
            contador+=1;
            actual = actual ->sig;
        }
        return contador;
    }
}

bool colaFab::existe(Producto * prod){
    if(vacia()){
        return false;
    }else{
        nodoFab *aux = frente;
        while(aux){
            if(prod->codigo_producto == aux->prod->codigo_producto){
                return true;
            }
            aux = aux->sig;
        }
        return false;
    }
}

int Fabricas::menorCola(int uno, int dos){
    if(arrayFabrica[uno]->getCola()->cantEnCola() <= arrayFabrica[dos]->getCola()->cantEnCola()){
        return uno;
    }
    else{
        return dos;
    }
}
void Fabricas::fabricar(Producto * prod, int cant){
    if (prod->categoria == 'C'){
        arrayFabrica[2]->getCola()->encolarFabrica(prod, cant);
        return;
    }else if (prod->categoria == 'A'){
        int menor = menorCola(0,3);
        arrayFabrica[menor]->getCola()->encolarFabrica(prod, cant);
        return;
    }else if (prod->categoria == 'B'){
        int menor = menorCola(1,3);
        arrayFabrica[menor]->getCola()->encolarFabrica(prod, cant);
        return;
    }
}

bool Fabricas::existeProd(Producto * prod){
    for(int i = 0; i <= 3; i++){
        if(arrayFabrica[i]->getCola()->existe(prod)){
            return true;
        }
    }
    return false;
}




