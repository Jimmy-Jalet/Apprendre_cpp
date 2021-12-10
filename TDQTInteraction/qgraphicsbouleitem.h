#ifndef QGRAPHICSBOULEITEM_H
#define QGRAPHICSBOULEITEM_H


#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include <QKeyEvent>
class QGraphicsBouleItem : public QGraphicsEllipseItem
{
public:
    QGraphicsBouleItem(qreal x,qreal y,qreal width,qreal height,QGraphicsItem *parent=nullptr);

private:

    qreal dx;
    qreal dy;
    // valeur du pas et du sens de deplacement
    //si <0 --> de droite a gauche
    //si >0 --> de gauche a droite
};

#endif // QGRAPHICSBOULEITEM_H
