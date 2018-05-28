#include <stdio.h>
#include "vecteur.h"
#include "vecteur_unitaire.h"

Vecteur_unitaire::Vecteur_unitaire(): Vecteur(1.0, 0.0, 0.0){};
    
Vecteur_unitaire::Vecteur_unitaire(double x, double y, double z): Vecteur(x, y, z) {normalise();};

Vecteur_unitaire::Vecteur_unitaire(const Vecteur& copie): Vecteur(copie) {normalise();};
    
void Vecteur_unitaire::normalise(){
        
        if (norme() == 0.0){
            *this = Vecteur_unitaire();
        } else if (norme() != 1) {
            *this = mult(1/norme());
        };
    }
