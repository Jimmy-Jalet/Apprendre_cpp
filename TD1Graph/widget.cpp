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

    QColor bleu(0,0,255);
    QColor vert(0,255,0);
    QColor rouge(255,0,0);
    QColor noir(0,0,0);
    QColor magenta(255,0,255);
    QBrush remplissage(bleu);
    QBrush remplissage2(vert);
    QPixmap brique("../TD1Graph/brique.jpg");
    QPen contour(bleu);
    QPolygon poly;
    QPolygon poly2;
    QPolygon poly3;
    QPolygon poly4;
    poly.setPoints(3,33,0,65,47,1,46);
    poly2.setPoints(10,54,1,68,37,108,37,75,59,87,94,55,74,23,95,34,60,1,37,42,37);
    poly3.setPoints(10,54,1,68,37,108,37,75,59,87,94,55,74,23,95,34,60,1,37,42,37);
    poly4.setPoints(66,307,9,353,10,352,125,440,70,458,106,353,178,351,330,483,255,492,131,530,118,527,225,621,170,652,212,560,265,647,310,621,344,511,295,376,368,508,445,623,393,647,430,555,472,652,526,621,572,528,520,532,620,496,613,484,492,351,409,352,562,459,635,439,671,354,616,355,727,306,726,308,619,217,676,201,638,307,567,309,414,179,490,171,608,127,623,132,520,38,572,7,531,109,475,16,428,40,392,151,447,288,370,154,295,35,346,14,313,106,270,11,214,37,172,133,225,128,117,172,132,180,251,308,331,310,181,204,108,218,71,309,126);
    QGraphicsRectItem *rectangle=new QGraphicsRectItem(10,10,100,50);
    QGraphicsPolygonItem *triangle=new QGraphicsPolygonItem(poly);
    QGraphicsPolygonItem *etoile=new QGraphicsPolygonItem(poly2);
    QGraphicsPolygonItem *etoileRayee=new QGraphicsPolygonItem(poly3);
    QGraphicsPolygonItem *flocon=new QGraphicsPolygonItem(poly4);
    QGraphicsEllipseItem *rond =new QGraphicsEllipseItem(100,100,100,100);
    QLinearGradient linegradient(100,0,450,0);
    QRadialGradient radGradient(200,0,500);

    rectangle->setPen(contour);
    rectangle->setBrush(remplissage);
    rectangle->setFlag(QGraphicsItem::ItemIsMovable);





    triangle->setPen(rouge);
    triangle->setBrush(bleu);
    triangle->setFlag(QGraphicsItem::ItemIsMovable);

    etoile->setPen(bleu);
    etoile->setBrush(vert);
    etoile->setFlag(QGraphicsItem::ItemIsMovable);

    etoileRayee->setPen(bleu);
    remplissage.setStyle(Qt::BDiagPattern);
    etoileRayee->setBrush(remplissage);
    etoileRayee->setFlag(QGraphicsItem::ItemIsMovable);




    linegradient.setColorAt(0,QColor(0,0,255));
    linegradient.setColorAt(1,QColor(255,255,255));

    radGradient.setColorAt(0,QColor(0,0,255));
    radGradient.setColorAt(0.2,QColor(255,255,255));

    rond->setPen(magenta);
    //rond->setBrush(linegradient);
    rond->setBrush(radGradient);
    rond->setFlag(QGraphicsItem::ItemIsMovable);

    flocon->setPen(noir);
    flocon->setScale(0.4);
    scene->addItem(flocon);
    scene->addItem(rond);
    scene->addItem(rectangle);
    scene->addItem(triangle);
    scene->addItem(etoile);
    scene->addItem(etoileRayee);


}
