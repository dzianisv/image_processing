#include "logfilter.h"
#include <QDebug>
#include <imagecontainer.h>

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
            QRgb pixel = logcorrect(srcImage.pixel(x, y), 128);
            dstImage.setPixel(x, y, pixel);
        }
        setProgress( x );
    }
    return dstImage;
}



void logfilter::apply()
{
    QImage filteredImage = logcorrect( *ImageContainer::getInstance()->getPixmap() );
    label_t **imageMap = new label_t*[filteredImage.width()];

    for(int i=0; i<filteredImage.width(); i++)
        imageMap[i]=new label_t[filteredImage.height()];

    imageWidgets[1].setImage(filteredImage);
    labeling(imageMap, &filteredImage);
}

/**
 * @brief logfilter::labeling perform labeling pixmap
 */
void logfilter::labeling(label_t **map, QImage *filteredImage)
{
    //default all pixel marked as 0x0. that means unmarked pixel
    for(int i=0;  i< filteredImage->width(); i++)
        for(int j=0; j<filteredImage->height(); j++)
            map[i][j]={ 0 };

    label_t label = { 1 };

    for(int i=0; i<filteredImage->width(); i++) {
        for(int j=0; j<filteredImage->height(); j++)
        {
            fill(map,  filteredImage, i, j, label);
            label.label++;
        }
    }

    qDebug() << "Labeling is done, labels count is " << label.label-1;
}

/**
 * @brief If you will be use big image, stack overflow may be ocure
 * @param map
 * @param filteredImage
 * @param x
 * @param y
 * @param label
 */
void logfilter::fill(label_t **map, QImage *filteredImage, int x, int y, label_t label)
{
    label_t unmarked_label = { 0 };
    bool factor1 =  ( filteredImage->pixel(x, y) == 0 ) ;
    bool factor2 =  ( map[x][y]== unmarked_label );

    if(  factor1 && factor2 ) {
        map[x][y] = label;

        if( x > 0 )
            fill(map, filteredImage, x-1, y, label);
        if( x < filteredImage->width()-2)
            fill(map, filteredImage, x+1, y, label);
        if( y > 0 )
            fill(map, filteredImage, x, y-1, label);
        if(y<filteredImage->height()-2)
            fill(map, filteredImage, x, y+1, label);
    }
}

QRgb logfilter::logcorrect(QRgb xy, int c)
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
