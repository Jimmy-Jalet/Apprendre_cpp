#ifndef ELEMENT_H
#define ELEMENT_H


class Element
{
public:
    Element();
    virtual ~Element();
    virtual void Afficher()=0;
    int getNumero() const;
    void setNumero(int value);

    int getVitesse() const;
    void setVitesse(int value);

protected:
    int numero;
    int vitesse;
};

#endif // ELEMENT_H
