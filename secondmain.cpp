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
static QJsonDocument   *doc =new QJsonDocument();
static QString fn = "C:/Users/truongdeptrai/Documents/qt5_finalproject/test.json";
static QJsonObject json;
static QString portname;
static bool serialconnected = false;

secondmain::secondmain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::secondmain)
{
    ui->setupUi(this);
    this->serialports= new QSerialPort;
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

//    connect(ui->label,&QLabel::,[=](){
//    QMessageBox m;
//    int ret = m.information(this,"truongdeptraititle","truongdeptraitext",QMessageBox::Open|QMessageBox::Save);
//    });
    timer->start(1000);
}

secondmain::~secondmain()
{
    delete ui;
}

void secondmain::scanSerialPorts()
{

    if(!serialconnected){
    QStringList cbx;
        foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
            ui->comboBox->clear();
            if(serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier()){
                if(serialPortInfo.productIdentifier()==29987) cbx.append("CH340");
                if(serialPortInfo.productIdentifier()==6000) cbx.append("CP210x");
                if(serialPortInfo.productIdentifier()==67) cbx.append("ATMEGA8");
                if((serialPortInfo.productIdentifier()!=6000)
                        &&(serialPortInfo.productIdentifier()!=29987)
                        &&(serialPortInfo.productIdentifier()!=67))
                    cbx.append(QString::number(serialPortInfo.productIdentifier()));
//                qDebug() << "scanning";
            }
            //        for(int i =0; i<QSerialPortInfo::availablePorts().size();i++ ){
            //        ui->cbx1->insertItems(i,cbx.at(i));
            //        }
        }        ui->comboBox->addItems(cbx);
    }
}
void secondmain::on_comboBox_activated(int index)
{
    qDebug()<< "abc" << index << endl;
    QString failed = "Connect failed";


    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
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
    }
    if(serialconnected)
    {
        this->serialports->setPortName(portname);
        this->serialports->setBaudRate(QSerialPort::Baud115200);
        this->serialports->setDataBits(QSerialPort::Data8);

        this->serialports->setParity(QSerialPort::NoParity);
        this->serialports->setStopBits(QSerialPort::OneStop);
        this->serialports->setFlowControl(QSerialPort::NoFlowControl);
        this->serialports->open(QIODevice::ReadWrite);
        qDebug() << "Serialconnected" <<endl;
        connect(this->serialports, &QSerialPort::readyRead, this, &secondmain::serialreceiverr);


    }
}

void secondmain::on_pushButton_4_clicked()
{
    this->serialports->open(QIODevice::ReadWrite);
    QString command = ui->lineEdit_3->text();
    command.append("\n");
    this->serialports->write(command.toUtf8());
    this->serialports->waitForBytesWritten(10);
    command.clear();
}
void secondmain::on_comboBox_currentIndexChanged(int index)
{



}
void secondmain::serialreceiverr()
{
    QByteArray data;
    data = this->serialports->readAll();
    qDebug()<<data;
    qDebug() <<"Serialreceiver";
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
        qDebug() << "Key = " << key << ", Value = " << value.toString();
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



