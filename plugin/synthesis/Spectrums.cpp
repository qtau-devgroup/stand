/* Spectrums.cpp from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#include "Spectrums.h"

standSpectrums::standSpectrums(int fftLength)
{
    this->fftLength = fftLength;
    power = new double[fftLength];
    residual = new double[fftLength];
}

standSpectrums::~standSpectrums()
{
    delete[] power;
    delete[] residual;
}
