#ifndef PLATINUMSPECTRUMESTIMATOR_H
#define PLATINUMSPECTRUMESTIMATOR_H

#include <QList>

#include "FftSg.h"
#include "MinimumPhase.h"

class PlatinumResidualCalculator
{
public:
    PlatinumResidualCalculator(int fftLength);
    ~PlatinumResidualCalculator();

    void calculate(double *dst, const float *wave, int peakIndex, float f0, int fs, const double *power, int length);
private:
    int _fftLength;

    Fft _real;
    MinimumPhase _minimumPhase;
    double *_working; // working memory for a minimum phase spectrum.
};

#endif // PLATINUMSPECTRUMESTIMATOR_H
