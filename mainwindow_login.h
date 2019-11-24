#ifndef MAINWINDOW_LOGIN_H
#define MAINWINDOW_LOGIN_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow_login; }
QT_END_NAMESPACE

class MainWindow_login : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow_login(QWidget *parent = nullptr);
    ~MainWindow_login();

private slots:
    void entermainwindows();

private:
    Ui::MainWindow_login *ui;
};
#endif // MAINWINDOW_LOGIN_H
