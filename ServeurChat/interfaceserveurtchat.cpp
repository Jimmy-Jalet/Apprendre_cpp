#include "interfaceserveurtchat.h"
#include "ui_interfaceserveurtchat.h"
#include <QNetworkInterface>

InterfaceServeurTchat::InterfaceServeurTchat(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::InterfaceServeurTchat)
{
    ui->setupUi(this);
    QObject::connect(socketServeur,&QWebSocketServer::newConnection,this,
                     &InterfaceServeurTchat::onQWebSocketServer_newConnection);
}

InterfaceServeurTchat::~InterfaceServeurTchat()
{
    delete ui;
}


void InterfaceServeurTchat::on_pushButtonLancer_clicked()
{

    socketServeur->listen(QHostAddress::Any,ui->lineEditPort->text().toInt());
    ui->textEdit->append("Ip Serveur : "+QNetworkInterface().at(2).toString());

}

void InterfaceServeurTchat::onQWebSocketServer_newConnection()
{

}

void InterfaceServeurTchat::onQWebSocket_textMessageReceived(const QString &message)
{

}

void InterfaceServeurTchat::onQWebSocket_disconnected()
{

}
