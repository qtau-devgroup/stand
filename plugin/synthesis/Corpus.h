/* Corpus.h from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#ifndef STAND_CORPUS_H
#define STAND_CORPUS_H

#include <QHash>
#include "utauloid/oto.h"
#include "synthesis/Phoneme.h"

class standSpectrums;
class QString;

class standCorpus
{
public:
    explicit standCorpus(const QOtoMap &otoMap);
    virtual void find(standSpectrums &dst, const QString &pronounce, double ms);
protected:
    QOtoMap otoMap;
    QHash<QString, standPhoneme> phonemeMap;
};

#endif // CORPUS_H
