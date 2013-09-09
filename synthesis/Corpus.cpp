/* Corpus.cpp from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#include "synthesis/Analysis.h"
#include "synthesis/Phoneme.h"
#include "synthesis/Spectrums.h"

#include "Corpus.h"

standCorpus::standCorpus(QOtoMap &otoMap) :
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
    // TODO : get phoneme through cache.
    standPhoneme phoneme;
    analysis.analyze(dst, phoneme, ms);
}
