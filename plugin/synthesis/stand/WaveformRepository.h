/* WaveformRepository.h from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#ifndef WAVEFORMREPOSITORY_H
#define WAVEFORMREPOSITORY_H

#include <QString>
#include "synthesis/stand/Waveform.h"
#include "util/SynchronizedRepository.h"

typedef SynchronizedRepository<QString, standWaveform> standWaveformRepository;

#endif // WAVEFORMREPOSITORY_H
