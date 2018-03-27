//
//  Oscillateur.cpp
//  PROJET PROG
//
//  Created by Pascal Epple on 17.03.18.
//  Copyright © 2018 Pascal Epple. All rights reserved.
//

#include "Oscillateur.h"
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

Vecteur vecteur_etat; //degrés de liberté, dimensions, paramètres ?
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

Oscillateur::Oscillateur(Vecteur vecteur_etat, Vecteur vitesse, double masse, double longueur):vecteur_etat(vecteur_etat), vitesse(vitesse), masse(masse), longueur(longueur){};

Vecteur Oscillateur::evolution(double t) const {
    Vecteur sortie;
    sortie = t * vitesse;
    return sortie;
}

void Oscillateur::afficher_evolution() const {
    cout << "Vecteur d'état :"; vecteur_etat.affiche();
    cout << endl << "Vecteur de vitesse :"; vitesse.affiche();
    cout << endl;
}

void Oscillateur::set_vecteurs(Vecteur vect_etat, Vecteur vect_vitesse) {
    vecteur_etat = vect_etat;
    vitesse = vect_vitesse;
}

Vecteur Oscillateur::get_vitesse() const {
    return vitesse;
}

Vecteur Oscillateur::get_etat() const {
    return vecteur_etat;
}
