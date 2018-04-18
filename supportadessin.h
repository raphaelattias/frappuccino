
#pragma once
class Pendule;
class Ressort;

class SupportADessin{
public:
    virtual void dessineSupport(Pendule const& ) = 0;
    virtual void dessineSupport(Ressort const& ) = 0;
    
};
