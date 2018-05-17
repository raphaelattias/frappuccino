//
//  systeme.cpp
//  PROJET
//
//  Created by Raphael Attias on 18/04/2018.
//  Copyright © 2018 Raphael Attias. All rights reserved.
//

#include "dessinable.h"
#include "oscillateur.h"
#include <stdio.h>
#include <vector>
#include "integrateur.h"
#include <memory>
#include "systeme.h"
#include <iostream>




/*
    Systeme(Integrateur integrateur, vector<Oscillateur*> init_list) : integrateur(integrateur) {
        for (int i(0); i < init_list.size() ; i++){
            //collection.push_back(init_list[i]);
        }
    }
    */
    


void Systeme::dessine(Integrateur* integrateur, int const& i){
        for(int j(0); j < collection.size(); j++){
            collection[j]->dessine(integrateur, i);
        }
        /*
        for(int j = 0; j < i; j++){
            support->dessineSupport(*this);
            evolue(*integrateur);
        }*/
    }

    void Systeme::ajouter(Oscillateur const& oscillateur){
        collection.push_back(oscillateur.copie());
    }
    
    void Systeme::evolue(Integrateur& I1){
        for(int i=0; i < collection.size(); i++){
            I1.integrer(*collection[i]);
        }
    }

    /*Oscillateur Systeme::get_oscillateur(size_t i) const {
       return *collection[i]; //on peut pas return d'objet d'une instance qui va jamais exister
    }*/

double Systeme::get_size() const {
    return collection.size();
}
Vecteur Systeme::get_position(int const& i) const{
    return collection[i]->get_position();
}

Vecteur Systeme::get_vitesse(int const& i) const{
    return collection[i]->get_vitesse();
}

double Systeme::get_longueur(int const& i) const{
    return collection[i]->get_longueur();
}

std::ostream& Systeme::afficher(std::ostream& sortie = std::cout) const{
    for(int i=0; i < collection.size(); i++){
        collection[i]->afficher_evolution(sortie);
    }
    return sortie;
}

