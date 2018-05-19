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
#include "integrateurNewmark.hpp"

using namespace std;


int main(){


    IntegrateurNewmark I1(0.01, 0.0001);

    TextViewer fichier("theTRUEone.txt");

    Pendule P1(&fichier , {2, 0}, {0, 0}, 1, 2, 0);

    for (int i = 0; i < 100; i++) {
        P1.afficher_evolution();
        I1.integrer(P1);
    }
    
    
    return 0;
};
