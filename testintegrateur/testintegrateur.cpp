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

using namespace std;


int main(){

    Oscillateur O1 ({0,1}, {1,2,0}, 0.127);
    Oscillateur O2 = O1;
    Oscillateur O3 = O1;
    IntegrateurEulerCromer I1 (0.01);
    IntegrateurNewmark I2 (0.01);
    IntegrateurRungeKutta I3 (0.01);
    
   
   
	
	cout << "RUNGE KUTTA " << endl;
	
	
	for (int i(0); i < 68 ; ++i ) {
		I3.integrer(O3);
		O3.afficher_evolution();
	}
	
	
    
    return 0;
};
