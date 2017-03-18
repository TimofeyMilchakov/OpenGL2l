#-------------------------------------------------
#
# Project created by QtCreator 2017-03-18T19:57:13
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OpenGL2l
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp \
    mylines.cpp \
    qwe.cpp

HEADERS  += mainwindow.h \
    glwidget.h \
    qwe.h \
    myLines.h

FORMS    += mainwindow.ui
