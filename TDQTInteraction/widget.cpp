#include "widget.h"
#include "ui_widget.h"
#include <QDebug>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setFocus();
    maScene.setSceneRect(0,0,LARGEUR,HAUTEUR);
    // creation de mon objet ayant advance
    maBoule= new QGraphicsBouleItem(0,0,10,10);
    maBoule->setPos(20,60);
    maBoule->setBrush(QBrush(Qt::green));
    maScene.addItem(maBoule);
    ui->maVue = new QGraphicsViewPerso(this);
    ui->maVue->fitInView(maScene.sceneRect(),Qt::KeepAspectRatio);
    connect(maVue,&QGraphicsViewPerso::positionSouris,this,&Widget::onQGraphicsViewPerso_positionSouris);
    ui->maVue->setScene(&maScene);
    connect(&timer,&QTimer::timeout,&maScene,&QGraphicsScene::advance);


}

Widget::~Widget()
{
    delete ui;
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Left:
        qDebug()<<"gauche";
        maBoule->moveBy(-10,0);
        break;
    case Qt::Key_Right:
        qDebug()<<"droite";
        maBoule->moveBy(10,0);



        break;
    case Qt::Key_Up:
        qDebug()<<"haut";
        maBoule->moveBy(0,-10);

        break;
    case Qt::Key_Down:
        qDebug()<<"bas";
        maBoule->moveBy(0,10);

        break;
    }

}

void Widget::mouseMoveEvent(QMouseEvent *event)
{

}

void Widget::mousePressEvent(QMouseEvent *event)
{

}

