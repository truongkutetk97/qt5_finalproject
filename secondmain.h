#ifndef SECONDMAIN_H
#define SECONDMAIN_H

#include <QMainWindow>
#include <QJsonDocument>
#include <QtSerialPort>

namespace Ui {
class secondmain;
}

class secondmain : public QMainWindow
{
    Q_OBJECT

public:


    explicit secondmain(QWidget *parent = nullptr);
    ~secondmain();
    QJsonDocument loadJson(QString fileName);
    void saveJson(QJsonDocument document, QString fileName);
    QSerialPort *serialports;
    QSerialPort *serialports2;
    void checkcheckbox(bool a,QString b,QString c) ;
     void isr27();
private slots:
    void scanSerialPorts();
    void on_comboBox_activated(QString index);

    void on_pushButton_clicked();

//    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();
    void serialreceiverr();

private:
    Ui::secondmain *ui;
};

#endif // SECONDMAIN_H
