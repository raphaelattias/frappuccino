//
//  Oscillateur.hpp
//  PROJET PROG
//
//  Created by Pascal Epple on 17.03.18.
//  Copyright © 2018 Pascal Epple. All rights reserved.
//

#pragma once

#include <stdio.h>
#include "vecteur.h"
#include <iostream>

class Oscillateur {
private:
    Vecteur vecteur_etat; //degrés de liberté, dimensions, paramètres ?
    Vecteur vitesse;
    
public:
    Vecteur evolution(double t);
    
    void afficher_evolution();
    
    void set_vecteurs(Vecteur vect, Vecteur vect2);
    
};
