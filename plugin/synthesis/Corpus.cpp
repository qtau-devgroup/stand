/* Corpus.cpp from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#include "synthesis/Analysis.h"
#include "synthesis/Spectrums.h"
#include "synthesis/WaveRepository.h"
#include "standLogger.h"

#include "Corpus.h"

standCorpus::standCorpus(standWaveRepository *repository, const QOtoMap &otoMap) :
    otoMap(otoMap)
{
    this->waveforms = repository;
}

standCorpus::~standCorpus()
{
}

bool standCorpus::find(standSpectrums &dst, const QString &pronounce, double ms)
{
    if(!otoMap.contains(pronounce))
    {
        Logger::info("The prinounce `" + pronounce + "` does not exist in this corpus.");
        return false;
    }
    const Oto &oto = otoMap.find(pronounce).value();
    standAnalysis analysis(dst.fftLength);
    // WaveRepository must contain all the waveforms for pronounces.
    if(!waveforms->contains(oto.fileName))
    {
        Logger::info("The file `" + oto.fileName + "` does not exist in this corpus.");
        return false;
    }
    const standWaveform *waveform = waveforms->find(oto.fileName);
    analysis.analyze(dst, waveform, ms);
    return true;
}
