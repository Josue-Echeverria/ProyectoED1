#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Pedidos_Thread.h"
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

    ~MainWindow();

private slots:

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
