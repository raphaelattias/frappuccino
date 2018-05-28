//
//  pendule.cpp
//  PROJET
//
//  Created by Raphael Attias on 23/03/2018.
//  Copyright © 2018 Raphael Attias. All rights reserved.
//

#include "pendule.h"
#include "oscillateur.h"
#include "integrateur.h"
#include <cmath>
#include "constantes.h"

class Integrateur;

using namespace std;


Pendule::Pendule(SupportADessin* SAD,Vecteur position, Vecteur vitesse, Vecteur origine, double masse, double longueur, double coefFrottement):
    Oscillateur(SAD, position,vitesse,origine,masse,longueur, coefFrottement) {} ;


Vecteur Pendule::evolution(Vecteur const& position_, Vecteur const& vitesse_) const {
 Vecteur sortie({(-g.norme()/longueur)*sin(position_.get_value(1))});
 //   Vecteur sortie({0, -9.81});
    return sortie;

}

unique_ptr<Pendule> Pendule::clone() const{
    return unique_ptr<Pendule>(new Pendule(*this));
}

unique_ptr<Oscillateur> Pendule::copie() const{
    return clone();
}

void Pendule::dessine(Integrateur* integrateur, double const& dt, int const& i){
    for(int j = 0; j < i; j++){
        support->dessineSupport(*this);
        if(integrateur != nullptr && ((i > 0) && (dt > 0))){
            integrateur->integrer(*this, dt);
        }
    }
}




