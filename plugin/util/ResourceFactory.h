/* ResourceFactory.h from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#ifndef RESOURCEFACTORY_H
#define RESOURCEFACTORY_H

template <class Key, class T> class ResourceFactory
{
public:
    virtual T *create(Key) = 0;
};

#endif // RESOURCEFACTORY_H
