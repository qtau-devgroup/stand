#ifndef STANDSYNTH_H
#define STANDSYNTH_H

#include "PluginInterfaces.h"
#include "utauloid/oto.h"
#include "utauloid/ust.h"


class standSynth : public QObject, public ISynth
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qtau.awesomesauce.ISynth" FILE "stand.json")
    Q_INTERFACES(ISynth)

public:
    QString name();
    QString description();
    QString version();

    void setup(SSynthConfig &cfg);
    bool setVoicebank(const QString &path);

    bool setVocals(const ust &u);
    bool setVocals(const QStringList &ust);

    bool synthesize(qtauAudioSource &a);
    bool synthesize(const QString &outFileName);

    bool isVbReady();
    bool isVocalsReady();

    bool supportsStreaming();

protected:
    vsLog*  log;
    QOtoMap vbCfg;
    ust     songCfg;

    inline void sLog(const QString &msg) { log->addMessage(msg, vsLog::success); }
    inline void dLog(const QString &msg) { log->addMessage(msg, vsLog::debug);   }
    inline void iLog(const QString &msg) { log->addMessage(msg, vsLog::info);    }
    inline void eLog(const QString &msg) { log->addMessage(msg, vsLog::error);   }
};

#endif // STANDSYNTH_H
