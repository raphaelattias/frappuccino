//
//  integrateur.h
//  PROJET
//
//  Created by Raphael Attias on 13/04/2018.
//  Copyright © 2018 Raphael Attias. All rights reserved.
//
#pragma once


#include "oscillateur.h"

class Integrateur{
public:
    // TROUVER UN MOYEN DE FAIRE VIRTUAL EN POUVANT L'UTILISER DANS SYSTEME
    virtual void integrer(Oscillateur &O1) = 0;
    Integrateur(double pas_de_temps=0.01);
    void afficherEvolution(Oscillateur const& oscillateur) const;
protected:
    double pas_de_temps;
};
