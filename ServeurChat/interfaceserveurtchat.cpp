#include "interfaceserveurtchat.h"
#include "ui_interfaceserveurtchat.h"
#include <QNetworkInterface>

InterfaceServeurTchat::InterfaceServeurTchat(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::InterfaceServeurTchat)
{
    ui->setupUi(this);


}

InterfaceServeurTchat::~InterfaceServeurTchat()
{
    delete ui;
}

void InterfaceServeurTchat::broadcastMessage(QString msg)
{
    foreach (QWebSocket *c, listeClient) {
        c->sendTextMessage(msg);
    }
}


void InterfaceServeurTchat::on_pushButtonLancer_clicked()
{

    socketServeur=new QWebSocketServer("serveur Tchat",QWebSocketServer::NonSecureMode);
    QObject::connect(socketServeur,&QWebSocketServer::newConnection,this,
                     &InterfaceServeurTchat::onQWebSocketServer_newConnection);
    socketServeur->listen(QHostAddress::Any,ui->lineEditPort->text().toInt());
    ui->textEdit->append("Ip Serveur : "+QNetworkInterface::allAddresses().at(2).toString());
    ui->textEdit->append("Port : "+QString::number(socketServeur->serverPort()));

}

void InterfaceServeurTchat::onQWebSocketServer_newConnection()
{
    QWebSocket *client=socketServeur->nextPendingConnection();
    listeClient.append(client);
    ui->textEdit->append("connexion de "+client->peerAddress().toString());
    broadcastMessage(" Nombre de client actuellement connectés : "+listeClient.size());
    QObject::connect(client,&QWebSocket::textFrameReceived,this,
                     &InterfaceServeurTchat::onQWebSocket_textMessageReceived);
    QObject::connect(client,&QWebSocket::disconnected,this,
                     &InterfaceServeurTchat::onQWebSocket_disconnected);
}

void InterfaceServeurTchat::onQWebSocket_textMessageReceived(const QString &message)
{

}

void InterfaceServeurTchat::onQWebSocket_disconnected()
{

}
