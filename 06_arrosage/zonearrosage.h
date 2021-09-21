#ifndef ZONEARROSAGE_H
#define ZONEARROSAGE_H
#include <iostream>
#include "vanne.h"
#include "capteurhumidite.h"

using namespace std;

class ZoneArrosage
{
private:
    Vanne *laVanne;
    CapteurHumidite *leCapteur;
    int numZone;
public:
    ZoneArrosage(const int _numZone,
                 const gpio_num_t _commandeVanne,
                 const gpio_num_t _senseAVanne,
                 const gpio_num_t _senseBVanne,
                 const gpio_num_t _brocheHumidite);
    ZoneArrosage(const string _initialisationZone);
    void Piloter();
    ~ZoneArrosage();
};
#endif // ZONEARROSAGE_H
