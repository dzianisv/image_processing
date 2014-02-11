#ifndef IMAGEOBJECT_H
#define IMAGEOBJECT_H

#include <label.h>
#include <baseparametr.h>

class ImageObject
{
public:
    ImageObject();
    ParametrValue perimetr;
    ParametrValue square;
    ParametrValue massCenter;

    label_t label;
    ClassID classID;
};

#endif // IMAGEOBJECT_H
