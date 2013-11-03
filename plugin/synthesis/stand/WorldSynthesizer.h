/* WorldSynthesizer.h from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#ifndef STANDSYNTHESIZER_H
#define STANDSYNTHESIZER_H

#include "WorldSpectrums.h"
#include "synthesis/Synthesizer.h"
#include "synthesis/stand/FrameList.h"
#include "dsp/FftSg.h"
#include "dsp/MinimumPhase.h"

class standCorpus;

class standSynthesizer : public Synthesizer<standFrameList>
{
public:
    explicit standSynthesizer(int fftLength, standCorpus *corpus);
    ~standSynthesizer();
    double synthesize(float *raw, int length, const standFrameList *internal, double ms);
private:
    void synthesizeOneFrame(double *wave, const standSpectrums &spectrums);
    int _fftLength;
    standCorpus *_corpus;
    standSpectrums aggregate;
    standSpectrums spectrums;
    MinimumPhase minimumPhaseCalculator;
    Fft inverse;
    double *_wave;
};

#endif // STANDSYNTHESIZER_H
