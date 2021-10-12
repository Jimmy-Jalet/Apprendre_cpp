#include "element.h"

Element::Element():numero(0)

{
    vitesse=1;
}

Element::~Element()
{

}

void Element::Afficher()
{

}

int Element::getNumero() const
{
    return numero;
}

void Element::setNumero(int value)
{
    numero = value;
}

int Element::getVitesse() const
{
    return vitesse;
}

void Element::setVitesse(int value)
{
    vitesse = value;
}
