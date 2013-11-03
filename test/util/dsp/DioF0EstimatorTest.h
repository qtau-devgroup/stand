#ifndef DIOF0ESTIMATORTEST_H
#define DIOF0ESTIMATORTEST_H

#include "util/dsp/DioF0Estimator.h"
#include "util/dsp/world/dio.h"
#include "AutoTest.h"
#include <qmath.h>
#include <time.h>
#include <QObject>

class DioF0EstimatorTest : public QObject
{
    Q_OBJECT
private slots:
    void result_of_estimation_should_be_equal_to_dio()
    {
        const int fs = 44100;
        const int length = 44100 * 10;
        const double msFramePeriod = 2.0;
        const int tLen = GetSamplesForDIO(fs, length, msFramePeriod);
        double *dWave = new double[length];
        float *fWave = new float[length];
        double *expect = new double[tLen];
        double *t = new double[tLen];
        for(int i = 0; i < length; i++)
        {
            dWave[i] = fWave[i] = sin(2 * M_PI * i / 100.0);
        }
        clock_t begin;
        begin = clock();
        QList<float> actual(DioF0Estimator().estimate(fWave, fs, msFramePeriod, length));
        printf("DioF0Estimator ElapsedTime : %lf[sec]\n", (double)(clock() - begin) / CLOCKS_PER_SEC);
        begin = clock();
        Dio(dWave, length, fs, msFramePeriod, t, expect);
        printf("OriginalDio ElapsedTime : %lf[sec]\n", (double)(clock() - begin) / CLOCKS_PER_SEC);

        QCOMPARE(actual.size(), tLen);
        for(int i = 0; i < tLen; i++)
        {
            QCOMPARE(actual[i], expect[i]);
        }
        delete[] dWave;
        delete[] fWave;
        delete[] expect;
        delete[] t;
    }
};

DECLARE_TEST(DioF0EstimatorTest)

#endif // DIOF0ESTIMATORTEST_H
