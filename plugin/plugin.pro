#-------------------------------------------------
# http://github.com/qtau-devgroup/stand
#-------------------------------------------------

TEMPLATE = lib
CONFIG  += plugin
kita
QT += multimedia
INCLUDEPATH += ../../../editor ../libstand/core ../.. .

HEADERS += \
    standConfig.h \
    standSynth.h \
    ../../../tools/utauloid/ust.h \
    ../../../tools/utauloid/oto.h \
    ../../../editor/Utils.h \
    ../../../editor/audio/Source.h \
    standLogger.h \
    util/Util.h \
    ../../../editor/audio/codecs/Wav.h \
    ../../../editor/audio/Codec.h \
    ../../../editor/audio/Resampler.h \
    generators/F0Generator.h \
    generators/FrameGenerator.h \
    util/Temperament.h

SOURCES += \
    standSynth.cpp \
    ../../../tools/utauloid/ust.cpp \
    ../../../tools/utauloid/oto.cpp \
    ../../../editor/Utils.cpp \
    ../../../editor/audio/Source.cpp \
    standLogger.cpp \
    util/Util.cpp \
    util/Temperament.cpp \
    ../../../editor/audio/codecs/Wav.cpp \
    ../../../editor/audio/Codec.cpp \
    ../../../editor/audio/Resampler.cpp \
    generators/F0Generator.cpp \
    generators/FrameGenerator.cpp

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
