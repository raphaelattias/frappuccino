//
//  testintegrateur.cpp
//  PROJET
//
//  Created by Raphael Attias on 21/03/2018.
//  Copyright © 2018 Raphael Attias. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include "oscillateur.h"
#include "vecteur.h"
#include "ressort.h"
#include "vecteur_unitaire.h"
#include "TextViewer.h"
#include "pendule.h"

#include "constantes.h"
#include "integrateur.h"

#include <iomanip>
#include <string>
#include <fstream>
#include "integrateurEulerCromer.h"
#include "systeme.h"
#include "integrateurNewmark.hpp"

using namespace std;


int main(){


    IntegrateurNewmark I1(0.01, 0.0001);
    
    TextViewer fichier("theVRAIMENTone.txt");

    Pendule P1(&fichier , {0, 1}, {1, 2}, 0, 0, 0);
    Ressort R1(&fichier , {1,0}, {0,0}, 3, 1, 0.33, 1.5, {0.8, 0.6});
    
    P1.dessine(&I1, 10);
/*
    Systeme S1;
    
    S1.ajouter(P1);
    S1.ajouter(R1);
    S1.assignerSupport(fichier);
    
    S1.dessine(&I1, 10);*/
    
    
    return 0;
};
