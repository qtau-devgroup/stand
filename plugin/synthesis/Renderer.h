/* Renderer.h from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#ifndef RENDERER_H
#define RENDERER_H

template <class T> class Synthesizer;

template <class T> class Renderer
{
public:
    virtual void render(float *raw, int samplesBegin, int samplesLength, int fs, T *internal, Synthesizer<T> *synthesizer) = 0;
};

template <class T> class SimpleRenderer : public Renderer<T>
{
public:
    void render(float *raw, int samplesBegin, int samplesLength, int fs, T *internal, Synthesizer<T> *synthesizer);
};


#endif // RENDERER_H
