//
//  pendule.hpp
//  PROJET
//
//  Created by Raphael Attias on 23/03/2018.
//  Copyright © 2018 Raphael Attias. All rights reserved.
//

#pragma once
#include "oscillateur.h"

class Pendule: public Oscillateur{
private:
    double lambda; // Coefficient de frottement, qui revient souvent devons nous le mettre dans oscillateur ou pas
public:
    Pendule(Vecteur position={0,0,0}, Vecteur vitesse={0,0,0}, double masse=0, double longueur=0, double lambda=0);
    
    Vecteur evolution();
};

