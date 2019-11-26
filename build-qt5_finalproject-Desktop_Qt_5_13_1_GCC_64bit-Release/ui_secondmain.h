/********************************************************************************
** Form generated from reading UI file 'secondmain.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECONDMAIN_H
#define UI_SECONDMAIN_H

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

class Ui_secondmain
{
public:
    QWidget *centralwidget;
    QComboBox *comboBox;
    QLabel *label;
    QPushButton *pushButton;
    QTextBrowser *textBrowser;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QTextBrowser *textBrowser_2;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_4;
    QComboBox *comboBox_2;
    QPushButton *pushButton_6;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *secondmain)
    {
        if (secondmain->objectName().isEmpty())
            secondmain->setObjectName(QString::fromUtf8("secondmain"));
        secondmain->resize(800, 600);
        centralwidget = new QWidget(secondmain);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(160, 570, 69, 22));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(260, 570, 47, 13));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(90, 40, 75, 23));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(0, 70, 256, 192));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 10, 81, 20));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(100, 10, 81, 20));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(190, 10, 75, 23));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(170, 40, 75, 23));
        textBrowser_2 = new QTextBrowser(centralwidget);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(380, 70, 256, 192));
        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(400, 30, 151, 20));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(570, 30, 75, 23));
        comboBox_2 = new QComboBox(centralwidget);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(80, 570, 69, 22));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(670, 70, 75, 23));
        secondmain->setCentralWidget(centralwidget);
        menubar = new QMenuBar(secondmain);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        secondmain->setMenuBar(menubar);
        statusbar = new QStatusBar(secondmain);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        secondmain->setStatusBar(statusbar);

        retranslateUi(secondmain);

        QMetaObject::connectSlotsByName(secondmain);
    } // setupUi

    void retranslateUi(QMainWindow *secondmain)
    {
        secondmain->setWindowTitle(QCoreApplication::translate("secondmain", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("secondmain", "TextLabel", nullptr));
        pushButton->setText(QCoreApplication::translate("secondmain", "Readfile", nullptr));
        pushButton_2->setText(QCoreApplication::translate("secondmain", "Add", nullptr));
        pushButton_3->setText(QCoreApplication::translate("secondmain", "Clear", nullptr));
        pushButton_4->setText(QCoreApplication::translate("secondmain", "Send", nullptr));
        pushButton_6->setText(QCoreApplication::translate("secondmain", "Clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class secondmain: public Ui_secondmain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECONDMAIN_H
