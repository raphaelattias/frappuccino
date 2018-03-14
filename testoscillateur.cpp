//
//  testoscillateur.cpp
//  PROJET
//
//  Created by Raphael Attias on 14/03/2018.
//  Copyright © 2018 Raphael Attias. All rights reserved.
//

#include <stdio.h>
#include "vecteur.h"
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Oscillateur {
private:
    Vecteur vecteur_etat; //degrés de liberté, dimensions, paramètres ?
    Vecteur vitesse;
    
public:
    Vecteur evolution(double t){
        Vecteur sortie;
        sortie = vecteur_etat.addition(vitesse);
        sortie = sortie.mult(t);
        return sortie;
    }
    
    void afficher_evolution(){
        cout << "Vecteur d'état :"; vecteur_etat.affiche();
        cout << endl << "Vecteur de vitesse :"; vitesse.affiche();
        cout << endl;
    }

    void set_vecteurs(Vecteur vect, Vecteur vect2) {
        vecteur_etat = vect;
        vitesse = vect2;
    }
    
};

int main(){
    
    Vecteur v2 (1, 2, 3);
    Vecteur v1(4, 1, 5);
    Oscillateur o1;
    
    o1.set_vecteurs(v2,v1);
    
    double t;
    cout << "Entre un temps fdp :";
    cin >> t;
    
    Vecteur v3(3);
    v3 = o1.evolution(t);
    
    o1.afficher_evolution();
    
    v3.affiche();
    return 0;
}
