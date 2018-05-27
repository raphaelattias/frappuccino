//
//  ressort.cpp
//  PROJET
//
//  Created by Raphael Attias on 15/04/2018.
//  Copyright © 2018 Raphael Attias. All rights reserved.
//

#include "ressort.h"
#include "oscillateur.h"
#include <iostream>
#include "constantes.h"
#include "integrateur.h"

using namespace std;

double raideur;
Vecteur unitaire;

//ON A REMPLACE VECTEUR UNITAIRE PAR VECTEUR TOUT COURT PARCE Que fuck it MATE THUG LIFE

Ressort::Ressort(SupportADessin* SAD, Vecteur position, Vecteur vitesse, Vecteur origine, double masse, double longueur, double coefFrottement, double raideur, Vecteur unitaire): Oscillateur(SAD, position, vitesse, origine, masse, longueur, coefFrottement), raideur(raideur), unitaire(unitaire){};

Vecteur Ressort::evolution(Vecteur const& position_, Vecteur const& vitesse_) const {
    Vecteur sortie({-raideur*position.get_value(1)/masse - coefFrottement*vitesse.get_value(1)/masse + g*unitaire});
    
    return sortie;
}

unique_ptr<Ressort> Ressort::clone() const{
    return unique_ptr<Ressort>(new Ressort(*this));
}

unique_ptr<Oscillateur> Ressort::copie() const{
    return clone();
}

void Ressort::dessine(Integrateur* integrateur,double const& dt, int const& i){
    for(int j = 0; j < i; j++){
        support->dessineSupport(*this);
        if(integrateur != nullptr && ((i > 0) && (dt > 0))){
            integrateur->integrer(*this, dt);
        }
    }
}
