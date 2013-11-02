#-------------------------------------------------
# http://github.com/qtau-devgroup/stand
#-------------------------------------------------

VPATH += ../plugin
INCLUDEPATH += ../plugin

include(../plugin/plugin.pro)

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
    util/dsp/MinimumPhaseTest.h \
    util/dsp/FftTest.h \
    util/dsp/DecimatorTest.h \
    util/dsp/helpers/WorldDecimator.h \
    util/dsp/DioF0EstimatorTest.h \
    util/dsp/world/tandem_ap.h \
    util/dsp/world/synthesis_ap.h \
    util/dsp/world/synthesis.h \
    util/dsp/world/star.h \
    util/dsp/world/platinum.h \
    util/dsp/world/matlabfunctions.h \
    util/dsp/world/fft.h \
    util/dsp/world/dio.h \
    util/dsp/world/constant_numbers.h \
    util/dsp/world/common.h
SOURCES += \
    AutoTest.cpp \
    main.cpp \
    util/dsp/helpers/WorldDecimator.cpp \
    util/dsp/world/tandem_ap.cpp \
    util/dsp/world/synthesis_ap.cpp \
    util/dsp/world/synthesis.cpp \
    util/dsp/world/star.cpp \
    util/dsp/world/platinum.cpp \
    util/dsp/world/matlabfunctions.cpp \
    util/dsp/world/dio.cpp \
    util/dsp/world/common.cpp \
    util/dsp/world/fft.cpp

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
