#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include "classe_menu.cpp"
using namespace std;
enum CHOIX_MENU
{
    OPTION_1 = 1,
    OPTION_2,
    OPTION_3,
    OPTION_4,
    QUITTER
};

void menu::AttendreAppuiTouche()
{
    string uneChaine;
    cout << endl << "appuyer sur la touche Entrée pour continuer...";
    getline(cin,uneChaine);
    cin.ignore( std::numeric_limits<streamsize>::max(), '\n' );
    system("clear");
}
int main()
{
    int choix;
    menu leMenu("menu.txt");
    do
    {
        choix = leMenu.Afficher();
        switch (choix)
        {
        case OPTION_1:
            cout << "Vous avez choisi l'option n°1" << endl;
            menu::AttendreAppuiTouche();
            break;
        // à compléter
        }
    } while(choix != QUITTER);

    return 0;
}

