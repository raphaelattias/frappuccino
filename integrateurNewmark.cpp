#include <cmath>
#include "integrateurNewmark.hpp"
/*
void IntegrateurNewmark::integrer(Oscillateur &O1, double const& pas_de_temps){
    Vecteur Vitesse_Sortie = O1.get_vitesse();
    Vecteur Position_Sortie = O1.get_position();
    s = O1.evolution();
    
    do {
        q = O1.get_position();
        r = O1.evolution(Position_Sortie, Vitesse_Sortie);
     //  Vitesse_Sortie = O1.get_vitesse() + 0.5*pas_de_temps*(r+s);
   //    Position_Sortie = O1.get_position() + pas_de_temps*O1.get_vitesse() + (1/3)*(pas_de_temps)*(pas_de_temps)*(0.5*r+s);$
        
        O1.set_vecteurs(Position_Sortie + pas_de_temps*Vitesse_Sortie+ (1/3)*(pas_de_temps)*(pas_de_temps)*(0.5*r+s), Position_Sortie + pas_de_temps*Vitesse_Sortie + (1/3)*(pas_de_temps)*(pas_de_temps)*(0.5*r+s));
    } while ((Position_Sortie-q).norme()>= 0.0001);


}*/



/*
 void IntegrateurNewmark::integrer(OscillateursCouples &O1, double const& pas_de_temps){
    Vecteur Vitesse_Sortie = O1.get_vitesse();
    Vecteur Position_Sortie = O1.get_position();
    s = O1.evolution();
    
    do {
        q = Position_Sortie;
        r = O1.evolution(Position_Sortie, Vitesse_Sortie);
        Vitesse_Sortie = O1.get_vitesse() + 0.5*pas_de_temps*(r+s);
        Position_Sortie = O1.get_position() + pas_de_temps*O1.get_vitesse() + (1/3)*(pas_de_temps)*(pas_de_temps)*(0.5*r+s);
    } while ((Position_Sortie-q).norme()>Epsilon);
    
    Vecteur Vitesse_Sortie2 = O1.get_vitesse2();
    Vecteur Position_Sortie2 = O1.get_position2();
    s = O1.evolution2();
    
    do {
        q = Position_Sortie2;
        r = O1.evolution2(Position_Sortie2, Vitesse_Sortie2);
        Vitesse_Sortie2 = O1.get_vitesse2() + 0.5*pas_de_temps*(r+s);
        Position_Sortie2 = O1.get_position2() + pas_de_temps*O1.get_vitesse2() + (1/3)*(pas_de_temps)*(pas_de_temps)*(0.5*r+s);
    } while ((Position_Sortie2-q).norme()>Epsilon);
    
 
    
    
    O1.set_vecteurs(Position_Sortie, Vitesse_Sortie, Position_Sortie2, Vitesse_Sortie2);
}*/
