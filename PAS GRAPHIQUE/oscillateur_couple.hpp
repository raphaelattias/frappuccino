#pragma once

#include "oscillateur.h"
#include "pendule.h"
#include <stdio.h>
#include "vecteur.h"
#include "vecteur_unitaire.h"

class OscillateursCouples: public Oscillateur {
protected:
    double masse2;
    double longueur2;
    double coefFrottement2;
    Vecteur_unitaire unitaireB;
    
public:
    OscillateursCouples(SupportADessin* SAD, Vecteur position1={0,0,0}, Vecteur vitesse1={0,0,0}, double masse1=0, double masse2=0, double longueur1=0, double longueur2=0, double coefFrottement1=0, double coefFrottement2=0);
    
    double get_longueur2() const;
};

class PenduleDouble: public OscillateursCouples {
public:
    virtual Vecteur evolution(Vecteur const& position_ = {0,0,0}, Vecteur const& vitesse_ = {0, 0, 0}) const override;
    PenduleDouble(SupportADessin* SAD, Vecteur position1={0,0,0}, Vecteur vitesse1={0,0,0}, double masse1=0, double masse2=0, double longueur1=0, double longueur2=0, double coefFrottement1=0, double coefFrottement2=0);


    virtual void dessine(Integrateur* integrateur, int const& i) override;
    std::unique_ptr<Oscillateur> copie() const override;
protected:
    std::unique_ptr<PenduleDouble> clone() const;
};

class PenduleRessort: public OscillateursCouples {
protected:
    double raideur1;
public:
    virtual Vecteur evolution(Vecteur const& position_ = {0,0,0}, Vecteur const& vitesse_ = {0, 0, 0}) const override;
    
    PenduleRessort(SupportADessin* SAD, Vecteur position1={0,0,0}, Vecteur vitesse1={0,0,0}, double masse1=0, double masse2=0, double longueur1=0, double longueur2=0, double coefFrottement1=0, double coefFrottement2=0, double raideur1 = 0);
    
};
