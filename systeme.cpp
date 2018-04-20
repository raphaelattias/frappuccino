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

using namespace::std;

class Systeme: public Dessinable{
/*
    Systeme(Integrateur integrateur, vector<Oscillateur*> init_list) : integrateur(integrateur) {
        for (int i(0); i < init_list.size() ; i++){
            //collection.push_back(init_list[i]);
        }
    }
    */
    
    void ajouter(Oscillateur const& oscillateur){
        collection.push_back(oscillateur.copie());
    }
    
    void evolue(){
        for(int i=0; i < collection.size(); i++){
            integrateur.integrer(*collection[i]);
        }
    }
    
    Integrateur integrateur;
    vector<unique_ptr<Oscillateur>> collection;
    
};
