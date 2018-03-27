//
//  pendule.cpp
//  PROJET
//
//  Created by Raphael Attias on 23/03/2018.
//  Copyright © 2018 Raphael Attias. All rights reserved.
//

#include "pendule.h"
#include "Oscillateur.h"
#include <cmath>

class Vecteur Pendule::evolutionPendule(){
    class Vecteur sortie((-9.81/longueur)*vecteur_etat.get_value(1), 0, 0);
        return sortie;
};


