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

using namespace std;


Pendule::Pendule(Vecteur position, Vecteur vitesse, double masse, double longueur, double coefFrottement):
    Oscillateur(position,vitesse,masse,longueur, coefFrottement){};


Vecteur Pendule::evolution() const{
    Vecteur sortie({(-9.81/longueur)*sin(position.get_value(1))});

    return sortie;

}

unique_ptr<Pendule> Pendule::clone() const{
    return unique_ptr<Pendule>(new Pendule(*this));
}

unique_ptr<Oscillateur> Pendule::copie() const{
    return clone();
}

void Pendule::dessine(){
    support->dessineSupport(*this);
}



