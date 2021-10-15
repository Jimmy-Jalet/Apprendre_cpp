#ifndef SEGMENT_H
#define SEGMENT_H
#include "element.h"


class Segment : public Element
{
public:
    Segment(const double _longeur, const double _angle, const int _numero, int vitesse =1);
    void Afficher();
private:
    double longueur;
    double angle;
};

#endif // SEGMENT_H
