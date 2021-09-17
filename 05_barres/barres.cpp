#include "barres.h"
#include <iostream>

Barre::Barre(const string _reference, const double _longueur, const double _densite, const string _nomAlliage)
{
    reference=_reference;
    longueur=_longueur;
    densite=_densite;
    nomAlliage=_nomAlliage;
    cout<< "Contructeur de la classe Barre"<< endl;
}

Barre::~Barre()
{
cout<< "Destructeur de la classe Barre"<< endl;
}

void Barre::AfficherCaracteristiques()
{
    cout << "Caractéristiques :" << endl ;
    cout << "reference :" << reference << endl ;
    cout << "longueur :" << longueur << endl ;
    cout << "densite :" << densite << endl ;
    cout << "nomAlliage :" << nomAlliage << endl ;
}


