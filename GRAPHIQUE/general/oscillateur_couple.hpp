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
    std::unique_ptr<PenduleRessort> clone() const;
public:
    std::unique_ptr<Oscillateur> copie() const override;
    virtual Vecteur evolution(Vecteur const& position_ = {0,0,0}, Vecteur const& vitesse_ = {0, 0, 0}) const override;
    virtual void dessine(Integrateur* integrateur, int const& i) override;
    
    PenduleRessort(SupportADessin* SAD, Vecteur position1={0,0,0}, Vecteur vitesse1={0,0,0}, double masse1=0, double masse2=0, double longueur1=0, double longueur2=0, double coefFrottement1=0, double coefFrottement2=0, double raideur1 = 0);
    
};

class Chariot: public OscillateursCouples {
protected:
    double raideur1;
    std::unique_ptr<Chariot> clone() const;
public:
    std::unique_ptr<Oscillateur> copie() const override;
    Chariot(SupportADessin* SAD, Vecteur position1={0,0,0}, Vecteur vitesse1={0,0,0}, double masse1=0, double masse2=0, double longueur1=0, double longueur2=0, double coefFrottement1=0, double coefFrottement2=0, double raideur1 = 0);
    virtual Vecteur evolution(Vecteur const& position_ = {0,0,0}, Vecteur const& vitesse_ = {0, 0, 0}) const override;
    virtual void dessine(Integrateur* integrateur, int const& i) override;
};

class PendulesLiesRessort: public OscillateursCouples{
protected:
    double raideur1;
    double d;
    double a1;
    double a2;
    std::unique_ptr<PendulesLiesRessort> clone() const;

public:
    double get_d() const;
    double get_L() const;
    double get_a1() const;
    double get_a2() const;

    PendulesLiesRessort(SupportADessin* SAD, Vecteur position1={0,0,0}, Vecteur vitesse1={0,0,0}, double masse1=0, double masse2=0, double longueur1=0, double longueur2=0, double coefFrottement1=0, double coefFrottement2=0, double raideur1 = 0, double a1 = 0, double a2 = 0, double d = 0);
    
    std::unique_ptr<Oscillateur> copie() const override;
    virtual Vecteur evolution(Vecteur const& position_ = {0,0,0}, Vecteur const& vitesse_ = {0, 0, 0}) const override;
    virtual void dessine(Integrateur* integrateur, int const& i) override;
};

class PenduleTriple: public OscillateursCouples{
public:
    virtual Vecteur evolution(Vecteur const& position_ = {0,0,0}, Vecteur const& vitesse_ = {0, 0, 0}) const override;
    PenduleTriple(SupportADessin* SAD, Vecteur position1={0,0,0}, Vecteur vitesse1={0,0,0}, double masse1=0, double masse2=0, double masse3=0, double longueur1=0, double longueur2=0, double longueur3 = 0, double coefFrottement1=0, double coefFrottement2=0);
    
    virtual void dessine(Integrateur* integrateur, int const& i) override;
    std::unique_ptr<Oscillateur> copie() const override;
    double get_longueur3() const;
protected:
    std::unique_ptr<PenduleTriple> clone() const;
    double longueur3;
    double masse3;
};

