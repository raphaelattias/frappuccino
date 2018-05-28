//
//  integrateur.cpp
//  PROJET
//
//  Created by Raphael Attias on 13/04/2018.
//  Copyright © 2018 Raphael Attias. All rights reserved.
//

#include <stdio.h>
#include <iomanip>
#include "integrateur.h"

using namespace std;

Integrateur::Integrateur(double pas_de_temps): pas_de_temps(pas_de_temps){};

void Integrateur::afficherEvolution(Oscillateur const& oscillateur) const{
    cout << "Vecteur de position :" << setprecision(10) << oscillateur.get_position();
    cout << endl << "Vecteur de vitesse :" << setprecision(10) << oscillateur.get_vitesse();
    cout << endl;
    }

double pas_de_temps;
