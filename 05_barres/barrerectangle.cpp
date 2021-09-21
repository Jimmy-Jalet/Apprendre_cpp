#include "barrerectangle.h"

BarreRectangle::BarreRectangle(const string _reference, const double _longueur, const double _densite, const string _nomAlliage,const double _hauteur ,const double _largeur)
    :Barre(_reference,_longueur,_densite,_nomAlliage),hauteur(_hauteur),largeur(_largeur)
{
    cout<< "Contructeur de la classe BarreRectangle"<< endl;
}
BarreRectangle::~BarreRectangle()
{
    cout<< "Destructeur de la classe BarreRectangle"<< endl;
}

double BarreRectangle::CalculerSection()
{
    return hauteur * largeur ;
}
