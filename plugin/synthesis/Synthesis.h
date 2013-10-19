/* Synthesis.h from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#ifndef STAND_SYNTHESIS_H
#define STAND_SYNTHESIS_H

#include "utauloid/ust.h"

template <class S, class T> class Converter;
template <class T> class Synthesizer;
template <class T> class Renderer;

template <class S, class T> class SynthesisSystem
{
public:
    SynthesisSystem(
            Converter<S, T> *converter,
            Synthesizer<T> *synthesizer,
            Renderer<T> *renderer
            );

    virtual void synthesize(float *raw, int samplesBegin, int samplesLength, int fs, const S &sequence);
private:
    Converter<S, T> *_converter;
    Synthesizer<T> *_synthesizer;
    Renderer<T> *_renderer;
};

#endif // STAND_SYNTHESIS_H
