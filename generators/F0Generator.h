#ifndef F0GENERATOR_H
#define F0GENERATOR_H

#include <QVector>
#include "utauloid/ust.h"

class Temperament;

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
        _Config(_Config &r)
        {
            msFramePeriod = r.msFramePeriod;
        }
    } Config;

    QVector<double> generate(const ust &sequence, const Config &config);
};

#endif // F0GENERATOR_H
