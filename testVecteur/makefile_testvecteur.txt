CXX= g++
CC=$(CXX)

CXXFLAGS = -std=c++11 -pedantic -Wall # supprimer -ansi
CXXFLAGS += -pedantic -Wall
CXXFLAGS += -O2
CXXFLAGS += -g
CXXFLAGS += -pg                 # pour profiler
LDFLAGS  += -pg                 # pour profiler

all : testvecteur


vecteur.o : vecteur.cpp vecteur.h

testvecteur.o : testvecteur.cpp vecteur.h

testvecteur : vecteur.o testvecteur.o 


clean :
	rm *.o


#gcc -MM nom.cc
