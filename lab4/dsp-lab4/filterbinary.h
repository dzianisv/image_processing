#ifndef FILTERBINARY_H
#define FILTERBINARY_H

#include <filterbase.h>

class FilterBinary : public FilterBase
{
public:
    FilterBinary();
    virtual QImage apply(QImage srcImage);
private:
    QRgb convertPixel(QRgb xy, int c);
};

#endif // FILTERBINARY_H
