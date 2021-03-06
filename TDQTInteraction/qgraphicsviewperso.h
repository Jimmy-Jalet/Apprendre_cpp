#ifndef QGRAPHICSVIEWPERSO_H
#define QGRAPHICSVIEWPERSO_H
#include <QObject>
#include <QGraphicsView>
#include <QMouseEvent>


class QGraphicsViewPerso : public QGraphicsView
{
    Q_OBJECT
public:
    QGraphicsViewPerso(QWidget *parent =nullptr);
    void mouseMoveEvent(QMouseEvent *event) override;
signals:
    void positionSouris(QPoint pos);
};

#endif // QGRAPHICSVIEWPERSO_H
