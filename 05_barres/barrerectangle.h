#ifndef BARRERECTANGLE_H
#define BARRERECTANGLE_H
#include "barres.h"


class BarreRectangle : public Barre
{
public:
    BarreRectangle(const string _reference, const double _longueur, const double _densite, const string _nomAlliage,const double _hauteur ,const double _largeur);
    ~BarreRectangle();
    private:
    double hauteur;
    double largeur;
};

#endif // BARRERECTANGLE_H
