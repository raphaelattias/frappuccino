#include "IntegrateurRungeKutta.h"

void IntegrateurRungeKutta::integrer(Oscillateur &O1, double const& pas_de_temps) {
        Vecteur k1 = O1.get_vitesse();
        Vecteur k1_prime = O1.evolution(O1.get_position(),O1.get_vitesse());
        Vecteur k2 = O1.get_vitesse() + (pas_de_temps/2)*(k1_prime);
        Vecteur k2_prime = O1.evolution(O1.get_position()+(pas_de_temps/2)*k1,O1.get_vitesse()+(pas_de_temps/2)*k1_prime);
        Vecteur k3 = O1.get_vitesse() + (pas_de_temps/2)*k2_prime;
        Vecteur k3_prime = O1.evolution(O1.get_position()+(pas_de_temps/2)*k2, O1.get_vitesse()+(pas_de_temps/2)*k2_prime);
        Vecteur k4 = O1.get_vitesse() + pas_de_temps*k3_prime;
        Vecteur k4_prime = O1.evolution(O1.get_position() + pas_de_temps*k3, O1.get_vitesse() + pas_de_temps*k3_prime);
        
        O1.set_vecteurs( O1.get_position() + (pas_de_temps/6)*(k1 + 2*k2 + 2*k3 + k4), O1.get_vitesse() + (pas_de_temps/6)*(k1_prime+2*k2_prime+2*k3_prime+k4_prime));
}
    
