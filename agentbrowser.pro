#-------------------------------------------------
#
# Project created by QtCreator 2013-04-15T23:52:58
#
#-------------------------------------------------

QT       += core gui webkit

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = agentbrowser
TEMPLATE = app


SOURCES += src/source/main.cpp\
        src/source/mainwindow.cpp \
    src/source/htmlview.cpp \
    src/source/addressbar.cpp \
    src/source/tabpage.cpp

HEADERS  += src/header/mainwindow.h \
    src/header/addressbar.h \
    src/header/htmlview.h \
    src/header/tabpage.h

FORMS    += src/form/mainwindow.ui

INCLUDEPATH += src/header/
