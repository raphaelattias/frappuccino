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

class TextViewer : public SupportADessin {
    
public:
    TextViewer(std::string nom_de_fichier = "data.txt");
    ~TextViewer();
    void ajouter(std::string const& txt);

private:
    
    
    virtual void dessineSupport(Pendule const& pendule) override;
    virtual void dessineSupport(Ressort const& ressort) override;
    virtual void dessineSupport(Systeme const& systeme) override;
    virtual void dessineSupport(PenduleDouble const& PenduleDouble) override;
    virtual void dessineSupport(PenduleRessort const& penduleressort) override;
    virtual void dessineSupport(Chariot const& penduleressort) override;
    virtual void dessineSupport(RessortDouble const& penduleressort) override;
    virtual void dessineSupport(PenduleTorsion const& penduleressort) override;
    virtual void dessineSupport(PendulesLiesRessort const& penduleressort) override;
    virtual void dessineSupport(PenduleTriple const& penduleressort) override;
    void dessineOsc(Oscillateur const& oscillateur);
    std::string nom_de_fichier;
    
    std::ofstream fichier;
    
    
};


#endif /* TextViewer_h */
