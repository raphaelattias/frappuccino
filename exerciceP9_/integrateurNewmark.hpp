#include "integrateur.h"

class IntegrateurNewmark : public Integrateur {
public:
    IntegrateurNewmark(double Epsilon = 0.0001);
    virtual void integrer(Oscillateur &O1, double const& pas_de_temps) override;
protected:
    Vecteur q;
    Vecteur r;
    Vecteur s;
    double Epsilon;
};
