//
//  integrateurEulerCromer.h
//  PROJET
//
//  Created by Raphael Attias on 13/04/2018.
//  Copyright © 2018 Raphael Attias. All rights reserved.
//

#ifndef integrateurEulerCromer_h
#define integrateurEulerCromer_h
#include "integrateur.h"

class IntegrateurEulerCromer: public Integrateur {
public:
    virtual void integrer(Oscillateur &O1, double const& pas_de_temps = 0.01) override;
};





#endif /* integrateurEulerCromer_h */
