#ifndef STAND_SYNTHESIS_H
#define STAND_SYNTHESIS_H

#include "generators/FrameGenerator.h"
#include "synthesis/Spectrums.h"

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
    virtual void synthesize(float *raw, int length, const standFrame &frame);
protected:
    Config config;
    standSpectrums aggregate;
    standSpectrums spectrums;
};

#endif // STAND_SYNTHESIS_H
