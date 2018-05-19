//
//  vecteur_unitaire.h
//  PROJET
//
//  Created by Raphael Attias on 18/04/2018.
//  Copyright © 2018 Raphael Attias. All rights reserved.
//

#pragma once


class Vecteur_unitaire : public Vecteur {
public:
    Vecteur_unitaire();
    
    Vecteur_unitaire(double x, double y, double z);
    
    
    
    Vecteur_unitaire(const Vecteur& copie);
        void normalise();
private:
/*
    Vecteur_unitaire& operator+=(const Vecteur& autre);
    Vecteur_unitaire& operator-=(const Vecteur& autre);
    Vecteur_unitaire& operator*=(double x);*/
};

