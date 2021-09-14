#include "classe_menu.h"
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <iomanip>


menu::menu(const string &_nom):nom(_nom), longueurMax(0)
{

    // ouvrir le fichier
    ifstream fichier("menu.txt");


    // Si il y a une erreur
    if (!fichier.is_open()) {
        // alors Afficher un message indiquant une erreur de lecture
        cerr << "Erreur lors de l'ouverture du fichier" << endl;
        // et mettre nbOptions à 0
        nbOption = 0;
    } else {
        nbOption = static_cast<int>(count(istreambuf_iterator<char>(fichier),istreambuf_iterator<char>(),'\n'));

        fichier.seekg(0,ios::beg);
        // allouer dynamiquement le tableau options en fonction de nbOptions
        options = new string [nbOption];
        // Pour chaque option dans le fichier
        for(int i = 0 ;i<=nbOption;i++){
            // Lire l’option et l’affecter dans le tableau options
            fichier >> options[i];
            // Si la taille de l’option est plus grande que longueurMax
            if(static_cast<int>(options->length())>longueurMax){
            // alors longueurMax reçoit la taille de l’option
                longueurMax = static_cast<int>(options->length());
            // FinSi
                }
            // FinPour
        }
        // FinSi
    }
}
menu::~menu()
{
    delete [] options;
}

void menu::menu::AfficherMenu()
{
     cout << "+" << setfill('-') << setw(5) << "+" << setfill('-') << setw(10) << "+" << endl;
     for(int i=0;i>=nbOption;i++)
     {
         cout << "|" << setfill(' ') << setw(5) << i << "+" << setfill('-') << setw(10) << options << "+" << endl;
     }
}










