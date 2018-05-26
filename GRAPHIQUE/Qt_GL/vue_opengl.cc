#include "vue_opengl.h"
#include "vertex_shader.h" // Identifiants Qt de nos différents attributs
#include "systeme.h"
#include "pendule.h"
#include "ressort.h"
#include <cmath>

// ======================================================================
void VueOpenGL::dessineSupport(Systeme const& a_dessiner)
{

    QMatrix4x4 matrice;

  dessineAxes(matrice);



  // Dessine le cube

  //dessineCube(matrice);

/*
  //grille axe Z
  glBegin(GL_LINES);
  prog.setAttributeValue(CouleurId, 1.0, 1.0, 1.0); // blanc aussi


  for(int i = -11; i < 12; i++){
    prog.setAttributeValue(SommetId, -10.0, -1, i+1);
    prog.setAttributeValue(SommetId, 10.0, -1, i+1);

    prog.setAttributeValue(SommetId, i+1, -1, -10);
    prog.setAttributeValue(SommetId, i+1, -1, 10);
  }

  glEnd();*/


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

void VueOpenGL::dessineSphere (QMatrix4x4 const& point_de_vue,
                               double rouge, double vert, double bleu)
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
  matrice_vue.translate(0.0, -1, -4.0);
// matrice_vue.rotate(60.0, 0.0, 1.0, 0.0);
// matrice_vue.rotate(45.0, 0.0, 0.0, 1.0);
  matrice_vue.rotate(20, 0, 1, 0);
}

void VueOpenGL::vueZero(){
    matrice_vue.setToIdentity();
    matrice_vue.translate(0.0, 0, -4.0);
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



void VueOpenGL::remettre_a_zero() {
  std::cout << "nada" << std::endl;
} // je la mets pour que ca compile

void VueOpenGL::dessineSupport(PenduleTriple const& a_dessiner){
    QMatrix4x4 matrice;


    double teta = a_dessiner.get_position().get_value(1);
    teta = teta/a_dessiner.get_longueur();
    double x = a_dessiner.get_longueur()*sin(teta);
    double y = -a_dessiner.get_longueur()*cos(teta);
    double angle;
    angle = atan(x/y);


    matrice.setToIdentity();
    matrice.translate(x, y , 0.0);
    matrice.rotate(angle, 0.0, 0.0, 1.0); // essayer de tourner le cube de sorte à ce qu'il soit perpendiculaire au fil
    matrice.scale(0.10);

    matrice.setToIdentity();
    matrice.translate(x, y, 0.0);
    matrice.scale(0.05);
    dessineSphere(matrice, 1.0, 1.0, 1.0); // rouge


    matrice.setToIdentity();

    prog.setUniformValue("vue_modele", matrice_vue * matrice); //Ajouter fil , faire une méthode?

    glBegin(GL_LINES);

    prog.setAttributeValue(CouleurId, 1.0, 1.0, 1.0); // blanc aussi
    prog.setAttributeValue(SommetId, 0.0, 0.0, 0.0);
    prog.setAttributeValue(SommetId, x , y, 0.0);
    glEnd();

    double teta2 = a_dessiner.get_position().get_value(2);
    teta2 = teta2/a_dessiner.get_longueur2();
    double x2 = a_dessiner.get_longueur2()*sin(teta2);
    double y2 = -a_dessiner.get_longueur2()*cos(teta2);
    double angle2;
    angle2 = atan(x2/y2);


    matrice.setToIdentity();
    matrice.translate(x+x2, y+y2 , 0.0);
    matrice.rotate(angle2, 0.0, 0.0, 1.0); // essayer de tourner le cube de sorte à ce qu'il soit perpendiculaire au fil
    matrice.scale(0.10);

    matrice.setToIdentity();
    matrice.translate(x+x2, y+y2, 0.0);
    matrice.scale(0.05);
    dessineSphere(matrice, 1.0, 1.0, 1.0); // rouge


    matrice.setToIdentity();

    prog.setUniformValue("vue_modele", matrice_vue * matrice); //Ajouter fil , faire une méthode?

    glBegin(GL_LINES);

    prog.setAttributeValue(CouleurId, 1.0, 1.0, 1.0); // blanc aussi
    prog.setAttributeValue(SommetId, x, y, 0.0);
    prog.setAttributeValue(SommetId, x2+x , y+y2, 0.0);
    glEnd();

    double teta3 = a_dessiner.get_position().get_value(3);
    teta3 = teta3/a_dessiner.get_longueur3();
    double x3 = a_dessiner.get_longueur3()*sin(teta3);
    double y3 = -a_dessiner.get_longueur3()*cos(teta3);
    double angle3;
    angle2 = atan(x3/y3);


    matrice.setToIdentity();
    matrice.translate(x+x2+x3, y+y2+y3 , 0.0);
    matrice.rotate(angle2, 0.0, 0.0, 1.0); // essayer de tourner le cube de sorte à ce qu'il soit perpendiculaire au fil
    matrice.scale(0.10);

    matrice.setToIdentity();
    matrice.translate(x+x2+x3, y+y2+y3, 0.0);
    matrice.scale(0.05);
    dessineSphere(matrice, 1.0, 1.0, 1.0); // rouge


    matrice.setToIdentity();

    prog.setUniformValue("vue_modele", matrice_vue * matrice); //Ajouter fil , faire une méthode?

    glBegin(GL_LINES);

    prog.setAttributeValue(CouleurId, 1.0, 1.0, 1.0); // blanc aussi
    prog.setAttributeValue(SommetId, x+x2, y+y2, 0.0);
    prog.setAttributeValue(SommetId, x2+x+x3 , y+y2+y3, 0.0);
    glEnd();
}

void VueOpenGL::dessineSupport(PenduleDouble const& a_dessiner){


    QMatrix4x4 matrice;


    double teta = a_dessiner.get_position().get_value(1);
    teta = teta/a_dessiner.get_longueur();
    double x = a_dessiner.get_longueur()*sin(teta);
    double y = -a_dessiner.get_longueur()*cos(teta);
    double angle;
    angle = atan(x/y);


    matrice.setToIdentity();
    matrice.translate(x, y , 0.0);
    matrice.rotate(angle, 0.0, 0.0, 1.0); // essayer de tourner le cube de sorte à ce qu'il soit perpendiculaire au fil
    matrice.scale(0.10);

    matrice.setToIdentity();
    matrice.translate(x, y, 0.0);
    matrice.scale(0.05);
    dessineSphere(matrice, 1.0, 1.0, 1.0); // rouge


    matrice.setToIdentity();

    prog.setUniformValue("vue_modele", matrice_vue * matrice); //Ajouter fil , faire une méthode?

    glBegin(GL_LINES);

    prog.setAttributeValue(CouleurId, 1.0, 1.0, 1.0); // blanc aussi
    prog.setAttributeValue(SommetId, 0.0, 0.0, 0.0);
    prog.setAttributeValue(SommetId, x , y, 0.0);
    glEnd();

    double teta2 = a_dessiner.get_position().get_value(2);
    teta2 = teta2/a_dessiner.get_longueur2();
    double x2 = a_dessiner.get_longueur2()*sin(teta2);
    double y2 = -a_dessiner.get_longueur2()*cos(teta2);
    double angle2;
    angle2 = atan(x2/y2);


    matrice.setToIdentity();
    matrice.translate(x+x2, y+y2 , 0.0);
    matrice.rotate(angle2, 0.0, 0.0, 1.0); // essayer de tourner le cube de sorte à ce qu'il soit perpendiculaire au fil
    matrice.scale(0.10);

    matrice.setToIdentity();
    matrice.translate(x+x2, y+y2, 0.0);
    matrice.scale(0.05);
    dessineSphere(matrice, 1.0, 1.0, 1.0); // rouge


    matrice.setToIdentity();

    prog.setUniformValue("vue_modele", matrice_vue * matrice); //Ajouter fil , faire une méthode?

    glBegin(GL_LINES);

    prog.setAttributeValue(CouleurId, 1.0, 1.0, 1.0); // blanc aussi
    prog.setAttributeValue(SommetId, x, y, 0.0);
    prog.setAttributeValue(SommetId, x2+x , y+y2, 0.0);
    glEnd();
}
void VueOpenGL::dessineSupport(Ressort const& a_dessiner){
      QMatrix4x4 matrice;
    //  dessineAxes(matrice);
      double x = a_dessiner.get_position().get_value(1);
      double y = a_dessiner.get_position().get_value(2);
      matrice.setToIdentity();

      glBegin(GL_LINES);

      prog.setAttributeValue(CouleurId, 1.0, 1.0, 1.0); // blanc aussi
      prog.setAttributeValue(SommetId, 0.0, 2, 0.0);
      prog.setAttributeValue(SommetId, x , y+2, 0.0);
      glEnd();
      matrice.setToIdentity();
      matrice.translate(x, y+2 ,0);

      matrice.scale(0.05);
      dessineSphere(matrice, 0, 1.0, 1.0);

      matrice.setToIdentity();
      matrice.translate(a_dessiner.get_position().get_value(1), a_dessiner.get_vitesse().get_value(1));
      matrice.scale(0.05);
      dessineSphere(matrice, 0, 1,0);

}

void VueOpenGL::dessineSupport(const PenduleRessort &a_dessiner){
    QMatrix4x4 matrice;
    double angle = a_dessiner.get_position().get_value(1)/a_dessiner.get_position().norme();
    double x = sin(angle)*a_dessiner.get_position().norme();
    double y = -cos(angle)*a_dessiner.get_position().norme();


    matrice.setToIdentity();
    matrice.translate(x, y , 0.0);
    matrice.scale(0.10);

    matrice.setToIdentity();
    matrice.translate(x, y, 0.0);
    matrice.scale(0.05);
    dessineSphere(matrice, 1.0, 1.0, 1.0); // rouge


    matrice.setToIdentity();

    prog.setUniformValue("vue_modele", matrice_vue * matrice); //Ajouter fil , faire une méthode?

    glBegin(GL_LINES);

    prog.setAttributeValue(CouleurId, 1.0, 1.0, 1.0); // blanc aussi
    prog.setAttributeValue(SommetId, 0.0, 0.0, 0.0);
    prog.setAttributeValue(SommetId, x , y, 0.0);
    glEnd();
}

void VueOpenGL::dessineSupport(const Chariot &a_dessiner){
    QMatrix4x4 matrice;
    double x = a_dessiner.get_position().get_value(1);
    double angle = a_dessiner.get_position().get_value(2)/a_dessiner.get_longueur();

    matrice.setToIdentity();
    matrice.translate(x, 0.0, 0.0);
    matrice.scale(0.05);
    dessineSphere(matrice, 1.0, 1.0, 1.0);

    matrice.setToIdentity();

    prog.setUniformValue("vue_modele", matrice_vue * matrice);

    glBegin(GL_LINES);

    prog.setAttributeValue(CouleurId, 0.5, 1.0, 1.0); // blanc aussi
    prog.setAttributeValue(SommetId, 0.0, 0.0, 0.0);
    prog.setAttributeValue(SommetId, x , 0.0, 0.0);
    glEnd();



    matrice.setToIdentity();
    matrice.translate(x+a_dessiner.get_longueur()*sin(angle), -a_dessiner.get_longueur()*cos(angle), 0.0);
    matrice.scale(0.05);
    dessineSphere(matrice, 1.0, 1.0, 1.0);

    matrice.setToIdentity();
    prog.setUniformValue("vue_modele", matrice_vue * matrice); //Ajouter fil , faire une méthode?

    glBegin(GL_LINES);
    prog.setAttributeValue(CouleurId, 1.0, 1.0, 1.0); // blanc aussi
    prog.setAttributeValue(SommetId, x, 0.0, 0.0);
    prog.setAttributeValue(SommetId, x+a_dessiner.get_longueur()*sin(angle), -a_dessiner.get_longueur()*cos(angle), 0.0);
    glEnd();

    matrice.setToIdentity();
}

void VueOpenGL::dessineSupport(PendulesLiesRessort const& a_dessiner){
    QMatrix4x4 matrice;
    double teta = a_dessiner.get_position().get_value(1);
    teta = teta/a_dessiner.get_longueur();
    double x = a_dessiner.get_longueur()*sin(teta);
    double y = -a_dessiner.get_longueur()*cos(teta);
    double angle;
    angle = atan(x/y);

    double teta2 = a_dessiner.get_position().get_value(2);
    teta2 = teta2/a_dessiner.get_longueur2();
    double x2 = a_dessiner.get_longueur2()*sin(teta2);
    double y2 = -a_dessiner.get_longueur2()*cos(teta2);
    double angle2;
    angle2 = atan(x2/y2);

    double d = a_dessiner.get_d();

    matrice.setToIdentity();
    matrice.translate(x+0.5*d, y, 0.0);
    matrice.scale(0.05);
    dessineSphere(matrice, 1.0, 1.0, 1.0);

    matrice.setToIdentity();
    prog.setUniformValue("vue_modele", matrice_vue * matrice); //Ajouter fil , faire une méthode?

    glBegin(GL_LINES);

    prog.setAttributeValue(CouleurId, 1.0, 1.0, 1.0); // blanc aussi
    prog.setAttributeValue(SommetId, 0.5*d, 0.0, 0.0);
    prog.setAttributeValue(SommetId, x+0.5*d, y, 0.0);
    glEnd();


    matrice.setToIdentity();
    matrice.translate(-x2-0.5*d, y2, 0.0);
    matrice.scale(0.05);
    dessineSphere(matrice, 1.0, 1.0, 1.0);
    matrice.setToIdentity();

    prog.setUniformValue("vue_modele", matrice_vue * matrice); //Ajouter fil , faire une méthode?

    glBegin(GL_LINES);

    prog.setAttributeValue(CouleurId, 1.0, 1.0, 1.0); // blanc aussi
    prog.setAttributeValue(SommetId, -0.5*d, 0.0, 0.0);
    prog.setAttributeValue(SommetId, -x2-0.5*d, y2, 0.0);
    glEnd();


    matrice.setToIdentity();
    matrice.translate(a_dessiner.get_a1()*sin(teta)+0.5*d, -a_dessiner.get_a1()*cos(teta), 0.0);
    matrice.scale(0.05);
    dessineSphere(matrice, 1.0, 0.8, 1.0);

    matrice.setToIdentity();
    matrice.translate(-a_dessiner.get_a1()*sin(teta2)-0.5*d, -a_dessiner.get_a1()*cos(teta2), 0.0);
    matrice.scale(0.05);
    dessineSphere(matrice, 1.0, 0.8, 1.0);

    matrice.setToIdentity();

    prog.setUniformValue("vue_modele", matrice_vue * matrice); //Ajouter fil , faire une méthode?

    glBegin(GL_LINES);

    prog.setAttributeValue(CouleurId, 1.0, 0.8, 1.0); // blanc aussi
    prog.setAttributeValue(SommetId, a_dessiner.get_a1()*sin(teta)+0.5*d, -a_dessiner.get_a1()*cos(teta), 0.0);
    prog.setAttributeValue(SommetId, -a_dessiner.get_a1()*sin(teta2)-0.5*d, -a_dessiner.get_a1()*cos(teta2), 0.0);
    glEnd();

}


void VueOpenGL::dessineSupport(Pendule const& a_dessiner){

      QMatrix4x4 matrice;


      double teta = a_dessiner.get_position().get_value(1);
      teta = teta/a_dessiner.get_longueur();
      double x = a_dessiner.get_longueur()*sin(teta);
      double y = -a_dessiner.get_longueur()*cos(teta);
      double angle;
      angle = atan(x/y);


      matrice.setToIdentity();
      matrice.translate(x, y , 0.0);
      matrice.rotate(angle, 0.0, 0.0, 1.0); // essayer de tourner le cube de sorte à ce qu'il soit perpendiculaire au fil
      matrice.scale(0.10);

      matrice.setToIdentity();
      matrice.translate(x, y, 0.0);
      matrice.scale(0.05);
      dessineSphere(matrice, 1.0, 1.0, 1.0); // rouge


      matrice.setToIdentity();

      prog.setUniformValue("vue_modele", matrice_vue * matrice); //Ajouter fil , faire une méthode?

      glBegin(GL_LINES);

      prog.setAttributeValue(CouleurId, 1.0, 1.0, 1.0); // blanc aussi
      prog.setAttributeValue(SommetId, 0.0, 0.0, 0.0);
      prog.setAttributeValue(SommetId, x , y, 0.0);
      glEnd();

      matrice.setToIdentity();
      matrice.translate(a_dessiner.get_position().get_value(1), a_dessiner.get_vitesse().get_value(1));
      matrice.scale(0.05);
      dessineSphere(matrice, 0, 1,0);

      matrice.setToIdentity();
      prog.setAttributeValue(CouleurId, 1.0, 1.0,1.0);

}



// Je la mets pour que ca compile
