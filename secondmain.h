#ifndef SECONDMAIN_H
#define SECONDMAIN_H

#include <QMainWindow>
#include <QJsonDocument>

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
private slots:
    void scanSerialPorts();
    void on_comboBox_activated(int index);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::secondmain *ui;
};

#endif // SECONDMAIN_H
