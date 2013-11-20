#ifndef ROBERTSFILTER_H
#define ROBERTSFILTER_H

#include <QObject>
#include "imageactionwidget.h"
#include <inttypes.h>

class RobertsFilter : public ImageActionWidget
{
        Q_OBJECT
public:
    RobertsFilter();
    QImage roberts(const QPixmap &srcPixmap);
    virtual  void apply();
private:
    QRgb roberts(QRgb xy, QRgb x1y, QRgb xy1, QRgb x1y1);
    quint8 monochromeRoberts( quint8 xy, quint8 x1y, quint8 xy1, quint8 x1y1 );
};

#endif // ROBERTSFILTER_H
