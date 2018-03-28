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

Oscillateur::Oscillateur(Vecteur vecteur_etat, Vecteur vitesse, double masse, double longueur):position(vecteur_etat), vitesse(vitesse), masse(masse), longueur(longueur){};

Vecteur Oscillateur::evolution() const {
    Vecteur sortie({0, -9.81});
    return sortie;
}

void Oscillateur::afficher_evolution() const {
    cout << "Vecteur d'état :"; position.affiche();
    cout << endl << "Vecteur de vitesse :"; vitesse.affiche();
    cout << endl;
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
