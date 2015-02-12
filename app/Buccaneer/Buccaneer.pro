#-------------------------------------------------
#
# Project created by QtCreator 2015-02-12T11:06:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Buccaneer
TEMPLATE = app

SOURCES += main.cpp\
        bucmain.cpp

HEADERS  += bucmain.h

FORMS    += bucmain.ui

unix:!macx: LIBS += -L$$PWD/../../../c/rackoonio/ -lrackio

INCLUDEPATH += $$PWD/../../../c/rackoonio/
DEPENDPATH += $$PWD/../../../c/rackoonio/

QMAKE_CXXFLAGS += -std=c++11

unix:!macx: LIBS += -L$$PWD/../../../c/local/lib/ -lresample

INCLUDEPATH += $$PWD/../../../c/local/include
DEPENDPATH += $$PWD/../../../c/local/include
INCLUDEPATH += $$PWD/../../widgets/BWidgets
OTHER_FILES += \
    ../build-Buccaneer-Desktop-Debug/buccaneer.cfg

unix: LIBS += -L$$PWD/../../../../../../usr/lib64/qt4/plugins/designer/ -lbunccaneerwidgetsplugin

INCLUDEPATH += $$PWD/../../../../../../usr/lib64/qt4/plugins/designer
DEPENDPATH += $$PWD/../../../../../../usr/lib64/qt4/plugins/designer

unix:!macx: LIBS += -L$$PWD/../../../c/libbuccaneer/ -lbuccaneer

INCLUDEPATH += $$PWD/../../../c/libbuccaneer
DEPENDPATH += $$PWD/../../../c/libbuccaneer
