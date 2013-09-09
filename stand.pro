#-------------------------------------------------
# http://github.com/qtau-devgroup/stand
#-------------------------------------------------

TEMPLATE = lib
CONFIG  += plugin
TARGET   = $$qtLibraryTarget(stand)

QT += multimedia

INCLUDEPATH += ../../editor ../

HEADERS += \
    standConfig.h \
    standSynth.h \
    ../../tools/utauloid/ust.h \
    ../../tools/utauloid/oto.h \
    ../../editor/Utils.h \
    ../../editor/audio/Source.h \
    generators/F0Generator.h \
    util/Temperament.h \
    generators/FrameGenerator.h \
    synthesis/Synthesis.h \
    synthesis/Corpus.h \
    synthesis/Spectrums.h \
    synthesis/Analysis.h \
    synthesis/Phoneme.h \
    Renderer.h

SOURCES += \
    standSynth.cpp \
    ../../tools/utauloid/ust.cpp \
    ../../tools/utauloid/oto.cpp \
    ../../editor/Utils.cpp \
    ../../editor/audio/Source.cpp \
    generators/F0Generator.cpp \
    util/Temperament.cpp \
    generators/FrameGenerator.cpp \
    synthesis/Synthesis.cpp \
    synthesis/Corpus.cpp \
    synthesis/Spectrums.cpp \
    synthesis/Analysis.cpp \
    synthesis/Phoneme.cpp \
    Renderer.cpp

#--------------------------------------------
CONFIG(debug, debug|release) {
    COMPILEDIR = $${OUT_PWD}/../../debug
} else {
    COMPILEDIR = $${OUT_PWD}/../../release
}

DESTDIR         = $${COMPILEDIR}/plugins
OBJECTS_DIR     = $${COMPILEDIR}/stand/.obj
MOC_DIR         = $${COMPILEDIR}/stand/.moc
RCC_DIR         = $${COMPILEDIR}/stand/.rcc
UI_DIR          = $${COMPILEDIR}/stand/.ui
#--------------------------------------------
