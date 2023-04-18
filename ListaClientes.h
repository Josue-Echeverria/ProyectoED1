#include "Cliente.h"


struct NodoCliente{
    Cliente *client;
    NodoCliente* sig;
    // constructores
    NodoCliente(Cliente * p)
    {
        client = p;
        sig = NULL;
    }
};
struct ListaClientes{
    NodoCliente *primero;

    ListaClientes()
    {
        primero = NULL;
    }

    // encabezados de funcion
    void insertar (Cliente *p);
    bool vacia(void);
    void imprimir(void);
    int prioridad_cliente(std::string);
};
ListaClientes *leerClientes(std::ifstream*);

