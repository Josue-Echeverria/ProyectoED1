
#include "mainwindow.h"
#include <QApplication>
#include <QFile>


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
