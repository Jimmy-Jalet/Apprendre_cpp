#include "qgraphicsbouleitem.h"
#include <QFileDialog>
QGraphicsBouleItem::QGraphicsBouleItem(qreal x, qreal y, qreal width, qreal height,QGraphicsRectItem*_raquette, QGraphicsItem *parent):

QGraphicsEllipseItem(x,y,width,height,parent),raquette(_raquette),dx(2),dy(2)
{
NomFichier = QFileDialog::getOpenFileName();
}

void QGraphicsBouleItem::advance(int step)
{
    moveBy(dx,dy); // deplacement de dx pixel horizontalement
   // deplacement de dx pixel verticalement
    qreal largeurBoule=rect().width();
    qreal hauteurBoule=rect().height();
    qreal largeurScene=scene()->width();
    qreal hauteurScene=scene()->height();
    // si la boule arrive sur le bord gauche, on avance
    if(x()<=2)
    {
        dx=2;
    }
    // si la boule arrive sur le bord droit, on recule
    if(x()>=(largeurScene-largeurBoule))
    {
        dx=-2;
    }
    // si la boule arrive sur le haut, on descent
    if(y()<=2)
    {
        dy=2;
    }
    // si la boule arrive sur le bas, on remonte
    if(y()>=(hauteurScene-hauteurBoule))
    {
        dy=-2;
    }

    // gestion des collisions
    QList<QGraphicsItem*> listeDesObjetsEnCollisions=this->collidingItems();
    if(listeDesObjetsEnCollisions.count()>0)
    {
        foreach (QGraphicsItem *objet,listeDesObjetsEnCollisions)
        {
            //si l'objet n'est pas la raquette, le suprimer de la scene et inverser la trajectoire de la balle
            if(objet!=raquette)
            {
                scene()->removeItem(objet);
                dx=-dx;
                dy=-dy;
                player.setMedia(QUrl("qrc:/cartoon-boing-sound-effect-2.mp3"));
                player.setVolume(100);
                player.play();

            }
            else     // si c'est la raquette, changer le sens de la balle
            {
                dy=-dy;
            }

        }
    }





}
