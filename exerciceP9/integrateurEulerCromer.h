#ifndef integrateurEulerCromer_h
#define integrateurEulerCromer_h
#include "integrateur.h"

class IntegrateurEulerCromer: public Integrateur {
public:
    virtual void integrer(Oscillateur &O1, double const& pas_de_temps = 0.01) override;
};

#endif /* integrateurEulerCromer_h */
