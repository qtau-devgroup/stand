/* Util.h from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#ifndef STAND_UTIL_H
#define STAND_UTIL_H

class standUtil
{
public:
    static double msFromPulse(double bpm, int pulse);
    static const int TicksPerBeat = 480;
};

#endif // UTIL_H
