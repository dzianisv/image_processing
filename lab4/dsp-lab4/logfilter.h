#ifndef LOGFILTER_H
#define LOGFILTER_H

#include <QObject>
#include "imageactionwidget.h"
#include <inttypes.h>
#include <QtCore/qmath.h>

class logfilter : public ImageActionWidget
{
    Q_OBJECT
public:
    logfilter();
    QImage logcorrect(const QPixmap &srcPixmap);
virtual void apply();
private:
    QRgb logcorrect(QRgb xy, int c);
};

#endif // LOGFILTER_H
