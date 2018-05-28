# frappuccino
Projet de programmation EPFL 2018 Bachelor Mathématiques (Première première)

# Introduction
Ce programme permet de simuler de nombreux oscillateurs. Il est possible de sélectionner et représenter 9 oscillateurs déjà proposés mais aussi d'en ajouter. Le programme propose au choix une visualisation texte (TextViewer) ou 3D (OpenGL).

![screenshot](https://i.imgur.com/TfZn8lN.png)

# Initialisation d'un Oscillateur
Tous les oscillateurs propose un constructeur par défaut permettant d'initialiser tous les attributs caractéristiques : masse, longueur, coefficient de frottement...
Des exemples de constructeurs sont proposés dans le main() et sont disponibles dans les fichiers .h, voici deux exemples:
```
Pendule P({Position initiale}, {Vitesse Initiale}, {Origine du repère}, [Masse], [Longueur], [Coefficient de frottement], [Support à Dessin])
Pendule P({7,0,0}, {0,0}, {0,0, 0}, 2, 1, 0, &text)
```
```
Ressort({Position initiale}, {Vitesse Initiale}, {Origine du repère}, [Masse], [Longueur], [Coefficient de frottement], [Raideur], {Orientation},[Support à Dessin])
Ressort R1({1,0}, {1,0}, {0,0,0}, 3, 0.01, 0.01, 10, {1, 0}, &vue)
```
# Initalisation d'un Vecteur
Les Vecteurs sont une structure de donnée équipée de méthodes pour les manipuler, utilisées dans le calcul des oscillateurs et des intégrateurs. Les constructeurs sont :
1. Initialisation d'un vecteur nul de dimension n: **Vecteur V(n)**
2. Initialisation d'un vecteur à n coordonnées de dimension n: **Vecteur V({1, 2, 3, ... , n})**
3. Initialisation d'un vecteur à 3 dimensions : **Vecteur V(x, y, z)**<br>
Les méthodes principales proposées sont :
1. Modifier la i-ème coordonnée d'un vecteur: **V.setcoord(i, double x)**
2. Retourner la i-ème coordonnée d'un vecteur: **V.get_value(i)**<br>
Les constructeurs habituels sont proposés :
1. Multiplication scalaire : 

# Utilisation Graphique
Dans le fichier ./Qt_GL/main_qt_gl.cc doivent être entrées les instructions pour l'affichage graphique. 9 exemples d'oscillateurs sont déjà proposés. Les étapes à suivre sont :
1. Choisir l'intégrateur à l'aide de la méthode **GLWidget::w.set_integrateur([INTEGRATEUR])**.
2. Ajouter un oscillateur au système à l'aide de la méthode **GLWidget::ajouter_oscillateur([OSCILLATEUR])**.
3. Compiler le projet

## Options
De plus des options sont proposés afin de modifier l'affichage. 
1. Activer l'espace des phases avec la méthode **GLWidget::w.activerEspaceDesPhases()**. Le tracé de l'espace des phases est proposé pour pendule double, la majorité des autres pendules affiche une sphère se trouvant à (position, vitesse.
2. Activer le suivi de la caméra avec la méthode **GLWidget::w.activerSuiviCamera([double z = 0], [bool nausee = 0])**. Le paramètre z permet de définir la distance à laquelle la caméra se trouve de l'oscillateur, et nausée oriente la caméra en fonction de la vitesse de l'oscillateur.
