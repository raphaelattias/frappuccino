#include "pendule.h"
#include "oscillateur.h"
#include "integrateur.h"
#include <cmath>
#include "constantes.h"

class Integrateur;

using namespace std;


Pendule::Pendule(Vecteur position, Vecteur vitesse, Vecteur origine, double masse, double longueur, double coefFrottement, SupportADessin* SAD):
    Oscillateur(position,vitesse,origine,masse,longueur, coefFrottement, SAD) {} ;

Vecteur Pendule::evolution(Vecteur const& position_, Vecteur const& vitesse_) const {
 Vecteur sortie({(-g.norme()/longueur)*sin(position_.get_value(1))});
    return sortie;
}

unique_ptr<Pendule> Pendule::clone() const{
    return unique_ptr<Pendule>(new Pendule(*this));
}

unique_ptr<Oscillateur> Pendule::copie() const{
    return clone();
}

void Pendule::dessine(Integrateur* integrateur, double const& dt, int const& i){
    for(int j = 0; j < i; j++){
        support->dessineSupport(*this);
        if(integrateur != nullptr && ((i > 0) && (dt > 0))){
            integrateur->integrer(*this, dt);
        }
    }
}




