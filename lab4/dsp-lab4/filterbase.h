#ifndef FILTERBASE_H
#define FILTERBASE_H

#include <QImage>

class FilterBase
{
public:
    virtual QImage apply(QImage sourceImage) = 0;
};

#endif // FILTERBASE_H
