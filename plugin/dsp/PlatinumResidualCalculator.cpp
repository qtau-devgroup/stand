#include <float.h>
#include <qmath.h>
#include "PlatinumResidualCalculator.h"

PlatinumResidualCalculator::PlatinumResidualCalculator(int fftLength) :
    _real(fftLength, Fft::Real), _minimumPhase(fftLength)
{
    _fftLength = fftLength;
    _working = new double[fftLength * 2];
}

PlatinumResidualCalculator::~PlatinumResidualCalculator()
{
    delete[] _working;
}

void PlatinumResidualCalculator::calculate(double *dst, const float *wave, int peakIndex, float f0, int fs, const double *power, int length)
{
    double T0 = fs / f0;
    int windowLength = qRound(2.0 * T0);
    for(int i = 0; i < windowLength; i++)
    {
        double w = 0.5 - 0.5 * cos(2.0 * M_PI * (i + 1.0) / (windowLength + 1.0));
        dst[i] = wave[qMin(length - 1, qMax(0, i + peakIndex - qRound(T0)))] * w;
    }
    for(int i = windowLength; i < _fftLength; i++)
    {
        dst[i] = 0.0;
    }
    _real.execute(Fft::Forward, dst);
    _minimumPhase.execute(_working, power);
    dst[0] = dst[0] / (_working[0] + DBL_MIN);
    dst[1] = dst[1] / (_working[_fftLength] + DBL_MIN);
    for(int i = 1; i < _fftLength / 2; i++)
    {
        double r = _working[i * 2] * _working[i * 2] + _working[i * 2 + 1] * _working[i * 2 + 1] + DBL_MIN;
        double re = (_working[i * 2] * dst[i * 2] + _working[i * 2 + 1] * dst[i * 2 + 1]) / r;
        double im = (_working[i * 2] * dst[i * 2 + 1] - _working[i * 2 + 1] * dst[i * 2]) / r;
        dst[i * 2] = re;
        dst[i * 2 + 1] = im;
    }
}
