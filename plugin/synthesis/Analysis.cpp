/* Analysis.cpp from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#include "Analysis.h"

standAnalysis::standAnalysis(int fftLength)
{
    buffer = new double[fftLength];
}

standAnalysis::~standAnalysis()
{
    delete[] buffer;
}

void standAnalysis::analyze(standSpectrums &dst, const standPhoneme &phoneme, double ms)
{

}
