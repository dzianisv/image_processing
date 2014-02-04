#include "imagewidget.h"
#include "ui_imagewidget.h"
#include <QPixmap>

ImageWidget::ImageWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ImageWidget)
{
    ui->setupUi(this);
}

ImageWidget::~ImageWidget()
{
    delete ui;
}

void ImageWidget::setImage(QImage image)
{
    QImage scaledImage = image.scaled(ui->imageLabel->size(), Qt::KeepAspectRatio);
    ui->imageLabel->setPixmap( QPixmap::fromImage(scaledImage) );
    ui->hostogramWidget->computeForImage(image);
}

void ImageWidget::setPixmap(QPixmap *pixmap)
{
    setImage(pixmap->toImage());
}

QImage ImageWidget::getImage()
{
    return ui->imageLabel->pixmap()->toImage();
}
