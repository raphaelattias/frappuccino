#ifndef VUEOPENGL_H
#define VUEOPENGL_H

#include <QOpenGLShaderProgram> // Classe qui regroupe les fonctions OpenGL liées aux shaders
#include <QMatrix4x4>
#include "supportadessin.h"
#include "glsphere.h"
#include "systeme.h"
#include "qpainter.h"
#include "qstring.h"

class VueOpenGL : public SupportADessin {
 public:

  // méthode(s) de dessin (héritée(s) de SupportADessin)
  virtual void dessineSupport(Systeme const& a_dessiner) override;

  void dessineAxes(QMatrix4x4 const& point_de_vue, bool en_couleur = true);

  virtual void dessineSupport(Ressort const& a_dessiner) override;
  virtual void dessineSupport(Pendule const& a_dessiner) override;
  virtual void dessineSupport(PenduleDouble const& a_dessiner) override;
  virtual void dessineSupport(PenduleRessort const& a_dessiner) override;
  virtual void dessineSupport(Chariot const& a_dessiner) override;
  virtual void dessineSupport(PendulesLiesRessort const& a_dessiner) override;
  virtual void dessineSupport(PenduleTriple const& a_dessiner) override;
  virtual void dessineSupport(RessortDouble const& a_dessiner) override;
  virtual void dessineSupport(PenduleTorsion const& a_dessiner) override;


  // méthodes de (ré-)initialisation
  void init();
  void initializePosition();
  void vueZero();

  // méthode set
  void setProjection(QMatrix4x4 const& projection)
  { prog.setUniformValue("projection", projection); }
  void setPhase(bool b);
  void setSuiviCamera(double z);
  void setNausee(bool nausee);
  // Méthodes set
  void translate(double x, double y, double z);
  void rotate(double angle, double dir_x, double dir_y, double dir_z);
  
  // méthode utilitaire offerte pour simplifier
  void dessineCube(QMatrix4x4 const& point_de_vue = QMatrix4x4() );  
  void dessineSphere(QMatrix4x4 const& point_de_vue,
                     double rouge = 1.0, double vert = 1.0, double bleu = 1.0);
  void dessineFace(QMatrix4x4 const& point_de_vue,double l = 1, double L = 1,
                     double x = 1.0, double y = 1.0, double z = 1.0);

 private:
  // Un shader OpenGL encapsulé dans une classe Qt
  QOpenGLShaderProgram prog;

  // Caméra
  QMatrix4x4 matrice_vue;

  GLSphere sphere;

  // Interrupteur pour espace des phases;
  bool espacePhase;
  std::vector<Vecteur> points;

  // Interrupteur pour suivi caméra
  bool suiviCamera;
  double z;
  bool nausee;
};

#endif
