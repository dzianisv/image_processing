#ifndef LOGFILTER_H
#define LOGFILTER_H

#include <QObject>
#include "imageactionwidget.h"
#include <inttypes.h>
#include <label.h>
#include <QtCore/qmath.h>



class logfilter : public ImageActionWidget
{
    Q_OBJECT
public:
    logfilter();
    QImage logcorrect(const QPixmap &srcPixmap);
virtual void apply();
private:
    void labeling(label_t** map,  QImage*);
    void fill(label_t** map, QImage*, int x, int y, label_t label);
    QRgb logcorrect(QRgb xy, int c);
};

#endif // LOGFILTER_H
