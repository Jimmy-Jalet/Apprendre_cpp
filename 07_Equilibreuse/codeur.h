#ifndef CODEUR_H
#define CODEUR_H
#include "mcculdaq.h"

class Codeur
{
public:
    Codeur();
    void ObtenirVitesse();
private:
    MccUldaq laCarte;
};

#endif // CODEUR_H
