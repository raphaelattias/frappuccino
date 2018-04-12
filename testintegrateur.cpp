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
#include "oscillateur.h"
#include "vecteur.h"
#include "pendule.h"


#include "constantes.h"

#include <iomanip>
#include <string>
#include <fstream>

using namespace std;


/*
 
 
 
 COMMENT REDEFINIR LA FONCTION D'EVOLUTION DANS CHAQUE SOUS CLASSE D'OSCILLATEUR
 
 
 
 
 
 
 */


class Integrateur{
public:
    Integrateur(double pas_de_temps=0.01): pas_de_temps(pas_de_temps){};
    void afficherEvolution(Oscillateur const& oscillateur) const{
        cout << "Vecteur de position :" << setprecision(10) << oscillateur.get_position();
        cout << endl << "Vecteur de vitesse :" << setprecision(10) << oscillateur.get_vitesse();
        cout << endl;
    }
protected:
    double pas_de_temps;
};


class IntegrateurEulerCromer: public Integrateur {
public:
    IntegrateurEulerCromer(double pas_de_temps):Integrateur(pas_de_temps){};
    void integrerEC(Oscillateur &O1){
        O1.set_vecteurs(O1.get_position(), O1.get_vitesse() + pas_de_temps*O1.evolution());
        O1.set_vecteurs(O1.get_position() + pas_de_temps*O1.get_vitesse(), O1.get_vitesse());
    }
};


int main(){
    
    string nom_fichier;
    nom_fichier = "dat";
    ofstream fichier(nom_fichier);
    if (fichier.fail()) {
        cerr << "Impossible" << endl;
    } else {
        
                        Pendule O1({0,1},{1,2}, 0.127);
                        IntegrateurEulerCromer I1(0.01);
        
                        cout << O1.evolution();
        
                        for(int i=0; i <= 100; i++){
                        I1.integrerEC(O1);
                        O1.afficher_evolution();
                        cout << endl;
                }
        
        
        fichier.close();
    }
    
    
        
    
    /*
    O1.set_vecteurs(v1, v2);
    IntegrateurEulerCromer I1(0.00001);
    I1.integrerEC(O1);
    O1.afficher_evolution();
    return 0;*/
}
