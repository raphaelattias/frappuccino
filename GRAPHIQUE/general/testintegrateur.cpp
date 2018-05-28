#include <iostream>
#include "oscillateur_couple.hpp"
#include "supportadessin.h"
#include "integrateurEulerCromer.h"
#include "TextViewer.h"
#include "systeme.h"
#include <cmath>
using namespace std;

int main(){
    TextViewer vue("petit test.txt");
    IntegrateurEulerCromer I1;


    PendulesLiesRessort c({1,1}, {0, 0}, {0,0, 0}, 1, 1, 1, 0.8, 0, 0, 50, 0.5, 0.5, 2);

    c.dessine(&I1, 0.01, 100);
    

    return 0;
}
    

