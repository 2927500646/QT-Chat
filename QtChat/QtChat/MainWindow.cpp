#include "MainWindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , tcpSocket(new QTcpSocket(this))
    , connected(false)
{
    ui->setupUi(this);
    setWindowTitle("简易聊天室");

    // 连接信号槽
    connect(tcpSocket, &QTcpSocket::connected, this, &MainWindow::onSocketConnected);
    connect(tcpSocket, &QTcpSocket::disconnected, this, &MainWindow::onSocketDisconnected);
    connect(tcpSocket, &QTcpSocket::readyRead, this, &MainWindow::onSocketReadyRead);
    connect(tcpSocket, &QTcpSocket::errorOccurred,
            this, &MainWindow::onSocketError);

    // 设置初始状态
    ui->sendButton->setEnabled(false);
    ui->messageEdit->setEnabled(false);
    ui->statusLabel->setText("未连接");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_connectButton_clicked()
{
    if (!connected) {
        // 连接服务器
        QString ip = ui->ipEdit->text();
        if (ip.isEmpty()) {
            ip = "127.0.0.1"; // 默认本地地址
            ui->ipEdit->setText(ip);
        }

        tcpSocket->connectToHost(ip, 8888);
        ui->connectButton->setText("连接中...");
        ui->connectButton->setEnabled(false);
    } else {
        // 断开连接
        tcpSocket->disconnectFromHost();
    }
}

void MainWindow::on_sendButton_clicked()
{
    QString message = ui->messageEdit->text().trimmed();
    if (!message.isEmpty() && connected) {
        tcpSocket->write(message.toUtf8());
        ui->chatDisplay->append("我: " + message);
        ui->messageEdit->clear();
    }
}

void MainWindow::onSocketConnected()
{
    connected = true;
    ui->connectButton->setText("断开连接");
    ui->connectButton->setEnabled(true);
    ui->sendButton->setEnabled(true);
    ui->messageEdit->setEnabled(true);
    ui->statusLabel->setText("已连接到服务器");

    ui->chatDisplay->append("*** 已进入聊天室 ***");
}

void MainWindow::onSocketDisconnected()
{
    connected = false;
    ui->connectButton->setText("连接");
    ui->connectButton->setEnabled(true);
    ui->sendButton->setEnabled(false);
    ui->messageEdit->setEnabled(false);
    ui->statusLabel->setText("连接已断开");

    ui->chatDisplay->append("*** 已断开连接 ***");
}

void MainWindow::onSocketReadyRead()
{
    while (tcpSocket->canReadLine()) {
        QByteArray data = tcpSocket->readLine();
        QString message = QString::fromUtf8(data).trimmed();
        if (!message.isEmpty()) {
            ui->chatDisplay->append("其他用户: " + message);
        }
    }
}

void MainWindow::onSocketError(QAbstractSocket::SocketError error)
{
    Q_UNUSED(error)
    ui->statusLabel->setText("连接错误: " + tcpSocket->errorString());
    ui->connectButton->setText("连接");
    ui->connectButton->setEnabled(true);
    QMessageBox::warning(this, "连接错误", "无法连接到服务器: " + tcpSocket->errorString());
}
