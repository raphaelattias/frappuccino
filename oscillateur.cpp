//
//  Oscillateur.cpp
//  PROJET PROG
//
//  Created by Pascal Epple on 17.03.18.
//  Copyright © 2018 Pascal Epple. All rights reserved.
//

#include "oscillateur.h"
#include "vecteur.h"

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;


/*
 *
 *
 *
 *
 //////////////////ATTRIBUTS
 *
 *
 *
 *
 */

Vecteur position; //degrés de liberté, dimensions, paramètres ?
Vecteur vitesse;
double masse;
double longueur;
Vecteur unitaireA;


/*
 *
 *
 *
 *
 //////////////////METHODES
 *
 *
 *
 *
 */

Oscillateur::Oscillateur(SupportADessin* SAD, Vecteur vecteur_etat, Vecteur vitesse, double masse, double longueur, double coefFrottement):
    Dessinable(SAD),position(vecteur_etat), vitesse(vitesse), masse(masse), longueur(longueur), coefFrottement(coefFrottement){};

Vecteur Oscillateur::evolution() const{
    Vecteur sortie({0, -9.81});
    return sortie;
}



ostream& Oscillateur::afficher_evolution(ostream& sortie) const{
    sortie << setw(10) << position;
    sortie <<  setw(5);
    sortie <<  setw(10) << vitesse;
    sortie << endl;
    return sortie;
}

void Oscillateur::set_vecteurs(Vecteur vect_position, Vecteur vect_vitesse) {
    position = vect_position;
    vitesse = vect_vitesse;
}

Vecteur Oscillateur::get_vitesse() const {
    return vitesse;
}

Vecteur Oscillateur::get_position() const {
    return position;
}
