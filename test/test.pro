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
    dsp/StarSpectrumEstimatorTest.h \
    dsp/MinimumPhaseTest.h \
    dsp/FftTest.h \
    dsp/DioF0EstimatorTest.h \
    dsp/DecimatorTest.h \
    dsp/world/world_synthesis.h \
    dsp/world/tandem_ap.h \
    dsp/world/synthesis_ap.h \
    dsp/world/star.h \
    dsp/world/platinum.h \
    dsp/world/matlabfunctions.h \
    dsp/world/fft.h \
    dsp/world/dio.h \
    dsp/world/constant_numbers.h \
    dsp/world/common.h \
    dsp/helpers/WorldDecimator.h \
    dsp/PlatinumResidualCalculatorTest.h
SOURCES += \
    AutoTest.cpp \
    main.cpp \
    dsp/world/world_synthesis.cpp \
    dsp/world/tandem_ap.cpp \
    dsp/world/synthesis_ap.cpp \
    dsp/world/star.cpp \
    dsp/world/platinum.cpp \
    dsp/world/matlabfunctions.cpp \
    dsp/world/fft.cpp \
    dsp/world/dio.cpp \
    dsp/world/common.cpp \
    dsp/helpers/WorldDecimator.cpp

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
