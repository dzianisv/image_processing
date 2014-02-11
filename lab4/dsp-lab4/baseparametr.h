#ifndef BASEPARAMETR_H
#define BASEPARAMETR_H

#include <label.h>

union ParametrValue {
    int ivalue;
    double dvalue;
    bool bvalue;
};

class BaseParametr
{
public:
    BaseParametr();
};

#endif // BASEPARAMETR_H
