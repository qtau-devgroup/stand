/* Util.cpp from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#include "Util.h"

double standUtil::msFromPulse(double bpm, int pulse)
{
    return (60.0 / bpm) * (pulse / (double)TicksPerBeat) * 1000.0;
}
