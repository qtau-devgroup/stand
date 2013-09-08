#include "FrameGenerator.h"

QStandFrameList standFrameGenerator::generate(const ust &sequence, const Config &config)
{
    int msLength = sequence.notes.last().pulseOffset + sequence.notes.last().pulseLength;
    int frameCount = msLength / config.msFramePeriod + 0.5;
}
