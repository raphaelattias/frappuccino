#pragma once
class Pendule;
class Ressort;
class Systeme;
class PenduleDouble;
class PenduleRessort;
class Chariot;
class PendulesLiesRessort;
class PenduleTriple;
class PenduleTorsion;
class RessortDouble;

class SupportADessin{
public:
    virtual void dessineSupport(Pendule const& ) = 0;
    virtual void dessineSupport(Ressort const& ) = 0;
    virtual void dessineSupport(Systeme const& ) = 0;
    virtual void dessineSupport(PenduleDouble const&) = 0;
    virtual void dessineSupport(PenduleRessort const&) = 0;
    virtual void dessineSupport(Chariot const&) = 0;
    virtual void dessineSupport(PendulesLiesRessort const&) = 0;
    virtual void dessineSupport(PenduleTriple const&) = 0;
    virtual void dessineSupport(RessortDouble const&) = 0;
    virtual void dessineSupport(PenduleTorsion const&) = 0;
};
