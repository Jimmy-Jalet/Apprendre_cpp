#include "widget.h"
#include "ui_widget.h"
#include "monthreads.h"
#include <QDebug>

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


void Widget::on_pushButtonLancer_clicked()
{
    MonThreads *tab[5];
    qDebug()<<"nb thread "<<MonThreads::nbThread;
    for(int i = 0 ; i < 5 ; i++)
    {
        tab[i] = new MonThreads(QString::number(i));
    }
    qDebug()<<"nb thread aprés boucle "<<MonThreads::nbThread;
    tab[0]->start();
    tab[1]->start();
    tab[2]->start();
    tab[3]->start();
    tab[4]->start();
}
