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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_secondmain
{
public:
    QWidget *centralwidget;
    QPushButton *btn;
    QToolButton *toolButton;
    QRadioButton *radioButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *secondmain)
    {
        if (secondmain->objectName().isEmpty())
            secondmain->setObjectName(QString::fromUtf8("secondmain"));
        secondmain->resize(800, 600);
        centralwidget = new QWidget(secondmain);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        btn = new QPushButton(centralwidget);
        btn->setObjectName(QString::fromUtf8("btn"));
        btn->setGeometry(QRect(290, 170, 75, 23));
        toolButton = new QToolButton(centralwidget);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(420, 200, 25, 19));
        radioButton = new QRadioButton(centralwidget);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(330, 220, 82, 17));
        secondmain->setCentralWidget(centralwidget);
        menubar = new QMenuBar(secondmain);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
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
        btn->setText(QCoreApplication::translate("secondmain", "PushButton", nullptr));
        toolButton->setText(QCoreApplication::translate("secondmain", "...", nullptr));
        radioButton->setText(QCoreApplication::translate("secondmain", "RadioButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class secondmain: public Ui_secondmain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECONDMAIN_H
