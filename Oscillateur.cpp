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


Vecteur vecteur_etat; //degrés de liberté, dimensions, paramètres ?
Vecteur vitesse;
    

Vecteur Oscillateur::evolution(double t){
        Vecteur sortie;
        sortie = vecteur_etat.addition(vitesse);
        sortie = sortie.mult(t);
        return sortie;
    
}
    
void Oscillateur::afficher_evolution(){
        cout << "Vecteur d'état :"; vecteur_etat.affiche();
        cout << endl << "Vecteur de vitesse :"; vitesse.affiche();
        cout << endl;
}
    
void Oscillateur::set_vecteurs(Vecteur vect, Vecteur vect2) {
        vecteur_etat = vect;
        vitesse = vect2;
}
    

