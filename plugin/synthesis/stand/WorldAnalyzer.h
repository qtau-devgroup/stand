#ifndef ANALYZER_H
#define ANALYZER_H

#include "FrameList.h"
#include "Waveform.h"

class standSpectrums;

template <class T>
class standAnalyzer
{
public:
    virtual void analyze(standSpectrums *dst, const T *data, double ms) = 0;
};

class standWaveformAnalyzer : public standAnalyzer<standWaveform>
{
public:
    explicit standWaveformAnalyzer(int fs, int fftLength);
    void analyze(standSpectrums *dst, const standWaveform *data, double ms);
private:
    int _fs;
    int _fftLength;
};

#endif // ANALYZER_H
