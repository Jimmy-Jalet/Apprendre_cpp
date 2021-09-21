#include "vanne.h"
#include <iostream>

using namespace std;

Vanne::Vanne(const gpio_num_t _brocheImpulsion,const gpio_num_t _sensA,const gpio_num_t _sensB)
{
    cout << "constructeur de la classe Vanne " << endl ;
    cout << "brocheImpulsion :" << _brocheImpulsion << endl ;
    cout << "sensA :" << _sensA << endl ;
    cout << "sensB :" << _sensB << endl ;
}
