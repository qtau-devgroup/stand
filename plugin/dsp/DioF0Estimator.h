#ifndef DIOF0ESTIMATOR_H
#define DIOF0ESTIMATOR_H

#include <QPair>
#include "F0Estimator.h"

class Fft;

class DioF0Estimator : public F0Estimator
{
public: // public constants
    static const double DefaultF0Floor;
    static const double DefaultF0Ceil;
    static const double DefaultChannelsInOctave;
    static const double DefaultDecimatedFs;
public:
    explicit DioF0Estimator(
            double f0Floor = DefaultF0Floor,
            double f0Ceil = DefaultF0Ceil,
            double channelsInOctave = DefaultChannelsInOctave,
            double decimatedFs = DefaultDecimatedFs);
    QList<float> estimate(const float *wave, int fs, double msFramePeriod, int length);
private:
    double _floorF0;
    double _ceilF0;
    double _channelsInOctave;
    double _decimatedFs;
    int _bandsCount;
    Fft *_fft;

    typedef struct _Spectrum
    {
        _Spectrum(const _Spectrum &other)
        {
            data = other.data;
            length = other.length;
            size = other.size;
            fs = other.fs;
        }
        _Spectrum(double *spectrum, int length, int size, double fs)
        {
            this->data = spectrum;
            this->length = length;
            this->size = size;
            this->fs = fs;
        }
        ~_Spectrum()
        {
            delete[] data;
        }

        double *data;
        int length; // length of wave
        int size;   // size of FFT
        double fs;
    } Spectrum;

    Spectrum _createDecimatedSpectrum(const float *wave, int length, int fs, int decimationRatio);
    void _getFilteredSignal(double *dst, int halfAverageLength, const Spectrum &spectrum);
    QList<float> _estimate(const Spectrum &spectrum, int length, int fs, double msFramePeriod);
};

#endif // DIOF0ESTIMATOR_H
