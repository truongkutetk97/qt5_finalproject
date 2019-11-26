#include "debugwindow.h"
#include "ui_debugwindow.h"
#include <QMenuBar>
#include <QStatusBar>
#include <QDebug>
#include <QAction>
#include <QApplication>
#include "mainwindow_login.h"
debugwindow::debugwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::debugwindow)
{
    ui->setupUi(this);
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

debugwindow::~debugwindow()
{
    delete ui;
}
