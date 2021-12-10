#include "qgraphicsviewperso.h"
#include <QDebug>

QGraphicsViewPerso::QGraphicsViewPerso(QWidget *parent)
{
    setMouseTracking(true);
    setAlignment(Qt::AlignLeft|Qt::AlignTop);
}

void QGraphicsViewPerso::mouseMoveEvent(QMouseEvent *event)
{
    qDebug()<<"Dans event souris de la vue : "<<event->pos();
    emit positionSouris(event->pos());
}
