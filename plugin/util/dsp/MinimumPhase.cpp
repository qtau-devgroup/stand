/* MinimuPhase.cpp from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#include <cmath>
#include "MinimumPhase.h"

typedef double fftComplex[2];

MinimumPhase::MinimumPhase(int fftLength) :
    fft(fftLength)
{
}


void MinimumPhase::spectrum(double *minimumPhase, double *powerSpectrum, int fftLength)
{
    for(int i = 0; i <= fftLength / 2; i++)
    {
        minimumPhase[i * 2] = log(powerSpectrum[i]);
        minimumPhase[i * 2 + 1] = 0.0;
    }
    for(int i = fftLength / 2 + 1; i < fftLength; i++)
    {
        minimumPhase[i * 2] = minimumPhase[(fftLength - i) * 2];
        minimumPhase[i * 2 + 1] = 0.0;
    }
    fft.real(fftLength, Fft::Inverse, minimumPhase);
    minimumPhase[1] += -1.0;
    for(int i = 2; i < fftLength; i += 2)
    {
        minimumPhase[i] *= 2.0;
        minimumPhase[i + 1] *= -2.0;
    }
    minimumPhase[fftLength + 1] *= -1.0;
    for(int i = fftLength + 2; i < fftLength * 2; i += 2)
    {
        minimumPhase[i] = minimumPhase[i + 1] = 0.0;
    }
    fft.complex(fftLength, Fft::Forward, minimumPhase);
    double re, im;
    for(int i = 0; i < fftLength; i += 2)
    {
        re = exp(minimumPhase[i] / fftLength);
        im = minimumPhase[i + 1] / fftLength;
        minimumPhase[i] = re * cos(im);
        minimumPhase[i+1] = re * sin(im);
    }
}
