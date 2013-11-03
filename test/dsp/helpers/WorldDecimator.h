/* WorldDecimator.h from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#ifndef WORLDDECIMATOR_H
#define WORLDDECIMATOR_H

class WorldDecimator
{
public:
    static void FilterForDecimate(double *x, int x_length, int r, double *y);
    static void decimate(double *x, int x_length, int r, double *y, int y_length);
};

#endif // WORLDDECIMATOR_H
