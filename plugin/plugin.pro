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
    standLogger.h \
    Renderer.h \
    util/Util.h \
    util/Temperament.h \
    util/SynchronizedRepository.h \
    util/ResourceRepositoryWithFactory.h \
    util/ResourceRepository.h \
    util/ResourceFactory.h \
    synthesis/Synthesizer.h \
    synthesis/Synthesis.h \
    synthesis/stand/WaveformRepository.h \
    synthesis/stand/WaveformFactory.h \
    synthesis/stand/Waveform.h \
    synthesis/stand/FrameList.h \
    synthesis/stand/Corpus.h \
    generators/FrameGenerator.h \
    generators/F0Generator.h \
    synthesis/Renderer.h \
    synthesis/stand/WorldSynthesizer.h \
    synthesis/stand/WorldAnalyzer.h \
    synthesis/stand/WorldSpectrums.h \
    synthesis/Converter.h \
    ../../../editor/audio/codecs/Wav.h \
    ../../../editor/audio/Codec.h \
    ../../../editor/audio/Resampler.h \
    dsp/WindowFunctions.h \
    dsp/SynchronousSpectrumEstimator.h \
    dsp/StarSpectrumEstimator.h \
    dsp/MinimumPhase.h \
    dsp/FftSg.h \
    dsp/F0Estimator.h \
    dsp/DioF0Estimator.h \
    dsp/Decimator.h \
    dsp/helpers/DioHelper.h

SOURCES += \
    standSynth.cpp \
    ../../../tools/utauloid/ust.cpp \
    ../../../tools/utauloid/oto.cpp \
    ../../../editor/Utils.cpp \
    ../../../editor/audio/Source.cpp \
    standLogger.cpp \
    Renderer.cpp \
    util/Util.cpp \
    util/Temperament.cpp \
    util/SynchronizedRepository.cpp \
    util/ResourceRepositoryWithFactory.cpp \
    util/ResourceRepository.cpp \
    util/ResourceFactory.cpp \
    synthesis/Synthesizer.cpp \
    synthesis/Synthesis.cpp \
    synthesis/Renderer.cpp \
    synthesis/stand/WaveformRepository.cpp \
    synthesis/stand/WaveformFactory.cpp \
    synthesis/stand/Waveform.cpp \
    synthesis/stand/FrameList.cpp \
    synthesis/stand/Corpus.cpp \
    generators/FrameGenerator.cpp \
    generators/F0Generator.cpp \
    synthesis/stand/WorldSynthesizer.cpp \
    synthesis/stand/WorldAnalyzer.cpp \
    synthesis/stand/WorldSpectrums.cpp \
    synthesis/Converter.cpp \
    ../../../editor/audio/codecs/Wav.cpp \
    ../../../editor/audio/Codec.cpp \
    ../../../editor/audio/Resampler.cpp \
    dsp/WindowFunctions.cpp \
    dsp/SynchronousSpectrumEstimator.cpp \
    dsp/StarSpectrumEstimator.cpp \
    dsp/MinimumPhase.cpp \
    dsp/FftSg.cpp \
    dsp/F0Estimator.cpp \
    dsp/DioF0Estimator.cpp \
    dsp/Decimator.cpp

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
