CXX= g++
CC=$(CXX)

CXXFLAGS = -std=c++11 -pedantic -Wall # supprimer -ansi
CXXFLAGS += -pedantic -Wall
CXXFLAGS += -O2
CXXFLAGS += -g
CXXFLAGS += -pg                 # pour profiler
LDFLAGS  += -pg                 # pour profiler

all : testintegrateur


vecteur.o : vecteur.cpp vecteur.h

integrateur.o : integrateur.cpp integrateur.h

oscillateur.o : oscillateur.cpp oscillateur.h 

integrateurEulerCromer.o : integrateurEulerCromer.cpp integrateurEulerCromer.h 

integrateurNewmark.o : IntegrateurNewmark.cpp IntegrateurNewmark.hpp

testintegrateur.o : testintegrateur.cpp Integrateur.h integrateurEulerCromer.h oscillateur.h vecteur.h IntegrateurNewmark.hpp


testintegrateur: testintegrateur.o integrateurEulerCromer.o integrateurNewmark.o oscillateur.o vecteur.o integrateur.o



clean :
	rm *.o


#gcc -MM nom.cc
