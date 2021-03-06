#include <cmath>
#include "integrateurNewmark.hpp"

void IntegrateurNewmark::integrer(Oscillateur &O1, double const& pas_de_temps){
    Vecteur Vitesse_Sortie = O1.get_vitesse();
    Vecteur Position_Sortie = O1.get_position();
    s = O1.evolution();
    
    do {
        q = Position_Sortie;
        r = O1.evolution(Position_Sortie, Vitesse_Sortie);
        Vitesse_Sortie = O1.get_vitesse() + 0.5*pas_de_temps*(r+s);
        Position_Sortie = O1.get_position() + pas_de_temps*O1.get_vitesse() + (1.0/3.0)*(pas_de_temps)*(pas_de_temps)*(0.5*r+s);
    } while ((Position_Sortie-q).norme()>Epsilon);
    O1.set_vecteurs(Position_Sortie, Vitesse_Sortie);
}

IntegrateurNewmark::IntegrateurNewmark(double Epsilon): Epsilon(Epsilon){};

