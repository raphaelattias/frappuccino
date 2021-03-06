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
#include "systeme.h"
#include "oscillateur_couple.hpp"
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

void TextViewer::dessineSupport(Systeme const& systeme) {
    systeme.afficher(fichier);
};

void TextViewer::dessineSupport(PenduleDouble const& pd){
    std::cout << pd.get_position().get_value(1) << "     " << pd.get_position().get_value(2) << endl;
}

void TextViewer::dessineSupport(PenduleRessort const& pr){
    std::cout << "slt";
}

void TextViewer::dessineSupport(PendulesLiesRessort const& pr){
    std::cout << "slt";
}

void TextViewer::dessineSupport(Chariot const& chariot){
    std::cout << "slt";
}
