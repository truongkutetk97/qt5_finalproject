#include "mainwindow_login.h"
#include "ui_mainwindow_login.h"
#include "secondmain.h"
MainWindow_login::MainWindow_login(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow_login)
{
    ui->setupUi(this);
    ui->lineEdit->setPlaceholderText("Enter your Password");
    ui->lineEdit_2->setPlaceholderText("Enter your Username");
    connect(ui->lineEdit,&QLineEdit::returnPressed,[=](){
        secondmain  *a = new secondmain (this);
        this->hide();
        a->show();
    });
}


MainWindow_login::~MainWindow_login()
{
    delete ui;
}


void MainWindow_login::on_pushButton_clicked()
{
    secondmain  *a = new secondmain (this);
    this->hide();
    a->show();
}
