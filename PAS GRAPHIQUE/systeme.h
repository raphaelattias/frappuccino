//
//  systeme.h
//  PROJET
//
//  Created by Raphael Attias on 18/04/2018.
//  Copyright © 2018 Raphael Attias. All rights reserved.
//

#pragma once
#include "integrateur.h"
#include "oscillateur.h"
#include "vecteur.h"

using namespace std;

class Systeme : public Dessinable {
public:
    virtual void dessine(Integrateur* integrateur = nullptr, int const& i = 1) override;
    void ajouter(Oscillateur const& oscillateur);
    void evolue(Integrateur& I1, int const& pas_de_temps = 1);
    double get_size() const;
    ostream& afficher(ostream& sortie) const;
    
    Vecteur get_position(int const& i) const;
    Vecteur get_vitesse(int const& i) const;
    double get_longueur(int const& i) const;
    
    
private:
    vector<unique_ptr<Oscillateur>> collection;
};
