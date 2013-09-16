/* Renderer.h from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#ifndef STAND_RENDERER_H
#define STAND_RENDERER_H

#include "utauloid/oto.h"
#include "utauloid/ust.h"

class standRenderer
{
public:
    typedef struct _Config {
        double msFramePeriod;
        int sampleRate;
        double f0Default;
        double f0Floor;
        double kLog2; // from WORLD
        _Config(double msFramePeriod = 2.0,
                int sampleRate = 44100,
                double f0Default = 150.0,
                double f0Floor = 71.0,
                double kLog2 = 0.69314718055994529);
        _Config(const _Config &other);
        int fftLength() const;
    } Config;

    void render(float *raw, int length, const ust &sequence, const QOtoMap &otoMap, const Config& config);
};

#endif // STAND_RENDERER_H
