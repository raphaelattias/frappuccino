CXX= g++
CC=$(CXX)

CXXFLAGS = -std=c++11 -pedantic -Wall # supprimer -ansi
CXXFLAGS += -pedantic -Wall
CXXFLAGS += -O2
CXXFLAGS += -g
CXXFLAGS += -pg                 # pour profiler
LDFLAGS  += -pg                 # pour profiler

all : testoscillateur


vecteur.o : vecteur.cpp vecteur.h

oscillateur.o : oscillateur.cpp oscillateur.h 

testoscillateur.o : testoscillateur.cpp vecteur.h oscillateur.h

testoscillateur : vecteur.o testoscillateur.o oscillateur.o

clean :
	rm *.o


#gcc -MM nom.cc
