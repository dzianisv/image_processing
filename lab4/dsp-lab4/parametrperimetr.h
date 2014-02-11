#ifndef PARAMETRPERIMETR_H
#define PARAMETRPERIMETR_H

#include <baseparametr.h>

class ParametrPerimetr : public BaseParametr
{
public:
    ParametrPerimetr();
    static ParametrValue compute(label_t** map, int width, int height, label_t targetLabel);
    static int neigborsCount(int x, int y, label_t** map, int width, int height, label_t targetLabel);

};

#endif // PARAMETRPERIMETR_H
