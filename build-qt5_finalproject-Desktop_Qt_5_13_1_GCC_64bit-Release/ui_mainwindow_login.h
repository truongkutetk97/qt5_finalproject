/********************************************************************************
** Form generated from reading UI file 'mainwindow_login.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_LOGIN_H
#define UI_MAINWINDOW_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow_login
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QFrame *formFrame;
    QFormLayout *formLayout;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow_login)
    {
        if (MainWindow_login->objectName().isEmpty())
            MainWindow_login->setObjectName(QString::fromUtf8("MainWindow_login"));
        MainWindow_login->resize(664, 425);
        centralwidget = new QWidget(MainWindow_login);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 98, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        formFrame = new QFrame(centralwidget);
        formFrame->setObjectName(QString::fromUtf8("formFrame"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(formFrame->sizePolicy().hasHeightForWidth());
        formFrame->setSizePolicy(sizePolicy);
        formFrame->setStyleSheet(QString::fromUtf8("#formFrame\n"
"{\n"
"border: 1px solid grey;\n"
"border-radius: 5px;\n"
"background-color: white;\n"
"}"));
        formLayout = new QFormLayout(formFrame);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(25, 25, 25, 25);
        label_3 = new QLabel(formFrame);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(formFrame);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_4);

        lineEdit_2 = new QLineEdit(formFrame);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setMinimumSize(QSize(150, 25));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_2);

        lineEdit = new QLineEdit(formFrame);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMinimumSize(QSize(150, 25));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit);


        horizontalLayout->addWidget(formFrame);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(196, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(260, 35));
        pushButton->setStyleSheet(QString::fromUtf8("border: 1px solid rgb(24, 103, 155);\n"
"border-radius: 5px;\n"
"background-color: rgb(124, 203, 255);\n"
"color: white;"));

        horizontalLayout_2->addWidget(pushButton);

        horizontalSpacer_4 = new QSpacerItem(196, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 97, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        MainWindow_login->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow_login);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 664, 21));
        MainWindow_login->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow_login);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow_login->setStatusBar(statusbar);

        retranslateUi(MainWindow_login);

        QMetaObject::connectSlotsByName(MainWindow_login);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow_login)
    {
        MainWindow_login->setWindowTitle(QCoreApplication::translate("MainWindow_login", "MainWindow_login", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow_login", "Username:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow_login", "Password:", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow_login", "LOGIN", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow_login: public Ui_MainWindow_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_LOGIN_H
