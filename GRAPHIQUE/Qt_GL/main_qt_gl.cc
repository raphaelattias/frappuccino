#include <QApplication>
#include "glwidget.h"
#include "integrateur.h"
#include "integrateurNewmark.hpp"
#include "IntegrateurRungeKutta.h"
#include "systeme.h"

int main(int argc, char* argv[])
{

  QApplication a(argc, argv);
  GLWidget w;


  IntegrateurEulerCromer I1;
  IntegrateurNewmark I2;
  IntegrateurRungeKutta I3;
  w.set_integrateur(I1);

  Pendule n({7,0,0}, {0,0}, {0,0, 0}, 2, 1, 0);
  Chariot c({2,0}, {0, 0}, {-3,0,0},1, 1, 1, 2, 1, 1, 50);
  PenduleDouble pd({5,10,0}, {3,6,0}, {1,0,0},1, 1, 1, 2, 0, 0);
  PendulesLiesRessort d({1,1}, {0, 0}, {0,0, 0}, 1, 1, 1, 1, 1, 1, 50, 0.8, 0.5, 2);
  PenduleTriple P1({0,0,1}, {0,0,3},{0,4,0}, 1, 1 ,1, 1, 1, 1, 0, 0);
  Ressort R1({1,0}, {1,0}, {0,0,0}, 3, 0.01, 0.01, 10, {1, 0});
  PenduleTorsion pt({3,0,0}, {0,0}, {0,0, 0}, 2, 1, 1, 1, 0);
  PenduleRessort p({0.2,0,0.1}, {0.7, 0.5,0},{3,0,0}, 1.3, 0.4, 1, 1, 1, 1, 20);
  RessortDouble rd({1,4,0}, {0,10,0},{0,3,0}, 1, 1 ,1, 3, 0.1, 1, 5, 10, 4, 4, {1, 1,0});

  w.ajouter_oscillateur(pd);
  w.ajouter_oscillateur(d);
 // w.activerSuiviCamera(-3);


  w.show();

  return a.exec();
}
