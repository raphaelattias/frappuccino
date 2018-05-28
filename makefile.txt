CXX= g++
CC=$(CXX)

CXXFLAGS = -std=c++11 -pedantic -Wall # supprimer -ansi
CXXFLAGS += -pedantic -Wall
CXXFLAGS += -O2
CXXFLAGS += -g
CXXFLAGS += -pg                 # pour profiler
LDFLAGS  += -pg                 # pour profiler

all : testRessort


vecteur.o : vecteur.cpp vecteur.h

oscillateur.o : oscillateur.cpp oscillateur.h

constantes.o : constantes.cpp constantes.h 

ressort.o : ressort.cpp ressort.h

IntegrateurRungeKutta.o : IntegrateurRungeKutta.cpp IntegrateurRungeKutta.h

integrateurNewmark.o : integrateurNewmark.cpp integrateurNewmark.hpp

integrateurEulerCromer.o : integrateurEulerCromer.cpp integrateurEulerCromer.h

integrateur.o : Integrateur.h

integrateur.o : integrateur.cpp integrateur.h

constantes.o : constantes.cpp constantes.h


testRessort : oscillateur.o vecteur.o integrateur.o integrateurEulerCromer.o integrateurNewmark.o IntegrateurRungeKutta.o ressort.o constantes.o



clean :
	rm *.o


#gcc -MM nom.cc
