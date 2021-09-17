#ifndef BARRES_H
#define BARRES_H
#include <iostream>

using namespace std;

class Barre
{

public:
    Barre(const string _reference,const double _longueur,const double _densite,const string _nomAlliage);
    ~Barre();
     void AfficherCaracteristiques();
protected:
    string reference;
    double longueur;
    double densite;
    string nomAlliage;

};



#endif // BARRES_H
