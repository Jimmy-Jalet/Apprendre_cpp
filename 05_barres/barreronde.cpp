#include "barreronde.h"

BarreRonde::BarreRonde(const string _reference, const double _longueur, const double _densite, const string _nomAlliage,const double _diametre):Barre(_reference,_longueur,_densite,_nomAlliage),diametre(_diametre)
{
    cout<< "Contructeur de la classe BarreRonde"<< endl;
}
BarreRonde::~BarreRonde()
{
    cout<< "Destructeur de la classe BarreRonde"<< endl;
}
