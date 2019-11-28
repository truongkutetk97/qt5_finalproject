#include "mainwindow_login.h"
#include "secondmain.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//     MainWindow_login *w = new MainWindow_login();
    secondmain *w =new secondmain() ;

//     w->setStyleSheet("QFrame {background-image :url(/*/resourcee/background2.jpg*/)}");

    w->show();

//    w->setFixedSize(1366,768 );
    return a.exec();
}
