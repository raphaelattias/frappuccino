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
Oscillateur::Oscillateur(Vecteur vecteur_etat, Vecteur vitesse, Vecteur origine, double masse, double longueur, double coefFrottement, SupportADessin* SAD):
Dessinable(SAD),position(vecteur_etat), vitesse(vitesse), origine(origine), masse(masse), longueur(longueur), coefFrottement(coefFrottement){};

Vecteur Oscillateur::evolution(Vecteur const& position_, Vecteur const& vitesse_) const{
    Vecteur sortie({0, -9.81});
    return sortie;
}

ostream& Oscillateur::afficher_evolution(ostream& sortie) const{
    sortie << position << " #parametre" << endl;
    sortie << vitesse << " #vitesse" << endl;
    sortie << "==================" << endl;
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

Vecteur Oscillateur::get_origine() const{
    return origine;
}

ostream& operator<<(ostream& sortie, Oscillateur const& oscillateur){
    return oscillateur.afficher_evolution(sortie);
}
