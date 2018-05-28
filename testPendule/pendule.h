#pragma once
#include "oscillateur.h"

class Pendule: public Oscillateur {
public:
    Pendule(Vecteur position={0,0,0}, Vecteur vitesse={0,0,0}, double masse=0, double longueur=0, double coefFrottement=0);
    virtual Vecteur evolution(Vecteur const& position_, Vecteur const& vitesse_) const override;
};





