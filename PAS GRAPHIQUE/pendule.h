//
//  pendule.hpp
//  PROJET
//
//  Created by Raphael Attias on 23/03/2018.
//  Copyright © 2018 Raphael Attias. All rights reserved.
//

#pragma once
#include "oscillateur.h"
#include "supportadessin.h"

class Pendule: public Oscillateur {
public:
    Pendule(SupportADessin* SAD, Vecteur position={0,0,0}, Vecteur vitesse={0,0,0}, Vecteur origine={0,0,0}, double masse=0, double longueur=0, double coefFrottement=0);

    virtual Vecteur evolution(Vecteur const& position_, Vecteur const& vitesse_) const override;
    
    virtual void dessine(Integrateur* integrateur = nullptr, double const& dt = 0.01, int const& i = 1) override;
    std::unique_ptr<Oscillateur> copie() const override;
protected:
    std::unique_ptr<Pendule> clone() const;
};





