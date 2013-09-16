/* MinimumPhase.h from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#ifndef MINIMUMPHASE_H
#define MINIMUMPHASE_H

#include "util/dsp/Fft.h"

class MinimumPhase
{
public:
    explicit MinimumPhase(int fftLength);
    /**
     * Calculates corresponding minimum-phase spectrum to given power specturm
     */
    void spectrum(double *minimumPhase, double *powerSpectrum, int fftLength);
private:
    Fft fft;
};

#endif // MINIMUMPHASE_H
