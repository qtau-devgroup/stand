/* ResourceRepository.h from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#ifndef RESOURCEREPOSITORY_H
#define RESOURCEREPOSITORY_H

template <class Key, class T> class ResourceRepository
{
public:
    virtual const T *find(const Key &key) = 0;
    virtual bool contains(const Key &key) = 0;
    virtual bool add(const Key &key, T *value) = 0;
    virtual void remove(const Key &key) = 0;
};

#endif // RESOURCEREPOSITORY_H
