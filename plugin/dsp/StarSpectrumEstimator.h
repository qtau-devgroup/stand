/* StarSpectrumEstimator.h from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#ifndef STARSPECTRUMESTIMATOR_H
#define STARSPECTRUMESTIMATOR_H

#include "FftSg.h"
#include "SynchronousSpectrumEstimator.h"

class StarSpectrumEstimator : public SynchronousSpectrumEstimator
{
public:
    static const double F0Floor;
    static const double F0Default;
    StarSpectrumEstimator(int fftLength, double f0Floor = F0Floor, double f0Default = F0Default);
    void estimate(double *dst, const float *wave, float ms, float f0, int fs, int length);
private:
    void _estimatePowerSpectrum(double *dst, const float *wave, float ms, float f0, int fs, int length);
    void _smootheSpectrum(double *dst, float f0, int fftLength, int fs);
    Fft real;
    double _f0Floor;
    double _f0Default;
};

#endif // STARSPECTRUMESTIMATOR_H
