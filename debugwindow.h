#ifndef DEBUGWINDOW_H
#define DEBUGWINDOW_H

#include <QMainWindow>
#include <QJsonDocument>
#include <QtSerialPort>
namespace Ui {
class debugwindow;
}

class debugwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit debugwindow(QWidget *parent = nullptr);
    ~debugwindow();
    QJsonDocument loadJson(QString fileName);
    void saveJson(QJsonDocument document, QString fileName);
    QSerialPort *serialports;
    QSerialPort *serialports2;

private slots:
    void scanSerialPorts();
    void on_comboBox_activated(QString index);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();
    void serialreceiverr();

    void on_comboBox_3_activated(const QString index);

private:
    Ui::debugwindow *ui;
};

#endif // DEBUGWINDOW_H
