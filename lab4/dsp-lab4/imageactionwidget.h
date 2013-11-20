#ifndef IMAGEACTIONWIDGET_H
#define IMAGEACTIONWIDGET_H

#include <QWidget>

namespace Ui {
class ImageActionWidget;
}

class ImageActionWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ImageActionWidget(QWidget *parent = 0);
    ~ImageActionWidget();
    const QPixmap *sourcePixmap();
    const QPixmap *destinationPixmap();

protected:
    Ui::ImageActionWidget *ui;

public slots:
    void loadSourceImage(QPixmap* pixmap);
    void loadDestinationImage(QPixmap* pixmap);
    void loadDestinationImage(QImage);
    void setProgress(int);
    void setProgressMax(int);
    virtual void apply();

signals:
    void finished();

};

#endif // IMAGEACTIONWIDGET_H
