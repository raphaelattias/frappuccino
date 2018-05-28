//
//  IntegrateurRungeKutta.hpp
//  ProjetProg
//
//  Created by Pascal Epple on 26.05.18.
//  Copyright © 2018 Pascal Epple. All rights reserved.
//

#include "integrateur.h"

#include <stdio.h>

class IntegrateurRungeKutta : public Integrateur {
public:

	IntegrateurRungeKutta(double pas_de_temps = 0.01): Integrateur(pas_de_temps) {}
    
    virtual void integrer(Oscillateur &O1) override;
    
    //virtual void integrer(OscillateursCouples &O1, double const& pas_de_temps = 0.01) override {}
    
};
