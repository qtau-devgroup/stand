#ifndef PLATINUMSPECTRUMESTIMATOR_H
#define PLATINUMSPECTRUMESTIMATOR_H

#include <QList>

#include "FftSg.h"
#include "MinimumPhase.h"

#include "SynchronousSpectrumEstimator.h"

class PlatinumSpectrumEstimator : public SynchronousSpectrumEstimator
{
public:
    PlatinumSpectrumEstimator(const QList<int> *peakIndices, double **powerSpectrum, int fftLength, double msFramePeriod);
    ~PlatinumSpectrumEstimator();

    void estimate(double *dst, const float *wave, float ms, float f0, int fs, int length);
private:
    const QList<int> *_indices;
    double _msFramePeriod;
    double **_powerSpectrum;
    int _fftLength;

    Fft _real;
    MinimumPhase _minimumPhase;
    double *_working; // working memory for a minimum phase spectrum.
};

#endif // PLATINUMSPECTRUMESTIMATOR_H
