/* SynchronizedRepository.h from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#ifndef SYNCHRONIZEDREPOSITORY_H
#define SYNCHRONIZEDREPOSITORY_H

#include <QHash>
#include <QMutex>

#include "util/ResourceRepositoryWithFactory.h"

template <class Key, class T> class SynchronizedRepository : public ResourceRepositoryWithFactory<Key, T>
{
public:
    explicit SynchronizedRepository(ResourceFactory<Key, T> *factory);
    ~SynchronizedRepository();
    const T *find(const Key &key);
    bool contains(const Key &key);

    bool add(const Key &key, T *value);
    bool add(const Key &key);
    void remove(const Key &key);
private:
    QHash<Key, T *> _data;
    QMutex _mutex;
    ResourceFactory<Key, T> *_factory;
};

#endif // SYNCHRONIZEDREPOSITORY_H
