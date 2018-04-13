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
    IntegrateurEulerCromer(double pas_de_temps);
    void integrerEC(Oscillateur &O1);
};





#endif /* integrateurEulerCromer_h */
