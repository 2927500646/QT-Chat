/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *statusLabel;
    QLineEdit *ipEdit;
    QPushButton *connectButton;
    QTextEdit *chatDisplay;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *messageEdit;
    QPushButton *sendButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(621, 700);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        widget = new QWidget(centralWidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 10, 601, 631));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        statusLabel = new QLabel(widget);
        statusLabel->setObjectName("statusLabel");

        horizontalLayout_5->addWidget(statusLabel);

        ipEdit = new QLineEdit(widget);
        ipEdit->setObjectName("ipEdit");

        horizontalLayout_5->addWidget(ipEdit);

        connectButton = new QPushButton(widget);
        connectButton->setObjectName("connectButton");

        horizontalLayout_5->addWidget(connectButton);


        verticalLayout_3->addLayout(horizontalLayout_5);

        chatDisplay = new QTextEdit(widget);
        chatDisplay->setObjectName("chatDisplay");

        verticalLayout_3->addWidget(chatDisplay);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        messageEdit = new QLineEdit(widget);
        messageEdit->setObjectName("messageEdit");
        messageEdit->setMinimumSize(QSize(0, 50));
        messageEdit->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_2->addWidget(messageEdit);

        sendButton = new QPushButton(widget);
        sendButton->setObjectName("sendButton");
        sendButton->setMinimumSize(QSize(80, 50));
        sendButton->setMaximumSize(QSize(80, 50));

        horizontalLayout_2->addWidget(sendButton);


        verticalLayout_3->addLayout(horizontalLayout_2);

        MainWindow->setCentralWidget(centralWidget);
        widget->raise();
        widget->raise();
        widget->raise();
        messageEdit->raise();
        sendButton->raise();
        ipEdit->raise();
        connectButton->raise();
        chatDisplay->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 621, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        statusLabel->setText(QCoreApplication::translate("MainWindow", "\346\234\215\345\212\241\345\231\250IP:", nullptr));
        connectButton->setText(QCoreApplication::translate("MainWindow", "\350\277\236\346\216\245", nullptr));
        sendButton->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
