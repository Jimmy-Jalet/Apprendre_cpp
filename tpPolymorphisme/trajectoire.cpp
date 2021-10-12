#include "trajectoire.h"
#include <iostream>
using namespace std;

Trajectoire::Trajectoire(const int _nbEtapesMaxi,const int _numero,const int _vitesse):
    nbEtapesMax(_nbEtapesMaxi)
{

}

Trajectoire::~Trajectoire()
{

}

void Trajectoire::Afficher()
{
    cout << "Trajectoire: " << endl;
}
