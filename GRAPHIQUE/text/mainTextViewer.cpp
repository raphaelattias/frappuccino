#include <iostream>
#include "oscillateur_couple.hpp"
#include "ressort.h"
#include "supportadessin.h"
#include "integrateurEulerCromer.h"
#include "integrateurNewmark.hpp"
#include "IntegrateurRungeKutta.h"
#include "TextViewer.h"
#include "systeme.h"
#include <cmath>
using namespace std;

int main(){
    TextViewer vue(cout);
    Systeme S;
    S.assignerSupport(vue);
    IntegrateurEulerCromer I1;
    IntegrateurNewmark I2;
    IntegrateurRungeKutta I3;
    double dt = 0.01;
    double nb = 20;

    PendulesLiesRessort c({1,1}, {0, 0}, {0,0, 0}, 1, 1, 1, 0.8, 0, 0, 50, 0.5, 0.5, 2, &vue);
    Ressort R1({1,0}, {1,0}, {1, 1,1}, 3, 0.01, 0.01, 10, {1, 0}, &vue);

    S.ajouter(c);
    S.ajouter(R1);


    cout << "==================" << endl;

    for(int i = 0; i < nb; i++){
        cout << "   t = " << dt*i << endl;
       S.dessine(&I1, dt, 1);
    }



    return 0;
}
