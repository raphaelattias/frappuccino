#include "integrateur.h"

#include <stdio.h>

class IntegrateurRungeKutta : public Integrateur {
public:
    virtual void integrer(Oscillateur &O1, double const& pas_de_temps = 0.01) override;       
};
