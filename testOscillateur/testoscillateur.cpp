#include <iostream>
#include "vecteur.h"
#include "oscillateur.h"

using namespace std;

int main() {

    Oscillateur oscillateur1({1,2}, {3,4}, 1, 2, 0.5);
    cout << oscillateur1;
    
    cout << "Tests de son get() :" << endl;
    cout << "   de son parametre :" << oscillateur1.get_position() << endl;
    cout << "   de sa vitesse :" << oscillateur1.get_vitesse() << endl << endl;
    
    Vecteur newparameter({-2,-1});
    Vecteur newspeed({-6,12});
    cout << "Tests de son set() :" << endl;
    cout << "   de son parametre :" << newparameter << endl;
    oscillateur1.set_position(newparameter);
    cout << oscillateur1;
    cout << "   de sa vitesse :" << newspeed << endl;
    oscillateur1.set_vitesse(newspeed);
    cout << oscillateur1;
    
    return 0;
}
