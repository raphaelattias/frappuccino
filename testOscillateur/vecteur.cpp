#include "vecteur.h"
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <stdexcept>

using namespace std;

// Constructeurs :

Vecteur::Vecteur(size_t dimension){
    for(size_t i=0; i < dimension; i++){
        augmente(0);
    }
}

Vecteur::Vecteur(double x, double y, double z) {
    augmente(x);
    augmente(y);
    augmente(z);
}

Vecteur::Vecteur(initializer_list<double> const& init_list) {
    vecteur = vector<double>(init_list.begin(), init_list.end());
}

// Méthodes :

void Vecteur::augmente(double const& valeur_augmentee){
    vecteur.push_back(valeur_augmentee);
}

void Vecteur::set_coord(size_t const& rang, double const&  nouvelle_valeur){
    try {
        if(rang > vecteur.size()){
            throw runtime_error("Erreur: le rang entré est incorrect, plus grand/petit que la dimension du vecteur.");
        } else if (rang <= 0){
            throw runtime_error("Erreur: le rang entré est incorrect, égal à 0");
        }
        
        vecteur[rang-1] = nouvelle_valeur;
    } catch (const exception &ex) {
        cerr << ex.what() << endl;
    }
}

ostream& Vecteur::affiche(ostream& sortie) const {
    for(auto el: vecteur){
        sortie << el << " ";
    }
    
    return sortie;
}

bool Vecteur::compare(Vecteur const& vecteur2) const {
    for (size_t i=0; i < vecteur.size(); i++) {
        if (vecteur2.vecteur[i] != vecteur[i]) {
            return false;
        }
    }
    return true;
}

Vecteur Vecteur::addition(Vecteur const& vecteur2) const {
    // On souhaite déterminer la plus grande dimension des deux vecteurs afin de pouvoir manipuler deux vecteurs de tailles différentes.
    // Aussi communément appelé dans la Communauté mathématiques "Plongement naturel"
    Vecteur vecteur_sortie;
    Vecteur va; Vecteur vb(vecteur2);
    va.vecteur = vecteur;
    va.equilibrage_vecteurs(vb); vb.equilibrage_vecteurs(va); //car on ne sait pas lequel des deux a la plus grande dimension
    
    for(size_t i=0; i < va.vecteur.size(); i++){
        vecteur_sortie.vecteur.push_back(va.vecteur[i]+vb.vecteur[i]);
    }
    
    return vecteur_sortie;
}

Vecteur Vecteur::soustraction(Vecteur const& vecteur2) const{
    
    Vecteur vecteur_sortie;
    
    Vecteur va; Vecteur vb(vecteur2);
    va.vecteur = vecteur;
    va.equilibrage_vecteurs(vb); vb.equilibrage_vecteurs(va);
    
    
    for(size_t i=0; i < va.vecteur.size(); i++){
        vecteur_sortie.vecteur.push_back(va.vecteur[i]-vb.vecteur[i]);
    }
    
    return vecteur_sortie;
    
}

Vecteur Vecteur::oppose() const {
    Vecteur vecteur_sortie;
    for(size_t i=0; i < vecteur.size(); i++){
        vecteur_sortie.vecteur.push_back(-vecteur[i]);
    }
    return vecteur_sortie;
}

Vecteur Vecteur::mult(double scalaire) const{
    Vecteur vecteur_sortie;
    for(size_t i=0; i < vecteur.size(); i++){
        vecteur_sortie.vecteur.push_back(scalaire*vecteur[i]);
    }
    return vecteur_sortie;
}

Vecteur Vecteur::prod_vect(Vecteur const& vecteur2) const{
    Vecteur vecteur_sortie;
    try {
        if(vecteur.size() != 3 and vecteur2.vecteur.size() != 3) {
            throw string("error");
        }
        vecteur_sortie.vecteur = {
            vecteur[1]*vecteur2.vecteur[2]-vecteur[2]*vecteur2.vecteur[1],
            vecteur[2]*vecteur2.vecteur[0]-vecteur[0]*vecteur2.vecteur[2],
            vecteur[0]*vecteur2.vecteur[1]-vecteur[1]*vecteur2.vecteur[0]
        };
        
        
    } catch (string error) {
        cerr << "Erreur: le produit vectoriel n'est que possible pour des vecteurs de dimension 3." << endl;
    }
    return vecteur_sortie;
}

double Vecteur::prod_scalaire(Vecteur const& vecteur2) const{
    double resultat(0.0);
    for(size_t i = 0; i < min(vecteur.size(),vecteur2.vecteur.size()); i++){
        resultat += vecteur[i]*vecteur2.vecteur[i];
    }
    
    return resultat;
}

double Vecteur::norme2() const{
    double resultat(0.0);
    for(auto element : vecteur){
        resultat += element*element;
    }
    return resultat;
}

double Vecteur::norme() const{
    return sqrt(norme2());
}

bool Vecteur::test_unitaire() const {
    return (norme() == 1);
}

void Vecteur::equilibrage_vecteurs (Vecteur &vecteur2){
    if (vecteur2.vecteur.size() < vecteur.size()) {
        for (size_t i(vecteur2.vecteur.size()+1); i <= vecteur.size(); i++) {
            vecteur2.vecteur.push_back(0);
        }
    }
    
}

// Méthodes accesseurs :

double Vecteur::get_value(size_t const& i) const {
    return vecteur[i-1];
}

size_t Vecteur::get_dimension() const {
    return vecteur.size();
}

void Vecteur::get_vecteur(Vecteur &vecteur2) {
    vecteur2.vecteur = vecteur;
}

// Méthodes pour opérateurs internes

bool Vecteur::operator==(Vecteur const& v2 ){
    return compare(v2);
}

bool Vecteur::operator!=(Vecteur const& v2 ){
    return !(*this==v2);
}

Vecteur& Vecteur::operator^=(Vecteur const& vect2){
    *this = prod_vect(vect2);
    return *this;
}

const Vecteur Vecteur::operator-(){
    Vecteur sortie;
    sortie = oppose();
    *this = sortie;
    return *this;
}

Vecteur& Vecteur::operator*=(const double& i){
    *this = mult(i);
    return *this;
}

Vecteur& Vecteur::operator+=(Vecteur const& vect2){
    *this = addition(vect2);
    return *this;
}

Vecteur& Vecteur::operator-=(Vecteur const& vect2){
    Vecteur sortie;
    sortie = soustraction(vect2);
    *this = sortie;
    return *this;
}

// Méthodes pour opérateurs externes :

double operator*(Vecteur v1, Vecteur const& v2){
    return v1.prod_scalaire(v2);
}

const Vecteur operator^(Vecteur vect1, Vecteur const& vect2){
    return vect1 ^= vect2;
}

const Vecteur operator+(Vecteur vect1, Vecteur const& vect2){
    return vect1 += vect2;
}


const Vecteur operator-(Vecteur vect1, Vecteur const& vect2){
    return vect1 -= vect2;
}


const Vecteur operator*(double const& i, Vecteur vect1){
    return vect1 *= i;
}

const Vecteur operator*(Vecteur vect1, double  const& i){
    return vect1 *= i;
}

ostream& operator<<(ostream& sortie, Vecteur const& vect){
    return vect.affiche(sortie);
};
