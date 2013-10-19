/* Waveform.cpp from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#include <QFileInfo>
#include "Waveform.h"

standWaveform::standWaveform(float *wave, float *t, float *f0, int fs, int *indices, double msFramePeriod, int length)
{
    _f0 = f0;
    _t = t;
    _wave = wave;
    _indices = indices;
    _fs = fs;
    _msFramePeriod = msFramePeriod;
    _length = length;
}

standWaveform::~standWaveform()
{
    delete[] _f0;
    delete[] _t;
    delete[] _wave;
    delete[] _indices;
}

