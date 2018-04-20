#pragma once

#include "supportadessin.h"

class SupportADessin;

class Dessinable{
public:
    //Dessinable(SupportADessin* support): support(support){}
    virtual void dessine() = 0;
protected:
    
    SupportADessin* support;
    
};




