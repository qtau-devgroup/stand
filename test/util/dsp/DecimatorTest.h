/* DecimatorTest.h from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#ifndef DECIMATORTEST_H
#define DECIMATORTEST_H

#include <QObject>
#include "util/dsp/Decimator.h"
#include "helpers/WorldDecimator.h"
#include "AutoTest.h"

class DecimatorTest : public QObject
{
    Q_OBJECT
private slots:
    void decimate_equals_to_pre_calculated_values()
    {
        int length = 44101;
        float *floatWave = new float[length];
        double *doubleWave = new double[length];
        for(int i = 0; i < length; i++)
        {
            doubleWave[i] = floatWave[i] = (double)rand() / RAND_MAX;
        }
        for(int r = 1; r < 12; r++)
        {
            int decimatedLength = 1 + length / r;
            double *expected = new double[decimatedLength];
            double *actual = new double[decimatedLength];
            WorldDecimator::decimate(doubleWave, length, r, expected, decimatedLength);
            Decimator::decimate(floatWave, length, r, actual, decimatedLength);
            for(int i = 0; i < decimatedLength; i++)
            {
                QCOMPARE(actual[i], expected[i]);
            }
            delete[] expected;
            delete[] actual;
        }
        delete[] floatWave;
        delete[] doubleWave;
    }
};

DECLARE_TEST(DecimatorTest)

#endif // DECIMATORTEST_H
