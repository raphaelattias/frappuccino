#include "oscillateur.h"
#include "vecteur.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;


// Attributs :

Vecteur position;
Vecteur vitesse;
double masse;
double longueur;
Vecteur unitaireA;

// Méthodes :

Oscillateur::Oscillateur(SupportADessin* SAD, Vecteur vecteur_etat, Vecteur vitesse, double masse, double longueur, double coefFrottement):
Dessinable(SAD),position(vecteur_etat), vitesse(vitesse), masse(masse), longueur(longueur), coefFrottement(coefFrottement){};

Vecteur Oscillateur::evolution(Vecteur const& position_, Vecteur const& vitesse_) const{
    Vecteur sortie({0, -9.81});
    return sortie;
}

ostream& Oscillateur::afficher_evolution(ostream& sortie) const{
    sortie << setw(10) << position;
    sortie << setw(5);
    sortie << setw(10) << vitesse;
    sortie << endl;
    return sortie;
}

void Oscillateur::set_vecteurs(Vecteur const& vect_position, Vecteur const& vect_vitesse) {
    position = vect_position;
    vitesse = vect_vitesse;
}

Vecteur Oscillateur::get_vitesse() const {
    return vitesse;
}

double Oscillateur::get_longueur() const{
    return longueur;
}

Vecteur Oscillateur::get_position() const {
    return position;
}

ostream& operator<<(ostream& sortie, Oscillateur const& oscillateur){
    return oscillateur.afficher_evolution(sortie);
}
