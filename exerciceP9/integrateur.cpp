#include <stdio.h>
#include <iomanip>
#include "integrateur.h"

using namespace std;

void Integrateur::afficherEvolution(Oscillateur const& oscillateur) const{
    cout << "Vecteur de position :" << setprecision(10) << oscillateur.get_position();
    cout << endl << "Vecteur de vitesse :" << setprecision(10) << oscillateur.get_vitesse();
    cout << endl;
    }

