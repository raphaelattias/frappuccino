#include "supportadessin.h"
#include "TextViewer.h"
#include "oscillateur.h"
#include "pendule.h"
#include "ressort.h"
#include "systeme.h"
#include <iostream>
#include <fstream>


using namespace std;

/*
TextViewer::TextViewer(ostream& sortie): fichier(&sortie), nom_de_fichier("data.txt"){
	fichier.
}*/

TextViewer::~TextViewer(){}

void TextViewer::dessineSupport(Pendule const& pendule) {
     pendule.afficher_evolution(std::cout);
}
void TextViewer::dessineSupport(Ressort const& ressort) {
     ressort.afficher_evolution(std::cout);
}

void TextViewer::dessineSupport(Systeme const& systeme) {
	systeme.afficher(cout);
};
