/* SynchronizedRepository.cpp from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#include "SynchronizedRepository.h"

template <class Key, class T> SynchronizedRepository<Key, T>::SynchronizedRepository(ResourceFactory<Key, T> *factory)
{
    _factory = factory;
}

template <class Key, class T> SynchronizedRepository<Key, T>::~SynchronizedRepository()
{
    delete _factory;
    foreach(T *t, _data.values())
    {
        delete t;
    }
}

template <class Key, class T> const T *SynchronizedRepository<Key, T>::find(const Key &key)
{
    T *t = NULL;
    _read.lock();
    if(contains(key))
    {
        t = _data.value(key);
    }
    _read.unlock();
    return t;
}

template <class Key, class T> bool SynchronizedRepository<Key, T>::contains(const Key &key)
{
    bool result = false;
    _read.lock();
    result = _data.contains(key);
    _read.unlock();
    return result;
}

template <class Key, class T> bool SynchronizedRepository<Key, T>::add(const Key &key, T *value)
{
    bool result = false;
    _write.lock();
    if(!_data.contains(key))
    {
        _read.lock();
        _data.insert(key, value);
        _read.unlock();
        result = true;
    }
    _write.unlock();
    return result;
}

template <class Key, class T> bool SynchronizedRepository<Key, T>::add(const Key &key)
{
    bool result = false;
    _write.lock();
    T *v = _factory->create(key);
    if(v && !_data.contains(key))
    {
        _read.lock();
        _data.insert(key, v);
        _read.unlock();
        result = true;
    }
    _write.unlock();
    return result;
}

template <class Key, class T> void SynchronizedRepository<Key, T>::remove(const Key &key)
{
    _read.lock();
    if(_data.contains(key))
    {
        delete _data[key];
        _data.remove(key);
    }
    _read.unlock();
}
