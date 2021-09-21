#ifndef BARRECARREE_H
#define BARRECARREE_H
#include "barres.h"

class BarreCarree : public Barre
{
public:
    BarreCarree(const string _reference, const double _longueur, const double _densite, const string _nomAlliage,const double _cote);
    ~BarreCarree();
    double CalculerSection() ;
private:
    double cote;
};

#endif // BARRECARREE_H
