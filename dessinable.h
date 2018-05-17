#pragma once

#include "supportadessin.h"

class SupportADessin;
class Integrateur;


class Dessinable{
public:
    Dessinable(SupportADessin* support = nullptr);
    virtual void dessine(Integrateur* integrateur, int const& i = 1) = 0;
    void assignerSupport(SupportADessin& SAD);
protected:
    SupportADessin* support;
};




