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
    foreach (QObject* test, tests().values())
    {
        ret |= QTest::qExec(test, argc, argv);
    }
    return ret;
}

}


int main(int argc, char *argv[])
{
    return AutoTest::run(argc, argv);
}
