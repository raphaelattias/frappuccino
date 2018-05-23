//
//  integrateur.h
//  PROJET
//
//  Created by Raphael Attias on 13/04/2018.
//  Copyright © 2018 Raphael Attias. All rights reserved.
//
#pragma once


#include "oscillateur.h"
#include "oscillateur_couple.hpp"

class Integrateur{
public:
    // TROUVER UN MOYEN DE FAIRE VIRTUAL EN POUVANT L'UTILISER DANS SYSTEME
    virtual void integrer(Oscillateur &O1, double const& pas_de_temps = 0.01) = 0;
    void afficherEvolution(Oscillateur const& oscillateur) const;
    virtual void integrer(OscillateursCouples &O1, double const& pas_de_temps = 0.01) = 0;

};
