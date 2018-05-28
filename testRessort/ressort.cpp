//
//  ressort.cpp
//  PROJET
//
//  Created by Raphael Attias on 15/04/2018.
//  Copyright © 2018 Raphael Attias. All rights reserved.
//

#include "ressort.h"
#include "oscillateur.h"
#include <iostream>
#include "integrateur.h"
#include "constantes.h"

using namespace std;

double raideur;
Vecteur unitaire;

Ressort::Ressort(Vecteur position, Vecteur vitesse, double masse, double longueur, double coefFrottement, double raideur, Vecteur unitaire): Oscillateur(position, vitesse, masse, longueur, coefFrottement), raideur(raideur), unitaire(unitaire*(1.0/(unitaire.norme()))){};

Vecteur Ressort::evolution(Vecteur const& position_, Vecteur const& vitesse_) const {
    Vecteur sortie({-raideur*position_.get_value(1)/masse - coefFrottement*vitesse_.get_value(1)/masse+g.prod_scalaire(unitaire)});
    return sortie;
}
