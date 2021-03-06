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

TextViewer::TextViewer(ostream& sortie): fichier(&sortie), nom_de_fichier("data.txt"){
    i = 0;
}

TextViewer::~TextViewer(){}

void TextViewer::dessineOsc(Oscillateur const& oscillateur) {
    if (fichier->fail()) {
        cerr << "Impossible" << endl;
    } else {
        oscillateur.afficher_evolution(*fichier);
    }
}

void TextViewer::dessineSupport(Pendule const& pendule) {
    dessineOsc(pendule);
}
void TextViewer::dessineSupport(Ressort const& ressort) {
    dessineOsc(ressort);
}

void TextViewer::dessineSupport(Systeme const& systeme) {
 //   systeme.afficher(*fichier);
};


void TextViewer::dessineSupport(PenduleTorsion const& ressort) {
    dessineOsc(ressort);
}

void TextViewer::dessineSupport(RessortDouble const& ressort) {
    dessineOsc(ressort);
}


void TextViewer::dessineSupport(PenduleDouble const& pd){
    dessineOsc(pd);
}

void TextViewer::dessineSupport(PenduleRessort const& pr){
    dessineOsc(pr);
}

void TextViewer::dessineSupport(PendulesLiesRessort const& pr){
    dessineOsc(pr);
}

void TextViewer::dessineSupport(Chariot const& chariot){
    dessineOsc(chariot);
}

void TextViewer::dessineSupport(PenduleTriple const& pdt){
    dessineOsc(pdt);
}

