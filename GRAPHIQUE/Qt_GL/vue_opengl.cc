#include "vue_opengl.h"
#include "vertex_shader.h" // Identifiants Qt de nos différents attributs
#include "systeme.h"
#include "pendule.h"
#include "ressort.h"
#include <cmath>

#include <QpointF>
#include <QVector>

// ======================================================================
void VueOpenGL::dessineSupport(Systeme const& a_dessiner)
{

    QMatrix4x4 matrice;

  dessineAxes(matrice);



  // Dessine le cube

  //dessineCube(matrice);


  //grille axe Z
  glBegin(GL_LINES);
  prog.setAttributeValue(CouleurId, 1.0, 1.0, 1.0); // blanc aussi


  for(int i = -11; i <= 10; i++){
      i++;
    prog.setAttributeValue(SommetId, -10.0, -1, i);
    prog.setAttributeValue(SommetId, 10.0, -1, i);

    prog.setAttributeValue(SommetId, i, -1, -10);
    prog.setAttributeValue(SommetId, i, -1, 10);
  }

  glEnd();


/*
  matrice.translate(-0.5, 0.0, -2.0);
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // passe en mode "fil de fer"
  dessineSphere(matrice, 0.0, 0.0); // bleu
  matrice.scale(1.5); // taille des axes (1.5 pour qu'ils dépassent un peu)
  dessineAxes(matrice, false); // dessine (en blanc) les axes de la sphere

  matrice.setToIdentity();
  matrice.translate(1.0, 0.0, -2.0);
  matrice.scale(0.5);
  matrice.rotate(-30, 0.0, 1.0, 0.0);
  matrice.rotate(-30, 1.0, 0.0, 0.0);
  dessineSphere(matrice, 1.0, 1.0, 0.0); // jaune
  matrice.scale(1.5);
  dessineAxes(matrice); // dessine (en couleur) les axes de la sphere

  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // repasse en mode "plein"*/


}

// ======================================================================
void VueOpenGL::init()
{
  /* Initialise notre vue OpenGL.
   * Dans cet exemple, nous créons et activons notre shader.
   *
   * En raison du contenu des fichiers *.glsl, le shader de cet exemple
   * NE permet QUE de dessiner des primitives colorées
   * (pas de textures, brouillard, reflets de la lumière ou autres).
   *
   * Il est séparé en deux parties VERTEX et FRAGMENT.
   * Le VERTEX :
   * - récupère pour chaque sommet des primitives de couleur (dans
   *     l'attribut couleur) et de position (dans l'attribut sommet)
   * - multiplie l'attribut sommet par les matrices 'vue_modele' et
   *     'projection' et donne le résultat à OpenGL
   *   - passe la couleur au shader FRAGMENT.
   *
   * Le FRAGMENT :
   *   - applique la couleur qu'on lui donne
   */

  prog.addShaderFromSourceFile(QOpenGLShader::Vertex,   ":/vertex_shader.glsl");
  prog.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/fragment_shader.glsl");

  /* Identifie les deux attributs du shader de cet exemple
   * (voir vertex_shader.glsl).
   *
   * L'attribut identifié par 0 est particulier, il permet d'envoyer un
   * nouveau "point" à OpenGL
   *
   * C'est pourquoi il devra obligatoirement être spécifié et en dernier
   * (après la couleur dans cet exemple, voir plus bas).
   */

  prog.bindAttributeLocation("sommet",  SommetId);
  prog.bindAttributeLocation("couleur", CouleurId);

  // Compilation du shader OpenGL
  prog.link();

  // Activation du shader
  prog.bind();

  /* Activation du "Test de profondeur" et du "Back-face culling"
   * Le Test de profondeur permet de dessiner un objet à l'arrière-plan
   * partielement caché par d'autres objets.
   *
   * Le Back-face culling consiste à ne dessiner que les face avec ordre
   * de déclaration dans le sens trigonométrique.
   */
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);

  sphere.initialize();                                      // initialise la sphère

  initializePosition();
}

// ======================================================================
void VueOpenGL::dessineSphere (QMatrix4x4 const& point_de_vue, double rouge, double vert, double bleu)
{
  prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);
  prog.setAttributeValue(CouleurId, rouge, vert, bleu);  // met la couleur
  sphere.draw(prog, SommetId);                           // dessine la sphère
}

// ======================================================================
void VueOpenGL::initializePosition()
{
  // position initiale
  matrice_vue.setToIdentity();
  matrice_vue.translate(0.0, -1, -5.0);
// matrice_vue.rotate(60.0, 0.0, 1.0, 0.0);
// matrice_vue.rotate(45.0, 0.0, 0.0, 1.0);
 // matrice_vue.rotate(20, 0, 1, 0);
}

// ======================================================================
void VueOpenGL::setPhase(bool b){
    espacePhase = b;
}

// ======================================================================
void VueOpenGL::setSuiviCamera(double z){
    suiviCamera = 1;

    this->z=z;
}
// ======================================================================
void VueOpenGL::setNausee(bool nausee){
this->nausee=nausee;
}

// ======================================================================
void VueOpenGL::vueZero(){
    matrice_vue.setToIdentity();
    matrice_vue.translate(0, 0, -3.0);
}

// ======================================================================
void VueOpenGL::translate(double x, double y, double z)
{
  /* Multiplie la matrice de vue par LA GAUCHE.
   * Cela fait en sorte que la dernière modification apportée
   * à la matrice soit appliquée en dernier (composition de fonctions).
   */
  QMatrix4x4 translation_supplementaire;
  translation_supplementaire.translate(x, y, z);
  matrice_vue = translation_supplementaire * matrice_vue;
}

// ======================================================================
void VueOpenGL::rotate(double angle, double dir_x, double dir_y, double dir_z)
{
  // Multiplie la matrice de vue par LA GAUCHE
  QMatrix4x4 rotation_supplementaire;
  rotation_supplementaire.rotate(angle, dir_x, dir_y, dir_z);
  matrice_vue = rotation_supplementaire * matrice_vue;
}

// ======================================================================
void VueOpenGL::dessineCube (QMatrix4x4 const& point_de_vue)
{
  prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);

  glBegin(GL_QUADS);
  // face coté X = +1
  prog.setAttributeValue(CouleurId, 1.0, 1.0, 1.0); // blanc
  prog.setAttributeValue(SommetId, +1.0, -1.0, -0.25);
  prog.setAttributeValue(SommetId, +1.0, +1.0, -0.25);
  prog.setAttributeValue(SommetId, +1.0, +1.0, +0.25);
  prog.setAttributeValue(SommetId, +1.0, -1.0, +0.25);

  // face coté X = -1
  prog.setAttributeValue(CouleurId, 1.0, 1.0, 1.0); // vert
  prog.setAttributeValue(SommetId, -1.0, -1.0, -0.25);
  prog.setAttributeValue(SommetId, -1.0, -1.0, +0.25);
  prog.setAttributeValue(SommetId, -1.0, +1.0, +0.25);
  prog.setAttributeValue(SommetId, -1.0, +1.0, -0.25);

  // face coté Y = +1
  prog.setAttributeValue(CouleurId, 1.0, 1.0, 1.0); // bleu
  prog.setAttributeValue(SommetId, -1, +1.0, -0.25);
  prog.setAttributeValue(SommetId, -1, +1.0, +0.25);
  prog.setAttributeValue(SommetId, +1, +1.0, +0.25);
  prog.setAttributeValue(SommetId, +1, +1.0, -0.25);

  // face coté Y = -1
  prog.setAttributeValue(CouleurId, 1.0, 1.0, 1.0); // cyan
  prog.setAttributeValue(SommetId, -1.0, -1.0, -0.25);
  prog.setAttributeValue(SommetId, +1.0, -1.0, -0.25);
  prog.setAttributeValue(SommetId, +1.0, -1.0, +0.25);
  prog.setAttributeValue(SommetId, -1.0, -1.0, +0.25);

  // face coté Z = +1
  prog.setAttributeValue(CouleurId, 1.0, 0.0, 0.0); // jaune a ne pas modifier
  prog.setAttributeValue(SommetId, -1.0, -1.0, 0.25);
  prog.setAttributeValue(SommetId, +1.0, -1.0, 0.25);
  prog.setAttributeValue(SommetId, +1.0, +1.0, 0.25);
  prog.setAttributeValue(SommetId, -1.0, +1.0, 0.25);

  // face coté Z = -1
  prog.setAttributeValue(CouleurId, 1.0, 0.0, 0.0); // magenta a ne pas modifier
  prog.setAttributeValue(SommetId, -1.0, -1.0, -0.25);
  prog.setAttributeValue(SommetId, -1.0, +1.0, -0.25);
  prog.setAttributeValue(SommetId, +1.0, +1.0, -0.25);
  prog.setAttributeValue(SommetId, +1.0, -1.0, -0.25);

  glEnd();
}

// ======================================================================
void VueOpenGL::dessineAxes (QMatrix4x4 const& point_de_vue, bool en_couleur)
{
  prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);

  glBegin(GL_LINES);

  // axe X
  if (en_couleur) {
    prog.setAttributeValue(CouleurId, 1.0, 0.0, 0.0); // rouge
  } else {
    prog.setAttributeValue(CouleurId, 1.0, 1.0, 1.0); // blanc
  }
  prog.setAttributeValue(SommetId, 0.0, 0.0, 0.0);
  prog.setAttributeValue(SommetId, 1.0, 0.0, 0.0);

  // axe Y
  if (en_couleur) prog.setAttributeValue(CouleurId, 0.0, 1.0, 0.0); // vert
  prog.setAttributeValue(SommetId, 0.0, 0.0, 0.0);
  prog.setAttributeValue(SommetId, 0.0, 1.0, 0.0);

  // axe Z
  if (en_couleur) prog.setAttributeValue(CouleurId, 0.0, 0.0, 1.0); // bleu
  prog.setAttributeValue(SommetId, 0.0, 0.0, 0.0);
  prog.setAttributeValue(SommetId, 0.0, 0.0, 1.0);

  glEnd();
}

// ======================================================================
void VueOpenGL::dessineSupport(PenduleTriple const& a_dessiner){

    QMatrix4x4 matrice;

    // Initialisation du point d'origine de l'oscillateur
    double o_x = a_dessiner.get_origine().get_value(1);
    double o_y = a_dessiner.get_origine().get_value(2);
    double o_z = a_dessiner.get_origine().get_value(3);

    // Attribution des coordonnées de l'oscillateur pour un repère cartésien
    double teta = a_dessiner.get_position().get_value(1);
    teta = teta/a_dessiner.get_longueur();
    double x = o_x + a_dessiner.get_longueur()*sin(teta);
    double y = o_y -a_dessiner.get_longueur()*cos(teta);

    double teta2 = a_dessiner.get_position().get_value(2);
    teta2 = teta2/a_dessiner.get_longueur2();
    double x2 = a_dessiner.get_longueur2()*sin(teta2);
    double y2 = -a_dessiner.get_longueur2()*cos(teta2);

    double teta3 = a_dessiner.get_position().get_value(3);
    teta3 = teta3/a_dessiner.get_longueur3();
    double x3 = a_dessiner.get_longueur3()*sin(teta3);
    double y3 = -a_dessiner.get_longueur3()*cos(teta3);

    // Dessin du premier Pendule
    matrice.setToIdentity();
    matrice.translate(x, y, o_z);
    matrice.scale(0.05);
    dessineSphere(matrice, 1.0, 0.47, 0.09);

    matrice.setToIdentity();

    prog.setUniformValue("vue_modele", matrice_vue * matrice);

    glBegin(GL_LINES);

    prog.setAttributeValue(CouleurId, 1.0, 1.0, 1.0);
    prog.setAttributeValue(SommetId, o_x, o_y, o_z);
    prog.setAttributeValue(SommetId, x , y, o_z);
    glEnd();


    // Dessin du deuxième Pendule
    matrice.setToIdentity();
    matrice.translate(x+x2, y+y2, 0.0);
    matrice.scale(0.05);
    dessineSphere(matrice, 0.59, 0.15, 0.72);

    matrice.setToIdentity();

    prog.setUniformValue("vue_modele", matrice_vue * matrice);

    glBegin(GL_LINES);

    prog.setAttributeValue(CouleurId, 1.0, 1.0, 1.0);
    prog.setAttributeValue(SommetId, x, y, o_z);
    prog.setAttributeValue(SommetId, x2+x , y+y2, o_z);
    glEnd();

    // Dessin du troisième Pendule
    matrice.setToIdentity();
    matrice.translate(x+x2+x3, y+y2+y3, o_z);
    matrice.scale(0.05);
    dessineSphere(matrice, 0.09, 1.0, 232/255);
    matrice.setToIdentity();

    prog.setUniformValue("vue_modele", matrice_vue * matrice);

    glBegin(GL_LINES);

    prog.setAttributeValue(CouleurId,  1.0, 1.0, 1.0);
    prog.setAttributeValue(SommetId, x+x2, y+y2, o_z);
    prog.setAttributeValue(SommetId, x2+x+x3 , y+y2+y3, o_z);
    glEnd();

    // Dessin de l'espace des phases
    QMatrix4x4 phase;
    if(espacePhase){
    phase.translate(a_dessiner.get_position().get_value(1), a_dessiner.get_vitesse().get_value(1), 0);
    phase.scale(0.05);
    dessineSphere(phase, 1.0, 0.47, 0.09);
    phase.setToIdentity();
    phase.translate(a_dessiner.get_position().get_value(2), a_dessiner.get_vitesse().get_value(2), 0);
    phase.scale(0.05);
    dessineSphere(phase, 0.59, 0.15, 0.72);
    phase.setToIdentity();
    phase.translate(a_dessiner.get_position().get_value(3), a_dessiner.get_vitesse().get_value(2), 0);
    phase.scale(0.05);
    dessineSphere(phase, 0.09, 1.0, 232/255);
    }

    // Dessin du parcours
    points.push_back({x,y,o_z});
    points.push_back({x+x2,y+y2,o_z});
    points.push_back({x+x2+x3, y+y2+y3, o_z});

    for(int i = 3; i < points.size(); i+=3){
        glBegin(GL_LINE_STRIP);
        prog.setAttributeValue(CouleurId, 1.0, 0.47, 0.09);
        prog.setAttributeValue(SommetId, points[i-3].get_value(1), points[i-3].get_value(2), o_z);
        prog.setAttributeValue(SommetId, points[i].get_value(1), points[i].get_value(2), o_z);
        glEnd();

        glBegin(GL_LINE_STRIP);
        prog.setAttributeValue(CouleurId, 0.59, 0.15, 0.72);
        prog.setAttributeValue(SommetId, points[i-2].get_value(1), points[i-2].get_value(2), o_z);
        prog.setAttributeValue(SommetId, points[i+1].get_value(1), points[i+1].get_value(2), o_z);
        glEnd();

        glBegin(GL_LINE_STRIP);
        prog.setAttributeValue(CouleurId, 0.09, 1.0, 232/255);
        prog.setAttributeValue(SommetId, points[i-1].get_value(1), points[i-1].get_value(2), o_z);
        prog.setAttributeValue(SommetId, points[i+2].get_value(1), points[i+2].get_value(2), o_z);
        glEnd();
    }

    // Suivi de la caméra
    if(suiviCamera){
        matrice_vue.setToIdentity();
        matrice_vue.translate(-(x+x2+x3) ,-(y+y2+y3),this->z + o_z);
        if(nausee) matrice_vue.rotate(a_dessiner.get_vitesse().get_value(1)*5, 0.0, 0.0, 1.0);
    }

}

// ======================================================================
void VueOpenGL::dessineSupport(PenduleDouble const& a_dessiner){

    QMatrix4x4 matrice;

    // Initialisation du point d'origine de l'oscillateur
    double o_x = a_dessiner.get_origine().get_value(1);
    double o_y = a_dessiner.get_origine().get_value(2);
    double o_z = a_dessiner.get_origine().get_value(3);

    // Attribution des coordonnées de l'oscillateur pour un repère cartésien
    double teta = a_dessiner.get_position().get_value(1);
    teta = teta/a_dessiner.get_longueur();
    double x = o_x + a_dessiner.get_longueur()*sin(teta);
    double y = o_y + -a_dessiner.get_longueur()*cos(teta);

    double teta2 = a_dessiner.get_position().get_value(2);
    teta2 = teta2/a_dessiner.get_longueur2();
    double x2 = a_dessiner.get_longueur2()*sin(teta2);
    double y2 = -a_dessiner.get_longueur2()*cos(teta2);

    // Dessin du premier Pendule
    matrice.setToIdentity();
    matrice.translate(x, y, o_z);
    matrice.scale(0.05);
    dessineSphere(matrice, 1.0, 0.47, 0.09);

    matrice.setToIdentity();

    prog.setUniformValue("vue_modele", matrice_vue * matrice);

    glBegin(GL_LINES);

    prog.setAttributeValue(CouleurId, 1.0, 1.0, 1.0);
    prog.setAttributeValue(SommetId, o_x, o_y, o_z);
    prog.setAttributeValue(SommetId, x , y, o_z);
    glEnd();

    // Dessin du deuxième Pendule
    matrice.setToIdentity();
    matrice.translate(x+x2, y+y2, 0.0);
    matrice.scale(0.05);
    dessineSphere(matrice, 0.59, 0.15, 0.72);


    matrice.setToIdentity();

    prog.setUniformValue("vue_modele", matrice_vue * matrice);

    glBegin(GL_LINES);
    prog.setAttributeValue(CouleurId, 1.0, 1.0, 1.0);
    prog.setAttributeValue(SommetId, x, y, o_z);
    prog.setAttributeValue(SommetId, x2+x , y+y2, o_z);
    glEnd();

    // Dessin de l'espace des phases
    QMatrix4x4 phase;
    if(espacePhase){
    phase.translate(a_dessiner.get_position().get_value(1), a_dessiner.get_vitesse().get_value(1), 0);
    phase.scale(0.05);
    dessineSphere(phase, 1.0, 0.47, 0.09);
    phase.setToIdentity();
    phase.translate(a_dessiner.get_position().get_value(2), a_dessiner.get_vitesse().get_value(2), 0);
    phase.scale(0.05);
    dessineSphere(phase, 0.59, 0.15, 0.72);
    }

    // Suivi de la caméra
    if(suiviCamera){
        matrice_vue.setToIdentity();
        matrice_vue.translate(-x2-x, -y-y2, this->z + o_z);
        if(nausee) matrice_vue.rotate(a_dessiner.get_vitesse().get_value(2)*5, 0.0, 0.0, 1.0);
    }

    Vecteur p(x,y, 0);

    points.push_back({x,y,o_z});
    points.push_back({x+x2,y+y2,o_z});

    // Dessin du parcours
    for(int i = 2; i < points.size(); i+=2){
        glBegin(GL_LINE_STRIP);
        prog.setAttributeValue(CouleurId, 0.0, 1.0, 1.0);
        prog.setAttributeValue(SommetId, points[i-2].get_value(1), points[i-2].get_value(2), o_z);
        prog.setAttributeValue(SommetId, points[i].get_value(1), points[i].get_value(2), o_z);
        glEnd();
        glBegin(GL_LINE_STRIP);
        prog.setAttributeValue(CouleurId, 1.0, 1.0, 1.0);
        prog.setAttributeValue(SommetId, points[i-1].get_value(1), points[i-1].get_value(2), o_z);
        prog.setAttributeValue(SommetId, points[i+1].get_value(1), points[i+1].get_value(2), o_z);
        glEnd();
    }

}

// ======================================================================
void VueOpenGL::dessineSupport(Ressort const& a_dessiner){
      QMatrix4x4 matrice;

      // Initialisation du point d'origine de l'oscillateur
      double o_x = a_dessiner.get_origine().get_value(1);
      double o_y = a_dessiner.get_origine().get_value(2);
      double o_z = a_dessiner.get_origine().get_value(3);

      // Attribution des coordonnées de l'oscillateur pour un repère cartésien
      double x = o_x + a_dessiner.get_position().get_value(1)*a_dessiner.get_unitaire().get_value(1);
      double y = o_y+ a_dessiner.get_position().get_value(1)*a_dessiner.get_unitaire().get_value(2);;
      double z = o_z+ a_dessiner.get_position().get_value(1)*a_dessiner.get_unitaire().get_value(3);;

      matrice.setToIdentity();

      // Dessin du Ressort
      prog.setUniformValue("vue_modele", matrice_vue * matrice);
      glBegin(GL_LINES);
      prog.setAttributeValue(CouleurId, 1.0, 1.0, 1.0);
      prog.setAttributeValue(SommetId, o_x, o_y, o_z);
      prog.setAttributeValue(SommetId, x , y, z);
      glEnd();
      matrice.setToIdentity();
      matrice.translate(x, y , z);

      matrice.scale(0.05);
      dessineSphere(matrice, 0.28, 1.0, 0.43);

      // Dessin de l'espace des phases
      QMatrix4x4 phase;
      if(espacePhase){
      phase.translate(a_dessiner.get_position().get_value(1), a_dessiner.get_vitesse().get_value(1), 0);
      phase.scale(0.05);
      dessineSphere(phase, 0.28, 1.0, 0.43);
      phase.setToIdentity();
      }

      // Suivi de la caméra
      if(suiviCamera){
          matrice_vue.setToIdentity();
          matrice_vue.translate(-x, -y, this->z + z);
          if(nausee) matrice_vue.rotate(a_dessiner.get_vitesse().get_value(1)*5, 0.0, 0.0, 1.0);
      }

}

// ======================================================================
void VueOpenGL::dessineSupport(PenduleRessort const& a_dessiner){
    QMatrix4x4 matrice;

    // Initialisation du point d'origine de l'oscillateur
    double o_x = a_dessiner.get_origine().get_value(1);
    double o_y = a_dessiner.get_origine().get_value(2);
    double o_z = a_dessiner.get_origine().get_value(3);

    // Attribution des coordonnées de l'oscillateur pour un repère cartésien
    double x = o_x + a_dessiner.get_position().get_value(1);
    double y = o_y + a_dessiner.get_position().get_value(2);


    // Dessin du Pendule
    matrice.setToIdentity();
    matrice.translate(x, y , o_z);
    matrice.scale(0.10);

    matrice.setToIdentity();
    matrice.translate(x, y, o_z);
    matrice.scale(0.05);
    dessineSphere(matrice, 1.0, 1.0, 1.0);


    matrice.setToIdentity();

    prog.setUniformValue("vue_modele", matrice_vue * matrice);
    glBegin(GL_LINES);

    prog.setAttributeValue(CouleurId, 1.0, 1.0, 1.0);
    prog.setAttributeValue(SommetId, o_x, o_y, o_z);
    prog.setAttributeValue(SommetId, x , y, o_z);
    glEnd();

    // Suivi de la caméra
    if(suiviCamera){
        matrice_vue.setToIdentity();
        matrice_vue.translate(-x ,-y,this->z + o_z);
        if(nausee) matrice_vue.rotate(a_dessiner.get_vitesse().get_value(1)*5, 0.0, 0.0, 1.0);
    }

}

// ======================================================================
void VueOpenGL::dessineSupport(Chariot const& a_dessiner){
    QMatrix4x4 matrice;

    // Initialisation du point d'origine de l'oscillateur
    double o_x = a_dessiner.get_origine().get_value(1);
    double o_y = a_dessiner.get_origine().get_value(2);
    double o_z = a_dessiner.get_origine().get_value(3);

    // Attribution des coordonnées de l'oscillateur pour un repère cartésien
    double x =o_x +  a_dessiner.get_position().get_value(1);
    double angle = a_dessiner.get_position().get_value(2)/a_dessiner.get_longueur();

    // Dessin du Ressort
    matrice.setToIdentity();
    matrice.translate(x, o_y, o_z);
    matrice.scale(0.05);
    dessineSphere(matrice, 1, 0.98, 0.28);

    matrice.setToIdentity();
    prog.setUniformValue("vue_modele", matrice_vue * matrice);

    glBegin(GL_LINES);
    prog.setAttributeValue(CouleurId, 0.5, 1.0, 1.0);
    prog.setAttributeValue(SommetId, o_x, o_y, o_z);
    prog.setAttributeValue(SommetId, x , o_y, o_z);
    glEnd();

    // Dessin du Pendule
    matrice.setToIdentity();
    matrice.translate(x+a_dessiner.get_longueur()*sin(angle), o_y -a_dessiner.get_longueur()*cos(angle), o_z);
    matrice.scale(0.05);
    dessineSphere(matrice, 0, 1.0, 0.74);

    matrice.setToIdentity();
    prog.setUniformValue("vue_modele", matrice_vue * matrice);

    glBegin(GL_LINES);
    prog.setAttributeValue(CouleurId, 1.0, 1.0, 1.0);
    prog.setAttributeValue(SommetId, x, o_y, o_z);
    prog.setAttributeValue(SommetId, x+a_dessiner.get_longueur()*sin(angle), o_y-a_dessiner.get_longueur()*cos(angle),this->z + o_z);
    glEnd();

    // Dessin de l'espace des phases
    QMatrix4x4 phase;
    if(espacePhase){
    phase.translate(a_dessiner.get_position().get_value(1), a_dessiner.get_vitesse().get_value(1), 0);
    phase.scale(0.05);
    dessineSphere(phase, 1, 0.98, 0.28);
    phase.setToIdentity();
    phase.translate(a_dessiner.get_position().get_value(2), a_dessiner.get_vitesse().get_value(2), 0);
    std::cout << a_dessiner.get_position().get_value(2) << std::endl;
    phase.scale(0.05);
    dessineSphere(phase, 0, 1.0, 0.74);
    }

    // Suivi de la caméra
    if(suiviCamera){
        matrice_vue.setToIdentity();
        matrice_vue.translate(-(x+a_dessiner.get_longueur()*sin(angle)), -(o_y -a_dessiner.get_longueur()*cos(angle)), o_z);
        if(nausee) matrice_vue.rotate(a_dessiner.get_vitesse().get_value(1)*5, 0.0, 0.0, 1.0);
    }

    matrice.setToIdentity();
}

// ======================================================================
void VueOpenGL::dessineSupport(PendulesLiesRessort const& a_dessiner){
    QMatrix4x4 matrice;

    // Initialisation du point d'origine de l'oscillateur
    double o_x = a_dessiner.get_origine().get_value(1);
    double o_y = a_dessiner.get_origine().get_value(2);
    double o_z = a_dessiner.get_origine().get_value(3);

    // Attribution des coordonnées de l'oscillateur pour un repère cartésien
    double teta = a_dessiner.get_position().get_value(1);
    teta = teta/a_dessiner.get_longueur();
    double x =  o_x + a_dessiner.get_longueur()*sin(teta);
    double y = o_y -a_dessiner.get_longueur()*cos(teta);

    double teta2 = a_dessiner.get_position().get_value(2);
    teta2 = teta2/a_dessiner.get_longueur2();
    double x2 = a_dessiner.get_longueur2()*sin(teta2);
    double y2 = -a_dessiner.get_longueur2()*cos(teta2);

    double d = a_dessiner.get_d();

    // Dessin du premier Pendule
    matrice.setToIdentity();
    matrice.translate(x+0.5*d, y, o_z);
    matrice.scale(0.05);
    dessineSphere(matrice, 0.0, 0.49, 0.8);

    matrice.setToIdentity();
    prog.setUniformValue("vue_modele", matrice_vue * matrice);

    glBegin(GL_LINES);
    prog.setAttributeValue(CouleurId,1.0, 1.0, 1.0);
    prog.setAttributeValue(SommetId, o_x+0.5*d, o_y, o_z);
    prog.setAttributeValue(SommetId, x+0.5*d, y, o_z);
    glEnd();

    // Dessin du deuxième Pendule
    matrice.setToIdentity();
    matrice.translate(o_x-x2-0.5*d, o_y + y2, o_z);
    matrice.scale(0.05);
    dessineSphere(matrice, 1.0, 0.28,0.2);
    matrice.setToIdentity();

    prog.setUniformValue("vue_modele", matrice_vue * matrice);

    glBegin(GL_LINES);

    prog.setAttributeValue(CouleurId,1.0, 1.0, 1.0);
    prog.setAttributeValue(SommetId, o_x-0.5*d, o_y, o_z);
    prog.setAttributeValue(SommetId, o_x-x2-0.5*d, o_y + y2, o_z);
    glEnd();

    // Dessin du Ressort
    matrice.setToIdentity();
    matrice.translate(o_x, o_y, o_z);
    matrice.translate(a_dessiner.get_a1()*sin(teta)+0.5*d, -a_dessiner.get_a1()*cos(teta), 0.0);
    matrice.scale(0.05);
    dessineSphere(matrice, 1.0, 0.8, 1.0);

    matrice.setToIdentity();
    matrice.translate(o_x, o_y, o_z);

    matrice.translate(-a_dessiner.get_a2()*sin(teta2)-0.5*d, -a_dessiner.get_a2()*cos(teta2), 0.0);
    matrice.scale(0.05);
    dessineSphere(matrice, 1.0, 0.8, 1.0);

    matrice.setToIdentity();

    prog.setUniformValue("vue_modele", matrice_vue * matrice);

    glBegin(GL_LINES);

    prog.setAttributeValue(CouleurId, 1.0, 0.8, 1.0);
    prog.setAttributeValue(SommetId, o_x + a_dessiner.get_a1()*sin(teta)+0.5*d, o_y -a_dessiner.get_a1()*cos(teta),o_z);
    prog.setAttributeValue(SommetId, o_x-a_dessiner.get_a2()*sin(teta2)-0.5*d, o_y-a_dessiner.get_a2()*cos(teta2),o_z);
    glEnd();

    // Dessin de l'espace des phases
    QMatrix4x4 phase;
    if(espacePhase){
    phase.translate(a_dessiner.get_position().get_value(1), a_dessiner.get_vitesse().get_value(1), 0);
    phase.scale(0.05);
    dessineSphere(phase, 0.0, 0.49, 0.8);
    phase.setToIdentity();
    phase.translate(a_dessiner.get_position().get_value(2), a_dessiner.get_vitesse().get_value(2), 0);
    phase.scale(0.05);
    dessineSphere(phase, 1, 0.28, 0.28);
    }

    // Suivi de la caméra
    if(suiviCamera){
        matrice_vue.setToIdentity();
        matrice_vue.translate(-(o_x-x2-0.5*d), -(o_y + y2), this->z + o_z);
        if(nausee) matrice_vue.rotate(a_dessiner.get_vitesse().get_value(1)*5, 0.0, 0.0, 1.0);
    }

}

// ======================================================================
void VueOpenGL::dessineSupport(Pendule const& a_dessiner){

    // Initialisation du point d'origine de l'oscillateur
      QMatrix4x4 matrice;
      double o_x = a_dessiner.get_origine().get_value(1);
      double o_y = a_dessiner.get_origine().get_value(2);
      double o_z = a_dessiner.get_origine().get_value(3);

    // Attribution des coordonnées de l'oscillateur pour un repère cartésien
      double teta = a_dessiner.get_position().get_value(1);
      teta = teta/a_dessiner.get_longueur();
      double x = o_x + a_dessiner.get_longueur()*sin(teta);
      double y = o_y + -a_dessiner.get_longueur()*cos(teta);

      // Dessin du Pendule
      matrice.setToIdentity();
      matrice.translate(x, y, o_z);
      matrice.scale(0.05);
      dessineSphere(matrice, 1.0, 1.0, 1.0);

      matrice.setToIdentity();

      prog.setUniformValue("vue_modele", matrice_vue * matrice);

      glBegin(GL_LINES);
      prog.setAttributeValue(CouleurId, 1.0, 1.0, 1.0);
      prog.setAttributeValue(SommetId, o_x, o_y, o_z);
      prog.setAttributeValue(SommetId, x , y,o_z);
      glEnd();

      // Dessin de l'espace des phases
      QMatrix4x4 phase;
      phase.translate(a_dessiner.get_position().get_value(1), a_dessiner.get_vitesse().get_value(1), 0);
      if(espacePhase){
      phase.scale(0.05);
      dessineSphere(phase, 1.0, 1.0, 1.0);
      points.push_back({a_dessiner.get_position().get_value(1), a_dessiner.get_vitesse().get_value(1), 0});

      prog.setUniformValue("vue_modele", matrice_vue * matrice);
      for(int i = 1; i < points.size(); i++){
          glBegin(GL_LINE_STRIP);
          prog.setAttributeValue(CouleurId, 0.0, 1.0, 1.0);
          prog.setAttributeValue(SommetId, points[i].get_value(1), points[i].get_value(2), o_z);
          prog.setAttributeValue(SommetId, points[i-1].get_value(1), points[i-1].get_value(2), o_z);
          glEnd() ;
      }}


      // Suivi de la caméra
      if(suiviCamera){
          matrice_vue.setToIdentity();
          matrice_vue.translate(-x, -y, this->z + o_z);
          if(nausee) matrice_vue.rotate(a_dessiner.get_vitesse().get_value(1)*5, 0.0, 0.0, 1.0);
      }
      prog.setUniformValue("vue_modele", matrice_vue * matrice);

}
// ======================================================================
void VueOpenGL::dessineSupport(PenduleTorsion const& a_dessiner){

    // Initialisation du point d'origine de l'oscillateur
      QMatrix4x4 matrice;
      double o_x = a_dessiner.get_origine().get_value(1);
      double o_y = a_dessiner.get_origine().get_value(2);
      double o_z = a_dessiner.get_origine().get_value(3);

    // Attribution des coordonnées de l'oscillateur pour un repère cartésien
      double teta = a_dessiner.get_position().get_value(1);
      teta = teta/a_dessiner.get_longueur();
      double x = o_x + a_dessiner.get_longueur()*sin(teta);
      double y = o_y + -a_dessiner.get_longueur()*cos(teta);

      // Dessin du Pendule
      matrice.setToIdentity();
      matrice.translate(x, y, o_z);
      matrice.scale(0.05);
      dessineSphere(matrice, 1.0, 1.0, 1.0);

      matrice.setToIdentity();

      prog.setUniformValue("vue_modele", matrice_vue * matrice);

      glBegin(GL_LINES);

      prog.setAttributeValue(CouleurId, 1.0, 1.0, 1.0);
      prog.setAttributeValue(SommetId, o_x-x, o_y-y, o_z);
      prog.setAttributeValue(SommetId, x , y,o_z);
      glEnd();

      matrice.setToIdentity();
      matrice.translate(o_x-x, o_y-y, o_z);
      matrice.scale(0.05);
      dessineSphere(matrice, 1.0, 1.0, 1.0);

      // Dessin de l'espace des phases
      QMatrix4x4 phase;
      phase.translate(a_dessiner.get_position().get_value(1), a_dessiner.get_vitesse().get_value(1), 0);
      if(espacePhase){
      phase.scale(0.05);
      dessineSphere(phase, 1.0, 1.0, 1.0);
      }


      // Suivi de la caméra
      if(suiviCamera){
          matrice_vue.setToIdentity();
          matrice_vue.translate(-x, -y, this->z + o_z);
          if(nausee) matrice_vue.rotate(a_dessiner.get_vitesse().get_value(1)*5, 0.0, 0.0, 1.0);
      }

}

// ======================================================================
void VueOpenGL::dessineSupport(RessortDouble const& a_dessiner){

    QMatrix4x4 matrice;
    // Initialisation du point d'origine de l'oscillateur
    double o_x = a_dessiner.get_origine().get_value(1);
    double o_y = a_dessiner.get_origine().get_value(2);
    double o_z = a_dessiner.get_origine().get_value(3);

    // Attribution des coordonnées de l'oscillateur pour un repère cartésien
    double x = o_x + a_dessiner.get_position().get_value(1)*a_dessiner.get_unitaire().get_value(1);
    double y = o_y+ a_dessiner.get_position().get_value(1)*a_dessiner.get_unitaire().get_value(2);
    double z = o_z+ a_dessiner.get_position().get_value(1)*a_dessiner.get_unitaire().get_value(3);

    double L = + a_dessiner.get_longueur() + a_dessiner.get_longueur2() + a_dessiner.get_longueur3();
    double x2 = o_x + (a_dessiner.get_position().get_value(2)+L)*a_dessiner.get_unitaire().get_value(1) ;
    double y2 = o_y + (a_dessiner.get_position().get_value(2)+ L)*a_dessiner.get_unitaire().get_value(2);
    double z2 = o_z+ (a_dessiner.get_position().get_value(2)+L)*a_dessiner.get_unitaire().get_value(3);

    matrice.setToIdentity();

    // Dessin du premier Ressort
    prog.setUniformValue("vue_modele", matrice_vue * matrice);
    glBegin(GL_LINES);
    prog.setAttributeValue(CouleurId, 165/255, 191/255, 1.0);
    prog.setAttributeValue(SommetId, o_x, o_y, o_z);
    prog.setAttributeValue(SommetId, x , y, z);
    glEnd();
    matrice.setToIdentity();
    matrice.translate(x, y , z);

    matrice.scale(0.05);
    dessineSphere(matrice, 45/255, 105/255, 1.0);

    matrice.setToIdentity();
    matrice.translate(o_x, o_y , o_z);

    matrice.scale(0.03);
    dessineSphere(matrice, 45/255, 105/255, 1.0);
    matrice.setToIdentity();

    // Dessin du deuxième Ressort
    prog.setUniformValue("vue_modele", matrice_vue * matrice);
    glBegin(GL_LINES);
    prog.setAttributeValue(CouleurId, 1, 165/255, 165/255);
    prog.setAttributeValue(SommetId, o_x+L*a_dessiner.get_unitaire().get_value(1), o_y+L*a_dessiner.get_unitaire().get_value(2), o_z+L*a_dessiner.get_unitaire().get_value(3));
    prog.setAttributeValue(SommetId, x2, y2, z2);
    glEnd();
    matrice.setToIdentity();
    matrice.translate(x2 , y2, z2);

    matrice.scale(0.05);
    dessineSphere(matrice, 1.0, 48/255, 49/255);

    matrice.setToIdentity();
    matrice.translate(o_x+L*a_dessiner.get_unitaire().get_value(1), o_y+L*a_dessiner.get_unitaire().get_value(2), o_z+L*a_dessiner.get_unitaire().get_value(3));

    matrice.scale(0.03);
    dessineSphere(matrice, 1.0, 48/255, 49/255);

    matrice.setToIdentity();
    prog.setUniformValue("vue_modele", matrice_vue * matrice);

    glBegin(GL_LINES);
    prog.setAttributeValue(CouleurId, 1.0, 1.0, 1.0);
    prog.setAttributeValue(SommetId, x, y, z);
    prog.setAttributeValue(SommetId, x2, y2, z2);
    glEnd();


    // Dessin de l'espace des phases
    QMatrix4x4 phase;
    if(espacePhase){
    phase.translate(a_dessiner.get_position().get_value(1), a_dessiner.get_vitesse().get_value(1), 0);
    phase.scale(0.05);
    dessineSphere(phase, 0.28, 1.0, 0.43);
    phase.setToIdentity();
    }

    // Suivi de la caméra
    if(suiviCamera){
        matrice_vue.setToIdentity();
        matrice_vue.translate(-x, -y, this->z + z);
       if(nausee) matrice_vue.rotate(a_dessiner.get_vitesse().get_value(2)*2, 0.0, 0.0, 1.0);
    }


}
