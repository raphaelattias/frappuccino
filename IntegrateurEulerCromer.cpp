//
//  IntegrateurEulerCromer.cpp
//  PROJET
//
//  Created by Raphael Attias on 13/04/2018.
//  Copyright © 2018 Raphael Attias. All rights reserved.
//

#include <stdio.h>
#include "integrateurEulerCromer.h"
#include "oscillateur.h"
#include "integrateur.h"

using namespace std;

IntegrateurEulerCromer::IntegrateurEulerCromer(double pas_de_temps):Integrateur(pas_de_temps){};

void IntegrateurEulerCromer::integrerEC(Oscillateur &O1){
    O1.set_vecteurs(O1.get_position(), O1.get_vitesse() + pas_de_temps*O1.evolution());
    O1.set_vecteurs(O1.get_position() + pas_de_temps*O1.get_vitesse(), O1.get_vitesse());
}
