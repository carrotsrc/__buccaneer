CONFIG      += plugin debug_and_release
TARGET      = $$qtLibraryTarget(bunccaneerwidgetsplugin)
TEMPLATE    = lib

HEADERS     = buflacloadplugin.h bualsaplugin.h buechoplugin.h bunccaneerwidgets.h
SOURCES     = buflacloadplugin.cpp bualsaplugin.cpp buechoplugin.cpp bunccaneerwidgets.cpp
RESOURCES   = icons.qrc \
    IconSet.qrc
LIBS        += -L. 

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += designer
} else {
    CONFIG += designer
}

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS    += target

include(bualsa.pri)
include(buecho.pri)
include(buflacload.pri)

unix:!macx: LIBS += -L$$PWD/../../../c/rackoonio/ -lrackio

INCLUDEPATH += $$PWD/../../../c/rackoonio
DEPENDPATH += $$PWD/../../../c/rackoonio

QMAKE_CXXFLAGS += -std=c++11

unix:!macx: LIBS += -L$$PWD/../../../c/libbuccaneer/ -lbuccaneer

INCLUDEPATH += $$PWD/../../../c/libbuccaneer
DEPENDPATH += $$PWD/../../../c/libbuccaneer
