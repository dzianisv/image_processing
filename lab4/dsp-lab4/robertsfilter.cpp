#include "robertsfilter.h"
#include <cmath>

RobertsFilter::RobertsFilter()
{
}

QImage RobertsFilter::roberts(const QPixmap &srcPixmap)
{
    QImage srcImage = srcPixmap.toImage();
    QImage dstImage(srcImage.width(), srcImage.height(), QImage::Format_RGB32);

    setProgressMax( dstImage.width()-1);

    for(int x=0; x<dstImage.width(); x++) {
        for( int y=0; y<dstImage.height(); y++) {

            QRgb x1y1, x1y, xy1, xy;

            x1y1 = srcImage.pixel(x+1, y+1);
            x1y = srcImage.pixel(x+1, y);
            xy1 = srcImage.pixel(x, y+1);
            xy = srcImage.pixel(x, y);

            QRgb pixel = roberts(xy, x1y, xy1, x1y1);
            dstImage.setPixel(x, y, pixel);
        }
        setProgress( x );
    }
    dstImage.invertPixels();
    return dstImage;
}

void RobertsFilter::apply()
{
    QImage filteredImage = roberts(*sourcePixmap());
    loadDestinationImage(filteredImage);
}

QRgb RobertsFilter::roberts(QRgb xy, QRgb x1y, QRgb xy1, QRgb x1y1)
{
    QRgb pixel = monochromeRoberts( 0xFF & qGray(xy), 0xFF & qGray(x1y), 0xFF &qGray(xy1),  0xFF &qGray(x1y1));
    pixel |= (pixel << 8)  | (pixel << 16 );
    return  pixel;
}

quint8 RobertsFilter::monochromeRoberts(quint8 xy, quint8 x1y, quint8 xy1,quint8 x1y1)
{
    return std::sqrt( std::pow(x1y-xy1,2) + std::pow(xy-x1y1,2));
}
