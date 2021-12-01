#include "monthreads.h"
#include <QDebug>
#include <QDataStream>


QBuffer MonThreads::zoneCommune;
unsigned int MonThreads::nbThread=0;
QMutex MonThreads::verrou;

MonThreads::MonThreads(QString _nom):nom(_nom)
{
    nbThread++;
}

void MonThreads::run()
{
    verrou.lock();
    zoneCommune.open(QIODevice::ReadWrite);
    QDataStream out(&zoneCommune);
    qDebug()<<"Debut lancement du thread "<<nom<<" id : "<<(quint64)QThread::currentThreadId();
    out<<(quint64)QThread::currentThreadId();
    out<<nom;
    verrou.unlock();
    afficherZone();



}

void MonThreads::afficherZone()
{
    verrou.lock();
    zoneCommune.open(QIODevice::ReadWrite);
    QDataStream in(&zoneCommune);
    quint64 ptr;
    QString chaine;
    in>>ptr>>chaine;
    qDebug()<<" thread "<<nom<<"zone commune "<<chaine<<" id : "<<QString::number(ptr,16);
    verrou.unlock();
}
