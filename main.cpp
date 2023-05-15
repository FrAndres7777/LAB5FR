
#include "mainwindow.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setStyle("fusion");
    MainWindow w;
    w.show();// HACE QUE LA VENTANA SE MUESTRE
    return a.exec();
}
