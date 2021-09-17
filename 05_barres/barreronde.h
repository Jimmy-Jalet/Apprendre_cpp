#ifndef BARRERONDE_H
#define BARRERONDE_H
#include "barres.h"


class BarreRonde : public Barre
{
public:
    BarreRonde(const string _reference, const double _longueur, const double _densite, const string _nomAlliage,const double _diametre);
    ~BarreRonde();
private:
    double diametre;
};

#endif // BARRERONDE_H
