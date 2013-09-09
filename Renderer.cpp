/* Renderer.cpp from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#include <cmath>

#include "generators/F0Generator.h"
#include "generators/FrameGenerator.h"
#include "synthesis/Synthesis.h"
#include "synthesis/Corpus.h"
#include "util/Util.h"

#include "Renderer.h"

standRenderer::_Config::_Config(double msFramePeriod, int sampleRate, double f0Default, double f0Floor, double kLog2)
{
    this->msFramePeriod = msFramePeriod;
    this->sampleRate = sampleRate;
    this->f0Default = f0Default;
    this->f0Floor = f0Floor;
    this->kLog2 = kLog2;
}

standRenderer::_Config::_Config(const _Config &other)
{
    this->msFramePeriod = other.msFramePeriod;
    this->sampleRate = other.sampleRate;
    this->f0Default = other.f0Default;
    this->f0Floor = other.f0Floor;
    this->kLog2 = other.kLog2;
}

int standRenderer::_Config::fftLength() const
{
    return static_cast<int>(pow(2.0, 1.0 + static_cast<int>(log(3.0 * sampleRate / f0Floor + 1) / kLog2)));
}

void standRenderer::render(const ust &sequence, const QOtoMap &otoMap, const Config &config)
{
    int ticksLength = sequence.notes.last().pulseOffset + sequence.notes.last().pulseLength;
    int length = standUtil::msFromPulse(sequence.tempo, ticksLength) * config.sampleRate / 1000.0 + 0.5;
    int fftLength = config.fftLength();
    standF0Generator f0gen;
    standFrameGenerator framegen;

    QVector<double> f0 = f0gen.generate(sequence, standF0Generator::Config(config.msFramePeriod));
    QStandFrameList frames = framegen.generate(sequence, standFrameGenerator::Config(config.msFramePeriod));

    standCorpus corpus(otoMap);
    standSynthesis synth(standSynthesis::Config(&corpus, config.msFramePeriod, fftLength));

    float *raw = new float[length];
    for(int i = 0; i < length; i++)
    {
        raw[i] = 0.0f;
    }

    double ms = 0.0;
    for(int f = 0; f < f0.size();)
    {
        int index = (ms * config.sampleRate / 1000.0 + 0.5);
        int len = qMin(fftLength, length - index);
        synth.synthesize(raw + index, len, frames[f]);

        ms += (f0[f] < config.f0Floor) ? 1000 / config.f0Default : 1000 / f0[f];
        f = ms / config.msFramePeriod;
    }

    delete[] raw;
}
