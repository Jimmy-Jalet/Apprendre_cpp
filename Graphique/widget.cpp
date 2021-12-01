#include "widget.h"
#include "ui_widget.h"
#include <QGraphicsItem>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButtonDessiner_clicked()
{
    QGraphicsScene *maScene=new QGraphicsScene();
    maScene->setSceneRect(0,0,400,300);
    QPolygon poly1;
    QGraphicsLineItem *ligne;
    QGraphicsPolygonItem *poliI;
    QGraphicsTextItem *monTexte;
    poly1.setPoints(4,10,10,100,20,50,50,30,100);
    ligne=new QGraphicsLineItem(0,0,400,300);
    poliI=new QGraphicsPolygonItem(poly1);
    monTexte=new QGraphicsTextItem("bonjour");
    monTexte->setPos(50,100);
    monTexte->setFlag(QGraphicsItem::ItemIsMovable);
    maScene->addItem(monTexte);
    maScene->addItem(poliI);
    maScene->addItem(ligne);

    ui->maVue->fitInView(maScene->sceneRect(),Qt::KeepAspectRatio);
    ui->maVue->setScene(maScene);
    ui->maVue->show();

}
