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
protected:
    Vecteur position; //degrés de liberté, dimensions, paramètres ?
    Vecteur vitesse;
    double masse;
    double longueur;
    
public:
    Oscillateur(Vecteur position={0,0,0}, Vecteur vitesse={0,0,0}, double masse=0, double longueur=0);
    
    Vecteur evolution() const ;
    
    std::ostream& afficher_evolution(std::ostream& sortie = std::cout) const ;
    
    void set_vecteurs(Vecteur vect_etat, Vecteur vitesse);
    
    Vecteur get_vitesse() const ;
    
    Vecteur get_position() const ;
};
