#include "histogramwidget.h"
#include  <QHBoxLayout>
#include <QVector>

HistogramWidget::HistogramWidget(QWidget *parent) :
    QWidget(parent)
{
    plot = new QCustomPlot();
    plot->addGraph();
    plot->xAxis->setLabel("Grayscale brightness");
    plot->yAxis->setLabel("Frequency");

    QHBoxLayout* layout = new QHBoxLayout();
    layout->addWidget(plot);

    setLayout(layout);
}

HistogramWidget::~HistogramWidget()
{
    delete plot;
}

void HistogramWidget::computeForImage(QImage image)
{
    QVector<double> xData(256), yData(256);
    for(int x=0; x<image.width(); x++)
    {
        for(int y=0; y<image.height(); y++) {
            quint8 brightness =  qGray( image.pixel(x, y) ) & 0xFF;
             yData[brightness]++;
        }
    }

    double maxF = yData[0];
    for(int i=0; i<256; i++) {
        xData[i]=i;
        maxF = qMax(maxF, yData[i]);
    }

    plot->graph(0)->setData(xData, yData);
    plot->xAxis->setRange(0, 255);
    plot->yAxis->setRange(0, maxF+1);
    plot->replot();
}
