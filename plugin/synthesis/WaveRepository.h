/* WaveRepository.h from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#ifndef WAVEREPOSITORY_H
#define WAVEREPOSITORY_H

#include <QFileInfo>
#include <QHash>

class standWaveform;

class standWaveRepository
{
public:
    explicit standWaveRepository(double msFramePeriod = 2.0);
    virtual ~standWaveRepository();

    bool add(const QFileInfo &fileinfo);
    const standWaveform *find(const QFileInfo &fileinfo) const;
    bool contains(const QFileInfo &fileinfo) const;
private:
    /**
     * This map contains (filepath, phoneme) not pronounce.
     */
    QHash<QFileInfo, standWaveform *> _waveforms;
    double _msFramePeriod;
};

#endif // WAVEREPOSITORY_H
