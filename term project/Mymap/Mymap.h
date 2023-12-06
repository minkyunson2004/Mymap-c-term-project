//
//  Mymap.h
//  term project
//
//  Created by 손민균 on 12/3/23.
//

#ifndef Mymap_h
#define Mymap_h
#include "MapImage.h"
#include "Saveplace.h"
#include <queue>
using namespace std;
class Mymap
{
private:
    MapImage base;
    Saveplace placelist;
public:
    //Mymap_mapmodify.cpp
    Mymap(int ix, int iy);
    void add_WEroad(int y, int x_start, int x_end, bool house_destroy = false);
    void add_NSroad(int x, int y_start, int y_end, bool house_destroy = false);
    void add_road(int x, int y, bool house_destroy = false);
    void remove_WEroad(int y, int x_start, int x_end);
    void remove_NSroad(int x, int y_srart, int y_end);
    void remove_road(int x, int y);
    void remove_road_area(int x_start, int y_start, int x_end, int y_end);
    bool add_house(int x, int y, bool ignore_road = false);
    void remove_house(int x, int y);
    void remove_house_area(int x_start, int y_start, int x_end, int y_end);
    void remove_all_initialrize();
    void print();
    //Mymap_placelist.cpp
    void register_place(string place_name, int x, int y);
    void remove_place(string place_name);
    void remove_place(int x, int y);
    void register_place_and_building(string place_name, int x, int y);
    void remove_place_and_building(string place_name);
    void remove_place_and_building(int x, int y);
    void register_place_print();
    pair<int, int> return_place_pos(string place_name);
    string return_place_name(int x, int y);
    //Mymap_navigator.cpp
    void print_navigator(int start_x, int start_y, int end_x, int end_y);
};
#endif /* Mymap_h */
