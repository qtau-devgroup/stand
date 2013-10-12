/* Waveform.cpp from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#include <QFileInfo>
#include "Waveform.h"

standWaveform::standWaveform(const QFileInfo &fileinfo, double msFramePeriod)
{
    _f0 = NULL;
    _t = NULL;
    _wave = NULL;
    _indices = NULL;
    _fs = 0;
    _msFramePeriod = msFramePeriod;
    _isAvailable = false;

    // TODO: read wave
}

standWaveform::~standWaveform()
{
    delete[] _f0;
    delete[] _t;
    delete[] _wave;
    delete[] _indices;
}

bool standWaveform::isAvailable() const
{
    return _isAvailable;
}
