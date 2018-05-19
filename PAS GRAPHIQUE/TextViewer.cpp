//
//  TextViewer.cpp
//  PROJET
//
//  Created by Steve Jobs on 18/04/2018.
//  Copyright © 2018 Steve Jobs. All rights reserved.
//

#include <stdio.h>
#include "supportadessin.h"
#include "TextViewer.h"
#include "pendule.h"
#include "ressort.h"
#include <iostream>
#include <fstream>


using namespace std;

TextViewer::TextViewer(string nom_de_fichier): nom_de_fichier(nom_de_fichier){
    fichier.open(nom_de_fichier, fstream::trunc);
}

TextViewer::~TextViewer(){
    fichier.close();
}



void TextViewer::remettre_a_zero(){
    //fichier.open(nom_de_fichier, ios::trunc);
}


void TextViewer::dessineOsc(Oscillateur const& oscillateur) {
    if (fichier.fail()) {
        cerr << "Impossible" << endl;
    } else {
        oscillateur.afficher_evolution(fichier);
    }
}



void TextViewer::dessineSupport(Pendule const& pendule) {
    dessineOsc(pendule);
}
void TextViewer::dessineSupport(Ressort const& ressort) {
    dessineOsc(ressort);
}

/*void TextViewer::dessineSupport(Systeme const& syst) {

}*/

    

