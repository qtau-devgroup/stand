/* FrameGenerator.h from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#ifndef STAND_FRAMEGENERATOR_H
#define STAND_FRAMEGENERATOR_H

#include <QList>
#include "utauloid/ust.h"
#include "utauloid/oto.h"

typedef struct _standFrameFactor
{
    double msPosition;
    double amplify;    // How much amplify this frame.
    QString pronounce;
    _standFrameFactor(double msPosition, double amplify, const QString &pronounce) : pronounce(pronounce)
    {
        this->msPosition = msPosition;
        this->amplify = amplify;
    }
} standFrameFactor;

typedef QList<standFrameFactor> standFrame;

typedef QList<standFrame> QStandFrameList;

/**
 * @brief Generates an intermediate data for Stand synth.
 *        QStandFrameList contains what phoneme to use and how much to morph it.
 */
class standFrameGenerator
{
public:
    typedef struct _Config {
        double msFramePeriod;

        explicit _Config(double msFramePeriod)
        {
            this->msFramePeriod = msFramePeriod;
        }
        _Config(const _Config& other)
        {
            this->msFramePeriod = other.msFramePeriod;
        }
    } Config;
    QStandFrameList generate(const ust &sequence, const Config &config);
};

#endif // STAND_FRAMEGENERATOR_H
