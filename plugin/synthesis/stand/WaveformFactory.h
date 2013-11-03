/* WaveformFactory.h from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#ifndef WAVEFORMFACTORY_H
#define WAVEFORMFACTORY_H

#include <QFileInfo>
#include "audio/codecs/Wav.h"

#include "synthesis/stand/Waveform.h"
#include "util/ResourceFactory.h"

class qtauAudioCodecFactory;

class standWaveformFactory : public ResourceFactory<QString, standWaveform>
{
public:
    explicit standWaveformFactory(double msFramePeriod, qtauAudioCodecFactory *codec = new qtauWavCodecFactory);
    virtual ~standWaveformFactory();
    virtual standWaveform *create(const QString &filepath);
protected:
    standWaveform *newWaveform(QByteArray &wave, QList<float> &f0, QList<int> &indices, int fs, double msFramePeriod, int length);
    qtauAudioCodecFactory *codec;
    double msFramePeriod;
private:
    QByteArray _readFile(QFile &file);
};

#endif // WAVEFORMFACTORY_H
