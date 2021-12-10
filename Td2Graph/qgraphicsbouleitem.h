#ifndef QGRAPHICSBOULEHORIZONTALITEM_H
#define QGRAPHICSBOULEHORIZONTALITEM_H

#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include <QMediaPlayer>

class QGraphicsBouleItem : public QGraphicsEllipseItem
{
public:
    QGraphicsBouleItem(qreal x,qreal y,qreal width,qreal height,QGraphicsRectItem*_raquette,QGraphicsItem *parent=nullptr);
protected:
    void advance(int step) override;
private:
    QGraphicsRectItem *raquette;
    qreal dx;
    qreal dy;
    QMediaPlayer player;
    QString NomFichier;
    // valeur du pas et du sens de deplacement
    //si <0 --> de droite a gauche
    //si >0 --> de gauche a droite
};

#endif // QGRAPHICSBOULEHORIZONTALITEM_H
