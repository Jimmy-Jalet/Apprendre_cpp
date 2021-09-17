#include "barrecarree.h"

BarreCarree::BarreCarree(const string _reference, const double _longueur, const double _densite, const string _nomAlliage,const double _cote):Barre(_reference,_longueur,_densite,_nomAlliage),cote(_cote)
{
    cout<< "Contructeur de la classe BarreCarree"<< endl;
}
BarreCarree::~BarreCarree()
{
    cout<< "Destructeur de la classe BarreCarree"<< endl;
}
