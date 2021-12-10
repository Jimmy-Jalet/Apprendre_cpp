#ifndef WIDGET_H
#define WIDGET_H
#define LARGEUR 500
#define HAUTEUR 400
#include <QWidget>
#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include <QTimer>
#include "qgraphicsbouleitem.h"
#include <QKeyEvent>
#include "qgraphicsviewperso.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void keyPressEvent(QKeyEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

private slots:
   void onQGraphicsViewPerso_positionSouris();
private:
    QTimer timer;
    Ui::Widget *ui;
    QGraphicsScene maScene;
    QGraphicsBouleItem *maBoule;


};
#endif // WIDGET_H
