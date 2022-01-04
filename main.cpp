#include "mainwindow.h"
#include   "windows.h "
#include   "shellapi.h "
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qRegisterMetaType<Parameter>( "Parameter" );
    MainWindow w;
    w.show();    
    return a.exec();
}
