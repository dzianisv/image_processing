#include "imageactionwidget.h"
#include "ui_imageactionwidget.h"
#define IMAGE_COUNT 3

ImageActionWidget::ImageActionWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ImageActionWidget)
{
    ui->setupUi(this);
   imageWidgets = new ImageWidget[IMAGE_COUNT];

    for(int i=0; i<IMAGE_COUNT; i++)
    {
        ui->widgetLayout->addWidget(&imageWidgets[i]);
    }
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(apply()));
}

ImageActionWidget::~ImageActionWidget()
{
    delete ui;
    delete imageWidgets;
}

void ImageActionWidget::apply()
{
    emit finished();
}

ImageWidget *ImageActionWidget::getImageWidget(int index)
{
 return &imageWidgets[index];
}


void ImageActionWidget::setProgress(int p)
{
    ui->progressBar->setValue(p);
}

void ImageActionWidget::setProgressMax(int v)
{
    ui->progressBar->setMaximum(v);
}

