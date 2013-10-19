/* WaveformFactory.cpp from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#include "WaveformFactory.h"

standWaveform *standWaveformFactory::create(const QString &filepath)
{
    // TODO: implement reading file from fileinfo
    return NULL;
}

standWaveform *standWaveformFactory::_create(float *wave, float *t, float *f0, int fs, int *indices, double msFramePeriod, int length)
{
    return new standWaveform(wave, t, f0, fs, indices, msFramePeriod, length);
}

