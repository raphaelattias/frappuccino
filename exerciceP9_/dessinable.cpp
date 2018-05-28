#include <stdio.h>
#include "dessinable.h"
#include "constantes.h"

using namespace std;

SupportADessin* support;

Dessinable::Dessinable(SupportADessin* support): support(support){}

void Dessinable::assignerSupport(SupportADessin& SAD){
    this->support = &SAD;
}
    
