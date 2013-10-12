/* WaveRepository.cpp from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#include "WaveRepository.h"

#include "synthesis/Waveform.h"

standWaveRepository::standWaveRepository(double msFramePeriod)
{
    _msFramePeriod = msFramePeriod;
}

standWaveRepository::~standWaveRepository()
{
    foreach(standWaveform *w, phonemeMap)
    {
        delete w;
    }
}

bool standWaveRepository::add(const QFileInfo &fileinfo)
{
    standWaveform *w = new standWaveform(fileinfo, _msFramePeriod);
    if(!w->isAvailable())
    {
        delete w;
        return false;
    }
    _waveforms.insert(fileinfo, w);
    return true;
}

const standWaveform *standWaveRepository::find(const QFileInfo &fileinfo) const
{
    return _waveforms.find(fileinfo);
}

bool standWaveRepository::contains(const QFileInfo &fileinfo) const
{
    return _waveforms.contains(fileinfo);
}
