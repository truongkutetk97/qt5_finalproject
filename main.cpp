#include "mainwindow_login.h"
#include "secondmain.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow_login w;
    secondmain w;
    w.show();
    w.setFixedSize(400,400 );
    return a.exec();
}
