/* Corpus.cpp from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#include "synthesis/Analysis.h"
#include "synthesis/Spectrums.h"
#include "synthesis/WaveRepository.h"
#include "standLogger.h"

#include "Corpus.h"

standCorpus::standCorpus(const standWaveRepository *repository, const QOtoMap &otoMap) :
    otoMap(otoMap)
{
    this->repository = repository;
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
    // WaveRepository must contain all the waveforms for pronounces.
    if(!repository->contains(oto.fileName))
    {
        Logger::info("The file `" + oto.fileName + "` does not exist in this corpus.");
        return false;
    }
    standAnalysis(dst.fftLength).analyze(dst, repository->find(oto.fileName), ms);
    return true;
}
