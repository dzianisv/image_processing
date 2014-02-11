#ifndef LOGFILTER_H
#define LOGFILTER_H

#include <QObject>
#include "imageactionwidget.h"
#include <filterbase.h>
#include <inttypes.h>
#include <label.h>
#include <imageobject.h>
#include <QVector>
#include <QtCore/qmath.h>


class ImageProcessing : public ImageActionWidget
{
    Q_OBJECT
public:
    ImageProcessing();
virtual void apply();

private:
    QVector<FilterBase*> filters;

    label_t labeling(label_t** map,  QImage*);
    void fill(label_t** map, QImage*, int x, int y, label_t label);
    QImage applyFilters(QImage sourceImage);
    QVector<ImageObject> computeParamtrs(label_t** map, int width, int height, label_t maxLabel);
    void printImageMap(label_t** map, int width, int height);
};

#endif // LOGFILTER_H
