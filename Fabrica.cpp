#include "Fabrica.h"

void colaFab::encolarFabrica (string cod, int cant){
    if (vacia()){
        frente = new nodoFab (cod, cant);
    }
    else
    {
        nodoFab* actual = frente;
        while (actual->sig != NULL)
            actual = actual->sig;
        nodoFab* nuevo = new nodoFab (cod, cant);
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

bool colaFab::existe(string cod){
    if(vacia()){
        return false;
    }else{
        nodoFab *aux = frente;
        while(aux){
            if(aux->cod == cod)
                return true;
            aux = aux->sig;
        }
        return false;
    }
}

int Fabricas::menorCola(int uno, int dos){
    if(arrayFabrica[uno]->getCola()->cantEnCola() > arrayFabrica[dos]->getCola()->cantEnCola()){
        return dos;
    }
    else{
        return uno;
    }
}
void Fabricas::fabricar(string cod, int cant){
    Producto * prod = arrayFabrica [0]->getAlmacen()->existeProducto(cod);
    if (prod->categoria == 'C'){
        arrayFabrica[2]->getCola()->encolarFabrica(prod->codigo_producto, prod->cantidad * cant);
        return;
    }else if (prod->categoria == 'A'){
        int menor = menorCola(0,3);
        arrayFabrica[menor]->getCola()->encolarFabrica(prod->codigo_producto, prod->duracion_d_fabricacion * cant);
        return;
    }else if (prod->categoria == 'B'){
        int menor = menorCola(1,3);
        arrayFabrica[menor]->getCola()->encolarFabrica(prod->codigo_producto, prod->duracion_d_fabricacion * cant);
        return;
    }
}

bool Fabricas::existeProd(string cod){
    for(int i = 0; i <= 3; i++){
        if(arrayFabrica[i]->getCola()->existe(cod)){
            return true;
        }
    }
    return false;
}




