
#pragma once
class Pendule;
class Ressort;
class Systeme;
class PenduleDouble;

class SupportADessin{
public:
    virtual void dessineSupport(Pendule const& ) = 0;
    virtual void dessineSupport(Ressort const& ) = 0;
    virtual void dessineSupport(Systeme const& ) = 0;
    virtual void dessineSupport(PenduleDouble const&) = 0;

public:
    virtual void remettre_a_zero() = 0;
};
