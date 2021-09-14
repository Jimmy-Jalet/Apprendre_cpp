#include <iostream>
using namespace std;
#include "carton.h"
#include "contenant.h"

int main()
{
    Carton carton1 (10,15,7,30);
    cout << "volume :" << carton1.CalculerVolume() << endl ;
     cout << "Pois max :" << carton1.ObtenirPoidsMaxi() << endl ;
}
