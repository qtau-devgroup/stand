/* FftSg.h from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#ifndef FFT_H
#define FFT_H

/**
 * Is a thin wrapper of Ooura FFT.
 */
class Fft
{
public:
    static const int Inverse = -1;
    static const int Forward = 1;
    enum Type
    {
        Real = 1,
        Complex = 2
    };
    typedef struct _Config
    {
        int fftLength;
        Type type;
        _Config(int fftLength, Type type)
        {
            this->fftLength = fftLength;
            this->type = type;
        }
        _Config(const _Config &other)
        {
            this->fftLength = other.fftLength;
            this->type = other.type;
        }
    } Config;

    static int suitableLength(int sampleCount);
public:
    explicit Fft(int fftLength, Type type);
    virtual ~Fft();
    void execute(int sign, double *inout);
    const Config &config() const;
private:
    void _createBuffer();
    void _destroy();
    int *_ip;
    double *_w;
    Config _config;
};

#endif // FFT_H
