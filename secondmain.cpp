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
static QJsonDocument   *doc =new QJsonDocument();
static QString fn = "/home/truongdeptrai/Documents/FINALPROJECT_QT5/qt5_finalproject/test.json";
static QJsonObject json;
static QString portname;
static bool serialconnected = false;
static QByteArray serialbuffer;
static QString serialoutput ;
secondmain::secondmain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::secondmain)
{
    ui->setupUi(this);
    this->serialports= new QSerialPort(this);
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

    QFont buttonFont("Times", 20, QFont::Bold);
    QTimer *timer = new QTimer(this);
//    serial.open(QIODevice::ReadWrite);
    connect(timer,SIGNAL(timeout()),this,SLOT(scanSerialPorts()));
    connect(this->serialports,&QSerialPort::readyRead,this,&secondmain::serialreceiverr);
    connect(ui->pushButton_6,&QPushButton::clicked,[=](){
        ui->textBrowser_2->clear();
    });
    connect(ui->pushButton_4,&QPushButton::clicked,[=](){ //send
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

    });
    timer->start(1000);
}

secondmain::~secondmain()
{
    this->serialports->close();
    delete ui;
}

void secondmain::scanSerialPorts()
{
    if(1){
    QStringList cbx;
        foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
            ui->comboBox->clear();
            if(serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier()){
                cbx.append(serialPortInfo.portName());
             }        ui->comboBox->addItems(cbx);
        }
    }
}
void secondmain::on_comboBox_activated(QString index)
{
    qDebug()<< "abc" << index << endl;
    QString failed = "Connect failed";
  /*  foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
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
        int ret = m.information(this,"Notification","Connected",QMessageBox::Close);
    }
}

void secondmain::serialreceiverr()
{
    QByteArray data;
    data = this->serialports->readAll();
    ui->textBrowser_2->append(data);
//    qDebug()<<data;
}



//Json block
void secondmain::on_pushButton_clicked()
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
void secondmain::on_pushButton_2_clicked()
{
    QString *k = new  QString(ui->lineEdit->text());
    QString *v = new  QString(ui->lineEdit_2->text());
    json[*k]=*v;
    QJsonDocument temp(json);
    secondmain::saveJson(temp,fn);
    delete k;
    delete v;
}
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
    ui->textBrowser->clear();
}


// End Json



