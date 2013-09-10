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

    synthesizeOneFrame(wave, aggregate);

    for(int t = 0; t < length && t < config.fftLength; t++)
    {
        raw[t] += wave[t];
    }
    delete[] wave;
}

void standSynthesis::synthesizeOneFrame(double *wave, const standSpectrums &spectrums)
{
    typedef double complex[2];
    // TODO : one frame synthesis.
    complex *minimumPhase = new complex[config.fftLength];
    // calculate minimum phase spectrum from power-spectrum

    // calculate spectrum; minimumphase spectrum spectrum multipled by residual.
    complex *spectrum = new complex[config.fftLength];
    spectrum[0][0] = minimumPhase[0][0] * spectrums.residual[0];
    spectrum[0][1] = 0.0;
    for(int i = 1; i < config.fftLength / 2; i++)
    {
        spectrum[i][0] = minimumPhase[i][0] * spectrums.residual[i*2-1] - minimumPhase[i][1] * spectrums.residual[i*2];
        spectrum[i][1] = minimumPhase[i][1] * spectrums.residual[i*2] + minimumPhase[i][0] * spectrums.residual[i*2-1];
    }
    spectrum[config.fftLength/2][0] = minimumPhase[config.fftLength/2][0] * spectrums.residual[config.fftLength-1];
    spectrum[config.fftLength/2][1] = 0.0;
    // inverse FFT and get raw waveform in wave.

    // delete buffers
    delete[] spectrum;
    delete[] minimumPhase;
}
