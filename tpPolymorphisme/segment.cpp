#include "segment.h"
#include <iostream>
using namespace std;

Segment::Segment(const double _longeur, const double _angle,const int _numero, int vitesse):
    Element(),
    longueur(_longeur),
    angle(_angle)
{
setNumero(_numero);
}

void Segment::Afficher()
{
    cout << "(" << numero << ")" << "SEGMENT L = " << longueur << "       A = " << angle << "       V = "<< vitesse << endl;
}
