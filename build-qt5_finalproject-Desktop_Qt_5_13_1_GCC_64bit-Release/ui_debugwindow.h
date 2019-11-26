/********************************************************************************
** Form generated from reading UI file 'debugwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEBUGWINDOW_H
#define UI_DEBUGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_debugwindow
{
public:
    QWidget *centralwidget;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QTextBrowser *textBrowser;
    QTextBrowser *textBrowser_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_6;
    QComboBox *comboBox_3;
    QPushButton *pushButton_5;
    QPushButton *pushButton_7;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *debugwindow)
    {
        if (debugwindow->objectName().isEmpty())
            debugwindow->setObjectName(QString::fromUtf8("debugwindow"));
        debugwindow->resize(582, 414);
        centralwidget = new QWidget(debugwindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(90, 320, 86, 25));
        comboBox_2 = new QComboBox(centralwidget);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(250, 300, 86, 25));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(350, 320, 67, 17));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(-10, 30, 113, 25));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(110, 30, 113, 25));
        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(290, 60, 113, 25));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(20, 150, 221, 131));
        textBrowser_2 = new QTextBrowser(centralwidget);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(320, 150, 181, 131));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(30, 70, 89, 25));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(210, 30, 89, 25));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(120, 70, 89, 25));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(410, 60, 89, 25));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(490, 20, 89, 25));
        comboBox_3 = new QComboBox(centralwidget);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setGeometry(QRect(150, 300, 86, 25));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(420, 120, 89, 25));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(410, 90, 89, 25));
        lineEdit_4 = new QLineEdit(centralwidget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(290, 90, 113, 25));
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(500, 60, 89, 25));
        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(500, 90, 89, 25));
        debugwindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(debugwindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 582, 22));
        debugwindow->setMenuBar(menubar);
        statusbar = new QStatusBar(debugwindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        debugwindow->setStatusBar(statusbar);

        retranslateUi(debugwindow);

        QMetaObject::connectSlotsByName(debugwindow);
    } // setupUi

    void retranslateUi(QMainWindow *debugwindow)
    {
        debugwindow->setWindowTitle(QCoreApplication::translate("debugwindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("debugwindow", "TextLabel", nullptr));
        pushButton->setText(QCoreApplication::translate("debugwindow", "readfile", nullptr));
        pushButton_2->setText(QCoreApplication::translate("debugwindow", "add", nullptr));
        pushButton_3->setText(QCoreApplication::translate("debugwindow", "clear", nullptr));
        pushButton_4->setText(QCoreApplication::translate("debugwindow", "send1", nullptr));
        pushButton_6->setText(QCoreApplication::translate("debugwindow", "clear", nullptr));
        pushButton_5->setText(QCoreApplication::translate("debugwindow", "readstate", nullptr));
        pushButton_7->setText(QCoreApplication::translate("debugwindow", "send2", nullptr));
        pushButton_8->setText(QCoreApplication::translate("debugwindow", "send1", nullptr));
        pushButton_9->setText(QCoreApplication::translate("debugwindow", "send2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class debugwindow: public Ui_debugwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEBUGWINDOW_H
