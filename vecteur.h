//
//  vecteur.cpp
//  Brouillon
//
//  Created by Raphael Attias on 09/03/2018.
//  Copyright © 2018 Raphael Attias. All rights reserved.
//

#pragma once

#include <vector>

class Vecteur{
    
    
public:
    void augmente(double valeur_augmentee);
    void set_coord(size_t rang, double nouvelle_valeur);
    void affiche();
    
    bool compare(Vecteur vecteur2) const;
    
    Vecteur addition(Vecteur vecteur2) const;
    
    Vecteur soustraction(Vecteur vecteur2) const;
    
    Vecteur oppose() const;
    
    Vecteur mult(double scalaire) const;
    
    Vecteur prod_vect(Vecteur vecteur2) const;
    
    
    double prod_scalaire(Vecteur vecteur2) const;
    
    double norme2() const;
    
    double norme() const;
    
private:
    
    void equilibrage_vecteurs (Vecteur &vecteur2);
    
    void get_vecteur(Vecteur &vecteur2);
    
    
private:
    std::vector<double> vecteur;
    

    
};
