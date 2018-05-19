 //
//  systeme.h
//  PROJET
//
//  Created by Raphael Attias on 18/04/2018.
//  Copyright © 2018 Raphael Attias. All rights reserved.
//

#pragma once

using namespace std;

class Systeme : public Dessinable {
public:
    Systeme(Integrateur I1);
  virtual void dessine() override;
  Oscillateur get_oscillateur(size_t i) const;
  void ajouter(Oscillateur const& oscillateur);
  void evolue(Integrateur I);
private:
   vector<unique_ptr<Oscillateur>> collection;
    unique_ptr<Integrateur> integrateur;
};
