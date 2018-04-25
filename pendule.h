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
    Pendule(Vecteur position={0,0,0}, Vecteur vitesse={0,0,0}, double masse=0, double longueur=0, double coefFrottement=0);
    
    virtual Vecteur evolution() const override;
    
    virtual void dessine() override;
    std::unique_ptr<Oscillateur> copie() const override;
protected:
    std::unique_ptr<Pendule> clone() const;
};

