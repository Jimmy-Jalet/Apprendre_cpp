#ifndef WIDGET_H
#define WIDGET_H

#include "qgraphicsbouleitem.h"
#include <QWidget>
#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include <QTimer>
#include <QMediaPlayer>
#define NBOBSTACLES 50
#define LARGEUR 320
#define HAUTEUR 240

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();


private slots:

    void on_pushButtonLnacerAnime_clicked();
    void on_pushButtonJouerSon_clicked();
    void on_pushButtonChoisirFichier_clicked();
    void onQMediaPlayer_stateChanged(QMediaPlayer::State state);
    void onQMediaPlayer_error(QMediaPlayer::Error error);

private:
    Ui::Widget *ui;
    QGraphicsScene maScene;
    QGraphicsBouleItem *maBoule;
    QTimer timer;
    QGraphicsRectItem *laRaquette;
    QGraphicsRectItem *obstacles[NBOBSTACLES];
    QMediaPlayer player;
    QString MusiqueDeFond;
};
#endif // WIDGET_H
