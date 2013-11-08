#include <qmath.h>
#include "PlatinumSpectrumEstimator.h"

PlatinumSpectrumEstimator::PlatinumSpectrumEstimator(const QList<int> *peakIndices, double **powerSpectrum, int fftLength, double msFramePeriod) :
    _real(fftLength, Fft::Real), _minimumPhase(fftLength)
{
    _powerSpectrum = powerSpectrum;
    _msFramePeriod = msFramePeriod;
    _fftLength = fftLength;
    _indices = peakIndices;
    _working = new double[fftLength];
}

PlatinumSpectrumEstimator::~PlatinumSpectrumEstimator()
{
    delete[] _working;
}

void PlatinumSpectrumEstimator::estimate(double *dst, const float *wave, float ms, float f0, int fs, int length)
{
    int frameIndex = ms / _msFramePeriod;
    if(frameIndex < 0 || _indices->size() <= frameIndex)
    {
        return;
    }
    double T0 = fs / f0;
    int windowLength = qRound(2.0 * T0);
    int waveIndex = _indices->at(frameIndex);
    for(int i = 0; i < windowLength; i++)
    {
        double w = 0.5 - 0.5 * cos(2.0 * M_PI * (i + 1.0) / (windowLength + 1.0));
        dst[i] = wave[qMin(length - 1, qMax(0, i + waveIndex - qRound(T0)))] * w;
    }
    for(int i = windowLength + 1; i < _fftLength; i++)
    {
        dst[i] = 0.0;
    }
    _real.execute(Fft::Forward, dst);
    _minimumPhase.execute(_working, _powerSpectrum[frameIndex]);
    dst[0] = dst[0] / _working[0];
    dst[1] = dst[1] / _working[1];
    for(int i = 1; i < _fftLength / 2; i++)
    {
        double r = _working[i * 2] * _working[i * 2] + _working[i * 2 + 1] * _working[i * 2 + 1];
        double re = (_working[i * 2] * dst[i * 2] + _working[i * 2 + 1] * dst[i * 2 + 1]) / r;
        double im = (_working[i * 2] * dst[i * 2 + 1] - _working[i * 2 + 1] * dst[i * 2]) / r;
        dst[i * 2] = re;
        dst[i * 2 + 1] = im;
    }
}
