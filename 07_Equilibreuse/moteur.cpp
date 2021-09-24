#include "moteur.h"
#include "MccUldaq.h"
Moteur::Moteur(const MccUldaq &_laCarte, const int _numCanal, const double _tensionMaxCommande) :
    numCanal(_numCanal),
    tensionMaxCommande(_tensionMaxCommande),
    laCarte(_laCarte) // initialisation de la relation d'agrégation
{
    laCarte.ulAOut(numCanal,0);
}
