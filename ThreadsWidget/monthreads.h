#ifndef MONTHREADS_H
#define MONTHREADS_H

#include <QObject>

#include <QThread>
#include <QBuffer>
#include <QMutex>

class MonThreads : public QThread
{
    Q_OBJECT
public:
    MonThreads(QString _nom);
    void run() override;
    static unsigned int nbThread;
private:
    QString nom;
    static QBuffer zoneCommune;
    void afficherZone();
    static QMutex verrou;
signals:
    void monId(quint64 id);
};


#endif // MONTHREADS_H
