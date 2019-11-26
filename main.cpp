#include "mainwindow_login.h"
#include "secondmain.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
     MainWindow_login *w = new MainWindow_login();
//    secondmain w
    w->show();
    w->setFixedSize(800,400 );
    return a.exec();
}
