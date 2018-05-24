QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.7
LIBS += -framework IOKit
TEMPLATE = lib

CONFIG = staticlib c++11

SOURCES += \
    constantes.cpp \
    dessinable.cpp \
    integrateur.cpp \
    IntegrateurEulerCromer.cpp \
    oscillateur_couple.cpp \
    main.cpp \
    oscillateur.cpp \
    pendule.cpp \
    ressort.cpp \
    systeme.cpp \
    TextViewer.cpp \
    testintegrateur.cpp\
    vecteur_unitaire.cpp \
    vecteur.cpp



HEADERS += \
    constantes.h \
    integrateur.h \
    integrateurEulerCromer.h \
    oscillateur.h \
    oscillateur_couple.hpp\
    pendule.h \
    ressort.h \
    supportadessin.h \
    systeme.h \
    TextViewer.h \
    vecteur_unitaire.h \
    vecteur.h \
    dessinable.h



