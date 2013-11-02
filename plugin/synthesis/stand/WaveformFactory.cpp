/* WaveformFactory.cpp from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#include <QFile>
#include "standLogger.h"
#include "audio/Resampler.h"
#include "WaveformFactory.h"

standWaveformFactory::standWaveformFactory(double msFramePeriod, qtauAudioCodecFactory *codec)
{
    this->codec = codec;
    this->msFramePeriod = msFramePeriod;
}

standWaveformFactory::~standWaveformFactory()
{
    delete codec;
}

standWaveform *standWaveformFactory::create(const QString &filepath)
{
    QFile file(filepath);
    if(!file.open(QFile::ReadOnly))
    {
        Logger::info("stand tried to open `" + filepath + "`, but failed.");
        return NULL;
    }
    QByteArray wave(_readFile(file));
    if(wave.isEmpty())
    {
        return NULL;
    }
    return NULL;
}

standWaveform *standWaveformFactory::newWaveform(QByteArray &wave, QVector<float> &f0, QVector<int> &indices, int fs, double msFramePeriod, int length)
{
    return new standWaveform(wave, f0, indices, fs, msFramePeriod, length);
}

QByteArray standWaveformFactory::_readFile(QFile &file)
{
    qtauAudioCodec *audio = codec->make(file);

    // TODO: make format selectable.
    QAudioFormat fmt(audio->getAudioFormat());
    fmt.setByteOrder(QAudioFormat::LittleEndian);
    fmt.setChannelCount(1);
    fmt.setSampleSize(4);
    fmt.setSampleType(QAudioFormat::Float);
    qtauResampler resampler(audio->buffer(), audio->getAudioFormat(), fmt);
    QByteArray wave(resampler.encode());

    return wave;
}
