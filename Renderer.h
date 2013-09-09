/* Renderer.h from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#ifndef STAND_RENDERER_H
#define STAND_RENDERER_H

#include "utauloid/oto.h"
#include "utauloid/ust.h"

class standRenderer
{
public:
    standRenderer();
    void render(const ust &sequence, const QOtoMap &otoMap);
};

#endif // STAND_RENDERER_H
