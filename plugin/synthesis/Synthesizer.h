/* Synthesizer.h from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#ifndef SYNTHESIZER_H
#define SYNTHESIZER_H

/**
 * Interface class of vocal synthesizer.
 */
template <class T>
class Synthesizer
{
public:
    /**
     * Synthesizes one frame into the buffer `raw` from the data `internal` at `ms`[ms] and returns f0 at `ms`[ms].
     * Add value the buffer `raw` because it may have data of the previous frame.
     */
    virtual double synthesize(float *raw, int length, const T *internal, double ms) = 0;
};


#endif // SYNTHESIZER_H
