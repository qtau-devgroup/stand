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
    ../../editor/audio/Source.h

SOURCES += \
    standSynth.cpp \
    ../../tools/utauloid/ust.cpp \
    ../../tools/utauloid/oto.cpp \
    ../../editor/Utils.cpp \
    ../../editor/audio/Source.cpp

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
