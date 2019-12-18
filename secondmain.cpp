#include "secondmain.h"
#include "ui_secondmain.h"
#include <QMessageBox>
#include <QDebug>
#include <QtSerialPort/QSerialPortInfo>
#include <QtSerialPort/QSerialPort>
#include <QComboBox>
#include <QSerialPortInfo>
#include <QList>
#include <QString>
#include <QTimer>
#include <QFile>
#include <QTextStream>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QMenuBar>
#include <QStatusBar>
#include <QAction>
#include <QApplication>
#include "mainwindow_login.h"
#include <QMenu>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QObject>
#include <wiringPi.h>
#include<iostream>
#include <sstream>
#include <string.h>
#define button1 = 21
#define button2 = 22
#define button3 = 23
#define button4 = 24
#define button5 = 25
static QJsonDocument   *doc =new QJsonDocument();
//static QString fn = "/home/truongdeptrai/Documents/FINALPROJECT_QT5/qt5_finalproject/test.json";
static QString fn = "/home/pi/Desktop/qt5_finalproject/test.json";
static QJsonObject json;
static QString portname;
static QString portname2;

static bool serialconnected = false;
static bool serialconnected2 = false;
static uint16_t  connectcouting= 0;
static uint16_t  debugcouting= 1;
static uint8_t readbutton = 0;
static float total = 0;

static uint8_t columnmenu = 0;
static bool ispush = false;
static bool isorderdone = false;
static QString receipt;
static QByteArray serialbuffer;
static QString serialoutput ;
static QFont buttonFont("Sans Serif", 14, QFont::Bold);
static QFont choosedfont("Sans Serif", 26, QFont::Bold);
static QFont normalfont("Sans Serif", 19);
static QTimer *checkouttimer = new QTimer();

void isr231();
void isr232();
void isr233();
void isr234();
void isr235();
secondmain::secondmain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::secondmain)
{
    wiringPiSetup();
    pinMode(21, OUTPUT);
    pinMode(22, OUTPUT);
    pinMode(23, OUTPUT);
    pinMode(24, OUTPUT);
    pinMode(25, OUTPUT);
    pullUpDnControl(21,PUD_DOWN);
    pullUpDnControl(22,PUD_DOWN);
    pullUpDnControl(23,PUD_DOWN);
    pullUpDnControl(24,PUD_DOWN);
    pullUpDnControl(25,PUD_DOWN);
    wiringPiISR(21,INT_EDGE_RISING,isr231);
    wiringPiISR(22,INT_EDGE_RISING,isr232);
    wiringPiISR(23,INT_EDGE_RISING,isr233);
    wiringPiISR(24,INT_EDGE_RISING,isr234);
    wiringPiISR(25,INT_EDGE_RISING,isr235);


    ui->setupUi(this);
    this->serialports= new QSerialPort(this);
    this->serialports2 = new QSerialPort(this);

    QPushButton *debugbtn = new QPushButton (this);
    QAction * logoutaction = new QAction("Logout");
    QAction * connectt = new QAction("Connect");
    QAction * debug = new QAction("Debug");
    QAction *readfile = new QAction("Read File");
    QAction *addline = new QAction("Add Line");
    QAction *clear = new QAction("Clear Text");

    //Setup font to button



    //Setup title
    QFont title1("Times New Roman",30,QFont::Bold);
  QFont title2("Times New Roman",25,QFont::Bold);
  QFont title3("Times New Roman",20,QFont::Bold);
    QPixmap pixmap2;
    pixmap2.load(":/logo_cokhi.png");
    pixmap2 = pixmap2.scaled(1280,180, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QPalette palette2;
    palette2.setBrush(QPalette::Window, pixmap2);
    //ui->label_11->setPixmap(pixmap2);

    // logout button in menu bar, back to mainwindow
    connect(logoutaction,&QAction::triggered,[=](){
        this->hide();
        MainWindow_login *w = new MainWindow_login();
        w->showFullScreen();
    });
    // file menubar block
    connect(readfile,&QAction::triggered,[&](){
        *doc = loadJson(fn);
         json = doc->object();
        foreach(const QString& key, json.keys()) {
            QJsonValue value = json.value(key);
            QString texttemp = key.simplified() +"="+ json.value(key).toString().simplified() ;
    //        qDebug() << "Key = " << key << ", Value = " << value.toString();
            }
    });
    connect(addline,&QAction::triggered,[&](){
    });
    connect(clear,&QAction::triggered,[&](){
    });
    // end file menubar block
    // debug button in menu bar
    connect(debug,&QAction::triggered,[&](){

    });
    // Login dialog after turn on status bar
    connect(connectt,&QAction::triggered,[=](){
         this->ui->statusbar->hide();        connectcouting +=1;
        QDialog dialog(this);
        auto *layoutDialog = new QVBoxLayout(&dialog);
        auto *lineEdit = new QLineEdit(&dialog);
        auto *label = new QLabel(tr("Enter password to close the window:"), &dialog);
        lineEdit->setEchoMode(QLineEdit::Password);
        layoutDialog->addWidget(label);
        layoutDialog->addWidget(lineEdit);
        layoutDialog->addStretch();
        connect(lineEdit, &QLineEdit::editingFinished, [&]() {
            auto *label2 = new QLabel(tr("Wrong pass"), &dialog);
            auto *label3 = new QLabel(tr("Got it!"), &dialog);
            if(lineEdit->text()=="admin"){
                if(connectcouting%2) this->ui->statusbar->show();
                     layoutDialog->addWidget(label3);
                dialog.done(lineEdit->text() == "11223344");
            }
            else {
                layoutDialog->removeWidget(label2);
                layoutDialog->addWidget(label2);
            }
           });
        dialog.resize(250, 100);
        dialog.exec();
    });



    // menu bar setup
    QMenu *filemenu =  menuBar()->addMenu("File");
    menuBar()->addMenu("Edit");
    menuBar()->addMenu("Window");
    menuBar()->addMenu("Settings");
     QMenu * helpmenu =menuBar()->addMenu("Help");
     helpmenu->addAction(logoutaction);
     helpmenu->addAction(connectt);
     helpmenu->addAction(debug);
     filemenu->addAction(readfile);
     filemenu->addAction(addline);
     filemenu->addAction(clear);
     // end menu bar setup

     // UI setup
    ui->label->setMinimumWidth(100);
    ui->label->setText("Not connected");
    debugbtn->setText("Debug UI");
    ui->statusbar->addPermanentWidget(ui->label);
    ui->statusbar->addPermanentWidget(ui->comboBox_2);
    ui->comboBox_2->addItem("9600",9600);
    ui->comboBox_2->addItem("115200",115200);
    ui->statusbar->addPermanentWidget(ui->comboBox);
    ui->statusbar->addPermanentWidget(ui->comboBox_3);
    ui->statusbar->addPermanentWidget(debugbtn);
    ui->label_11->setText("");
    ui->label_12->setText("");
    ui->label_13->setText("");
    ui->label_2->setText("");
    ui->label_3->setText("");
    ui->label_4->setText("");
    ui->label_5->setText("");
    ui->label_6->setText("");

    //    ui->statusbar->hide();  //this should be uncomment at run mode

    //Timersetup
    QTimer *timer = new QTimer(this);
    QTimer *scanbutton = new QTimer(this);

    //Define Timer
    connect(timer,SIGNAL(timeout()) ,this,SLOT(scanSerialPorts()));
    connect(scanbutton,&QTimer::timeout,this,&secondmain::scanbutton);
    connect(checkouttimer,&QTimer::timeout,[&](){
        ui->label_10->setText("CHÀO QUÝ KHÁCH ! ");
        ui->label_14->setText("NHẤN NÚT BẤT KỲ ĐỂ BẮT ĐẦU CHỌN MÓN!");
        ui->label_11->setText("");
        ui->label_12->setText("");
        ui->label_13->setText("");
        ui->label_3->setText("");
        ui->label_2->setText("");
        ui->label_4->setText("");
        ui->label_5->setText("");
        ui->label_6->setText("");
        columnmenu = 0;
        total=0;
        checkouttimer->stop();
    });

    connect(this->serialports2,&QSerialPort::readyRead,[=](){
        QByteArray data;
        data = this->serialports2->readAll();
    });

    //connect to serial callback
    connect(this->serialports,&QSerialPort::readyRead,this,&secondmain::serialreceiverr);
    //button clear text browsing
    //Debug button UI in status bar
    connect(debugbtn, &QPushButton::clicked,[=](){
        debugcouting++;
        if(debugcouting%2){
            filemenu->clear();
        }else {
            filemenu->addAction(readfile);
            filemenu->addAction(addline);
            filemenu->addAction(clear);
        }
    });



    timer->start(1000);
    scanbutton->start(100);
}
void secondmain::scanbutton(){

            if(ispush){
                if(!columnmenu){
                    columnmenu = 1;
                }
                qDebug()<<columnmenu;
                if(readbutton==5){
                    checkouttimer->start(5);
                    columnmenu = 0;
                }
                if (columnmenu==1){
                    columnmenu ++;
                    ui->label_10->setText("MỜI QUÝ KHÁCH CHỌN");
                    ui->label_2->setText("Trà sữa: ");
                    ui->label_4->setText("Thành tiền:");
                    QString temp1 = QString::number(total,'f',2);
                    ui->label_5->setText(temp1);
                    ui->label_6->setText("VND");
                    ui->label_14->setText("CỠ LY !");
                    ui->label_11->setText("L");
                    ui->label_12->setText("XL");
                    ui->label_13->setText("XXL");
                    switch (readbutton) {
                    case 1:    break;
                    default:    break;
                    }
                }else
                if ((columnmenu==2)&&(readbutton!=1)){
                    columnmenu ++;
                    ui->label_14->setText("LOẠI TRÀ !");
                    ui->label_11->setText("Caramel");
                    ui->label_12->setText("Chocolate");
                    ui->label_13->setText("Ô long");
                    receipt.clear();
                    receipt.append("Size ")                    ;
                    switch (readbutton) {
                    case 2:    {       total+= 20000; receipt.append("L "); break;  }
                    case 3:    {       total+= 25000; receipt.append("XL "); break; }
                    case 4:    {       total+= 30000; receipt.append("XXL "); break; }
                    }
                    QLocale locale ;
                    QString temp1 = locale.toString(total,'f',2);
                    ui->label_5->setText(temp1);
                    ui->label_3->setText(receipt);

                }else
                if ((columnmenu==3)&&(readbutton!=1)){
                    columnmenu ++;
                    ui->label_14->setText("LOẠI THẠCH !");
                    ui->label_11->setText("Pudding");
                    ui->label_12->setText("Đậu đỏ");
                    ui->label_13->setText("");
                    receipt.append(", Vị ")                    ;
                    switch (readbutton) {
                    case 2:     total+=5000; receipt.append("Caramel "); break;
                    case 3:     total+=6000; receipt.append("Chocolate "); break;
                    case 4:     total+=7000; receipt.append("Ô long "); break;
                    }
                    QLocale locale ;
                    QString temp1 = locale.toString(total,'f',2);
                    ui->label_5->setText(temp1);
                    ui->label_3->setText(receipt);
                }else
                if ((columnmenu==4)&&(readbutton!=1)){
                    columnmenu ++;
                    ui->label_14->setText("LƯỢNG THẠCH !");
                    ui->label_11->setText("Ít");
                    ui->label_12->setText("Vừa");
                    ui->label_13->setText("Nhiều");
                    receipt.append(", Thạch ")                    ;
                    switch (readbutton) {
                    case 2:     total+=5000; receipt.append("Pudding "); break;
                    case 3:     total+=6000; receipt.append("Đậu đỏ "); break;
                    }
                    QLocale locale ;
                    QString temp1 = locale.toString(total,'f',2);
                    ui->label_5->setText(temp1);
                    ui->label_3->setText(receipt);
                }else
                if ((columnmenu==5)&&(readbutton!=1)){
                    columnmenu ++;
                    ui->label_14->setText("LƯỢNG ĐƯỜNG !");
                    ui->label_11->setText("Ít");
                    ui->label_12->setText("Vừa");
                    ui->label_13->setText("Nhiều");
                    receipt.append(", ")                    ;
                    switch (readbutton) {
                    case 2:    total+=5000; receipt.append("Ít "); break;
                    case 3:    total+=7000; receipt.append("Vừa "); break;
                    case 4:    total+=10000; receipt.append("Nhiều "); break;
                    }
                    QLocale locale ;
                    QString temp1 = locale.toString(total,'f',2);
                    ui->label_5->setText(temp1);
                    receipt.append("thạch, ")                    ;
                    ui->label_3->setText(receipt);
                }else
                if ((columnmenu==6)&&(readbutton!=1)){
                    columnmenu ++;
                    ui->label_14->setText("LƯỢNG ĐÁ !");
                    ui->label_11->setText("Ít");
                    ui->label_12->setText("Vừa");
                    ui->label_13->setText("Nhiều");
                    switch (readbutton) {
                    case 2:     receipt.append("Ít "); break;
                    case 3:     receipt.append("Vừa "); break;
                    case 4:     receipt.append("Nhiều "); break;
                    }
                    receipt.append("đường, ")                    ;
                    ui->label_3->setText(receipt);
                }else
                    if ((columnmenu==7)&&(readbutton!=1)){
                        columnmenu ++;
                        isorderdone = true;
                        ui->label_10->setText("MỜI QUÝ KHÁCH ");
                        ui->label_14->setText("XÁC NHẬN ĐƠN HÀNG !");
                        ui->label_11->setText("");
                        QString temp1("Tổng cộng: ");
                        QLocale locale ;
                        QString temp2 = locale.toString(total,'f',2);
                        temp1.append(temp2);temp1.append(" VND.");
                        ui->label_12->setText(temp1);
                        ui->label_13->setText("");
                        switch (readbutton) {
                        case 2:     receipt.append("Ít "); break;
                        case 3:     receipt.append("Vừa "); break;
                        case 4:     receipt.append("Nhiều "); break;
                        }
                        receipt.append("đá.")                    ;
                        ui->label_3->setText(receipt);
                 }else
                    //Checkout btn pressed
                    if((readbutton==1)&&(isorderdone)){
                        checkouttimer->start(3000);
                        isorderdone = false;
                        ui->label_10->setText("MỜI QUÝ KHÁCH TÍNH TIỀN");
                        ui->label_14->setText("VÀ ĐỢI TRONG GIÂY LÁT!");
                        // Build json from menu

                        // Send json to uno
                    //            QString command = ui->lineEdit_3->text();
                                QString command;
                                command +="{";
                                QJsonDocument a = loadJson(fn);
                                QJsonObject b = a.object();
                                uint8_t indexx = 1;
                                foreach(const QString& key, b.keys()) {
                                    QJsonValue value1 = b.value(key);
                                    QString texttemp = key.simplified() +"="+ b.value(key).toString().simplified() ;
                                    command = command + "\"" +key.simplified() +"\"" +":"
                                                         "\"" ;command +=b.value(key).toString();command+= "\"" ;
                                    if(indexx!=b.keys().length())command= command +",";
                                    indexx++;
                                }
                                command +="}";
                                command.append("@");
                                this->serialports->write(command.toUtf8());
                                qDebug()<<command;
                                command.clear();

                                //Show in textbrowser
                                    *doc = loadJson(fn);
                                     json = doc->object();
                                    foreach(const QString& key, json.keys()) {
                                        QJsonValue value = json.value(key);
                                        QString texttemp = key.simplified() +"="+ json.value(key).toString().simplified() ;
                                        }
                    }

//                if ((columnmenu>=1)&&(columnmenu<=6)&&(readbutton!=4)&&(readbutton!=5)){
//                    columnmenu ++;
//                }
//                if((readbutton==4)&&(columnmenu==0)){
//                    ui->label_10->setText("PLEASE CHOOSE SIZE!");
//                    columnmenu++;
//                }else if((readbutton==4)&&(columnmenu=!0)) {
//                    columnmenu=0;
//                    ui->cbx01->setFont(normalfont);

//                }

                 readbutton = 0;
                ispush = false;
            }
}
void secondmain::checkcheckbox(bool a, QString b, QString c)
{
    if(a){
    QString *k = new  QString(b);
    QString *v = new  QString(c);
    json[*k]=*v;
    QJsonDocument temp(json);
    secondmain::saveJson(temp,fn);
    delete k;
    delete v;
    }
}

void secondmain::isr27()
{

}
void isr231(){
    if(digitalRead(21)){
        //delay(30);
        delayMicroseconds(10000);
        while(digitalRead(21)){}
        qDebug()<< "frombutton 21 ";
        readbutton = 1;ispush =true;
    }
}
void isr232(){
    if(digitalRead(22)){
        //delay(30);
        delayMicroseconds(10000);
        while(digitalRead(22)){}
        readbutton = 2;ispush =true;
        qDebug()<< "frombutton 22 ";
    }
}
void isr233(){
    if(digitalRead(23)){
        //delay(30);
        delayMicroseconds(10000);
        while(digitalRead(23)){}
        readbutton = 3;ispush =true;
        qDebug()<< "frombutton  23 ";
    }
}
void isr234(){
    if(digitalRead(24)){
        //delay(30);
        delayMicroseconds(10000);
        while(digitalRead(24)){}
        readbutton = 5;ispush =true;
        qDebug()<< "frombutton  25 ";
    }
}
void isr235(){
    if(digitalRead(25)){
        //delay(30);
        delayMicroseconds(10000);
        while(digitalRead(25)){}
        readbutton = 4;ispush =true;
        qDebug()<< "frombutton  24 ";
    }
}

secondmain::~secondmain()
{
    this->serialports->close();
    delete ui;
}

void secondmain::scanSerialPorts() //playeach 1 sec
{

         /*   qDebug()<< "Serialport1 IsReadable: " <<this->serialports->isReadable() <<"------ "
                    << "Serialport2 IsReadable: " <<this->serialports2->isReadable()
                    << "Serialport1 IsWriteable: " <<this->serialports->isWritable() <<"------ "
                     <<"Serialport2 IsWriteable: " <<this->serialports2->isWritable()
                       ;*/
            QStringList cbx1;
            QStringList cbx2;
            if(!serialconnected)
            {
                foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts())
                {
                    ui->comboBox->clear();
                    if(serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier())
                    {
                        cbx1.append(serialPortInfo.portName());
                    }
                    ui->comboBox->addItems(cbx1);
                }
            }
            if(!serialconnected2)
            {
                foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts())
                {
                    ui->comboBox_3->clear();
                    if(serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier())
                    {
                        cbx2.append(serialPortInfo.portName());
                    }
                    ui->comboBox_3->addItems(cbx2);
                }
            }
}
void secondmain::on_comboBox_activated(QString index)
{
    qDebug()<< "abc" << index << endl;
    QString failed = "Connect failed";
    portname = index;
    serialconnected=true;
    qDebug ()<<index;
    if(serialconnected)
    {
        this->serialports->setPortName(portname);
        this->serialports->open(QIODevice::ReadWrite);
        this->serialports->setBaudRate(QSerialPort::Baud115200);
        this->serialports->setDataBits(QSerialPort::Data8);
        this->serialports->setParity(QSerialPort::NoParity);
        this->serialports->setStopBits(QSerialPort::OneStop);
        this->serialports->setFlowControl(QSerialPort::NoFlowControl);

        qDebug() << "Serialconnected" <<endl;
        connect(this->serialports,&QSerialPort::errorOccurred,[=](QSerialPort::SerialPortError error){
            qDebug() <<"Error occurred: " << error;
        });
        QMessageBox m;
        int ret = m.information(this,"Notification","Connected to "+index,QMessageBox::Close);
    }
}

void secondmain::serialreceiverr()
{
    QByteArray data;
    data = this->serialports->readAll();
//    qDebug()<<data;
}



//Json block
void secondmain::on_pushButton_clicked()
{

    *doc = loadJson(fn);
     json = doc->object();
    foreach(const QString& key, json.keys()) {
        QJsonValue value = json.value(key);
        QString texttemp = key.simplified() +"="+ json.value(key).toString().simplified() ;
//        qDebug() << "Key = " << key << ", Value = " << value.toString();
        }
}
//void secondmain::on_pushButton_2_clicked()
//{
//    QString *k = new  QString();//(ui->lineEdit->text());
//    QString *v = new  QString();//(ui->lineEdit_2->text());
//    json[*k]=*v;
//    QJsonDocument temp(json);
//    secondmain::saveJson(temp,fn);
//    delete k;
//    delete v;
//}
QJsonDocument secondmain::loadJson(QString fileName) {
    QFile jsonFile(fileName);
    jsonFile.open(QFile::ReadOnly);
    return QJsonDocument().fromJson(jsonFile.readAll());
}
void secondmain::saveJson(QJsonDocument document, QString fileName) {
    QFile jsonFile(fileName);
    jsonFile.open(QFile::WriteOnly);
    jsonFile.write(document.toJson());
    qDebug() << "Added";
}


void secondmain::on_pushButton_3_clicked()
{
}


// End Json



