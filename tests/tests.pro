#-------------------------------------------------
# http://github.com/qtau-devgroup/stand
#-------------------------------------------------

include(../stand.pro)
QT += testlib
QT -= gui
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app
CONFIG  += test
TARGET   = $$qtLibraryTarget(standTest)

QT += testlib

HEADERS += \
    AutoTest.h \
    MinimumPhaseTest.h
SOURCES += \
    AutoTest.cpp

QMAKE_CXXFLAGS += -Wall -std=c++11

#--------------------------------------------
CONFIG(debug, debug|release) {
    COMPILEDIR = $${OUT_PWD}/../../../debug
} else {
    COMPILEDIR = $${OUT_PWD}/../../../release
}

DESTDIR         = $${COMPILEDIR}/stand/.tests
OBJECTS_DIR     = $${COMPILEDIR}/stand/.obj
MOC_DIR         = $${COMPILEDIR}/stand/.moc
RCC_DIR         = $${COMPILEDIR}/stand/.rcc
UI_DIR          = $${COMPILEDIR}/stand/.ui
#--------------------------------------------
