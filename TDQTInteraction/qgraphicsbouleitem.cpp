#include "qgraphicsbouleitem.h"

#include "qgraphicsbouleitem.h"
#include <QFileDialog>
QGraphicsBouleItem::QGraphicsBouleItem(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent):

    QGraphicsEllipseItem(x,y,width,height,parent),dx(2),dy(2)
{
   // setFocus();
}
