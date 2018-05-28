#include "pendule.h"
#include "oscillateur.h"
#include "integrateur.h"
#include <cmath>
#include "constantes.h"

class Integrateur;

using namespace std;


Pendule::Pendule(Vecteur position, Vecteur vitesse, double masse, double longueur, double coefFrottement):
    Oscillateur(position,vitesse,masse,longueur,coefFrottement) {} ;

Vecteur Pendule::evolution(Vecteur const& position_, Vecteur const& vitesse_) const {
 Vecteur sortie({(-g.norme()/longueur)*sin(position_.get_value(1))});
    return sortie;
}


