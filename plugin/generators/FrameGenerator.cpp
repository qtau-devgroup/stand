/* FrameGenerator.cpp from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#include "util/Util.h"
#include "FrameGenerator.h"

QStandFrameList standFrameGenerator::generate(const ust &sequence, const Config &config)
{
    int ticksLength = sequence.notes.last().pulseOffset + sequence.notes.last().pulseLength;
    int msLength = standUtil::msFromPulse(sequence.tempo, ticksLength);
    int frameCount = msLength / config.msFramePeriod + 0.5;
    QStandFrameList frames;
    frames.reserve(frameCount);
    for(int i = 0; i < frameCount; i++)
    {
        frames.append(QList<standFrame>());
    }

    for(int i = sequence.notes.size() - 1; i >= 0; i--)
    {
        const ust_note &note =  sequence.notes[i];
        int beginFrame = standUtil::msFromPulse(sequence.tempo, note.pulseOffset) / config.msFramePeriod;
        int endFrame = standUtil::msFromPulse(sequence.tempo, note.pulseLength + note.pulseOffset) / config.msFramePeriod + 0.5;
        for(int f = beginFrame; f < endFrame; f++)
        {
            double msForNote = (f - beginFrame) * config.msFramePeriod;
            QList<standFrameFactor> &frame = frames[f];
            // Treats lyric as pronounce.
            frame.append(standFrameFactor(msForNote, 1.0, note.lyric));
        }
    }
    return frames;
}
