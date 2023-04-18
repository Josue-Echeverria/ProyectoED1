
#include "mainwindow.h"
#include <QApplication>
#include <QFile>

void x(ColaPedidos *pedidos,ListaClientes* Clientes,Almacen *almacen){
    while(true){

        leer_pedidos(pedidos,Clientes,almacen);
        pedidos->imprimir();

        std::this_thread::sleep_for(5000ms);
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
// std::thread thread_lectura_pedidos(x,Pedidos,Clientes,Almacen);

   // std::thread t2(function2);


    //t2.join();


//

   w.show();
 //   thread_lectura_pedidos.join();

    return a.exec();

}
