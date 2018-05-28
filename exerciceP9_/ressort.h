#pragma once
#include "oscillateur.h"
#include "supportadessin.h"

class Ressort: public Oscillateur {
protected:
    double raideur;
    Vecteur unitaire = {1,0,0};
    std::unique_ptr<Ressort> clone() const;
public:
    Ressort(Vecteur position={0,0,0}, Vecteur vitesse={0,0,0}, Vecteur origine={0,0,0}, double masse=0, double longueur = 0, double coefFrottement=0, double raideur=0, Vecteur unitaire={1,0,0}, SupportADessin* SAD = nullptr);
    virtual Vecteur evolution(Vecteur const& position_, Vecteur const& vitesse_) const override;
    std::unique_ptr<Oscillateur> copie() const override;
    virtual void dessine(Integrateur* integrateur = nullptr, double const& dt = 0.01, int const& i = 1) override;
    Vecteur get_unitaire() const;
};
