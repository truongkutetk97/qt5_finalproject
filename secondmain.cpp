#include "secondmain.h"
#include "ui_secondmain.h"

secondmain::secondmain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::secondmain)
{
    ui->setupUi(this);
}

secondmain::~secondmain()
{
    delete ui;
}
