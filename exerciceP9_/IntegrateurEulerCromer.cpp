#include <stdio.h>
#include "integrateurEulerCromer.h"
#include "oscillateur.h"
#include "integrateur.h"

using namespace std;

void IntegrateurEulerCromer::integrer(Oscillateur &O1, double const& pas_de_temps){
    O1.set_vecteurs(O1.get_position(), O1.get_vitesse() + pas_de_temps*O1.evolution(O1.get_position(), O1.get_vitesse()));
    O1.set_vecteurs(O1.get_position() + pas_de_temps*O1.get_vitesse(), O1.get_vitesse());
}
