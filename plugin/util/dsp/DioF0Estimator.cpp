#include <qmath.h>
#include <QtAlgorithms>
#include <float.h>
#include "util/dsp/Decimator.h"
#include "util/dsp/FftSg.h"
#include "util/dsp/WindowFunctions.h"
#include "DioF0Estimator.h"

const static double Log2 = log(2.0);
const double DioF0Estimator::DefaultF0Floor = 80.0;
const double DioF0Estimator::DefaultF0Ceil = 640.0;
const double DioF0Estimator::DefaultChannelsInOctave = 2.0;
const double DioF0Estimator::DefaultDecimatedFs = 4000.0;

#include "helpers/DioHelper.h"

DioF0Estimator::DioF0Estimator(double f0Floor, double f0Ceil, double channelsInOctave, double decimatedFs)
{
    _floorF0 = f0Floor;
    _ceilF0 = f0Ceil;
    _channelsInOctave = channelsInOctave;
    _bandsCount = 2 + (log(_ceilF0 / _floorF0) / Log2 * _channelsInOctave);
    _decimatedFs = decimatedFs;
}

DioF0Estimator::Spectrum DioF0Estimator::_createDecimatedSpectrum(const float *wave, int length, int fs, int decimationRatio)
{
    int decimatedLength = 1 + length / decimationRatio;
    int fftLength = _fft->config().fftLength;
    double *decimatedWave = new double[fftLength];
    Decimator::decimate(wave, length, decimationRatio, decimatedWave, decimatedLength);
    double mean = 0.0;
    for(int i = 0; i < decimatedLength; i++)
    {
        mean += decimatedWave[i];
    }
    mean /= decimatedLength;
    for(int i = 0; i < decimatedLength; i++)
    {
        decimatedWave[i] -= mean;
    }
    for(int i = decimatedLength; i < fftLength; i++)
    {
        decimatedWave[i] = 0.0;
    }
    _fft->execute(Fft::Forward, decimatedWave);
    return Spectrum(decimatedWave, decimatedLength, fftLength, (double)fs / decimationRatio);
}

void DioF0Estimator::_getFilteredSignal(double *dst, int halfAverageLength, const Spectrum &spectrum)
{
    // First, `dst` contains waveform of Nuttall window corresponding to halfAverageLength.
    for (int i = halfAverageLength * 2; i < spectrum.size; i++)
    {
        dst[i] = 0.0;
    }
    WindowFunctions::nuttall(dst, halfAverageLength * 4);
    // Then, `dst` becomes spectrum of that Nuttal window.
    _fft->execute(Fft::Forward, dst);

    // Third, `dst` will be a convolution of the decimated spectrum and nuttal window spectrum.
    dst[0] *= spectrum.data[0];
    dst[1] *= spectrum.data[1];
    for (int i = 1; i <= spectrum.size / 2; ++i) {
        double tmp = spectrum.data[i * 2] * dst[i * 2 + 1] + spectrum.data[i * 2 + 1] * dst[i * 2];
        dst[i * 2] = spectrum.data[i * 2] * dst[i * 2] - spectrum.data[i * 2 + 1] * dst[i * 2 + 1];
        dst[i * 2 + 1] = tmp;
    }
    // Last, `dst` gets a waveform.
    _fft->execute(Fft::Inverse, dst);

    // And compensate the delay of the signal.
    int offset = halfAverageLength * 2;
    for (int i = 0; i < spectrum.length; i++)
    {
        dst[i] = dst[i + offset];
    }
}

QList<float> DioF0Estimator::_estimate(const Spectrum &spectrum, int length, int fs, double msFramePeriod)
{
    int f0Length = length / (double)fs / msFramePeriod * 1000.0 + 1;
    double **candidates = newMatrix(f0Length, _bandsCount);
    double **stabilities = newMatrix(f0Length, _bandsCount);

    double *filteredSignal = new double[spectrum.size];
    for (int i = 0; i < _bandsCount; i++)
    {
        double boundaryF0 = _floorF0 * pow(2.0, i / _channelsInOctave);
        _getFilteredSignal(filteredSignal, qRound(spectrum.fs / boundaryF0 / 2.0), spectrum);

        getCandidates(candidates[i], stabilities[i], f0Length, msFramePeriod, boundaryF0, _ceilF0, _floorF0, filteredSignal, spectrum.length, spectrum.fs);
    }
    QList<float> result(getF0Contour(candidates, stabilities, _bandsCount, f0Length, msFramePeriod));
    delete[] filteredSignal;
    deleteMatrix(stabilities);
    deleteMatrix(candidates);
    return result;
}

QList<float> DioF0Estimator::estimate(const float *wave, int fs, double msFramePeriod, int length)
{
    int decimationRatio = qMax(1, qMin(12, (int)(fs / _decimatedFs)));
    int decimatedLength = 1 + length / decimationRatio;
    _fft = new Fft(Fft::suitableLength(decimatedLength), Fft::Real);

    Spectrum decimatedSpectrum(_createDecimatedSpectrum(wave, length, fs, decimationRatio));

    QList<float> result(_estimate(decimatedSpectrum, length, fs, msFramePeriod));

    delete _fft;

    return result;
}

