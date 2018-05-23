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

using namespace std;


int main(){

    Oscillateur O1 ({0,1}, {1,2,0}, 0.127);
    Oscillateur O2 = O1;
    IntegrateurEulerCromer I1 (0.01);
    IntegrateurNewmark I2 (0.01);
    
    for (int i(0); i < 50 ; ++i ) {
		I1.integrer(O1);
		O1.afficher_evolution();
	}
	
	for (int i(0); i < 50 ; ++i ) {
		I2.integrer(O2);
		O2.afficher_evolution();
	}
    
    return 0;
};
