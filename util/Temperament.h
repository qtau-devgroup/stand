/* Temperament.h from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#ifndef TEMPERAMENT_H
#define TEMPERAMENT_H

#include <QVector>

class Temperament
{
public:
    virtual double frequency(int keyNumber) const = 0;
};

class EqualTemperament
{
public:
    static const int HighestKey = 128;
    EqualTemperament(double concertPitch = 440.0, int keyNumber = 69);

    double frequency(int keyNumber) const;

    static double generate(int keyNumber, double concertPitch = 440.0, int concertKeyNumber = 69);
private:
    QVector<double> _frequencies;
};

#endif // TEMPERAMENT_H
