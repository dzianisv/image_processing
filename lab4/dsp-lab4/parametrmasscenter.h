#ifndef PARAMETRMASSCENTER_H
#define PARAMETRMASSCENTER_H

#include <baseparametr.h>

class ParametrMassCenter : public BaseParametr
{
public:
    ParametrMassCenter();
    virtual ParametrValue compute(label_t** map, int width, int height, label_t targetLabel);
};

#endif // PARAMETRMASSCENTER_H
