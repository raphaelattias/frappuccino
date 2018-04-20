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


void TextViewer::dessineOsc(Oscillateur const& oscillateur) {
    string nom_fichier;
    nom_fichier = "dat";
    ofstream fichier(nom_fichier);
    if (fichier.fail()) {
        cerr << "Impossible" << endl;
    } else {
        oscillateur.afficher_evolution(fichier);
        fichier.close();
    }
}



void TextViewer::dessineSupport(Pendule const& pendule) {
    dessineOsc(pendule);
}
void TextViewer::dessineSupport(Ressort const& ressort) {
    dessineOsc(ressort);
}

    

