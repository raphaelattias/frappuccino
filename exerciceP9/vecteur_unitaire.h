#pragma once


class Vecteur_unitaire : public Vecteur {
public:
    Vecteur_unitaire();
    
    Vecteur_unitaire(double x, double y, double z);
    
    
    
    Vecteur_unitaire(const Vecteur& copie);
        void normalise();
private:
};

