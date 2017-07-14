#-------------------------------------------------
#
# Project created by QtCreator 2016-02-24T22:57:36
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = opengl_app
TEMPLATE = app

INCLUDEPATH += "C:\local\boost_1_60_0"

SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp \
    libicp/icp.cpp \
    libicp/icpPointToPlane.cpp \
    libicp/kdtree.cpp \
    libicp/matrix.cpp

HEADERS  += mainwindow.h \
    glwidget.h \
    libicp/icp.h \
    libicp/icpPointToPlane.h \
    libicp/kdtree.h \
    libicp/matrix.h

FORMS    += mainwindow.ui

#LIBS += "C:\local\OpenGL\glut32.lib"
LIBS += "C:\local\OpenGL\glut64.lib"
