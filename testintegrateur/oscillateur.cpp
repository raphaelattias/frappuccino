#include "oscillateur.h"
#include "vecteur.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;


// Attributs :

Vecteur position;
Vecteur vitesse;
double masse;
double longueur;

// Méthodes :

Oscillateur::Oscillateur(Vecteur vecteur_etat, Vecteur vitesse, double masse, double longueur, double coefFrottement):position(vecteur_etat), vitesse(vitesse), masse(masse), longueur(longueur), coefFrottement(coefFrottement){};

Vecteur Oscillateur::evolution(Vecteur const& position_, Vecteur const& vitesse_) const{
    Vecteur sortie({0, -9.81});
    return sortie;
}

ostream& Oscillateur::afficher_evolution(ostream& sortie) const{
    sortie << "# Oscillateur" << endl;
    sortie << position << " # parametre " << endl;
    sortie << vitesse << " # vitesse " << endl;
    sortie << endl;
    return sortie;
}

void Oscillateur::set_vecteurs(Vecteur const& vect_position, Vecteur const& vect_vitesse) {
    set_position(vect_position);
    set_vitesse(vect_vitesse);
}

void Oscillateur::set_position(Vecteur const& vect_position){
    position = vect_position;
}

void Oscillateur::set_vitesse(Vecteur const& vect_vitesse){
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

std::ostream& operator<<(std::ostream& sortie, Oscillateur const& oscillateur){
    return oscillateur.afficher_evolution(sortie);
}
