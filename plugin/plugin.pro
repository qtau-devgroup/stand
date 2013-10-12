#-------------------------------------------------
# http://github.com/qtau-devgroup/stand
#-------------------------------------------------

TEMPLATE = lib
CONFIG  += plugin
TARGET   = $$qtLibraryTarget(stand)

QT += multimedia

INCLUDEPATH += ../../../editor ../.. .

HEADERS += \
    standConfig.h \
    standSynth.h \
    ../../../tools/utauloid/ust.h \
    ../../../tools/utauloid/oto.h \
    ../../../editor/Utils.h \
    ../../../editor/audio/Source.h \
    generators/F0Generator.h \
    util/Temperament.h \
    generators/FrameGenerator.h \
    synthesis/Synthesis.h \
    synthesis/Corpus.h \
    synthesis/Spectrums.h \
    synthesis/Analysis.h \
    Renderer.h \
    util/Util.h \
    util/dsp/MinimumPhase.h \
    util/dsp/Fft.h \
    standLogger.h \
    synthesis/Waveform.h \
    ../plugin/synthesis/WaveRepository.h

SOURCES += \
    standSynth.cpp \
    ../../../tools/utauloid/ust.cpp \
    ../../../tools/utauloid/oto.cpp \
    ../../../editor/Utils.cpp \
    ../../../editor/audio/Source.cpp \
    generators/F0Generator.cpp \
    util/Temperament.cpp \
    generators/FrameGenerator.cpp \
    synthesis/Synthesis.cpp \
    synthesis/Corpus.cpp \
    synthesis/Spectrums.cpp \
    synthesis/Analysis.cpp \
    Renderer.cpp \
    util/Util.cpp \
    util/dsp/MinimumPhase.cpp \
    util/dsp/fft.cpp \
    standLogger.cpp \
    synthesis/Waveform.cpp \
    ../plugin/synthesis/WaveRepository.cpp

QMAKE_CXXFLAGS += -Wall -std=c++11

#--------------------------------------------
CONFIG(debug, debug|release) {
    COMPILEDIR = $${OUT_PWD}/../../../debug
} else {
    COMPILEDIR = $${OUT_PWD}/../../../release
}

DESTDIR         = $${COMPILEDIR}/plugins
OBJECTS_DIR     = $${COMPILEDIR}/stand/.obj
MOC_DIR         = $${COMPILEDIR}/stand/.moc
RCC_DIR         = $${COMPILEDIR}/stand/.rcc
UI_DIR          = $${COMPILEDIR}/stand/.ui
#--------------------------------------------
