#pragma once
class Pendule;
class Ressort;
class Systeme;

class SupportADessin{
public:
    virtual void dessineSupport(Pendule const& ) = 0;
    virtual void dessineSupport(Ressort const& ) = 0;
    virtual void dessineSupport(Systeme const& ) = 0;
};
