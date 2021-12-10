#include "widget.h"
#include "ui_widget.h"
#include <QRandomGenerator>
#include <QtMath>
#include <QFileDialog>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    maScene.setSceneRect(0,0,LARGEUR,HAUTEUR);
    // creation de la raquette
    laRaquette=new QGraphicsRectItem(LARGEUR/2,HAUTEUR-20,100,10);
    laRaquette->setBrush((QBrush(Qt::red)));
    maScene.addItem(laRaquette);
    // creation de mon objet ayant advance
    maBoule= new QGraphicsBouleItem(0,0,10,10,laRaquette);
    maBoule->setPos(20,60);
    maBoule->setBrush(QBrush(Qt::green));
    maScene.addItem(maBoule);
    // creation de 50 obstacles
    for(int i=0;i<NBOBSTACLES;i++)
    {
        obstacles[i]=new QGraphicsRectItem(0,0,10,10);
        //positionnement aleatoire dans les limites de la scene
        obstacles[i]->setPos(1+QRandomGenerator::global()->bounded(LARGEUR-10),1+QRandomGenerator::global()->bounded(HAUTEUR-10));
        obstacles[i]->setBrush(QBrush(Qt::blue));
        maScene.addItem(obstacles[i]);

    }
    ui->maVue->fitInView(maScene.sceneRect(),Qt::KeepAspectRatio);
    ui->maVue->setScene(&maScene);

    ui->maVue2->fitInView(maScene.sceneRect(),Qt::KeepAspectRatio);
    ui->maVue2->setScene(&maScene);
    ui->maVue2->rotate(180);

    ui->maVue3->fitInView(maScene.sceneRect(),Qt::KeepAspectRatio);
    ui->maVue3->setScene(&maScene);
    QRadialGradient soleil(160,230,150);
    soleil.setColorAt(0,QColor(255,255,255));
    soleil.setColorAt(0.5,QColor(255,255,0));
    soleil.setColorAt(1,QColor(255,0,0));
    ui->maVue3->setBackgroundBrush(QBrush(soleil));

    ui->maVue4->fitInView(maScene.sceneRect(),Qt::KeepAspectRatio);
    ui->maVue4->setScene(&maScene);
    QBrush remplissage;
    remplissage.setStyle(Qt::Dense5Pattern);
    remplissage.setColor(QColor(0,0,255));
    ui->maVue4->setBackgroundBrush(QBrush(remplissage));

    // association de timeout du timer au slot advance des objets
    connect(&timer,&QTimer::timeout,&maScene,&QGraphicsScene::advance);
    connect(&player,&QMediaPlayer::stateChanged,this,&Widget::onQMediaPlayer_stateChanged);
    connect(&player,QOverload<QMediaPlayer::Error>::of(&QMediaPlayer::error),this,&Widget::onQMediaPlayer_error);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButtonLnacerAnime_clicked()
{
    // lancement du timer -> timeout toutes les 10 millisecondes
    timer.start(10);
    player.setMedia(QUrl("qrc:/unfinished-chill-video-game-plus-echo-piano-beat-85-bpm-10918.mp3"));
    player.setVolume(50);
    player.play();
}



void Widget::on_pushButtonJouerSon_clicked()
{
    player.setMedia(QUrl::fromLocalFile(MusiqueDeFond));
    player.setVolume(50);
    player.play();
}

void Widget::on_pushButtonChoisirFichier_clicked(){
}

void Widget::onQMediaPlayer_stateChanged(QMediaPlayer::State state)
{
    QString etat;
    switch (state)
    {
    case QMediaPlayer::StoppedState :etat="stopped";break;
    case QMediaPlayer::PlayingState :etat="playing";break;
    case QMediaPlayer::PausedState :etat="paused";break;
    }
    qDebug()<<etat;


}

void Widget::onQMediaPlayer_error(QMediaPlayer::Error error)
{
    qDebug()<<player.errorString();
}
