/* FrameList.h from Stand http://github.com/qtau-devgroup/stand by HAL@ShurabaP, BSD license */
#ifndef FRAMELIST_H
#define FRAMELIST_H

#include <QList>
#include <QPair>
#include <QString>

typedef struct _standFrameElement
{
    double msPosition;
    double amplify;    // How much amplify this frame.
    QString pronounce;
    _standFrameElement(double msPosition, double amplify, const QString &pronounce) : pronounce(pronounce)
    {
        this->msPosition = msPosition;
        this->amplify = amplify;
    }
} standFrameElement;

typedef QList<standFrameElement> standFrame;

class standFrameList : public QList<QPair<double, standFrame> >
{
public:
    explicit standFrameList(double msFramePeriod);

    double msFramePeriod() const
    {
        return _msFramePeriod;
    }

    const QPair<double, standFrame> &at(double ms) const;
private:
    const static standFrame _nullFrame;
    const static QPair<double, standFrame> _null;
    double _msFramePeriod;
};


#endif // FRAMELIST_H
