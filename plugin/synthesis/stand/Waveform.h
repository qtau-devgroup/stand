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
    ~standWaveform();

    const float *f0() const
    {
        return _f0;
    }
    const float *t() const
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
    int length() const
    {
        return _length;
    }

private:
    explicit standWaveform(float *wave, float *t, float *f0, int fs, int *indices, double msFramePeriod, int length);
    float *_f0;
    float *_t;
    float *_wave;
    int _fs;
    int *_indices;
    int _length;
    double _msFramePeriod;

    friend class standWaveformFactory;
};

#endif // STAND_PHONEME_MODEL_H
