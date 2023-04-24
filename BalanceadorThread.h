
#ifndef BALANCEADORTHREAD_H
#define BALANCEADORTHREAD_H

#include <QtCore>
#include <QDebug>
#include <QLabel>

#include "ColaFabricaciones.h"

class BalanceadorThread : public QThread
{
public:
    BalanceadorThread(ColaPedidos* cola, QLabel* label_Balanceador)
    {
        running = false;
        this->cola = cola;
        this->label = label_Balanceador;
    }

    void run()
    {
        running = true;
        while (running)
        {
            if (!cola->vacia())
            {
                int waitTime = cola->desencolar();
                label->setText(cola->toString());

                while (waitTime > 0)
                {
                    attendingLabel->setText(QString::number(waitTime--));
                    QThread::sleep(1);
                }
            }

            QThread::sleep(1);
        }
    }
private:
    bool running;
    ColaPedidos* cola;
    QLabel* label;
};

#endif // BALANCEADORTHREAD_H
