#ifndef MINIMUM_PHASE_TEST_H
#define MINIMUM_PHASE_TEST_H

#include "util/dsp/MinimumPhase.h"
#include "AutoTest.h"

// Compare accuracy
const double Epsilon = 0.01;

class MinimumPhaseTest : public QObject
{
    Q_OBJECT
private slots:
    void minimum_phase_spectrum_of_gaussian_noise_is_white_spectrum()
    {
        int fftLength = 512;
         MinimumPhase mp(fftLength);
         double *power = new double[fftLength];
         double *out = new double[fftLength * 2];
         for(int i = 0; i < fftLength; i++)
         {
             power[i] = 1.0;
         }
         mp.spectrum(out, power, fftLength);
         for(int i = 0; i < fftLength / 2; i++)
         {
             if(fabs(out[i*2] - 1.0) > Epsilon)
             {
                 QFAIL((QString("expected = 1.0; out[i*2] = ") + QString::number(out[i*2])).toLocal8Bit().data());
             }
             if(fabs(out[i*2 + 1]) > Epsilon)
             {
                 QFAIL((QString("expected = 0.0; out[i*2+1] = ") + QString::number(out[i*2+1])).toLocal8Bit().data());
             }
         }
         delete[] power;
         delete[] out;
     }

};

DECLARE_TEST(MinimumPhaseTest)

#endif // MINIMUM_PHASE_TEST_H
