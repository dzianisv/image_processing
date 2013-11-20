#include "imageactionwidget.h"
#include "ui_imageactionwidget.h"

ImageActionWidget::ImageActionWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ImageActionWidget)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(apply()));
}

ImageActionWidget::~ImageActionWidget()
{
    delete ui;
}

const QPixmap *ImageActionWidget::sourcePixmap()
{
    return  ( this->ui->sourceImageWidget->pixmap() );
}

const QPixmap *ImageActionWidget::destinationPixmap()
{
    return ( this->ui->destinationImageWidget->pixmap());
}

void ImageActionWidget::apply()
{
    emit finished();
}

void ImageActionWidget::loadDestinationImage(QPixmap *pixmap)
{

    this->ui->destinationImageWidget->setPixmap(*pixmap);
    this->ui->destinationHistogramWidget->computeForImage(pixmap->toImage());
}


void ImageActionWidget::loadDestinationImage(QImage image)
{
    this->ui->destinationImageWidget->setPixmap(QPixmap::fromImage(image));
    this->ui->destinationHistogramWidget->computeForImage(image);
}

void ImageActionWidget::setProgress(int p)
{
    ui->progressBar->setValue(p);
}

void ImageActionWidget::setProgressMax(int v)
{
    ui->progressBar->setMaximum(v);
}

void ImageActionWidget::loadSourceImage(QPixmap *pixmap)
{
    this->ui->sourceImageWidget->setPixmap(*pixmap);
     this->ui->sourceHistogramWidget->computeForImage(pixmap->toImage());
}
