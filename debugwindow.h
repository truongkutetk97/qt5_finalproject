#ifndef DEBUGWINDOW_H
#define DEBUGWINDOW_H

#include <QMainWindow>

namespace Ui {
class debugwindow;
}

class debugwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit debugwindow(QWidget *parent = nullptr);
    ~debugwindow();

private:
    Ui::debugwindow *ui;
};

#endif // DEBUGWINDOW_H
