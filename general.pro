QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.9

TEMPLATE = lib

CONFIG = staticlib c++11

SOURCES += \
    constantes.cpp \
    dessinable.cpp \
    integrateur.cpp \
    IntegrateurEulerCromer.cpp \
    main.cpp \
    oscillateur.cpp \
    pendule.cpp \
    ressort.cpp \
    supportadessin.cpp \
    systeme.cpp \
    test.cpp \
    testintegrateur.cpp \
    testoscillateur.cpp \
    testvecteur.cpp \
    TextViewer.cpp \
    vecteur_unitaire.cpp \
    vecteur.cpp



HEADERS += \
    constantes.h \
    integrateur.h \
    integrateurEulerCromer.h \
    oscillateur.h \
    pendule.h \
    ressort.h \
    supportadessin.h \
    systeme.h \
    TextViewer.h \
    vecteur_unitaire.h \
    vecteur.h \
    dessinable.h



