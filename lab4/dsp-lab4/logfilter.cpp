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
            QRgb pixel = logcorrect(srcImage.pixel(x, y), c);
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
    QColor src(xy);
    QColor dst(c*qLn(1+src.red()), c*qLn(1+src.green()), c*qLn(1+src.blue()));
    return dst.rgb();
}
