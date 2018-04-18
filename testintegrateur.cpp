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
#include "pendule.h"
#include "ressort.h"
#include "vecteur_unitaire.h"


#include "constantes.h"
#include "integrateur.h"

#include <iomanip>
#include <string>
#include <fstream>
#include "integrateurEulerCromer.h"

using namespace std;


int main(){
    
    
    
    Ressort R1({0.18,0,0}, {0,0,0}, 0.25, 0.15, 0.33, {0.8, 0, 0.6});
    Pendule P1({1, 1}, {0, 0}, 1, 1, 0);
    IntegrateurEulerCromer I1(0.01);
    
    for(int i=0; i < 1000; i++){
        I1.integrer(R1);
            I1.afficherEvolution(R1);
            cout << endl;
}
    return 0;
};
