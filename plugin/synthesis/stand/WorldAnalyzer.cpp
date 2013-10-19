#include "WorldSpectrums.h"
#include "WorldAnalyzer.h"

standWaveformAnalyzer::standWaveformAnalyzer(int fs, int fftLength)
{
    _fs = fs;
    _fftLength = fftLength;
}

void standWaveformAnalyzer::analyze(standSpectrums *dst, const standWaveform *data, double ms)
{

}
