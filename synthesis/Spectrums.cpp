#include "Spectrums.h"

standSpectrums::standSpectrums(int fftLength)
{
    this->fftLength = fftLength;
    spectrum = new double[fftLength];
    residual = new double[fftLength];
}

standSpectrums::~standSpectrums()
{
    delete[] spectrum;
    delete[] residual;
}
