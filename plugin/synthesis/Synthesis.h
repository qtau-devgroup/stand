/* Synthesis.h from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#ifndef STAND_SYNTHESIS_H
#define STAND_SYNTHESIS_H

#include "generators/FrameGenerator.h"
#include "synthesis/Spectrums.h"
#include "util/dsp/MinimumPhase.h"

class standCorpus;

class standSynthesis
{
public:
    typedef struct _Config {
        int fftLength;
        double msFramePeriod;
        standCorpus *corpus;
        //
        _Config(standCorpus *corpus, double msFramePeriod, int fftLength)
        {
            this->corpus = corpus;
            this->msFramePeriod = msFramePeriod;
            this->fftLength = fftLength;
        }
        _Config(const _Config &other)
        {
            this->corpus = other.corpus;
            this->msFramePeriod = other.msFramePeriod;
            this->fftLength = other.fftLength;
        }
    } Config;

    explicit standSynthesis(const Config &config);
    virtual ~standSynthesis();
    virtual void synthesize(float *raw, int length, const standFrame &frame);
protected:
    void synthesizeOneFrame(double *wave, const standSpectrums &spectrums);
    Config config;
    standSpectrums aggregate;
    standSpectrums spectrums;
    MinimumPhase minimumPhaseCalculator;
    Fft inverse;
private:
    double *_wave;
};

#endif // STAND_SYNTHESIS_H
