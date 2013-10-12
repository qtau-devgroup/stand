/* standSynth.cpp from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#include "standSynth.h"
#include "standConfig.h"
#include "standLogger.h"

#include "audio/Source.h"

#include <QDir>
#include <QFile>
#include <QTextStream>

QString standSynth::name()        { return "Stand synth"; }
QString standSynth::description() { return "Stand synthesizer by HAL@ShurabaP"; }
QString standSynth::version()     { return QString("%1.%2")
                                            .arg(CONST_STANDSYNTH_VER_MJ).arg(CONST_STANDSYNTH_VER_MN); }

void standSynth::setup(SSynthConfig &cfg)
{
    Logger::setLogger(cfg.log);
}

bool standSynth::setVoicebank(const QString &path)
{
    bool result = false;
    QFile otoIni(path + "/oto.ini");

    if (otoIni.open(QFile::ReadOnly))
    {
        QTextStream reader(&otoIni);
        reader.setAutoDetectUnicode(true);
        QStringList otoStrings;

        while (!reader.atEnd())
            otoStrings << reader.readLine();

        vbCfg = otoFromStrings(otoStrings);
        Logger::debug(QString("configured with %1 oto keys").arg(vbCfg.keys().length()));
        result = !vbCfg.isEmpty();

        otoIni.close();
    }
    else
        Logger::error("Stand synth could not open oto.ini from " + path);

    return result;
}

bool standSynth::setVocals(const ust &u)           { songCfg = u;                    return isVocalsReady(); }
bool standSynth::setVocals(const QStringList &ust) { songCfg = ustFromStrings(ust);  return isVocalsReady(); }

bool standSynth::synthesize(qtauAudioSource &/*a*/)
{
    bool result = false;

    //

    return result;
}

bool standSynth::synthesize(const QString &outFileName)
{
    qtauAudioSource as;
    bool ok = synthesize(as);

    if (ok)
    {
        QFile f(outFileName);

        if (f.open(QFile::WriteOnly))
        {
            f.write(as.buffer());
            f.close();
            Logger::success("Synthesized to " + outFileName);
        }
        else
            ok = false;
    }

    return ok;
}

bool standSynth::isVbReady()         { return !vbCfg.isEmpty();         }
bool standSynth::isVocalsReady()     { return !songCfg.notes.isEmpty(); }
bool standSynth::supportsStreaming() { return false;                    }
