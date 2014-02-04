#ifndef PARAMETEREXIST_H
#define PARAMETEREXIST_H

#include <baseparametr.h>

class ParameterExist : public BaseParametr
{
public:
    ParameterExist();
    virtual ParametrValue compute(label_t** map, int width, int height, label_t targetLabel);
};

#endif // PARAMETEREXIST_H
