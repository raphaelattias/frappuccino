#include <iostream>
#include "ressort.h"
#include "supportadessin.h"
#include "integrateurEulerCromer.h"
#include "integrateurNewmark.hpp"
#include "IntegrateurRungeKutta.h"
#include "TextViewer.h"
#include "systeme.h"
#include <cmath>
#include <fstream>
#include "pendule.h"
using namespace std;

int main(){
	
	
    TextViewer vue;
    Systeme S;
    S.assignerSupport(vue);
    IntegrateurEulerCromer I1;
    IntegrateurNewmark I2;
    IntegrateurRungeKutta I3;
    double dt = 0.01;
    double nb = 20;
    
    Ressort R1({1,0}, {1,0}, {1, 1,1}, 3, 0.01, 0.01, 10, {1, 0}, &vue);
    Pendule P({1,0}, {0,0}, {0,0,0}, 2, 1, 0, &vue);

    S.ajouter(R1);
    S.ajouter(P);


    cout << "==================" << endl;

	S.dessine(&I1, dt, nb);



    return 0;
}
