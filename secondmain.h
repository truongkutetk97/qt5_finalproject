#ifndef SECONDMAIN_H
#define SECONDMAIN_H

#include <QMainWindow>

namespace Ui {
class secondmain;
}

class secondmain : public QMainWindow
{
    Q_OBJECT

public:
    explicit secondmain(QWidget *parent = nullptr);
    ~secondmain();
private slots:
    void scanSerialPorts();
    void on_comboBox_activated(int index);

private:
    Ui::secondmain *ui;
};

#endif // SECONDMAIN_H
