/* Corpus.h from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#ifndef STAND_CORPUS_H
#define STAND_CORPUS_H

#include <QFileInfo>
#include <QHash>
#include "utauloid/oto.h"

class standSpectrums;
class standWaveRepository;
class QString;

class standCorpus
{
public:
    /**
     * @brief Initializez with waveform cache `repository` and pronounces `otoMap`
     */
    explicit standCorpus(const standWaveRepository *repository, const QOtoMap &otoMap);
    virtual ~standCorpus();

    /**
     * @brief Finds WORLD spectra of `pronounce` at `ms` [ms].
     * @return whether `find` succeeds or not.
     */
    virtual bool find(standSpectrums &dst, const QString &pronounce, double ms);
protected:
    QOtoMap otoMap;
    const standWaveRepository *repository;
};

#endif // CORPUS_H
