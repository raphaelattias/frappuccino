//
//  Dessinable.cpp
//  PROJET
//
//  Created by Raphael Attias on 13/04/2018.
//  Copyright © 2018 Raphael Attias. All rights reserved.
//

#include <stdio.h>
#include "dessinable.h"
#include "constantes.h"

using namespace std;

SupportADessin* support;

Dessinable::Dessinable(SupportADessin* support): support(support){}

void Dessinable::assignerSupport(SupportADessin& SAD){
    SAD.remettre_a_zero();
    this->support = &SAD;
}
    
void Dessinable::dessine(){};

