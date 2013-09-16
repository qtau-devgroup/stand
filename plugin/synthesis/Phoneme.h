/* Phoneme.h from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#ifndef STAND_PHONEME_H
#define STAND_PHONEME_H

#include <QString>

class standPhoneme
{
public:
    standPhoneme(const QString &filename = "");
protected:
    double *f0;
    double *t;
    double *wave;
    int *indices;
};

#endif // STAND_PHONEME_H
