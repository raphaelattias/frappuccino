//
//  main.cpp
//  Brouillon
//
//  Created by Raphael Attias on 04/03/2018.
//  Copyright © 2018 Raphael Attias. All rights reserved.
//

#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;


class Vecteur{
public:
    void augmente(double valeur_augmentee){
        vecteur.push_back(valeur_augmentee);
    }
    void set_coord(size_t rang, double nouvelle_valeur){ //si size t est faux que faire
        try {
            if(rang <= 0 or rang > vecteur.size()){
                throw string("error");
            }
            vecteur[rang-1] = nouvelle_valeur;
        } catch (string error) {
            cerr << "Erreur: le rang entré est incorrect, plus grand que la dimension du vecteur (" << vecteur.size() << ") ou inférieur ou égal à 0." << endl;
        }
    }
    void affiche(){
        for(auto el: vecteur){
            cout << el << " ";
        }
    }
    bool compare(Vecteur vecteur2) const {
        for (size_t i=0; i < vecteur.size(); i++) {
            if (vecteur2.vecteur[i] != vecteur[i]) {
                return false;
            }
        }
        return true;
    }
    
    Vecteur addition(Vecteur vecteur2) const{
        // On souhaite déterminer la plus grande dimension des deux vecteurs afin de pouvoir manipuler deux vecteurs de tailles différentes.
        // Aussi communément appelé dans la Communauté mathématiques "Plongement naturel"
        Vecteur vecteur_sortie;
        if(vecteur.size() > vecteur2.vecteur.size()){
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
        }
        
        
        return vecteur_sortie;
    }
    
    Vecteur soustraction(Vecteur vecteur2) const{
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
        return vecteur_sortie;
    }
    
    Vecteur oppose() const {
        Vecteur vecteur_sortie;
        for(size_t i=0; i < vecteur.size(); i++){
            vecteur_sortie.vecteur.push_back(-vecteur[i]);
        }
        return vecteur_sortie;
    }
    
    Vecteur mult(double scalaire) const{
        Vecteur vecteur_sortie;
        for(size_t i=0; i < vecteur.size(); i++){
            vecteur_sortie.vecteur.push_back(scalaire*vecteur[i]);
        }
        return vecteur_sortie;
    }
    
    Vecteur prod_vect(Vecteur vecteur2) const{
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

    
    double prod_scalaire(Vecteur vecteur2) const{
        double resultat(0.0);
        for(size_t i = 0; i < min(vecteur.size(),vecteur2.vecteur.size()); i++){
            resultat += vecteur[i]*vecteur2.vecteur[i];
        }
        
        return resultat;
    }
    
    double norme2() const{
        double resultat(0.0);
        for(auto element : vecteur){
            resultat += element*element;
        }
        return resultat;
    }
    
    double norme() const{
        return sqrt(norme2());
    }
    
    
private:
    vector<double> vecteur;
    size_t dimension = vecteur.size();
};



int main(int argc, const char * argv[]) {
    
    Vecteur v1;
    Vecteur v2;
    
    v1.augmente(0);
    v1.augmente(2);
    v1.augmente(-0.1);
    
    v1.set_coord(0, 1.0);
    
    return 0;
}
