/* MinimumPhase.h from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#ifndef MINIMUMPHASE_H
#define MINIMUMPHASE_H

#include "util/dsp/fft.h"

/**
 * @brief Keeps buffers for calculation of minimum phase spectrum.
 */
class MinimumPhase
{
public:
    explicit MinimumPhase(int fftLength);
    /**
     * @brief Calculates corresponding minimum-phase spectrum to given power specturm
     */
    void execute(double *minimumPhase, double *powerSpectrum);

    Fft real;
    Fft complex;
};

#endif // MINIMUMPHASE_H
