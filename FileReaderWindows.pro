#-------------------------------------------------
#
# Project created by QtCreator 2017-10-16T14:39:05
#
#-------------------------------------------------

QT       += core gui testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FileReaderWindows
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    modeldata.cpp \
    vertexdata.cpp \
    testobj_loader.cpp \
    OBJLoader.cpp \
    display.cpp \
    transformation.cpp \
    camera.cpp \
    graphicsview.cpp

HEADERS  += mainwindow.h \
    modeldata.h \
    vertexdata.h \
    testobj_loader.h \
    extrafunctions.h \
    OBJLoader.h \
    display.h \
    transformation.h \
    camera.h \
    graphicsview.h

FORMS    += mainwindow.ui
