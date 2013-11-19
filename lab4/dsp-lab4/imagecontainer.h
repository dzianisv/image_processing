#ifndef IMAGECONTAINER_H
#define IMAGECONTAINER_H

#include <QObject>
#include <QImage>
#include <QPixmap>

class ImageContainer: public QObject
{
    Q_OBJECT
public:
    static ImageContainer* getInstance();
    void load(QString path);
    QPixmap* getPixmap();

private:
    ImageContainer();
    static ImageContainer* localInstance;
    QPixmap sourcePixmap;
signals:
    void loaded(QPixmap* pixmap);
};

#endif // IMAGECONTAINER_H
