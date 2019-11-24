#include "mainwindow_login.h"
#include "secondmain.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow_login w;
//    w.show();
    secondmain w;
    w.show();
    return a.exec();
}
