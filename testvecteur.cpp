//
//  vecteur.cpp
//  Brouillon
//
//  Created by Raphael Attias on 09/03/2018.
//  Copyright © 2018 Raphael Attias. All rights reserved.
//

#include "vecteur.h"

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <stdexcept>

using namespace std;


class Apero{
    
public:
    Apero(){
        cout <<" ça va être super !" << endl;
    }
    void bis(){
        cout << "tg" << endl;
    }
    
};

int main() {
    Apero bic;
    cout << "Super !" << endl;
    bic.bis();
    cout << "Non merci." << endl;
    return 0;
}
