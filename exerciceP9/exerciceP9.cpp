#include <iostream>
#include "supportadessin.h"
#include "integrateurEulerCromer.h"
#include "IntegrateurRungeKutta.h"
#include "integrateurNewmark.hpp"
#include "TextViewer.h"
#include "systeme.h"
#include "ressort.h"
#include "pendule.h"
#include <cmath>
using namespace std;

int main(){
    TextViewer vue("data.txt");
    IntegrateurEulerCromer I1;
    IntegrateurNewmark I2;
    IntegrateurRungeKutta I3;
    double dt = 0.01;
    
    Pendule P({1,0}, {0,0}, {0,0,0}, 2, 1, 0, &vue);
    Ressort R({0.18,0,0}, {0,0,0}, {0,0,0}, 0.25, 0, 0.15, 0.33, {0.8, 0, 0.6}, &vue);
    
    Systeme S;
    S.ajouter(P);
    S.ajouter(R);
    S.assignerSupport(vue);
    
    // La méthode dessine permet de choisir dans l'ordre: l'intégrateur, le pas de temps et le nombre de fois qu'il doit dessiner.
    S.dessine(&I1, dt, 20);
    
    return 0;
}
    

