#ifndef STAND_CORPUS_H
#define STAND_CORPUS_H

class standSpectrums;
class QString;

class standCorpus
{
public:
    virtual void find(standSpectrums &dst, const QString &pronounce, double ms);
};

#endif // CORPUS_H
