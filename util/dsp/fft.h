/* Fft.h from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
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

public:
    explicit Fft(int fftLength);
    virtual ~Fft();
    void complex(int fftLength, int sign, double *inout);
    void real(int fftLength, int sign, double *inout);
    int fftLength;
private:
    int *_ip;
    double *_w;
};

#endif // FFT_H
