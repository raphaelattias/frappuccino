//
//  TextViewer.h
//  PROJET
//
//  Created by Steve Jobs on 18/04/2018.
//  Copyright © 2018 Steve Jobs. All rights reserved.
//

#ifndef TextViewer_h
#define TextViewer_h
#include <stdio.h>
#include "supportadessin.h"
#include "oscillateur.h"
#include <iostream>
#include <fstream>


using namespace std;

class TextViewer : public SupportADessin {

public:
    TextViewer(string nom_de_fichier = "data.txt");
    ~TextViewer();
protected:
    void remettre_a_zero() override;
    
private:
    
    
    virtual void dessineSupport(Pendule const& pendule) override;
    virtual void dessineSupport(Ressort const& ressort) override;
    /*virtual void dessineSupport(Systeme const& ) override;*/
    
    void dessineOsc(Oscillateur const& oscillateur);
    string nom_de_fichier;
    ofstream fichier;

    
};




#endif /* TextViewer_h */
