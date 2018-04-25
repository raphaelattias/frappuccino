
#pragma once
class Pendule;
class Ressort;

class SupportADessin{
public:
    virtual void dessineSupport(Pendule const& ) = 0;
    virtual void dessineSupport(Ressort const& ) = 0;
public:
    virtual void remettre_a_zero() = 0;
};
