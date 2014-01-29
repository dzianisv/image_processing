#include "logfilter.h"

logfilter::logfilter()
{
}

QImage logfilter::logcorrect(const QPixmap &srcPixmap)
{
    int c = 46;
    QImage srcImage = srcPixmap.toImage();
    QImage dstImage(srcImage.width(), srcImage.height(), QImage::Format_RGB32);

    setProgressMax( dstImage.width()-1);

    for(int x=0; x<dstImage.width(); x++) {
        for( int y=0; y<dstImage.height(); y++) {
            QRgb pixel = logcorrect(srcImage.pixel(x, y), 700);
            dstImage.setPixel(x, y, pixel);
        }
        setProgress( x );
    }
    return dstImage;
}

void logfilter::apply()
{
    QImage filteredImage = logcorrect(*sourcePixmap());
    loadDestinationImage(filteredImage);
}

QRgb logfilter::logcorrect(QRgb xy, int c)
{
    int r, g, b;
    QColor src(xy);
    if(src.red()+src.green()+src.blue() >= c)
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
