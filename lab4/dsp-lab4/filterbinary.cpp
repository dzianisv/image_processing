#include "filterbinary.h"
#include <QColor>
#include <QImage>

FilterBinary::FilterBinary()
{
}

QImage FilterBinary::apply(QImage srcImage)
{
    QImage dstImage(srcImage.width(), srcImage.height(), QImage::Format_RGB32);

    for(int x=0; x<dstImage.width(); x++) {
        for( int y=0; y<dstImage.height(); y++) {
            QRgb pixel = convertPixel(srcImage.pixel(x, y), 128);
            dstImage.setPixel(x, y, pixel);
        }
    }
    return dstImage;
}

QRgb FilterBinary::convertPixel(QRgb xy, int c)
{
    int r, g, b;
    QColor src(xy);
    if( (src.red()+src.green()+src.blue())/3 >= c)
    {
        r = 0xFF;
        g = 0xFF;
        b = 0xFF;
    }
    else
    {
        r = 0;
        g = 0;
        b = 0;
    }

    QColor dst(r, g, b);
    return dst.rgb();
}
