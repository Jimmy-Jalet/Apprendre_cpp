#include "capteurhumidite.h"
#include <iostream>

using namespace std;

CapteurHumidite::CapteurHumidite(const gpio_num_t _brocheCapteur)
{
cout << "constructeur de la classe CapteurHumidite " << endl ;
cout << "brocheCapteur :" << _brocheCapteur << endl ;
}
