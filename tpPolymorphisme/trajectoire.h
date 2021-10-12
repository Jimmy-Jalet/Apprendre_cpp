#ifndef TRAJECTOIRE_H
#define TRAJECTOIRE_H
#include "element.h"

class Trajectoire
{
public:
    Trajectoire(const int _nbEtapesMaxi,const int _numero,const int _vitesse);
    ~Trajectoire();
    bool Ajouter(const Element * _Ajouter);
    void Afficher();
private:
    Element ** parcours;
    int nbEtapesMax;
    int prochaineEtape;
};

#endif // TRJECTOIRE_H
