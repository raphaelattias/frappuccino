//
//  oscillateur_couple.cpp
//  PROJET
//
//  Created by Raphael Attias on 09/05/2018.
//  Copyright © 2018 Raphael Attias. All rights reserved.
//

#include "oscillateur_couple.hpp"
#include "oscillateur.h"
#include "vecteur.h"
#include <cmath>
#include "constantes.h"
#include "integrateur.h"

OscillateursCouples::OscillateursCouples(SupportADessin* SAD, Vecteur position1, Vecteur vitesse1, double masse1, double masse2, double longueur1, double longueur2, double coefFrottement1, double coefFrottement2): Oscillateur(SAD, position1, vitesse1, masse1, longueur1, coefFrottement1), longueur2(longueur2), masse2(masse2), coefFrottement2(coefFrottement2){};

Vecteur PenduleDouble::evolution(Vecteur const& position_, Vecteur const& vitesse_) const {
    double dteta = position_.get_value(1)-position_.get_value(2);
    double M = masse+masse2;
    return {(masse2*g.norme()*cos(dteta)*sin(position_.get_value(2))-M*g.norme()*sin(position_.get_value(1))-masse2*longueur*vitesse_.get_value(1)*vitesse_.get_value(1)*cos(dteta)*sin(dteta)-masse2*longueur2*vitesse_.get_value(2)*vitesse_.get_value(2)*sin(dteta))/((masse+masse2*sin(dteta)*sin(dteta))*longueur), (M*g.norme()*cos(dteta)*sin(position_.get_value(1))-M*g.norme()*sin(position_.get_value(2))+masse2*longueur2*vitesse_.get_value(2)*vitesse_.get_value(2)*cos(dteta)*sin(dteta)+M*longueur*vitesse_.get_value(1)*vitesse_.get_value(1)*sin(dteta))/((masse+masse2*sin(dteta)*sin(dteta))*longueur2), 0};
};


std::unique_ptr<PenduleDouble> PenduleDouble::clone() const{
    return std::unique_ptr<PenduleDouble>(new PenduleDouble(*this));
}

std::unique_ptr<Oscillateur> PenduleDouble::copie() const{
    return clone();
}


void PenduleDouble::dessine(Integrateur* integrateur, int const& i){
    for(int j = 0; j < i; j++){
        support->dessineSupport(*this);
        if(integrateur != nullptr){
          integrateur->integrer(*this);
        }
    }
}

PenduleDouble::PenduleDouble(SupportADessin* SAD, Vecteur position1, Vecteur vitesse1, double masse1, double masse2, double longueur1, double longueur2, double coefFrottement1, double coefFrottement2): OscillateursCouples(SAD, position1, vitesse1, masse1, masse2, longueur1, longueur2, coefFrottement1, coefFrottement2){};

double OscillateursCouples::get_longueur2() const{
    return longueur2;
}

Vecteur PenduleRessort::evolution(Vecteur const& position_, Vecteur const& vitesse_) const {
    return ({0, -9.81} - (raideur1/masse)*(1-longueur/position_.norme()*position_);
}

PenduleRessort::PenduleRessort(SupportADessin* SAD, Vecteur position1, Vecteur vitesse1, double masse1, double masse2, double longueur1, double longueur2, double coefFrottement1, double coefFrottement2): OscillateursCouples(SAD, position1, vitesse1, masse1, masse2, longueur1, longueur2, coefFrottement1, coefFrottement2), raideur1(raideur1){};)
