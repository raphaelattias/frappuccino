//
//  integrateurNewmark.hpp
//  PROJET
//
//  Created by Raphael Attias on 11/05/2018.
//  Copyright © 2018 Raphael Attias. All rights reserved.
//

#include "integrateur.h"

class IntegrateurNewmark : public Integrateur {
public:
    IntegrateurNewmark(double pas_de_temps = 0.01, double Epsilon = 0.01): Integrateur(pas_de_temps){};
    virtual void integrer(Oscillateur &O1) override;
protected:
    Vecteur q;
    Vecteur r;
    Vecteur s;
    double Epsilon;
};
