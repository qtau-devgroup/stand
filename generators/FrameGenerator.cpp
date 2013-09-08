/* FrameGenerator.cpp from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#include "FrameGenerator.h"

QStandFrameList standFrameGenerator::generate(const ust &sequence, const Config &config)
{
    int msLength = sequence.notes.last().pulseOffset + sequence.notes.last().pulseLength;
    int frameCount = msLength / config.msFramePeriod + 0.5;
}
