#ifndef IMAGEACTIONWIDGET_H
#define IMAGEACTIONWIDGET_H

#include <QWidget>
#include <imagewidget.h>

namespace Ui {
class ImageActionWidget;
}

class ImageActionWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ImageActionWidget(QWidget *parent = 0);
    ~ImageActionWidget();
    ImageWidget* imageWidgets;

protected:
        Ui::ImageActionWidget *ui;

public slots:
    void setProgress(int);
    void setProgressMax(int);
    virtual void apply();
    ImageWidget* getImageWidget(int index);
signals:
    void finished();

};

#endif // IMAGEACTIONWIDGET_H
