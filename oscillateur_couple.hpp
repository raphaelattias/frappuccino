//
//  oscillateur_couple.hpp
//  PROJET
//
//  Created by Raphael Attias on 09/05/2018.
//  Copyright © 2018 Raphael Attias. All rights reserved.
//

#pragma once

#include "oscillateur.h"
#include <stdio.h>

class PenduleRessort: public Oscillateur{
public:
    Vecteur evolution() const;
};
