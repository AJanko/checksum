#include "mainwindow.h"
#include <QApplication>
#include <QtPlugin>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.Plik();
    return a.exec();
}