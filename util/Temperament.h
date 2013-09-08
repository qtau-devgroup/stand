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
    int HIGHEST_KEY = 128;
    EqualTemperament(double concertPitch = 440.0, int keyNumber = 69);

    double frequency(int keyNumber) const;

    static double generate(int keyNumber, double concertPitch = 440.0, int concertKeyNumber = 69);
private:
    QVector<double> _frequencies;
};

#endif // TEMPERAMENT_H
