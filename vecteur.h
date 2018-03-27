//
//  vecteur.h
//  Brouillon
//
//  Created by Raphael Attias on 09/03/2018.
//  Copyright © 2018 Raphael Attias. All rights reserved.
//

#pragma once

#include <vector>
#include <iostream>

class Vecteur{
    
    
public:
    
    Vecteur(size_t dimension=0);
    Vecteur(double x, double y, double z); // Si on met un seul paramètre (ex: v1(3), quel constructeur il utilise ?
    Vecteur(Vecteur const& V2);
    Vecteur(std::initializer_list<double> init_list);
    
    
    void augmente(double valeur_augmentee);
    
    void set_coord(size_t rang, double nouvelle_valeur);
    
    std::ostream& affiche(std::ostream& sortie=std::cout) const;
    
    bool compare(Vecteur vecteur2) const;
    
    Vecteur addition(Vecteur vecteur2) const;
    
    Vecteur soustraction(Vecteur vecteur2) const;
    
    Vecteur oppose() const;
    
    Vecteur mult(double scalaire) const;
    
    Vecteur prod_vect(Vecteur vecteur2) const;
    
    bool operator==(Vecteur const& v2);
    
    double prod_scalaire(Vecteur vecteur2) const;
    
    double norme2() const;
    
    double norme() const;
    
    size_t get_dimension() const;
    
    double get_value(size_t i) const; // il retourne la i-ème valeur du tableau
    
    Vecteur& operator^=(Vecteur vect2);
    const Vecteur operator-();
    Vecteur& operator*=(const double& i);
    Vecteur& operator+=(Vecteur const& vect2);
    Vecteur& operator-=(Vecteur const& vect2);
    
private:
    
    void equilibrage_vecteurs (Vecteur &vecteur2);
    
    void get_vecteur(Vecteur &vecteur2);
    
    
private:
    std::vector<double> vecteur;
    std::size_t dimension=0;
    
    
    
};

const double operator*(Vecteur v1, Vecteur const& v2);
Vecteur operator^(Vecteur vect1, Vecteur vect2);
const Vecteur operator+(Vecteur vect1, Vecteur const& v2);
const Vecteur operator-(Vecteur vect1, Vecteur const& v2);


const Vecteur operator*(double i, Vecteur vect1);
const Vecteur operator*(Vecteur vect1, double i);

std::ostream& operator<<(std::ostream& sortie, Vecteur const& vect);

;
