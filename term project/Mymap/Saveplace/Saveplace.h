//
//  saveplace.h
//  term project
//
//  Created by 손민균 on 12/3/23.
//

#ifndef Saveplace_h
#define Saveplace_h
#include <map>
#include <string>
#include <iostream>
using namespace std;
class Saveplace
{
private:
    map<string, pair<int, int>> name_pos_search;
    map<pair<int, int>, string> pos_name_search;
public:
    void new_place_add(string new_place_name, int new_place_xpos, int new_place_ypos);
    void place_delete(string delete_place_name);
    void place_delete(int delete_place_xpos, int delete_place_ypos);
    pair<int, int> return_pos(const string & name);
    string return_name(const int x, const int y);
    void print_list();
};

#endif /* Saveplace_h */
