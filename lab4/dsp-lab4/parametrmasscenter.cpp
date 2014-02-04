#include "parametrmasscenter.h"

ParametrMassCenter::ParametrMassCenter()
{
}

ParametrValue ParametrMassCenter::compute(label_t **map, int width, int height, label_t targetLabel)
{
    ParametrValue value;
    value.dvalue=0;

    for(uint32_t i=0; i<width; i++) {
        for(uint32_t j=0; j<height; j++)
        {
            if(map[i][j]==targetLabel)
                //TODO:
                value.dvalue+=1;

        }
    }

    return value;
}
