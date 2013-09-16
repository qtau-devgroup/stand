/* Analysis.h from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#ifndef STAND_ANALYSIS_H
#define STAND_ANALYSIS_H

class standSpectrums;
class standPhoneme;

class standAnalysis
{
public:
    standAnalysis(int fftLength);
    ~standAnalysis();
    virtual void analyze(standSpectrums &dst, const standPhoneme &phoneme, double ms);
private:
    double *buffer;
};

#endif // STAND_ANALYSIS_H
