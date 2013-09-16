#ifndef AUTOTEST_H
#define AUTOTEST_H

#include <QTest>
#include <QHash>
#include <QString>
#include <QSharedPointer>

namespace AutoTest
{
QHash<QString, QObject *> &tests();

int run(int argc, char *argv[]);
}

template <class T> class Test
{
public:
    QSharedPointer<T> test;
    Test(const QString &name) : test(new T)
    {
        if(!AutoTest::tests().contains(name))
        {
            AutoTest::tests()[name] = test.data();
        }
    }
};

#define DECLARE_TEST(className) static Test<className> t(#className);

#endif // AUTOTEST_H
