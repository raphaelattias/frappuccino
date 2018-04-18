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



Pendule::Pendule(Vecteur position, Vecteur vitesse, double masse, double longueur, double coefFrottement):
    Oscillateur(position,vitesse,masse,longueur, coefFrottement){};


Vecteur Pendule::evolution() const{
    Vecteur sortie({(-9.81/longueur)*sin(position.get_value(1))});

    return sortie;

}

void Pendule::dessine(){
    support->dessineSupport(*this);
}



