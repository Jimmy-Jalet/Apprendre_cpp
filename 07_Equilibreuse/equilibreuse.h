#ifndef EQUILIBREUSE_H
#define EQUILIBREUSE_H
#include "moteur.h"
#include "mcculdaq.h"

class Equilibreuse
{
private:
    MccUldaq laCarte;
    Moteur *leMoteur;
public:
    Equilibreuse();
};
#endif // EQUILIBREUSE_H
