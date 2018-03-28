//
//  pendule.cpp
//  PROJET
//
//  Created by Raphael Attias on 23/03/2018.
//  Copyright © 2018 Raphael Attias. All rights reserved.
//

#include "pendule.h"
#include "oscillateur.h"
#include <cmath>



Pendule::Pendule(Vecteur position, Vecteur vitesse, double masse, double longueur, double lambda):
    Oscillateur(position,vitesse,masse, longueur), lambda(lambda){};

double lambda;

Vecteur Pendule::evolution(){
    /*
    Vecteur sortie({(-9.81/longueur)*sin(position.get_value(1))});
     */
    Vecteur sortie({0,-9.81});
    return sortie;
}




