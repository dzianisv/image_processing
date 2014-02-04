#include "parametrsquare.h"
#include <stdint.h>

ParametrSquare::ParametrSquare()
{
}

ParametrValue ParametrSquare::compute(label_t **map, int width, int height, label_t targetLabel)
{
        ParametrValue square;
        square.ivalue=0;

       for(uint32_t i=0; i<width; i++) {
           for(uint32_t j=0; j<height; j++)
           {
               if(map[i][j]==targetLabel)
                   square.ivalue++;
           }
       }

       return square;
}
