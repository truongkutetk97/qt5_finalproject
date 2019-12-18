/********************************************************************************
** Form generated from reading UI file 'secondmain.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
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
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_secondmain
{
public:
    QWidget *centralwidget;
    QComboBox *comboBox;
    QLabel *label;
    QComboBox *comboBox_2;
    QComboBox *comboBox_3;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;
    QToolBar *toolBar_2;

    void setupUi(QMainWindow *secondmain)
    {
        if (secondmain->objectName().isEmpty())
            secondmain->setObjectName(QStringLiteral("secondmain"));
        secondmain->resize(1284, 966);
        secondmain->setMinimumSize(QSize(811, 0));
        centralwidget = new QWidget(secondmain);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(120, 880, 69, 22));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(220, 880, 47, 13));
        comboBox_2 = new QComboBox(centralwidget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(40, 880, 69, 22));
        comboBox_3 = new QComboBox(centralwidget);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));
        comboBox_3->setGeometry(QRect(400, 880, 86, 25));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(20, 120, 1261, 71));
        QFont font;
        font.setPointSize(36);
        label_10->setFont(font);
        label_10->setAlignment(Qt::AlignCenter);
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(410, 330, 481, 81));
        label_11->setFont(font);
        label_11->setStyleSheet(QStringLiteral("color: rgb(255, 85, 0);"));
        label_11->setAlignment(Qt::AlignCenter);
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(240, 460, 831, 81));
        label_12->setFont(font);
        label_12->setStyleSheet(QLatin1String("color: rgb(29, 29, 255);\n"
""));
        label_12->setAlignment(Qt::AlignCenter);
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(410, 580, 481, 81));
        label_13->setFont(font);
        label_13->setStyleSheet(QStringLiteral("color:rgb(42, 116, 46);"));
        label_13->setAlignment(Qt::AlignCenter);
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(20, 200, 1261, 71));
        label_14->setFont(font);
        label_14->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(100, 720, 151, 71));
        QFont font1;
        font1.setPointSize(20);
        label_2->setFont(font1);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(220, 720, 1081, 71));
        label_3->setFont(font1);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(100, 770, 151, 71));
        label_4->setFont(font1);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(250, 770, 151, 71));
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(420, 770, 151, 71));
        label_6->setFont(font1);
        secondmain->setCentralWidget(centralwidget);
        menubar = new QMenuBar(secondmain);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1284, 20));
        secondmain->setMenuBar(menubar);
        statusbar = new QStatusBar(secondmain);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        secondmain->setStatusBar(statusbar);
        toolBar = new QToolBar(secondmain);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        secondmain->addToolBar(Qt::TopToolBarArea, toolBar);
        toolBar_2 = new QToolBar(secondmain);
        toolBar_2->setObjectName(QStringLiteral("toolBar_2"));
        secondmain->addToolBar(Qt::TopToolBarArea, toolBar_2);

        retranslateUi(secondmain);

        QMetaObject::connectSlotsByName(secondmain);
    } // setupUi

    void retranslateUi(QMainWindow *secondmain)
    {
        secondmain->setWindowTitle(QApplication::translate("secondmain", "MainWindow", nullptr));
        label->setText(QApplication::translate("secondmain", "TextLabel", nullptr));
        label_10->setText(QApplication::translate("secondmain", "CH\303\200O QU\303\235 KH\303\201CH!", nullptr));
        label_11->setText(QApplication::translate("secondmain", "L", nullptr));
        label_12->setText(QApplication::translate("secondmain", "XL", nullptr));
        label_13->setText(QApplication::translate("secondmain", "XXL", nullptr));
        label_14->setText(QApplication::translate("secondmain", "NH\341\272\244N N\303\232T B\341\272\244T K\341\273\262 \304\220\341\273\202 B\341\272\256T \304\220\341\272\246U CH\341\273\214N M\303\223N!", nullptr));
        label_2->setText(QApplication::translate("secondmain", "Tr\303\240 s\341\273\257a :", nullptr));
        label_3->setText(QApplication::translate("secondmain", "Size XXL", nullptr));
        label_4->setText(QApplication::translate("secondmain", "Th\303\240nh ti\341\273\201n:", nullptr));
        label_5->setText(QApplication::translate("secondmain", "50000.00", nullptr));
        label_6->setText(QApplication::translate("secondmain", "VND", nullptr));
        toolBar->setWindowTitle(QApplication::translate("secondmain", "toolBar", nullptr));
        toolBar_2->setWindowTitle(QApplication::translate("secondmain", "toolBar_2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class secondmain: public Ui_secondmain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECONDMAIN_H
