/* F0Estimator.h from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#ifndef F0ESTIMATOR_H
#define F0ESTIMATOR_H

#include <QList>

class F0Estimator
{
public:
    virtual QList<float> estimate(const float *wave, int fs, double msFramePeriod, int length) = 0;
};

#endif // F0ESTIMATOR_H
