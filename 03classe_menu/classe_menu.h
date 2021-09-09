#ifndef CLASSE_MENU_H
#define CLASSE_MENU_H
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

class menu
{
public:
    menu(const string &_nom);
    ~menu();
    static void attendreAppuiTouche();
    int Afficher();
private:
    string nom;
    string *options;
    int nbOption;
    int longueurMax;
};

#endif // CLASSE_MENU_H
