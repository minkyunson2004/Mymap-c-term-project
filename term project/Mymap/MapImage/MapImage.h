//
//  MapImage.h
//  term project
//
//  Created by 손민균 on 12/3/23.
//

#ifndef MapImage_h
#define MapImage_h
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
enum
{
    PLAIN = 0,      // ' '
    ROAD = 1,       // L'■'
    HOUSE = 2,      // L'⌂'
    
    CURRENT = 3,    // L'▼'
    
    NORTH = 4,      // '^'
    SOUTH = 5,      // 'v'
    WEST = 6,       // '<'
    EAST = 7        // '>'
};

class MapImage
{
private:
    int x, y;
    vector<vector<int>> mapdat;
public:
    MapImage(int sizex, int sizey);
    MapImage(const MapImage & copy);
    MapImage & operator=(const MapImage & other);
    int & operator()(int ix, int iy);
    int return_limit_x();
    int return_limit_y();
    void print();
};

#endif /* MapImage_h */
