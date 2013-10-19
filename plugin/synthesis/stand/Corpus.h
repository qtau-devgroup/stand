/* Corpus.h from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#ifndef STAND_CORPUS_H
#define STAND_CORPUS_H

#include <QString>
#include "utauloid/oto.h"

#include "WaveformRepository.h"

class standSpectrums;

class standCorpus
{
public:
    /**
     * @brief Initializez with waveform cache `repository` and pronounces `otoMap`
     */
    explicit standCorpus(standWaveformRepository *repository, const QOtoMap &otoMap);
    virtual ~standCorpus();

    /**
     * @brief Finds WORLD spectra of `pronounce` at `ms` [ms].
     * @return whether `find` succeeds or not.
     */
    virtual bool find(standSpectrums &dst, const QString &pronounce, double ms);
protected:
    QOtoMap otoMap;
    standWaveformRepository *repository;
};

#endif // CORPUS_H
