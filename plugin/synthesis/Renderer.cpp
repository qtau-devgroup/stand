/* Renderer.cpp from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#include "Renderer.h"

template <class T>
void SimpleRenderer<T>::render(float *raw, int samplesBegin, int samplesLength, int fs, T *internal, Synthesizer<T> *synthesizer)
{
    for(int i = 0; i < samplesLength; i++)
    {
        raw[i] = 0.0f;
    }

    double ms = samplesBegin / (double)fs * 1000.0;
    for(int index = 0; index < samplesLength; index = (ms * fs / 1000.0 + 0.5) - samplesBegin)
    {
        int len = samplesLength - index;
        double f0 = qMax(70.0, synthesizer->synthesize(raw + index, len, internal, ms));

        ms += 1000.0 / f0;
    }
}
