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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_secondmain
{
public:
    QWidget *centralwidget;
    QComboBox *comboBox;
    QLabel *label;
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
        comboBox->setGeometry(QRect(270, 130, 69, 22));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(360, 140, 47, 13));
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
        label->setText(QCoreApplication::translate("secondmain", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class secondmain: public Ui_secondmain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECONDMAIN_H
