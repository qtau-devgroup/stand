/* Waveform.cpp from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#include <QFileInfo>
#include "Waveform.h"

standWaveform::standWaveform(QByteArray &wave, QList<float> &f0, QList<int> &indices, int fs, double msFramePeriod, int length) :
    _wave(wave),
    _f0(f0),
    _indices(indices)
{
    _fs = fs;
    _msFramePeriod = msFramePeriod;
    _length = length;
}

