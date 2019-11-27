#include "mainwindow_login.h"
#include "ui_mainwindow_login.h"
#include "secondmain.h"
#include "adminwindow.h"
#include "debugwindow.h"
MainWindow_login::MainWindow_login(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow_login)
{
    ui->setupUi(this);
    ui->lineEdit->setPlaceholderText("Enter your Password");
    ui->lineEdit_2->setPlaceholderText("Enter your Username");
    ui->lineEdit_2->setAutoFillBackground(false);
    connect(ui->lineEdit,&QLineEdit::returnPressed,this,&MainWindow_login::entermainwindows);
    connect(ui->pushButton,&QPushButton::clicked,this,&MainWindow_login::entermainwindows);
    ui->pushButton->setAutoFillBackground(false);
//    this->setStyleSheet("background-image: url(:/resourcee/background2.jpg);");
    QPixmap pixmap;
    pixmap.load(":/resourcee/background2.jpg");
    pixmap = pixmap.scaled(1366,768, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QPalette palette;
    palette.setBrush(QPalette::Window, pixmap);

    this->setPalette(palette);
}

MainWindow_login::~MainWindow_login()
{
    delete ui;
}

void MainWindow_login::entermainwindows()
{

    if(ui->lineEdit_2->text()=="admin")
    {
        adminwindow *admin = new adminwindow(this);
        this->hide();
        admin->show();
    }else
    if(ui->lineEdit_2->text()=="debug")
    {
        debugwindow *debug = new debugwindow(this);
        this->hide();
        debug->show();
    }else
    {
        secondmain  *a = new secondmain (this);
        this->hide();
        a->show();
    }
}
