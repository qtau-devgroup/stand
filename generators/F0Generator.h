#ifndef F0GENERATOR_H
#define F0GENERATOR_H

#include <QVector>
#include "utauloid/ust.h"

class Temperament;

/**
 * @brief Generates intermediate data for Stand synth.
 *        The generated contour simply represents a pitch contour.
 *        If contour contains 0 Hz data, it means that no note is located there.
 */
class standF0Generator
{
public:
    typedef struct _Config{
        double msFramePeriod;
        Temperament *temperament;
        explicit _Config(double msFramePeriod)
        {
            this->msFramePeriod = msFramePeriod;
        }
        _Config(const _Config &other)
        {
            this->msFramePeriod = other.msFramePeriod;
        }
    } Config;

    QVector<double> generate(const ust &sequence, const Config &config);
};

#endif // F0GENERATOR_H
