#ifndef HISTOGRAMWIDGET_H
#define HISTOGRAMWIDGET_H

#include <QObject>
#include <qcustomplot.h>

class HistogramWidget : public QWidget
{
    Q_OBJECT
public:
    explicit HistogramWidget(QWidget *parent = 0);
    ~HistogramWidget();


protected:
    QCustomPlot* plot;

signals:

public slots:
    void computeForImage(QImage image);
};

#endif // HISTOGRAMWIDGET_H
