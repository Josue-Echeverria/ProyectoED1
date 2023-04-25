#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Pedidos_Thread.h"
#include "Fabrica.h"
#include "BalanceadorThread.h"
#include <QMainWindow>
#include <QFile>
#include <QDir>
#include <QDebug>
#include <QString>
#include <QTextStream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    Pedidos_Thread *pedidos_thread;
    Fabricas *fabricas_thread;
    BalanceadorThread *balanceador_thread;
    ~MainWindow();

private slots:

    void on_pushButton_detenerfabrica_a_clicked();

    void on_pushButton_detenerfabrica_b_clicked();

    void on_pushButton_detenerfabrica_c_clicked();

    void on_pushButton_detenerfabrica_comodin_clicked();


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
