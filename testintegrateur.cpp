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


#include "constantes.h"
#include "integrateur.h"

#include <iomanip>
#include <string>
#include <fstream>
#include "integrateurEulerCromer.h"

using namespace std;


int main(){
    
    string nom_fichier;
    nom_fichier = "dat";
    ofstream fichier(nom_fichier);
    if (fichier.fail()) {
        cerr << "Impossible" << endl;
    } else {
        
                        IntegrateurEulerCromer I1(0.01);
                        cout << endl;
                }
        
        
        fichier.close();
    }
    /*
    O1.set_vecteurs(v1, v2);
    IntegrateurEulerCromer I1(0.00001);
    I1.integrerEC(O1);
    O1.afficher_evolution();
    return 0;*/

