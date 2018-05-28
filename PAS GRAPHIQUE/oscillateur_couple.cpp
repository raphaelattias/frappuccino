//
//  oscillateur_couple.cpp
//  PROJET
//
//  Created by Raphael Attias on 09/05/2018.
//  Copyright © 2018 Raphael Attias. All rights reserved.
//

#include "oscillateur_couple.hpp"
#include "oscillateur.h"
#include <cmath>
#include "constantes.h"
#include "vecteur.h"
#include "integrateur.h"

OscillateursCouples::OscillateursCouples(SupportADessin* SAD, Vecteur position1, Vecteur vitesse1, Vecteur origine, double masse1, double masse2, double longueur1, double longueur2, double coefFrottement1, double coefFrottement2): Oscillateur(SAD, position1, vitesse1, origine, masse1, longueur1, coefFrottement1), longueur2(longueur2), masse2(masse2), coefFrottement2(coefFrottement2){};

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


std::unique_ptr<PenduleRessort> PenduleRessort::clone() const{
    return std::unique_ptr<PenduleRessort>(new PenduleRessort(*this));
}

std::unique_ptr<Oscillateur> PenduleRessort::copie() const{
    return clone();
}

std::unique_ptr<Chariot> Chariot::clone() const{
    return std::unique_ptr<Chariot>(new Chariot(*this));
}

std::unique_ptr<Oscillateur> Chariot::copie() const{
    return clone();
}

std::unique_ptr<PenduleTriple> PenduleTriple::clone() const{
    return std::unique_ptr<PenduleTriple>(new PenduleTriple(*this));
}

std::unique_ptr<Oscillateur> PenduleTriple::copie() const{
    return clone();
}

std::unique_ptr<PendulesLiesRessort> PendulesLiesRessort::clone() const{
    return std::unique_ptr<PendulesLiesRessort>(new PendulesLiesRessort(*this));
}

std::unique_ptr<Oscillateur> PendulesLiesRessort::copie() const{
    return clone();
}


void PenduleDouble::dessine(Integrateur* integrateur, double const& dt, int const& i){
    for(int j = 0; j < i; j++){
        support->dessineSupport(*this);
        if(integrateur != nullptr && ((i > 0) && (dt > 0))){
            integrateur->integrer(*this, dt);
        }
    }
}


void PenduleRessort::dessine(Integrateur* integrateur, double const& dt, int const& i){
    for(int j = 0; j < i; j++){
        support->dessineSupport(*this);
        if(integrateur != nullptr && ((i > 0) && (dt > 0))){
            integrateur->integrer(*this, dt);
        }
    }
}

void Chariot::dessine(Integrateur* integrateur, double const& dt, int const& i){
    for(int j = 0; j < i; j++){
        support->dessineSupport(*this);
        if(integrateur != nullptr && ((i > 0) && (dt > 0))){
            integrateur->integrer(*this, dt);
        }
    }
}


void PendulesLiesRessort::dessine(Integrateur* integrateur, double const& dt, int const& i){
    for(int j = 0; j < i; j++){
        support->dessineSupport(*this);
        if(integrateur != nullptr && ((i > 0) && (dt > 0))){
            integrateur->integrer(*this, dt);
        }
    }
}
void PenduleTriple::dessine(Integrateur* integrateur, double const& dt, int const& i){
    for(int j = 0; j < i; j++){
        support->dessineSupport(*this);
        if(integrateur != nullptr && ((i > 0) && (dt > 0))){
            integrateur->integrer(*this, dt);
        }
    }
}

PenduleDouble::PenduleDouble(SupportADessin* SAD, Vecteur position1, Vecteur vitesse1,  Vecteur origine, double masse1, double masse2, double longueur1, double longueur2, double coefFrottement1, double coefFrottement2): OscillateursCouples(SAD, position1, vitesse1,origine, masse1, masse2, longueur1, longueur2, coefFrottement1, coefFrottement2){};

double OscillateursCouples::get_longueur2() const{
    return longueur2;
}

Vecteur PenduleRessort::evolution(Vecteur const& position_, Vecteur const& vitesse_) const {
    Vecteur g_ = {0, -9.81, 0};
    return (g_-position_*(raideur1/masse)*(1-longueur/position_.norme()));
}

PenduleRessort::PenduleRessort(SupportADessin* SAD, Vecteur position1, Vecteur vitesse1, Vecteur origine, double masse1, double masse2, double longueur1, double longueur2, double coefFrottement1, double coefFrottement2, double raideur1): OscillateursCouples(SAD, position1, vitesse1, origine, masse1, masse2, longueur1, longueur2, coefFrottement1, coefFrottement2), raideur1(raideur1){};

Chariot::Chariot(SupportADessin* SAD, Vecteur position1, Vecteur vitesse1,  Vecteur origine,double masse1, double masse2, double longueur1, double longueur2, double coefFrottement1, double coefFrottement2, double raideur1): OscillateursCouples(SAD, position1, vitesse1,origine, masse1, masse2, longueur1, longueur2, coefFrottement1, coefFrottement2), raideur1(raideur1){};


Vecteur Chariot::evolution(Vecteur const& position_, Vecteur const& vitesse_) const {
    
    double A = masse + masse2*(sin(position_.get_value(2)))*(sin(position_.get_value(2)));
    double B = raideur1*position_.get_value(1)+coefFrottement*vitesse_.get_value(1)-masse2*longueur*vitesse_.get_value(2)*vitesse_.get_value(2)*sin(position_.get_value(2));
    double C = 9.81*sin(position_.get_value(2))+coefFrottement2*vitesse_.get_value(2);
    Vecteur sortie(-B+masse2*C*cos(position_.get_value(2)), (B*cos(position_.get_value(2))-(masse+masse2)*C)/longueur, 0);
    sortie *= 1.0/A;
    return sortie;
}



Vecteur PendulesLiesRessort::evolution(Vecteur const& position_, Vecteur const& vitesse_) const {
    Vecteur sortie(0, 0, 0);
    double L = pow(a1*a1 + a2*a2 + d*d -2*a1*sin(position_.get_value(1))+ 2*a2*sin(position_.get_value(2))+2*a1*a2*cos(position_.get_value(2)-position_.get_value(1)), 0.5);
    sortie.set_coord(1, (-raideur1*a1*((L-d)/L)*(d*cos(position_.get_value(1))-a2*sin(position_.get_value(2)-position_.get_value(1)))-masse*9.81*longueur*sin(position_.get_value(1)))/(masse*longueur*longueur));
    sortie.set_coord(2, (-raideur1*a2*((L-d)/L)*(d*cos(position_.get_value(2))+a1*sin(position_.get_value(2)-position_.get_value(1)))-masse2*9.81*longueur2*sin(position_.get_value(2)))/(masse2*longueur2*longueur2));
    return sortie;
}

PendulesLiesRessort::PendulesLiesRessort(SupportADessin* SAD, Vecteur position1, Vecteur vitesse1, Vecteur origine, double masse1, double masse2, double longueur1, double longueur2, double coefFrottement1, double coefFrottement2, double raideur1, double a1, double a2, double d): OscillateursCouples(SAD, position1, vitesse1, origine, masse1, masse2, longueur1, longueur2, coefFrottement1, coefFrottement2), a1(a1), a2(a2), d(d), raideur1(raideur1){};


double PendulesLiesRessort::get_d() const {
    return d;
}

double PendulesLiesRessort::get_L() const {
    return pow(a1*a1 + a2*a2 + d*d -2*a1*sin(position.get_value(1))+ 2*a2*sin(position.get_value(2))-2*a1*a2*cos(position.get_value(2)-position.get_value(1)), 0.5);
}
double PendulesLiesRessort::get_a1() const {
    return a1;
}
double PendulesLiesRessort::get_a2() const {
    return a2;
}

double PenduleTriple::get_longueur3() const {
    return longueur3;
}

PenduleTriple::PenduleTriple(SupportADessin* SAD, Vecteur position1, Vecteur vitesse1, Vecteur origine, double masse1, double masse2,double masse3, double longueur1, double longueur2, double longueur3, double coefFrottement1, double coefFrottement2): OscillateursCouples(SAD, position1, vitesse1, origine, masse1, masse2, longueur1, longueur2, coefFrottement1, coefFrottement2), masse3(masse3), longueur3(longueur3){};

Vecteur PenduleTriple::evolution(Vecteur const& position_, Vecteur const& vitesse_) const {
    Vecteur sortie(0, 0, 0);
    double teta12 = (position_.get_value(1)-position_.get_value(2));
    double teta13 = (position_.get_value(1)-position_.get_value(3));
    double teta23 = (position_.get_value(2)-position_.get_value(3));
    sortie.set_coord(1, -(masse2+masse3)*longueur*longueur2*vitesse_.get_value(2)*vitesse_.get_value(2)*sin(teta12)-masse3*longueur3*longueur*vitesse_.get_value(3)*vitesse_.get_value(3)*sin(teta13)-(masse+masse2+masse3)*9.81*longueur*sin(position_.get_value(1)));
    sortie.set_coord(2, (masse2+masse3)*longueur*longueur2*vitesse_.get_value(1)*vitesse_.get_value(1)*sin(teta12)-masse3*longueur3*longueur2*vitesse_.get_value(3)*vitesse_.get_value(3)*sin(teta23)-(masse2+masse3)*9.81*longueur2*sin(position_.get_value(2)));
    sortie.set_coord(3, masse3*longueur*longueur3*vitesse_.get_value(1)*vitesse_.get_value(1)*sin(teta13)+masse3*longueur3*longueur2*vitesse_.get_value(2)*vitesse_.get_value(2)*sin(teta23)-masse3*9.81*longueur3*sin(position_.get_value(3)));
    return sortie;
}

