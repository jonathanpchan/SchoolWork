#-------------------------------------------------
#
# Project created by QtCreator 2013-04-15T23:37:29
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = final
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    creature.cpp \
    prey.cpp \
    predator.cpp \
    grid.cpp \
    coords.cpp \
    display.cpp \
    wall.cpp \
    hunter.cpp

HEADERS += \
    creature.h \
    prey.h \
    predator.h \
    grid.h \
    coords.h \
    display.h \
    wall.h \
    hunter.h

LIBS += -lGLFW -lopengl32 -lglu32 -luser32
