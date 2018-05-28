# frappuccino
Projet de programmation EPFL 2018 Bachelor Mathématiques (Première première)

# Introduction
Ce programme permet de simuler de nombreux oscillateurs. Il est possible de sélectionner et représenter 9 oscillateurs déjà proposés mais aussi d'en ajouter. Le programme propose au choix une visualisation texte (TextViewer) ou 3D (OpenGL).

![screenshot](https://i.imgur.com/TfZn8lN.png)

# Utilisation Graphique
Dans le fichier ./Qt_GL/main_qt_gl.cc doivent être entrées les instructions pour l'affichage graphique. 9 exemples d'oscillateurs sont déjà proposés. Les étapes à suivre sont :
1. Choisir l'intégrateur à l'aide de la méthode **GLWidget::w.set_integrateur([INTEGRATEUR])**.
2. Ajouter un oscillateur au système à l'aide de la méthode **GLWidget::ajouter_oscillateur([OSCILLATEUR])**.
3. Compiler le projet

## Options
De plus des options sont proposés afin de modifier l'affichage. 
1. Activer l'espace des phases avec la méthode **GLWidget::w.activerEspaceDesPhases()**. Le tracé de l'espace des phases est proposé pour pendule double, la majorité des autres pendules affiche une sphère se trouvant à (position, vitesse.
2. Activer le suivi de la caméra avec la méthode **GLWidget::w.activerSuiviCamera([double z = 0], [bool nausee = 0])**. Le paramètre z permet de définir la distance à laquelle la caméra se trouve de l'oscillateur, et nausée oriente la caméra en fonction de la vitesse de l'oscillateur.
