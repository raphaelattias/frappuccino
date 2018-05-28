#pragma once
#include <stdio.h>
#include "vecteur.h"
#include <vector>
#include <iostream>
#include <fstream>
#include "dessinable.h"

class Oscillateur: public Dessinable {
    
protected:
    Vecteur position;
    Vecteur vitesse;
    Vecteur origine;
    double masse;
    double longueur;
    double coefFrottement;    
public:
    Oscillateur(Vecteur position={0,0,0}, Vecteur vitesse={0,0,0}, Vecteur origine={0,0,0}, double masse=0, double longueur=0, double coefFrottement = 0, SupportADessin* SAD = nullptr);
    
    virtual ~Oscillateur(){}
    
    virtual Vecteur evolution(Vecteur const& position_ = {0, 0, 0}, Vecteur const& vitesse_ = {0, 0, 0}) const ;
    
    std::ostream& afficher_evolution(std::ostream& sortie = std::cout) const;
    
    void set_vecteurs(Vecteur const& vect_etat, Vecteur const& vitesse);
    
    virtual double get_longueur() const;
    
    Vecteur get_vitesse() const ;
    
    Vecteur get_position() const ;
    
    Vecteur get_origine() const;
    
    virtual std::unique_ptr<Oscillateur> copie() const = 0;
    
};
    std::ostream& operator<<(std::ostream& sortie, Oscillateur const& oscillateur);
