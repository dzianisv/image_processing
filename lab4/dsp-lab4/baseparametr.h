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
    virtual ParametrValue compute(label_t** map, int widht, int height, label_t target_label)=0;
};

#endif // BASEPARAMETR_H
