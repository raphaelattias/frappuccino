//
//  ressort.h
//  PROJET
//
//  Created by Raphael Attias on 15/04/2018.
//  Copyright © 2018 Raphael Attias. All rights reserved.
//

#pragma once
#include "oscillateur.h"
#include "supportadessin.h"

class Ressort: public Oscillateur {
private:

protected:
    double raideur;
    Vecteur unitaire = {1,0,0};
    std::unique_ptr<Ressort> clone() const;
public:
    Ressort(SupportADessin* SAD, Vecteur position={0,0,0}, Vecteur vitesse={0,0,0}, Vecteur origine={0,0,0}, double masse=0, double longueur = 0, double coefFrottement=0, double raideur=0, Vecteur unitaire={1,0,0});
    virtual Vecteur evolution(Vecteur const& position_, Vecteur const& vitesse_) const override;
    std::unique_ptr<Oscillateur> copie() const override;
    virtual void dessine(Integrateur* integrateur = nullptr, double const& dt = 0.01, int const& i = 1) override;
};
