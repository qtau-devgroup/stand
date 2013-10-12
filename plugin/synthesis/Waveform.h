/* Waveform.h from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#ifndef STAND_PHONEME_MODEL_H
#define STAND_PHONEME_MODEL_H

class QFileInfo;

/**
 * @brief Contains waveform, its f0 contour and indices of peak. This class is immutable.
 */
class standWaveform
{
public:
    explicit standWaveform(const QFileInfo &fileinfo, double msFramePeriod);
    ~standWaveform();

    const double *f0() const
    {
        return _f0;
    }
    const double *t() const
    {
        return _t;
    }
    const float *wave() const
    {
        return _wave;
    }
    int fs() const
    {
        return _fs;
    }
    const int *indices() const
    {
        return _indices;
    }
    double msFramePeriod() const
    {
        return _msFramePeriod;
    }
    bool isAvailable() const;

private:
    double *_f0;
    double *_t;
    float *_wave;
    int _fs;
    int *_indices;
    double _msFramePeriod;
    bool _isAvailable;
};

#endif // STAND_PHONEME_MODEL_H
