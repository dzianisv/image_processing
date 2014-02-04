#ifndef IMAGEWIDGET_H
#define IMAGEWIDGET_H

#include <QWidget>

namespace Ui {
class ImageWidget;
}

class ImageWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ImageWidget(QWidget *parent = 0);
    ~ImageWidget();
    QImage getImage();

public slots:
    void setImage(QImage);
    void setPixmap(QPixmap* pixmap);

private:
    Ui::ImageWidget *ui;
};

#endif // IMAGEWIDGET_H
