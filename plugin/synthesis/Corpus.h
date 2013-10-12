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
    explicit standCorpus(standWaveRepository *waveforms, const QOtoMap &otoMap);
    virtual ~standCorpus();
    virtual bool find(standSpectrums &dst, const QString &pronounce, double ms);
protected:
    QOtoMap otoMap;
    standWaveRepository *waveforms;
};

#endif // CORPUS_H
