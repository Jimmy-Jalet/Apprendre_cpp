#ifndef INTERFACESERVEURTCHAT_H
#define INTERFACESERVEURTCHAT_H

#include <QWidget>
#include <QWebSocket>
#include <QWebSocketServer>

QT_BEGIN_NAMESPACE
namespace Ui { class InterfaceServeurTchat; }
QT_END_NAMESPACE

class InterfaceServeurTchat : public QWidget
{
    Q_OBJECT

public:
    InterfaceServeurTchat(QWidget *parent = nullptr);
    ~InterfaceServeurTchat();
    void broadcastMessage(QString msg);

private slots:
    void on_pushButtonLancer_clicked();
    void onQWebSocketServer_newConnection();
    void onQWebSocket_textMessageReceived(const QString &message);
    void onQWebSocket_disconnected();

private:
    Ui::InterfaceServeurTchat *ui;
    QList <QWebSocket *>listeClient;
    QWebSocketServer *socketServeur;

};
#endif // INTERFACESERVEURTCHAT_H
