#include <iostream>
#include "ipv4.h"
using namespace std;
void AfficherTableau(unsigned char *tab);
int main()
{
    unsigned char adresse[4]= {192,168,1,1};
    unsigned char masque[4];
    unsigned char reseau[4];
    unsigned char diffusion[4];
    unsigned char derniereAdresse[4];
    unsigned char PremiereAdresse[4];
    IPv4 uneAdresse(adresse, 24); // instanciation de la classe IPv4
    cout << "Adresse IPv4 : ";
    AfficherTableau(adresse);
    uneAdresse.ObtenirMasque(masque); // appel d'une méthode
    cout << "Masque : ";
    AfficherTableau(masque);
    uneAdresse.ObtenirAdresseReseau(reseau);
    cout << "Réseau : ";
    AfficherTableau(reseau);
    uneAdresse.ObtenirAdresseDiffusion(diffusion);
    cout << "Diffusion : ";
    AfficherTableau(diffusion);
    uneAdresse.ObtenirPremiereAdresse(PremiereAdresse);
    cout << "Premiere Adresse : ";
    AfficherTableau(PremiereAdresse);
    uneAdresse.ObtenirDerniereAdresse(derniereAdresse);
    cout << "Derniere Adresse : ";
    AfficherTableau(derniereAdresse);
    return 0;
}
void AfficherTableau(unsigned char *tab)
{

   for(int indice=0 ; indice < 4 ; indice ++)
    {
        cout  << static_cast<int> (tab[indice]);
        if(indice < 3)
            cout << "." ;
    }
    cout << endl;
}
