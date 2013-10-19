/* Converter.h from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#ifndef CONVERTER_H
#define CONVERTER_H

// S as `Sequence` and T as internal data
template <class S, class T> class Converter
{
public:
    virtual void convert(T *dst, S *src) = 0;
};

#endif // CONVERTER_H
