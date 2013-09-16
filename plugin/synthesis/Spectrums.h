/* Spectrums.h from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#ifndef STAND_SPECTRUMS_H
#define STAND_SPECTRUMS_H

class standSpectrums
{
public:
    standSpectrums(int fftLength);
    ~standSpectrums();
    double *spectrum;
    double *residual;
    int fftLength;
};

#endif // STAND_SPECTRUMS_H
