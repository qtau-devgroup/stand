/* MinimuPhase.cpp from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#include <cmath>
#include <float.h>
#include "MinimumPhase.h"
#include <stdio.h>

typedef double fftComplex[2];

MinimumPhase::MinimumPhase(int fftLength) :
    real(fftLength, Fft::Real), complex(fftLength, Fft::Complex)
{
}


void MinimumPhase::execute(double *minimumPhase, const double *powerSpectrum)
{
    int fftLength = real.config().fftLength;
    for(int i = 0; i <= fftLength / 2; i++)
    {
        minimumPhase[i] = log(powerSpectrum[i] + DBL_MIN) / 2.0; // Safe guard for log(0)
    }
    // Needs mirroring, because power spectrum has information only in its front half.
    for(int i = fftLength / 2 + 1; i < fftLength; i++)
    {
        minimumPhase[i] = minimumPhase[fftLength - i];
    }
    // power spectrum -> cepstrum
    real.execute(Fft::Forward, minimumPhase);
    // Real to complex fft returns value@index[fftLength] in minimumPhase[1]
    // because imaginary parts at index[0] and index[fftLength] is always zero.
    minimumPhase[fftLength] = minimumPhase[1];
    minimumPhase[fftLength + 1] = 0.0;
    minimumPhase[1] = 0.0;

    // Calculates minimum phase spectrum below.
    for(int i = 2; i < fftLength; i += 2)
    {
        minimumPhase[i] *= 2.0;
        minimumPhase[i + 1] *= -2.0;
    }
    for(int i = fftLength + 2; i < fftLength * 2; i++)
    {
        minimumPhase[i] = 0.0;
    }
    complex.execute(Fft::Forward, minimumPhase);
    double re, im;
    for(int i = 0; i <= fftLength; i += 2)
    {
        // Needs scaling with FFT length.
        re = exp(minimumPhase[i] / fftLength);
        im = minimumPhase[i + 1] / fftLength;
        minimumPhase[i] = re * cos(im);
        minimumPhase[i + 1] = re * sin(im);
    }
}
