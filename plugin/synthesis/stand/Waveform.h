/* Waveform.h from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#ifndef STAND_PHONEME_MODEL_H
#define STAND_PHONEME_MODEL_H

#include <QByteArray>
#include <QVector>

class QFileInfo;

/**
 * @brief Contains waveform, its f0 contour and indices of peak. This class is immutable.
 */
class standWaveform
{
public:
    float f0(int i) const
    {
        return _f0.at(i);
    }
    const float *wave() const
    {
        return (float *)_wave.data();
    }
    int fs() const
    {
        return _fs;
    }
    int indices(int i) const
    {
        return _indices.at(i);
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
    explicit standWaveform(QByteArray &wave, QVector<float> &f0, QVector<int> &indices, int fs, double msFramePeriod, int length);
    QByteArray _wave;
    QVector<float> _f0;
    QVector<int> _indices;
    int _fs;
    int _length;
    double _msFramePeriod;

    friend class standWaveformFactory;
};

#endif // STAND_PHONEME_MODEL_H
