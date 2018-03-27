//
//  testintegrateur.cpp
//  PROJET
//
//  Created by Raphael Attias on 21/03/2018.
//  Copyright © 2018 Raphael Attias. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include "Oscillateur.h"
#include "vecteur.h"
#include "pendule.h"

using namespace std;

class Integrateur{
public:
    Integrateur(double pas_de_temps=0.1): pas_de_temps(pas_de_temps){};
    void afficherEvolution(Oscillateur const& oscillateur) const{
        cout << "Vecteur d'état :" << oscillateur.get_vitesse();
        cout << endl << "Vecteur de vitesse :" << oscillateur.get_etat();
        cout << endl;
    }
protected:
    double pas_de_temps;
};

class IntegrateurEulerCromer: public Integrateur {
public:
    IntegrateurEulerCromer(double pas_de_temps):Integrateur(pas_de_temps){};
    void integrerEC(Oscillateur &O1){
        O1.set_vecteurs(O1.get_vitesse() + O1.evolution(pas_de_temps), O1.get_etat() + pas_de_temps*O1.get_vitesse());
    }
};


int main(){
    Vecteur v0;
    Vecteur v1(3.14/2, 0, 0);
    Vecteur v2(0,0,0);
    Pendule pendule;
    cout << v1 << endl;
    /*
    O1.set_vecteurs(v1, v2);
    IntegrateurEulerCromer I1(0.00001);
    I1.integrerEC(O1);
    O1.afficher_evolution();
    return 0;*/
}
