/* WaveformFactory.h from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#ifndef WAVEFORMFACTORY_H
#define WAVEFORMFACTORY_H

#include <QFileInfo>
#include "synthesis/stand/Waveform.h"
#include "util/ResourceFactory.h"

class standWaveformFactory : public ResourceFactory<QString, standWaveform>
{
public:
    standWaveform *create(const QString &filepath);
private:
    standWaveform *_create(float *wave, float *t, float *f0, int fs, int *indices, double msFramePeriod, int length);
};

#endif // WAVEFORMFACTORY_H
