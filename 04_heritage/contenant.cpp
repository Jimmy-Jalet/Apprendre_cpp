#include "contenant.h"
#include <iostream>
#define CONTENANT_H
using namespace std;


class Contenant
{
public:
    Contenant(const int _largeur, const int _hauteur, const int _profondeur);
    int CalculerVolume();
protected:
    int largeur;
    int hauteur;
    int profondeur;
};
#endif // CONTENANT_H

Contenant::~Contenant()
{
    cout << "destructeur de la classe Contenant" << endl ;
}

