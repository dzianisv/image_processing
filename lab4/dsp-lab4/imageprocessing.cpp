#include <QDebug>
#include <QVector>

#include <imageprocessing.h>
#include <imagecontainer.h>
#include <parameterexist.h>
#include <parametrmasscenter.h>
#include <parametrperimetr.h>
#include <parametrsquare.h>

#include <filterbinary.h>

/************************************************/

ImageProcessing::ImageProcessing()
{
    //add filters to vector
    filters.append( new FilterBinary() );
}


void ImageProcessing::apply()
{
    QImage filteredImage = applyFilters( ImageContainer::getInstance()->getPixmap()->toImage() );

    //allocate memory for image map. Image map will be used in labeling.
    label_t **imageMap = new label_t*[filteredImage.width()];

    for(int i=0; i<filteredImage.width(); i++)
        imageMap[i]=new label_t[filteredImage.height()];

    //set image in first widget
    imageWidgets[1].setImage(filteredImage);
    label_t maxLabel = labeling(imageMap, &filteredImage);

    //compute image parameters
    QVector<ImageObject> imageObjects = computeParamtrs(imageMap, filteredImage.width(), filteredImage.height(), maxLabel);
    qDebug() << "ImageObjects count " << imageObjects.size();
}

/**
 * @brief logfilter::labeling perform labeling pixmap
 */
label_t ImageProcessing::labeling(label_t **map, QImage *filteredImage)
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

    return label;
}

/**
 * @brief If you will be use big image, stack overflow may be ocure
 * @param map
 * @param filteredImage
 * @param x
 * @param y
 * @param label
 */
void ImageProcessing::fill(label_t **map, QImage *filteredImage, int x, int y, label_t label)
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

QVector<ImageObject> ImageProcessing::computeParamtrs(label_t **map, int width, int height, label_t maxLabel)
{
    QVector<ImageObject> objects;

    for(int i=0; i<maxLabel.label; i++)
    {
        const label_t label = {i};
        if( ( ParameterExist::compute(map, width, height, label )).bvalue )
        {
            ImageObject newObject;
            newObject.label = label;
            newObject.perimetr = ParametrPerimetr::compute(map, width, height, label);
            newObject.square = ParametrSquare::compute(map, width, height, label);

            objects.append(newObject);
        }
    }

    return objects;
}

void ImageProcessing::printImageMap(label_t **map, int width, int height)
{

}


QImage ImageProcessing::applyFilters(QImage sourceImage)
{
    QImage image = sourceImage;
    QVector<FilterBase*>::iterator f = filters.begin();
    for(; f!=filters.end(); f++)
    {
        image = (*f)->apply(image);
    }

    return image;
}
