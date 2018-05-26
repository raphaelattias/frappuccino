#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>        // Classe pour faire une fenêtre OpenGL
#include <QTime>            // Classe pour gérer le temps
#include "vue_opengl.h"
#include "systeme.h"
#include "integrateurEulerCromer.h"
#include "pendule.h"
#include "ressort.h"
#include "oscillateur.h"

class GLWidget : public QOpenGLWidget
/* La fenêtre hérite de QOpenGLWidget ;
 * les événements (clavier, souris, temps) sont des méthodes virtuelles à redéfinir.
 */
{
public:
    GLWidget(QWidget* parent = nullptr)
        : QOpenGLWidget(parent){
       // Chariot p(&vue, {1,1}, {0, 0}, 1, 1, 1, 1, 1, 1, 30);
        PendulesLiesRessort p(&vue, {1,1}, {0, 0}, 1, 1, 1, 0.8, 1, 1, 100, 0.5, 0.5, 4);
      //  PendulesLiesRessort p1(&vue, {1,1}, {0, 0}, 1, 1, 1, 1, 1, 1, 1, 0.5, 0.5, 0.1);

//    Pendule q(&vue, {2,0,0}, {0,0}, 2, 2, 0);
   // Pendule n(&vue, {0.1,0,0}, {0,0}, 2, 0.1, 0);
   // Ressort R1(&vue , {1,0}, {1,0}, 3, 0.01, 0.01, 10, {1, 0});
   //PenduleDouble P(&vue, {3,0,0}, {0,0,0}, 1, 1, 1, 0.1, 0, 0);
  // PenduleDouble P1(&vue, {1,2,0}, {0,0,0}, 1, 1, 1, 0.5, 0, 0);

       // PenduleRessort p(&vue, {1,0,0}, {0,0,0}, 0.15, 0.18, 1, 2, 1, 1, 10);


    s.assignerSupport(vue);
    s.ajouter(p);
  //  s.ajouter(p1);
     /* s.ajouter(q);
      s.ajouter(n);*/
      //s.ajouter(R1);
     // s.ajouter(P);
  //    s.ajouter(P1);
    }
  virtual ~GLWidget() {}

   void set_integrateur(Integrateur &I1);

private:
  // Les 3 méthodes clés de la classe QOpenGLWidget à réimplémenter
  virtual void initializeGL()                  override;
  virtual void resizeGL(int width, int height) override;
  virtual void paintGL()                       override;

  // Méthodes de gestion d'évènements
  virtual void keyPressEvent(QKeyEvent* event) override;
  virtual void timerEvent(QTimerEvent* event)  override;

  // Méthodes de gestion interne
  void pause();

  // Vue : ce qu'il faut donner au contenu pour qu'il puisse se dessiner sur la vue //que représnte la vue
  VueOpenGL vue;

  // Timer
  int timerId;
  // pour faire évoluer les objets avec le bon "dt"
  QTime chronometre;

  // objets à dessiner, faire évoluer
  Systeme s;

  IntegrateurEulerCromer I1;

};

#endif // GLWIDGET_H
