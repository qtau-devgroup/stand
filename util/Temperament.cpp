/* Temperament.h from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#include <cmath>

#include "Temperament.h"

EqualTemperament::EqualTemperament(double concertPitch, int keyNumber)
{
    _frequencies.resize(HIGHEST_KEY);
    for(int k = 0; k < HIGHEST_KEY; k++)
    {
        _frequencies[k] = generate(k, concertPitch, keyNumber);
    }
}

double EqualTemperament::generate(int keyNumber, double concertPitch, int concertKeyNumber)
{
    return concertPitch * pow(2.0, (keyNumber - concertKeyNumber) / 12.0);
}

double EqualTemperament::frequency(int keyNumber) const
{
    return _frequencies[keyNumber];
}
