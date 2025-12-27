/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
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
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(621, 700);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 10, 601, 631));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        statusLabel = new QLabel(widget);
        statusLabel->setObjectName(QStringLiteral("statusLabel"));

        horizontalLayout_5->addWidget(statusLabel);

        ipEdit = new QLineEdit(widget);
        ipEdit->setObjectName(QStringLiteral("ipEdit"));

        horizontalLayout_5->addWidget(ipEdit);

        connectButton = new QPushButton(widget);
        connectButton->setObjectName(QStringLiteral("connectButton"));

        horizontalLayout_5->addWidget(connectButton);


        verticalLayout_3->addLayout(horizontalLayout_5);

        chatDisplay = new QTextEdit(widget);
        chatDisplay->setObjectName(QStringLiteral("chatDisplay"));

        verticalLayout_3->addWidget(chatDisplay);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        messageEdit = new QLineEdit(widget);
        messageEdit->setObjectName(QStringLiteral("messageEdit"));
        messageEdit->setMinimumSize(QSize(0, 50));
        messageEdit->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_2->addWidget(messageEdit);

        sendButton = new QPushButton(widget);
        sendButton->setObjectName(QStringLiteral("sendButton"));
        sendButton->setMinimumSize(QSize(80, 50));
        sendButton->setMaximumSize(QSize(80, 50));

        horizontalLayout_2->addWidget(sendButton);


        verticalLayout_3->addLayout(horizontalLayout_2);

        MainWindow->setCentralWidget(centralWidget);
        messageEdit->raise();
        sendButton->raise();
        ipEdit->raise();
        connectButton->raise();
        chatDisplay->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 621, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        statusLabel->setText(QApplication::translate("MainWindow", "\346\234\215\345\212\241\345\231\250IP:", Q_NULLPTR));
        connectButton->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245", Q_NULLPTR));
        sendButton->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
