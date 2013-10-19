/* Synthesis.cpp from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#include <cmath>

#include "Synthesis.h"

template <class S, class T>
SynthesisSystem<S, T>::SynthesisSystem(
        Converter<S, T> *converter,
        Synthesizer<T> *synthesizer,
        Renderer<T> *renderer)
{
    _converter = converter;
    _synthesizer = synthesizer;
    _renderer = renderer;
}

template <class S, class T>
void SynthesisSystem<S, T>::synthesize(float *raw, int samplesBegin, int samplesLength, int fs, const S &sequence)
{
    double msBegin = samplesBegin / (double)fs * 1000.0;
    double msLength = samplesLength / (double)fs * 1000.0;
    T *internal = _converter->convert(sequence, msBegin, msLength);
    _renderer->render(raw, samplesBegin, samplesLength, fs, internal, _synthesizer);
}
