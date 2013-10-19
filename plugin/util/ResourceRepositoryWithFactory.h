/* ResourceRepositoryWithFactory.h from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#ifndef RESOURCEREPOSITORYWITHFACTORY_H
#define RESOURCEREPOSITORYWITHFACTORY_H

#include "ResourceFactory.h"
#include "ResourceRepository.h"

template <class Key, class T> class ResourceRepositoryWithFactory : public ResourceRepository<Key, T>
{
public:
    explicit ResourceRepositoryWithFactory(ResourceFactory<Key, T> *factory){ }
    virtual bool add(const Key &key) = 0;
};

#endif // RESOURCEREPOSITORYWITHFACTORY_H
