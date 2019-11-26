#include "debugwindow.h"
#include "ui_debugwindow.h"
#include <QMenuBar>
#include <QStatusBar>
#include <QDebug>
#include <QAction>
#include <QApplication>

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
#include "mainwindow_login.h"

static QJsonDocument   *doc =new QJsonDocument();
static QString fn = "/home/truongdeptrai/Documents/FINALPROJECT_QT5/qt5_finalproject/test.json";
static QJsonObject json;
static QString portname;
static QString portname2;

static bool serialconnected = false;

static bool serialconnected2 = false;
static QByteArray serialbuffer;
static QString serialoutput ;
debugwindow::debugwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::debugwindow)
{
    ui->setupUi(this);
    this->serialports= new QSerialPort(this);
    this->serialports2 = new QSerialPort(this);
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


    ui->label->setMinimumWidth(100);
    ui->label->setText("Not connected");
    ui->statusbar->addPermanentWidget(ui->label);
    ui->statusbar->addPermanentWidget(ui->comboBox_2);
    ui->comboBox_2->addItem("9600",9600);
    ui->comboBox_2->addItem("115200",115200);
    ui->statusbar->addPermanentWidget(ui->comboBox);
    ui->statusbar->addPermanentWidget(ui->comboBox_3);

    QFont buttonFont("Times", 20, QFont::Bold);
    QTimer *timer = new QTimer(this);
//    serial.open(QIODevice::ReadWrite);
    connect(timer,SIGNAL(timeout()),this,SLOT(scanSerialPorts()));
    connect(this->serialports,&QSerialPort::readyRead,this,&debugwindow::serialreceiverr);
    connect(this->serialports2,&QSerialPort::readyRead,[=](){
        QByteArray data;
        data = this->serialports2->readAll();
        ui->textBrowser_2->append(data);
    });
    connect(ui->pushButton_6,&QPushButton::clicked,[=](){
        ui->textBrowser_2->clear();
    });
    connect(ui->pushButton_5,&QPushButton::clicked,[=](){
        QString temp(this->serialports->isOpen());
        qDebug()<< "Serialport 1 : " <<this->serialports->isOpen() <<"------ "
                << "Serialport 2 : " <<this->serialports2->isOpen();
    });
    connect(ui->pushButton_4,&QPushButton::clicked,[=](){ //send
        QString commandd = "1";
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
            commandd.append("@");

            this->serialports->write(commandd.toUtf8());
            qDebug()<<commandd;
            command.clear();

    });
    connect(ui->pushButton_8,&QPushButton::clicked,[=](){
        QString commandd = "0";
        commandd.append("@");
        this->serialports->write(commandd.toUtf8());
    });
    connect(ui->pushButton_9,&QPushButton::clicked,[=](){
        QString commandd = "0";
        commandd.append("@");
        this->serialports2->write(commandd.toUtf8());
    });
    connect(ui->pushButton_7,&QPushButton::clicked,[=](){ //send2
            QString commandd = ui->lineEdit_4->text();
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
            commandd.append("@");
            this->serialports2->write(commandd.toUtf8());
            qDebug()<<commandd;
            command.clear();

    });
    timer->start(1000);

}

debugwindow::~debugwindow()
{
    delete ui;
}

void debugwindow::scanSerialPorts()
{
    qDebug()<< "Serialport1 IsReadable: " <<this->serialports->isReadable() <<"------ "
            << "Serialport2 IsReadable: " <<this->serialports2->isReadable()
            << "Serialport1 IsWriteable: " <<this->serialports->isWritable() <<"------ "
             <<"Serialport2 IsWriteable: " <<this->serialports2->isWritable()
               ;


   // if(!(serialconnected&&serialconnected2)){
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
void debugwindow::on_comboBox_activated(QString index)
{
    qDebug()<< "abc" << index << endl;
    QString failed = "Connect failed";
    /*foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        if(serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier()){
            if(serialPortInfo.productIdentifier()==29987)
            {
                QString connected = "Connected to ";
                connected.append("CH340");
                ui->label->setText(connected);
                portname = serialPortInfo.portName();
                serialconnected = true;
            }
            else if(serialPortInfo.productIdentifier()==60000)
            {
                QString connected = "Connected to ";
                connected.append("CP210x");
                ui->label->setText(connected);
                portname = serialPortInfo.portName();
                serialconnected = true;
            }
            else ui->label->setText(failed);
        }
    }*/
    portname = index;
    serialconnected= true;
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
        int ret = m.information(this,"Notification","Connected" + index ,QMessageBox::Close);
    }
}
void debugwindow::on_comboBox_3_activated(const QString index)
{
    qDebug()<< "abc" << index << endl;
    QString failed = "Connect failed";
    /*foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        if(serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier()){
            if(serialPortInfo.productIdentifier()==29987)
            {
                QString connected = "Connected to ";
                connected.append("CH340");
                ui->label->setText(connected);
                portname = serialPortInfo.portName();
                serialconnected = true;
            }
            else if(serialPortInfo.productIdentifier()==60000)
            {
                QString connected = "Connected to ";
                connected.append("CP210x");
                ui->label->setText(connected);
                portname = serialPortInfo.portName();
                serialconnected = true;
            }
            else ui->label->setText(failed);
        }
    }*/
    portname2 = index;
    serialconnected2= true;
    if(serialconnected2)
    {
        this->serialports2 ->setPortName(portname2);
        this->serialports2->open(QIODevice::ReadWrite);
        this->serialports2->setBaudRate(QSerialPort::Baud115200);
        this->serialports2->setDataBits(QSerialPort::Data8);
        this->serialports2->setParity(QSerialPort::NoParity);
        this->serialports2->setStopBits(QSerialPort::OneStop);
        this->serialports2->setFlowControl(QSerialPort::NoFlowControl);

        qDebug() << "Serialconnected" <<endl;
        connect(this->serialports2,&QSerialPort::errorOccurred,[=](QSerialPort::SerialPortError error){
            qDebug() <<"Error occurred: " << error;
        });
        QMessageBox m;
        int ret = m.information(this,"Notification","Connected" + index ,QMessageBox::Close);
    }
}
void debugwindow::serialreceiverr()
{
    QByteArray data;
    data = this->serialports->readAll();
    ui->textBrowser_2->append(data);
//    qDebug()<<data;
}



//Json block
void debugwindow::on_pushButton_clicked()
{
    ui->textBrowser->clear();

    *doc = loadJson(fn);
     json = doc->object();
    foreach(const QString& key, json.keys()) {
        QJsonValue value = json.value(key);
        QString texttemp = key.simplified() +"="+ json.value(key).toString().simplified() ;
        ui->textBrowser->append(texttemp);
//        qDebug() << "Key = " << key << ", Value = " << value.toString();
    }
}
void debugwindow::on_pushButton_2_clicked()
{
    QString *k = new  QString(ui->lineEdit->text());
    QString *v = new  QString(ui->lineEdit_2->text());
    json[*k]=*v;
    QJsonDocument temp(json);
    debugwindow::saveJson(temp,fn);
    delete k;
    delete v;
}
QJsonDocument debugwindow::loadJson(QString fileName) {
    QFile jsonFile(fileName);
    jsonFile.open(QFile::ReadOnly);
    return QJsonDocument().fromJson(jsonFile.readAll());
}
void debugwindow::saveJson(QJsonDocument document, QString fileName) {
    QFile jsonFile(fileName);
    jsonFile.open(QFile::WriteOnly);
    jsonFile.write(document.toJson());
    qDebug() << "Added";
}
void debugwindow::on_pushButton_3_clicked()
{
    ui->textBrowser->clear();
}


