#include "imagecontainer.h"

ImageContainer* ImageContainer::localInstance=0x0;


ImageContainer* ImageContainer::getInstance()
{
    if(localInstance == NULL)
        localInstance = new ImageContainer();

    return localInstance;
}

void ImageContainer::load(QString path)
{
    sourcePixmap.load(path);
    emit loaded(&sourcePixmap);
    emit imageLoaded( sourcePixmap.toImage() );
}

QPixmap* ImageContainer::getPixmap()
{
    return &sourcePixmap;
}

ImageContainer::ImageContainer()
{

}
