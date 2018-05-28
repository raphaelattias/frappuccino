#include "dessinable.h"
#include "oscillateur.h"
#include <stdio.h>
#include <vector>
#include "integrateur.h"
#include <memory>
#include "systeme.h"
#include <iostream>

void Systeme::dessine(Integrateur* integrateur, double const& dt, int const& i){
    support->dessineSupport(*this);
        for(int j(0); j < collection.size(); j++){
            if(integrateur != nullptr && ((i > 0) && (dt > 0))){
                collection[j]->dessine(integrateur, dt, i);
            }
        }
}

void Systeme::ajouter(Oscillateur const& oscillateur){
        collection.push_back(oscillateur.copie());
}
    
void Systeme::evolue(Integrateur& I1, double const& pas_de_temps){
        for(int i=0; i < collection.size(); i++){
            I1.integrer(*collection[i], pas_de_temps);
        }
}

std::ostream& Systeme::afficher(std::ostream& sortie = std::cout) const{
    for(int i=0; i < collection.size(); i++){
        collection[i]->afficher_evolution(sortie);
    }
    return sortie;
}

