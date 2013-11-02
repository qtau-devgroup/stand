/* WorldSynthesizer.cpp from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */

#include "WorldSynthesizer.h"
#include "Corpus.h"
#include "FrameList.h"

standSynthesizer::standSynthesizer(int fftLength, standCorpus *corpus):
    aggregate(fftLength),
    spectrums(fftLength),
    minimumPhaseCalculator(fftLength),
    inverse(fftLength, Fft::Real)
{
    _fftLength = fftLength;
    _corpus = corpus;
    _wave = new double[fftLength * 2];
}

standSynthesizer::~standSynthesizer()
{
    delete[] _wave;
}

double standSynthesizer::synthesize(float *raw, int length, const standFrameList *frames, double ms)
{
    for(int i = 0; i <= _fftLength / 2; i++)
    {
        aggregate.power[i] = 1.0;
    }
    for(int i = 0; i < _fftLength; i++)
    {
        aggregate.residual[i] = 0.0;
    }

    const auto &pair = frames->at(ms);
    const standFrame &frame = pair.second;
    for(int i = 0; i < frame.size(); i++)
    {
        // If nothing found here, residual is zero then waveform will be zero.
        if(!_corpus->find(spectrums, frame[i].pronounce, frame[i].msPosition))
        {
            continue;
        }
        for(int f = 0; f <= _fftLength / 2; f++)
        {
            aggregate.power[f] *= pow(spectrums.power[f], frame[i].amplify);
        }
        for(int f = 0; f < _fftLength; f++)
        {
            aggregate.residual[f] += spectrums.residual[f] * frame[i].amplify;
        }
    }

    synthesizeOneFrame(_wave, aggregate);

    for(int t = 0; t < length && t < _fftLength; t++)
    {
        raw[t] += _wave[t];
    }
    return pair.first;
}

void standSynthesizer::synthesizeOneFrame(double *wave, const standSpectrums &spectrums)
{
    minimumPhaseCalculator.execute(wave, spectrums.power);

    wave[0] = wave[0] * spectrums.residual[0];
    for(int i = 1; i < _fftLength / 2; i++)
    {
        double re = wave[i * 2];
        double im = wave[i * 2 + 1];
        wave[i * 2] = re * spectrums.residual[i * 2 - 1] - im * spectrums.residual[i * 2];
        wave[i * 2 + 1] = im * spectrums.residual[i * 2] + re * spectrums.residual[i * 2 - 1];
    }
    wave[1] = wave[_fftLength] * spectrums.residual[_fftLength - 1];
    // inverse FFT and get raw waveform in wave.
    inverse.execute(Fft::Inverse, wave);
    for(int i = 0; i < _fftLength; i++)
    {
        wave[i] *= 2.0;
    }
}
