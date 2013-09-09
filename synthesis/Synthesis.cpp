/* Synthesis.cpp from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#include <cmath>
#include "synthesis/Corpus.h"

#include "Synthesis.h"

standSynthesis::standSynthesis(const Config &config) :
    config(config), aggregate(config.fftLength), spectrums(config.fftLength)
{
}

void standSynthesis::synthesize(float *raw, int length, const standFrame &frame)
{
    for(int i = 0; i <= config.fftLength / 2; i++)
    {
        aggregate.spectrum[i] = 1.0;
    }
    for(int i = 0; i < config.fftLength; i++)
    {
        aggregate.residual[i] = 0.0;
    }

    for(int i = 0; i < frame.size(); i++)
    {
        config.corpus->find(spectrums, frame[i].pronounce, frame[i].msPosition);
        for(int f = 0; f <= config.fftLength / 2; f++)
        {
            aggregate.spectrum[f] *= pow(spectrums.spectrum[f], frame[i].amplify);
        }
        for(int f = 0; f < config.fftLength; f++)
        {
            aggregate.spectrum[f] += spectrums.spectrum[f] * frame[i].amplify;
        }
    }

    double *wave = new double[config.fftLength];
    // synthesize spectrums here and add them into raw.
    for(int t = 0; t < length && t < config.fftLength; t++)
    {
        raw[t] += wave[t];
    }
    delete[] wave;
}
