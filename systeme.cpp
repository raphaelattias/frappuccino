//
//  systeme.cpp
//  PROJET
//
//  Created by Raphael Attias on 18/04/2018.
//  Copyright © 2018 Raphael Attias. All rights reserved.
//

#include "dessinable.h"
#include "oscillateur.h"
#include <stdio.h>
#include <vector>
#include "integrateur.h"
#include <memory>
#include "systeme.h"




/*
    Systeme(Integrateur integrateur, vector<Oscillateur*> init_list) : integrateur(integrateur) {
        for (int i(0); i < init_list.size() ; i++){
            //collection.push_back(init_list[i]);
        }
    }
    */
    


    void Systeme::dessine() {
        for(int i = 0; i < collection.size() ; ++i) {
            collection[i] -> dessine();
        }
    }

    void Systeme::ajouter(Oscillateur const& oscillateur){
        collection.push_back(oscillateur.copie());
    }
    
    void Systeme::evolue(Integrateur I){
        for(int i=0; i < collection.size(); i++){
            I.integrer(*collection[i]);
        }
    }

    /*Oscillateur Systeme::get_oscillateur(size_t i) const {
       return *collection[i]; //on peut pas return d'objet d'une instance qui va jamais exister
    }*/

    
    vector<unique_ptr<Oscillateur>> collection;

