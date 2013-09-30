/* AutoTest.cpp from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#include "AutoTest.h"

namespace AutoTest
{

QHash<QString, QObject *> &tests()
{
    static QHash<QString, QObject *> t;
    return t;
}

int run(int argc, char *argv[])
{
    int ret = 0;
    qDebug("%d", tests().size());
    foreach (QObject* test, tests().values())
    {
        ret |= QTest::qExec(test, argc, argv);
    }
    return ret;
}

}

