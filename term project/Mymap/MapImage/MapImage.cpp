//
//  MapImage.cpp
//  term project
//
//  Created by 손민균 on 12/3/23.
//

#include "MapImage.h"
MapImage::MapImage(int sizex, int sizey) : x(sizex), y(sizey), mapdat(sizey, vector<int>(sizex, 0))
{
        
}
MapImage::MapImage(const MapImage & copy) : x(copy.x), y(copy.y), mapdat(copy.mapdat)
{
        
}
MapImage & MapImage::operator=(const MapImage & other)
{
    x = other.x;
    y = other.y;
    mapdat = other.mapdat;
        
    return *this;
}
int & MapImage::operator()(int ix, int iy)
{
    return mapdat[iy][ix];
}
int MapImage::return_limit_x()
{
    return x;
}
int MapImage::return_limit_y()
{
    return y;
}
void MapImage::print()
{
    printf("\u00B7");           //·
    for(int i = 0; i < x; i++)
    {
        cout << "--";
    }
    printf("\u00B7");
    cout << endl;
    for(int i = 0; i < y; i++)
    {
        cout << '|';
        for(int j = 0; j < x; j++)
        {
            int temp = mapdat[i][j];
            switch (temp)
            {
                case PLAIN:
                    cout << "  ";
                    break;
                case ROAD:
                    printf("\u25A0 ");
                    break;
                case HOUSE:
                    printf("\u2302 ");
                    break;
                case CURRENT:
                    printf("\u25BC ");
                    break;
                case NORTH:
                    cout << "^ ";
                    break;
                case SOUTH:
                    cout << "v ";
                    break;
                case EAST:
                    cout << "> ";
                    break;
                case WEST:
                    cout << "< ";
                    break;
                default:
                    cout << "Error : (" << j << ", " << i  << ") data = " << temp << ", 유효하지 않은 데이터입니다."<< endl;
                    exit(1);
                    break;
            }
        }
        cout << "|\n";
    }
    printf("\u00B7");
    for(int i = 0; i < x; i++)
    {
        cout << "--";
    }
    printf("\u00B7");
    cout << endl;
}
