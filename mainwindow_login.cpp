#include "mainwindow_login.h"
#include "ui_mainwindow_login.h"
#include "secondmain.h"


MainWindow_login::MainWindow_login(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow_login)
{
    ui->setupUi(this);
    ui->lineEdit->setPlaceholderText("Enter your Password");
    ui->lineEdit_2->setPlaceholderText("Enter your Username");

    connect(ui->lineEdit,&QLineEdit::returnPressed,this,&MainWindow_login::entermainwindows);
    connect(ui->pushButton,&QPushButton::clicked,this,&MainWindow_login::entermainwindows);
}

MainWindow_login::~MainWindow_login()
{
    delete ui;
}
void MainWindow_login::entermainwindows()
{
    secondmain  *a = new secondmain (this);
    this->hide();
    a->show();
}
