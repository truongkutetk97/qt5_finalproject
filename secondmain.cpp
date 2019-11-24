#include "secondmain.h"
#include "ui_secondmain.h"
#include <QMessageBox>
#include <QDebug>

secondmain::secondmain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::secondmain)
{
    ui->setupUi(this);
    QFont buttonFont("Times", 20, QFont::Bold);

    ui->btn->setText("CLICK MEEEEE!");
    ui->btn->setMinimumSize(300,50);
    ui->btn->setFont(buttonFont);
    connect(ui->btn,&QPushButton::clicked,[=](){
        QMessageBox m;
        int ret = m.information(this,"truongdeptraititle","truongdeptraitext",QMessageBox::Open|QMessageBox::Save);

    });
}

secondmain::~secondmain()
{
    delete ui;
}
