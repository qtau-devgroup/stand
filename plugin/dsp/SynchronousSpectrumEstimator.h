#ifndef SYNCHRONOUSSPECTRUMESTIMATOR_H
#define SYNCHRONOUSSPECTRUMESTIMATOR_H

/**
 * @brief estimates spectrum pitch-synchronously.
 */
class SynchronousSpectrumEstimator
{
public:
    /**
     * @brief Estimates a spectrum at `ms`[msec] from `wave` with `length` samples whose sampling frequency is `fs`.
     *        The length of `dst` will be determined by the class that implements `estimate`.
     */
    virtual void estimate(double *dst, float *wave, float ms, float f0, int fs, int length) = 0;
};

#endif // SYNCHRONOUSSPECTRUMESTIMATOR_H
