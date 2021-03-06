#include "adminwindow.h"
#include "ui_adminwindow.h"
#include <QMenuBar>
#include <QStatusBar>
#include <QDebug>
#include <QAction>
#include <QApplication>
#include "mainwindow_login.h"
adminwindow::adminwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::adminwindow)
{
    QFont btnfont("Times", 20, QFont::Bold);

    ui->setupUi(this);
    ui->pushButton->setFont(btnfont);
    //MENU BAR LOGOUT BLOCK
    {
    QAction * logoutaction = new QAction("LOGOUT");
    connect(logoutaction,&QAction::triggered,[=](){
        this->hide();
        MainWindow_login *w = new MainWindow_login();
        w->show();
    });

    menuBar()->addMenu("File");
    menuBar()->addMenu("Edit");
    menuBar()->addMenu("Window");
    menuBar()->addMenu("Settings");
     QMenu * fileMenu =menuBar()->addMenu("Help");
     fileMenu->addAction(logoutaction);
    }



}

adminwindow::~adminwindow()
{
    delete ui;
}
