#ifndef PARAMETRSQUARE_H
#define PARAMETRSQUARE_H

#include "baseparametr.h"

class ParametrSquare : public BaseParametr
{
public:
    ParametrSquare();
    static ParametrValue compute(label_t** map, int width, int height, label_t targetLabel);
};

#endif // PARAMETRSQUARE_H
