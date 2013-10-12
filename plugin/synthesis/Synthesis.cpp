/* Synthesis.cpp from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#include <cmath>
#include "synthesis/Corpus.h"

#include "Synthesis.h"

standSynthesis::standSynthesis(const Config &config) :
    config(config),
    aggregate(config.fftLength),
    spectrums(config.fftLength),
    minimumPhaseCalculator(config.fftLength),
    inverse(Fft::Config(config.fftLength, Fft::Real))
{
    _wave = new double[config.fftLength * 2];
}

standSynthesis::~standSynthesis()
{
    delete[] _wave;
}

void standSynthesis::synthesize(float *raw, int length, const standFrame &frame)
{
    for(int i = 0; i <= config.fftLength / 2; i++)
    {
        aggregate.power[i] = 1.0;
    }
    for(int i = 0; i < config.fftLength; i++)
    {
        aggregate.residual[i] = 0.0;
    }

    for(int i = 0; i < frame.size(); i++)
    {
        // If nothing found here, residual is zero then waveform will be zero.
        if(!config.corpus->find(spectrums, frame[i].pronounce, frame[i].msPosition))
        {
            continue;
        }
        for(int f = 0; f <= config.fftLength / 2; f++)
        {
            aggregate.power[f] *= pow(spectrums.power[f], frame[i].amplify);
        }
        for(int f = 0; f < config.fftLength; f++)
        {
            aggregate.residual[f] += spectrums.residual[f] * frame[i].amplify;
        }
    }

    synthesizeOneFrame(_wave, aggregate);

    for(int t = 0; t < length && t < config.fftLength; t++)
    {
        raw[t] += _wave[t];
    }
}

void standSynthesis::synthesizeOneFrame(double *wave, const standSpectrums &spectrums)
{
    minimumPhaseCalculator.execute(wave, spectrums.power);

    wave[0] = wave[0] * spectrums.residual[0];
    for(int i = 1; i < config.fftLength / 2; i++)
    {
        double re = wave[i * 2];
        double im = wave[i * 2 + 1];
        wave[i * 2] = re * spectrums.residual[i * 2 - 1] - im * spectrums.residual[i * 2];
        wave[i * 2 + 1] = im * spectrums.residual[i * 2] + re * spectrums.residual[i * 2 - 1];
    }
    wave[1] = wave[config.fftLength] * spectrums.residual[config.fftLength - 1];
    // inverse FFT and get raw waveform in wave.
    inverse.execute(Fft::Inverse, wave);
    for(int i = 0; i < config.fftLength; i++)
    {
        wave[i] *= 2.0;
    }
}
