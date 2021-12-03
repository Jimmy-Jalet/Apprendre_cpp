#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    scene=new QGraphicsScene;
    scene->setSceneRect(0,0,400,300);
    ui->maVue->fitInView(scene->sceneRect(),Qt::KeepAspectRatio);
    ui->maVue->setScene(scene);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButtonDessiner_clicked()
{
    QGraphicsRectItem *rectangle=new QGraphicsRectItem(10,10,100,50);
    QColor bleu(0,0,255);
    QPen contour(bleu);
    rectangle->setPen(contour);
    QBrush remplissage(bleu);
    rectangle->setBrush(remplissage);
    rectangle->setFlag(QGraphicsItem::ItemIsMovable);
    scene->addItem(rectangle);
    QPolygon poly;
    poly.setPoints(3,33,0,65,47,1,46);
    QGraphicsPolygonItem *triangle=new QGraphicsPolygonItem(poly);
    QColor rouge(255,0,0);
    triangle->setPen(rouge);
    triangle->setBrush(bleu);
    triangle->setFlag(QGraphicsItem::ItemIsMovable);
    scene->addItem(triangle);

}
