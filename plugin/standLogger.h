/* standLogger.h from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#ifndef STANDLOGGER_H
#define STANDLOGGER_H

#include "PluginInterfaces.h"

class Logger
{
public:
    static inline void success(const QString &msg) { log->addMessage(msg, ELog::success); }
    static inline void debug  (const QString &msg) { log->addMessage(msg, ELog::debug);   }
    static inline void info   (const QString &msg) { log->addMessage(msg, ELog::info);    }
    static inline void error  (const QString &msg) { log->addMessage(msg, ELog::error);   }

    static void setLogger(vsLog *logger)
    {
        log = logger;
    }

private:
    static vsLog*  log;
};

#endif // STANDLOGGER_H
