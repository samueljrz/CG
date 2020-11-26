TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += bib
INCLUDEPATH += gui_glut
INCLUDEPATH += personal

LIBS += -lGL -lGLU -lglut -l3ds -lSDL_image

SOURCES += main.cpp \
    personal/objeto.cpp \
    personal/carro.cpp \
    personal/casa.cpp \
    personal/esqueleto.cpp \
    personal/bule.cpp \
    personal/peao.cpp \
    bib/Camera.cpp \
    bib/CameraDistante.cpp \
    bib/CameraJogo.cpp \
    bib/Desenha.cpp \
    bib/model3ds.cpp \
    bib/Vetor3D.cpp \
    gui_glut/extra.cpp \
    gui_glut/gui.cpp \
    personal/armario.cpp

HEADERS += \
    personal/objeto.h \
    personal/carro.h \
    personal/casa.h \
    personal/esqueleto.h \
    personal/bule.h \
    personal/peao.h \
    bib/Camera.h \
    bib/CameraDistante.h \
    bib/CameraJogo.h \
    bib/Desenha.h \
    bib/model3ds.h \
    bib/Vetor3D.h \
    gui_glut/extra.h \
    gui_glut/gui.h \
    personal/armario.h

