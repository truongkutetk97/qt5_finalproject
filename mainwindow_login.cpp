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
    ui->lineEdit->setEchoMode(QLineEdit::Password);
//    this->setStyleSheet("background-image: url(:/resourcee/background2.jpg);");
//    QPixmap pixmap;
//    pixmap.load(":/resourcee/background2.jpg");
//    pixmap = pixmap.scaled(1366,768, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
//    QPalette palette;
//    palette.setBrush(QPalette::Window, pixmap);
//    this->setPalette(palette);
         QFont title1("Times New Roman",30,QFont::Bold);
       QFont title2("Times New Roman",25,QFont::Bold);
       QFont title3("Times New Roman",20,QFont::Bold);

       ui->label_2->setFont(title1);
       ui->label_5->setFont(title2);
       ui->label_6->setFont(title3);
       ui->label_7->setFont(title3);
       ui->label_8->setFont(title3);

       QPixmap pixmap2;
       pixmap2.load(":/logo_cokhi.png");
       pixmap2 = pixmap2.scaled(1280,180, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
       QPalette palette2;
       palette2.setBrush(QPalette::Window, pixmap2);
       ui->label->setPixmap(pixmap2);
}

MainWindow_login::~MainWindow_login()
{
    delete ui;
}

void MainWindow_login::entermainwindows()
{

    if(ui->lineEdit->text()=="admin")
    {
        adminwindow *admin = new adminwindow(this);
        this->hide();
        admin->show();
    }else
    if(ui->lineEdit->text()=="debug")
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
