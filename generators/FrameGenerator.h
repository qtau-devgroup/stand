#ifndef STAND_FRAMEGENERATOR_H
#define STAND_FRAMEGENERATOR_H

#include <QList>
#include "utauloid/ust.h"
#include "utauloid/oto.h"

typedef struct _standSingleFrame
{
    double msPosition;
    double amplify;    // How much amplify this frame.
    Oto oto;
} standSingleFrame;

typedef struct _standFrame
{
    QList<standSingleFrame> frames;
} standFrame;

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
