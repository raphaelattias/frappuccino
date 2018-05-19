QT += core gui opengl widgets
CONFIG += c++11

win32:LIBS += -lopengl32


TARGET = ex_05_gl

LIBS += -L../general -lgeneral


PRE_TARGETDEPS += ../general/libgeneral.a

INCLUDEPATH = ../general

SOURCES += \
    main_qt_gl.cc \
    glsphere.cc \
    glwidget.cc \
    vue_opengl.cc

HEADERS += \
    glwidget.h \
    vertex_shader.h \
    glsphere.h \
    vue_opengl.h \
    ../general/dessinable.h \
    ../general/supportadessin.h \
    ../general/pendule.h \
    ../general/contenu.h

RESOURCES += \
    resource.qrc
