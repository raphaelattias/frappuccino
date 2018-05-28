# frappuccino
Projet de programmation EPFL 2018 Bachelor Mathématiques (Première première)

# Introduction
Ce programme permet de simuler de nombreux oscillateurs. Il est possible de sélectionner et représenter 9 oscillateurs déjà proposés mais aussi d'en ajouter. Le programme propose au choix une visualisation texte (TextViewer) ou 3D (OpenGL).

![screenshot](https://i.imgur.com/TfZn8lN.png)

# Utilisation Graphique
Dans le fichier ./Qt_GL/main_qt_gl.cc doivent être entrées les instructions pour l'affichage graphique. 9 exemples d'oscillateurs sont déjà proposés. Les étapes à suivre sont :
1. Choisir l'intégrateur à l'aide de la méthode GLWidget::w.set_integrateur([INTEGRATEUR])
