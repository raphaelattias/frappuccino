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
#include "ressort.h"

using namespace std;


int main(){
    Ressort R({0.18}, {0}, 0.25, 0, 0.15, 0.33, {0.8, 0, 0.6});
    
    double dt = 0.01;
    IntegrateurEulerCromer I1 (dt);
    IntegrateurNewmark I2 (dt);
    IntegrateurRungeKutta I3 (dt);
   
	
	cout << "EULER CROMER " << endl;
	
	
	for (int i(0); i < 68 ; ++i ) {
        cout << "   t = " << dt*i << endl;
        R.afficher_evolution();
        I1.integrer(R);
	}
	
	
    
    return 0;
};
