/* Corpus.cpp from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#include "synthesis/Analysis.h"
#include "synthesis/Spectrums.h"

#include "Corpus.h"

standCorpus::standCorpus(const QOtoMap &otoMap) :
    otoMap(otoMap)
{
}

void standCorpus::find(standSpectrums &dst, const QString &pronounce, double ms)
{
    if(!otoMap.contains(pronounce))
    {
        return;
    }
    const Oto &oto = otoMap.find(pronounce).value();
    standAnalysis analysis(dst.fftLength);
    if(!phonemeMap.contains(oto.fileName))
    {
        // TODO : read phoneme from file and put it into map.
        // TODO : return if failed reading.
    }
    const standPhoneme &phoneme = phonemeMap.value(oto.fileName);
    analysis.analyze(dst, phoneme, ms);
}
