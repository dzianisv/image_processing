#include "parameterexist.h"

ParameterExist::ParameterExist()
{
}

ParametrValue ParameterExist::compute(label_t **map, int width, int height, label_t targetLabel)
{
    ParametrValue value;
    value.bvalue=false;

    for(uint32_t i=0; i<width; i++) {
        for(uint32_t j=0; j<height; j++)
        {
            if(map[i][j]==targetLabel)
                value.bvalue=true;
            return value;
        }
    }
}
