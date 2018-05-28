CONFIG += c++11

TARGET = ex_05_text

LIBS += -L../general -lgeneral
PRE_TARGETDEPS += ../general/libgeneral.a

INCLUDEPATH = ../general

SOURCES += \
TextViewer.cpp \
main_text.cc \
mainTextViewer.cpp

HEADERS += \
TextViewer.h
