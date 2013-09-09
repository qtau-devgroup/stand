/* F0Generator.cpp from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#include "util/Temperament.h"
#include "util/Util.h"

#include "F0Generator.h"

QVector<double> standF0Generator::generate(const ust &sequence, const Config &config)
{
    int ticksLength = sequence.notes.last().pulseOffset + sequence.notes.last().pulseLength;
    int msLength = standUtil::msFromPulse(sequence.tempo, ticksLength);
    int frameCount = msLength / config.msFramePeriod + 0.5;
    QVector<double> contour;
    contour.resize(frameCount);

    for(int i = 0; i < contour.size(); i++)
    {
        contour[i] = 0.0;
    }

    for(int i = sequence.notes.size() - 1; i >= 0; i--)
    {
        const ust_note &note =  sequence.notes[i];
        int beginFrame = standUtil::msFromPulse(sequence.tempo, note.pulseOffset) / config.msFramePeriod;
        int endFrame = standUtil::msFromPulse(sequence.tempo, note.pulseLength + note.pulseOffset) / config.msFramePeriod + 0.5;
        for(int f = beginFrame; f < endFrame; f++)
        {
            contour[f] = config.temperament->frequency(note.keyNumber);
        }
    }
    return contour;
}

