#pragma once
#include "integrateur.h"
#include "oscillateur.h"
#include <iostream>
#include "vecteur.h"
#include <vector>

class Systeme : public Dessinable {
public:
    virtual void dessine(Integrateur* integrateur = nullptr, double const& dt = 0, int const& i = 0) override;
    void ajouter(Oscillateur const& oscillateur);
    void evolue(Integrateur& I1, double const& pas_de_temps = 0.01);
    std::ostream& afficher(std::ostream& sortie) const;
    
private:
    std::vector<std::unique_ptr<Oscillateur>> collection;
};
