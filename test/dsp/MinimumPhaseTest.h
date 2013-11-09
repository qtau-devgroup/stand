/* MinimumPhaseTest.h from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#ifndef MINIMUM_PHASE_TEST_H
#define MINIMUM_PHASE_TEST_H

#include <float.h>
#include "dsp/MinimumPhase.h"
#include "AutoTest.h"
#include "dsp/world/common.h"

// Compare accuracy
const double Epsilon = 0.01;

class MinimumPhaseTest : public QObject
{
    Q_OBJECT
private slots:
    void minimum_phase_spectrum_of_gaussian_noise_is_white_spectrum()
    {
        int fftLength = 32;
         MinimumPhase mp(fftLength);
         double *power = new double[fftLength];
         double *out = new double[fftLength * 2];
         for(int i = 0; i < fftLength; i++)
         {
             power[i] = 1.0;
         }
         mp.execute(out, power);
         for(int i = 0; i <= fftLength / 2; i++)
         {
             QCOMPARE(out[i * 2], 1.0);
             QCOMPARE(out[i * 2 + 1] + 1.0, 1.0); // Needs plus 1.0 to compare zero with QCOMPARE.
         }
         delete[] power;
         delete[] out;
     }

    void minimum_phase_spectrum_of_single_pulse_is_single_pulse()
    {
        int fftLength = 32;
        MinimumPhase mp(fftLength);
        double *power = new double[fftLength];
        double *out = new double[fftLength * 2];
        power[0] = 1.0;
        for(int i = 1; i < fftLength; i++)
        {
            power[i] = 0.0;
        }
        mp.execute(out, power);
        QCOMPARE(out[0], 1.0);
        for(int i = 1; i <= fftLength; i++)
        {
            QCOMPARE(out[i] + 1.0, 1.0); // Needs plus 1.0 to compare zero with QCOMPARE.
        }
        delete[] power;
        delete[] out;
    }

    void the_result_of_MinimumPhase_execute_must_equal_to_worlds_minimum_phase_analysis()
    {
        int fftLength = 32;
        MinimumPhase mp(fftLength);
        MinimumPhaseAnalysis ma;
        InitializeMinimumPhaseAnalysis(fftLength, &ma);
        double *power = new double[fftLength];
        double *out = new double[fftLength * 2];
        for(int i = 0; i < fftLength; i++)
        {
            power[i] = (double)rand() / RAND_MAX;
            ma.log_spectrum[i] = log(power[i] + DBL_MIN) / 2;
        }
        mp.execute(out, power);
        GetMinimumPhaseSpectrum(&ma);
        for(int i = 0; i <= fftLength / 2; i++)
        {
            QCOMPARE(out[i * 2], ma.minimum_phase_spectrum[i][0]);
            QCOMPARE(out[i * 2 + 1], ma.minimum_phase_spectrum[i][1]);
        }
        delete[] power;
        delete[] out;
    }
};

DECLARE_TEST(MinimumPhaseTest)

#endif // MINIMUM_PHASE_TEST_H
