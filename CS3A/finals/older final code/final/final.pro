#-------------------------------------------------
#
# Project created by QtCreator 2013-04-15T23:37:29
#
#-------------------------------------------------

QT       += core

QT       -= gui


CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    creature.cpp \
    prey.cpp \
    predator.cpp \
    grid.cpp \
    coords.cpp \
    display.cpp

HEADERS += \
    creature.h \
    prey.h \
    predator.h \
    grid.h \
    coords.h \
    display.h

LIBS += -lGLFW -lopengl32 -lglu32 -luser32
