//
//  vecteur.cpp
//  Brouillon
//
//  Created by Raphael Attias on 09/03/2018.
//  Copyright © 2018 Raphael Attias. All rights reserved.
//

#include "vecteur.h"

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <stdexcept>

using namespace std;

Vecteur::Vecteur(size_t dimension): dimension(dimension){ // Only in the declaration but not in the definition
    for(size_t i=0; i < dimension; i++){
        augmente(0);
    }
}

// A RAJOUTER PLUS TARD: constrcuteur avec liste d'initialsiation (plus que 3D)
// A RAJOUTER PLUS TARD: operateur

Vecteur::Vecteur(double x, double y, double z): dimension(3){
    augmente(x);
    augmente(y);
    augmente(z);
}

Vecteur::Vecteur(Vecteur &V2): dimension(V2.dimension), vecteur(V2.vecteur){}


void Vecteur::augmente(double valeur_augmentee){
    vecteur.push_back(valeur_augmentee);
}



void Vecteur::set_coord(size_t rang, double nouvelle_valeur){ //si size t est faux que faire
    try {
        // J'ai utilisé la bibliothèque stdexcept qui gère mieux les exceptions et les erreurs, je trouve ça bg
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
void Vecteur::affiche(){
    for(auto el: vecteur){
        cout << el << " ";
    }
}

bool Vecteur::compare(Vecteur vecteur2) const {
    for (size_t i=0; i < vecteur.size(); i++) {
        if (vecteur2.vecteur[i] != vecteur[i]) {
            return false;
        }
    }
    return true;
}

Vecteur Vecteur::addition(Vecteur vecteur2) const {
    // On souhaite déterminer la plus grande dimension des deux vecteurs afin de pouvoir manipuler deux vecteurs de tailles différentes.
    // Aussi communément appelé dans la Communauté mathématiques "Plongement naturel"
    /*  if(vecteur.size() > vecteur2.vecteur.size()){
     vecteur_sortie.vecteur = vecteur;
     for(size_t i=0; i < vecteur2.vecteur.size(); i++){
     vecteur_sortie.set_coord(i+1,vecteur[i]+vecteur2.vecteur[i]);
     }
     } else if (vecteur.size() < vecteur2.vecteur.size()){
     vecteur_sortie.vecteur = vecteur2.vecteur;
     for(size_t i=0; i < vecteur.size(); i++){
     vecteur_sortie.set_coord(i+1,vecteur[i]+vecteur2.vecteur[i]);
     }
     } else {
     for(size_t i=0; i < vecteur.size(); i++){
     vecteur_sortie.vecteur = vecteur;
     vecteur_sortie.set_coord(i+1,vecteur[i]+vecteur2.vecteur[i]);
     
     }
     }*/
    Vecteur vecteur_sortie;
    
    
    Vecteur va; Vecteur vb;
    va.vecteur = vecteur; vb.vecteur = vecteur2.vecteur;
    va.equilibrage_vecteurs(vb); vb.equilibrage_vecteurs(va);
    
    
    for(size_t i=0; i < va.vecteur.size(); i++){
        vecteur_sortie.vecteur.push_back(va.vecteur[i]+vb.vecteur[i]);
    }
    
    return vecteur_sortie;
}

Vecteur Vecteur::soustraction(Vecteur vecteur2) const{
    /*
     Vecteur vecteur_sortie;
     if(vecteur.size() > vecteur2.vecteur.size()){
     vecteur_sortie.vecteur = vecteur;
     for(size_t i=0; i < vecteur2.vecteur.size(); i++){
     vecteur_sortie.set_coord(i+1,vecteur[i]-vecteur2.vecteur[i]);
     }
     } else if (vecteur.size() < vecteur2.vecteur.size()){
     vecteur_sortie.vecteur = vecteur2.vecteur;
     for(size_t i=0; i < vecteur.size(); i++){
     vecteur_sortie.set_coord(i+1,vecteur[i]-vecteur2.vecteur[i]);
     }
     } else {
     for(size_t i=0; i < vecteur.size(); i++){
     vecteur_sortie.vecteur = vecteur;
     vecteur_sortie.set_coord(i+1,vecteur[i]-vecteur2.vecteur[i]);
     
     }
     }
     return vecteur_sortie;*/
    
    Vecteur vecteur_sortie;
    
    
    Vecteur va; Vecteur vb;
    va.vecteur = vecteur; vb.vecteur = vecteur2.vecteur;
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

Vecteur Vecteur::prod_vect(Vecteur vecteur2) const{
    // Prevoir le catch dans le cas où les vecteurs sont de dimension différente de 3 (produit vect pas défini)
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


double Vecteur::prod_scalaire(Vecteur vecteur2) const{
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


vector<double> vecteur;
int dimension;

void Vecteur::equilibrage_vecteurs (Vecteur &vecteur2){
    if (vecteur2.vecteur.size() < vecteur.size()) {
        for (size_t i(vecteur2.vecteur.size()+1); i <= vecteur.size(); i++) {
            vecteur2.vecteur.push_back(0);
        }
    }
    
}

void Vecteur::get_vecteur(Vecteur &vecteur2) {
    vecteur2.vecteur = vecteur;
}


