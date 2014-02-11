#include "parametrperimetr.h"

ParametrPerimetr::ParametrPerimetr()
{
}

ParametrValue ParametrPerimetr::compute(label_t **map, int width, int height, label_t targetLabel)
{
    ParametrValue perimetr;
    perimetr.ivalue=0;

   for(uint32_t i=0; i<width; i++) {
       for(uint32_t j=0; j<height; j++)
       {

           int xyneigborsCount = neigborsCount(i, j, map, width, height, targetLabel);
           if(map[i][j]==targetLabel &&  xyneigborsCount < 8 && xyneigborsCount != -1 );
               perimetr.ivalue++;
       }
   }

   return perimetr;
}

int ParametrPerimetr::neigborsCount(int x, int y, label_t **map, int width, int height, label_t targetLabel)
{
    if(map[x][y] != targetLabel)
    {
        return -1;
    }

    int count=0;

    if( x+1<width )
        count += ( map[x+1][y] == targetLabel)?1:0;
    if( y+1<width )
        count += ( map[x][y+1] == targetLabel)?1:0;
    if( x+1<width && y+1<height )
        count += ( map[x+1][y+1] == targetLabel)?1:0;
    if( x-1>-1 )
        count += ( map[x-1][y] == targetLabel)?1:0;
    if( y-1>-1 )
        count += ( map[x][y-1] == targetLabel)?1:0;
    if( x-1>-1 && y-1>-1  )
        count += ( map[x-1][y-1] == targetLabel)?1:0;
    if( x+1<width && y-1>-1)
        count += ( map[x+1][y-1] == targetLabel)?1:0;
    if( x-1>-1 && y+1<height )
        count += ( map[x-1][y+1] == targetLabel)?1:0;
}
