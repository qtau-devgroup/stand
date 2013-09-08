/* F0Generator.cpp from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#include "F0Generator.h"

#include "../util/Temperament.h"

QVector<double> standF0Generator::generate(const ust &sequence, const Config &config)
{
    int msLength = sequence.notes.last().pulseOffset + sequence.notes.last().pulseLength;
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
        int beginFrame = note.pulseOffset / config.msFramePeriod;
        int endFrame = (note.pulseLength + note.pulseOffset) / config.msFramePeriod + 0.5;
        for(int f = beginFrame; f < endFrame; f++)
        {
            contour[f] = config.temperament->frequency(note.keyNumber);
        }
    }
    return contour;
}

