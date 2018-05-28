#pragma once

#include <vector>
#include <iostream>

class Vecteur{
    
public:
    
    // Constructeurs:
    
    Vecteur(size_t dimension=0);
    Vecteur(double x, double y, double z);
    Vecteur(std::initializer_list<double> const& init_list);
    
    // Méthodes :
    
    void augmente(double const& valeur_augmentee);
    
    void set_coord(size_t const&  rang,  double const& nouvelle_valeur);
    
    std::ostream& affiche(std::ostream& sortie=std::cout) const;
    
    bool compare(Vecteur const& vecteur2) const;
    
    Vecteur addition(Vecteur const& vecteur2) const;
    
    Vecteur soustraction(Vecteur const& vecteur2) const;
    
    Vecteur oppose() const;
    
    Vecteur mult(double scalaire) const;
    
    Vecteur prod_vect(Vecteur const& vecteur2) const;
    
    double prod_scalaire(Vecteur const& vecteur2) const;
    
    double norme2() const;
    
    double norme() const;
    
    bool test_unitaire() const;
    
    // Méthodes accesseurs
    
    size_t get_dimension() const;
    
    double get_value(size_t const& i) const; // il retourne la i-ème valeur du tableau
    
    // Méthodes pour opérateurs internes :
    
    bool operator==(Vecteur const& v2);
    bool operator!=(Vecteur const& v2);
    Vecteur& operator^=(Vecteur const& vect2);
    const Vecteur operator-();
    Vecteur& operator*=(const double& i);
    Vecteur& operator+=(Vecteur const& vect2);
    Vecteur& operator-=(Vecteur const& vect2);
    
private:
    
    void equilibrage_vecteurs (Vecteur &vecteur2);
    
    void get_vecteur(Vecteur &vecteur2);
    
protected:
    std::vector<double> vecteur;
};



double operator*(Vecteur v1, Vecteur const& v2);
const Vecteur operator^(Vecteur vect1, Vecteur const& vect2);
const Vecteur operator+(Vecteur vect1, Vecteur const& v2);
const Vecteur operator-(Vecteur vect1, Vecteur const& v2);


const Vecteur operator*(double const& i, Vecteur vect1);
const Vecteur operator*(Vecteur vect1, double const& i);

std::ostream& operator<<(std::ostream& sortie, Vecteur const& vect);

;
