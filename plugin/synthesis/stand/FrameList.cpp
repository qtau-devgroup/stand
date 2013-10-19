/* FrameList.cpp from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#include "FrameList.h"

const standFrame standFrameList::_nullFrame = standFrame();
const QPair<double, standFrame> standFrameList::_null = QPair<double, standFrame>(0.0, _nullFrame);

standFrameList::standFrameList(double msFramePeriod) :
    QList()
{
    _msFramePeriod = qMax(1.0, msFramePeriod);
}

const QPair<double, standFrame> &standFrameList::at(double ms) const
{
    int index = ms / _msFramePeriod;
    if(0 <= index && index < size())
    {
        return this->at(index);
    }
    return _null;
}
