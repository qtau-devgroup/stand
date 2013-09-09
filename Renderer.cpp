/* Renderer.cpp from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#include "generators/F0Generator.h"
#include "generators/FrameGenerator.h"
#include "synthesis/Synthesis.h"
#include "synthesis/Corpus.h"

#include "Renderer.h"

standRenderer::standRenderer()
{
}

void standRenderer::render(const ust &sequence, const QOtoMap &otoMap)
{
    double msFramePeriod = 2.0;
    int fftLength = 2048;
    int sampleRate = 44100;
    int length = 0;
    double f0Default = 150.0;
    double f0Floor = 60.0;
    standF0Generator f0gen;
    standFrameGenerator framegen;

    QVector<double> f0 = f0gen.generate(sequence, standF0Generator::Config(msFramePeriod));
    QStandFrameList frames = framegen.generate(sequence, standFrameGenerator::Config(msFramePeriod));

    standCorpus corpus(otoMap);
    standSynthesis synth(standSynthesis::Config(&corpus, msFramePeriod, fftLength));

    float *raw = new float[length];
    for(int i = 0; i < length; i++)
    {
        raw[i] = 0.0f;
    }

    double ms = 0.0;
    for(int f = 0; f < f0.size();)
    {
        int index = (ms * sampleRate / 1000.0 + 0.5);
        int len = qMin(fftLength, length - index);
        synth.synthesize(raw + index, len, frames[f]);

        ms += (f0[f] < f0Floor) ? 1000 / f0Default : 1000 / f0[f];
        f = ms / msFramePeriod;
    }

    delete[] raw;
}
