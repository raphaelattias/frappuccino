#pragma once

#include "supportadessin.h"

class SupportADessin;

class Dessinable{
public:
    //Dessinable(SupportADessin* support): support(support){}
    virtual void dessine() = 0;
    void assignerSupport(SupportADessin& SAD);
protected:
    SupportADessin* support;
};




