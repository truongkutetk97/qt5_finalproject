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

static QByteArray serialbuffer;
static QString serialoutput ;
void isr231();
secondmain::secondmain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::secondmain)
{
    wiringPiSetup();
    pinMode(1, OUTPUT);
    pullUpDnControl(1,PUD_DOWN);
    wiringPiISR(1,INT_EDGE_RISING,isr231);

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
    // logout button in menu bar, back to mainwindow
    connect(logoutaction,&QAction::triggered,[=](){
        this->hide();
        MainWindow_login *w = new MainWindow_login();
        w->show();
    });
    // file menubar block
    connect(readfile,&QAction::triggered,[&](){
        ui->textBrowser->clear();
        *doc = loadJson(fn);
         json = doc->object();
        foreach(const QString& key, json.keys()) {
            QJsonValue value = json.value(key);
            QString texttemp = key.simplified() +"="+ json.value(key).toString().simplified() ;
            ui->textBrowser->append(texttemp);
    //        qDebug() << "Key = " << key << ", Value = " << value.toString();
            }
    });
    connect(addline,&QAction::triggered,[&](){
    });
    connect(clear,&QAction::triggered,[&](){
    ui->textBrowser->clear();
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
    //    ui->statusbar->hide();  //this should be uncomment at run mode
    QFont buttonFont("Times", 20, QFont::Bold);
    QTimer *timer = new QTimer(this);
    // TImer serial scan
    connect(timer,SIGNAL(timeout()) ,this,SLOT(scanSerialPorts()));

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
            this->ui->textBrowser->hide();
            filemenu->clear();
        }else {
            this->ui->textBrowser->show();
            filemenu->addAction(readfile);
            filemenu->addAction(addline);
            filemenu->addAction(clear);
        }
    });
    // Handle menu and Send json to uno
    connect(ui->pushButton,&QPushButton::clicked,[=](){ //send
    // Build json from menu
        this->checkcheckbox(ui->cbx01->isChecked(),"size","1");
        this->checkcheckbox(ui->cbx02->isChecked(),"size","2");
        this->checkcheckbox(ui->cbx11->isChecked(),"syrup","1");
        this->checkcheckbox(ui->cbx12->isChecked(),"syrup","2");
        this->checkcheckbox(ui->cbx13->isChecked(),"syrup","3");
        this->checkcheckbox(ui->cbx21->isChecked(),"toptype","1");
        this->checkcheckbox(ui->cbx22->isChecked(),"toptype","2");
        this->checkcheckbox(ui->cbx31->isChecked(),"toplevel","1");
        this->checkcheckbox(ui->cbx32->isChecked(),"toplevel","2");
        this->checkcheckbox(ui->cbx33->isChecked(),"toplevel","3");
        this->checkcheckbox(ui->cbx41->isChecked(),"sugar","1");
        this->checkcheckbox(ui->cbx42->isChecked(),"sugar","2");
        this->checkcheckbox(ui->cbx43->isChecked(),"sugar","3");
        this->checkcheckbox(ui->cbx51->isChecked(),"ice","1");
        this->checkcheckbox(ui->cbx52->isChecked(),"ice","2");
        this->checkcheckbox(ui->cbx53->isChecked(),"ice","3");

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
                ui->textBrowser->clear();
                *doc = loadJson(fn);
                 json = doc->object();
                foreach(const QString& key, json.keys()) {
                    QJsonValue value = json.value(key);
                    QString texttemp = key.simplified() +"="+ json.value(key).toString().simplified() ;
                    ui->textBrowser->append(texttemp);
                    }

    });


    timer->start(1000);
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
    if(digitalRead(1)){
        //delay(30);
        delayMicroseconds(10000);
        while(digitalRead(1)){}
        qDebug()<< "frombutton";
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
    ui->textBrowser->clear();
}


// End Json



