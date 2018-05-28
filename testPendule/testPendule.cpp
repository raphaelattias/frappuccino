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
#include "integrateur.h"
#include "integrateurEulerCromer.h"
#include "integrateurNewmark.hpp"
#include "IntegrateurRungeKutta.h"
#include "pendule.h"

using namespace std;


int main(){
    Pendule P({1,0}, {0,0}, 2, 1, 0);
    
    double dt = 0.01;
    IntegrateurEulerCromer I1 (dt);
    IntegrateurNewmark I2 (dt);
    IntegrateurRungeKutta I3 (dt);
   
	
	cout << "EULER CROMER " << endl;
	
	
	for (int i(0); i < 68 ; ++i ) {
        cout << "   t = " << dt*i << endl;
        P.afficher_evolution();
        I1.integrer(P);
	}
	
	
    
    return 0;
};
