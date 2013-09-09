/* Corpus.h from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#ifndef STAND_CORPUS_H
#define STAND_CORPUS_H

#include "utauloid/oto.h"
class standSpectrums;
class QString;

class standCorpus
{
public:
    explicit standCorpus(QOtoMap &otoMap);
    virtual void find(standSpectrums &dst, const QString &pronounce, double ms);
protected:
    QOtoMap otoMap;
};

#endif // CORPUS_H
