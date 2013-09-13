/* standSynth.h from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#ifndef STANDSYNTH_H
#define STANDSYNTH_H

#include "PluginInterfaces.h"
#include "utauloid/oto.h"
#include "utauloid/ust.h"


class standSynth : public QObject, public ISynth
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID c_isynth_comname FILE "stand.json")
    Q_INTERFACES(ISynth)

public:
    QString name()                          override;
    QString description()                   override;
    QString version()                       override;

    void setup(SSynthConfig &cfg)           override;
    bool setVoicebank(const QString &path)  override;

    bool setVocals(const ust &u)            override;
    bool setVocals(const QStringList &ust)  override;

    bool synthesize(qtauAudioSource &a)     override;
    bool synthesize(const QString &outFileName) override;

    bool isVbReady()                        override;
    bool isVocalsReady()                    override;

    bool supportsStreaming()                override;

protected:
    vsLog*  log;
    QOtoMap vbCfg;
    ust     songCfg;

    inline void sLog(const QString &msg) { log->addMessage(msg, ELog::success); }
    inline void dLog(const QString &msg) { log->addMessage(msg, ELog::debug);   }
    inline void iLog(const QString &msg) { log->addMessage(msg, ELog::info);    }
    inline void eLog(const QString &msg) { log->addMessage(msg, ELog::error);   }
};

#endif // STANDSYNTH_H
