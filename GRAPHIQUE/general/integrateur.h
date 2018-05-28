#pragma once

#include "oscillateur.h"
#include "oscillateur_couple.hpp"

class Integrateur{
public:
    virtual void integrer(Oscillateur &O1, double const& pas_de_temps = 0.01) = 0;
    void afficherEvolution(Oscillateur const& oscillateur) const;
};
