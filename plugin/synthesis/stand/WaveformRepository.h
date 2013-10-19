/* WaveformRepository.h from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#ifndef WAVEFORMREPOSITORY_H
#define WAVEFORMREPOSITORY_H

#include <QString>
#include "synthesis/stand/Waveform.h"
#include "util/ResourceRepositoryWithFactory.h"

typedef ResourceRepositoryWithFactory<QString, standWaveform> standWaveformRepository;

#endif // WAVEFORMREPOSITORY_H
