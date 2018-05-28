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
public:
    OscillateursCouples(Vecteur position1={0,0,0}, Vecteur vitesse1={0,0,0}, Vecteur origine={0,0,0}, double masse1=0, double masse2=0, double longueur1=0, double longueur2=0, double coefFrottement1=0, double coefFrottement2=0, SupportADessin* SAD = nullptr);
    double get_longueur2() const;
};

class PenduleDouble: public OscillateursCouples {
public:
    PenduleDouble(Vecteur position1={0,0,0}, Vecteur vitesse1={0,0,0},Vecteur origine={0,0,0}, double masse1=0, double masse2=0, double longueur1=0, double longueur2=0, double coefFrottement1=0, double coefFrottement2=0, SupportADessin* SAD = nullptr);

    virtual Vecteur evolution(Vecteur const& position_ = {0,0,0}, Vecteur const& vitesse_ = {0, 0, 0}) const override;
    virtual void dessine(Integrateur* integrateur = nullptr, double const& dt = 0.01, int const& i = 1) override;
    std::unique_ptr<Oscillateur> copie() const override;
protected:
    std::unique_ptr<PenduleDouble> clone() const;
};

class PenduleRessort: public OscillateursCouples {
protected:
    double raideur1;
    std::unique_ptr<PenduleRessort> clone() const;
public:   
    PenduleRessort( Vecteur position1={0,0,0}, Vecteur vitesse1={0,0,0}, Vecteur origine={0,0,0},double masse1=0, double masse2=0, double longueur1=0, double longueur2=0, double coefFrottement1=0, double coefFrottement2=0, double raideur1 = 0, SupportADessin* SAD = nullptr);

    std::unique_ptr<Oscillateur> copie() const override;
    virtual Vecteur evolution(Vecteur const& position_ = {0,0,0}, Vecteur const& vitesse_ = {0, 0, 0}) const override;
    virtual void dessine(Integrateur* integrateur = nullptr, double const& dt = 0.01, int const& i = 1) override;
};

class Chariot: public OscillateursCouples {
protected:
    double raideur1;
    std::unique_ptr<Chariot> clone() const;
public:
    std::unique_ptr<Oscillateur> copie() const override;
    Chariot(Vecteur position1={0,0,0}, Vecteur vitesse1={0,0,0},Vecteur origine={0,0,0}, double masse1=0, double masse2=0, double longueur1=0, double longueur2=0, double coefFrottement1=0, double coefFrottement2=0, double raideur1 = 0, SupportADessin* SAD = nullptr);
    virtual Vecteur evolution(Vecteur const& position_ = {0,0,0}, Vecteur const& vitesse_ = {0, 0, 0}) const override;
    virtual void dessine(Integrateur* integrateur = nullptr, double const& dt = 0.01, int const& i = 1) override;
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

    PendulesLiesRessort(Vecteur position1={0,0,0}, Vecteur vitesse1={0,0,0}, Vecteur origine={0,0,0},double masse1=0, double masse2=0, double longueur1=0, double longueur2=0, double coefFrottement1=0, double coefFrottement2=0, double raideur1 = 0, double a1 = 0, double a2 = 0, double d = 0, SupportADessin* SAD = nullptr);
    
    std::unique_ptr<Oscillateur> copie() const override;
    virtual Vecteur evolution(Vecteur const& position_ = {0,0,0}, Vecteur const& vitesse_ = {0, 0, 0}) const override;
    virtual void dessine(Integrateur* integrateur = nullptr, double const& dt = 0.01, int const& i = 1) override;
};

class PenduleTriple: public OscillateursCouples{
public:
    virtual Vecteur evolution(Vecteur const& position_ = {0,0,0}, Vecteur const& vitesse_ = {0, 0, 0}) const override;
    PenduleTriple(Vecteur position1={0,0,0}, Vecteur vitesse1={0,0,0}, Vecteur origine={0,0,0}, double masse1=0, double masse2=0, double masse3=0, double longueur1=0, double longueur2=0, double longueur3 = 0, double coefFrottement1=0, double coefFrottement2=0, SupportADessin* SAD = nullptr);
    
    virtual void dessine(Integrateur* integrateur = nullptr, double const& dt = 0.01, int const& i = 1) override;
    std::unique_ptr<Oscillateur> copie() const override;
    double get_longueur3() const;
protected:
    std::unique_ptr<PenduleTriple> clone() const;
    double longueur3;
    double masse3;
};

class RessortDouble: public OscillateursCouples{
protected:
    double raideur1;
    double raideur2;
    double raideur3;
    double longueur3;
    Vecteur unitaire;
    std::unique_ptr<RessortDouble> clone() const;
public:
    virtual Vecteur evolution(Vecteur const& position_ = {0,0,0}, Vecteur const& vitesse_ = {0, 0, 0}) const override;
    RessortDouble(Vecteur position1={0,0,0}, Vecteur vitesse1={0,0,0}, Vecteur origine={0,0,0}, double masse1=0, double masse2=0, double longueur1=0, double longueur2=0, double longueur3 = 0, double raideur1 = 0, double raideur2 = 0, double raideur3 = 0, double coefFrottement1=0, double coefFrottement2=0, Vecteur unitaire = {1,0,0}, SupportADessin* SAD = nullptr);

    double get_longueur3() const;
    Vecteur get_unitaire() const;
    virtual void dessine(Integrateur* integrateur = nullptr, double const& dt = 0.01, int const& i = 1) override;
    std::unique_ptr<Oscillateur> copie() const override;
};

class PenduleTorsion: public Oscillateur{
protected:
    std::unique_ptr<PenduleTorsion> clone() const;
    double C;
    double I;
public:
    PenduleTorsion(Vecteur position={0,0,0}, Vecteur vitesse={0,0,0}, Vecteur origine={0,0,0}, double masse=0, double longueur = 0, double C = 1, double I = 1, double coefFrottement=0, SupportADessin* SAD = nullptr);
    virtual Vecteur evolution(Vecteur const& position_, Vecteur const& vitesse_) const override;
    std::unique_ptr<Oscillateur> copie() const override;
    virtual void dessine(Integrateur* integrateur = nullptr, double const& dt = 0.01, int const& i = 1) override;
    double get_C() const;
    double get_I() const;
};
