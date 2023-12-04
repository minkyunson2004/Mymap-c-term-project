//
//  Mymap_placelist.cpp
//  term project
//
//  Created by 손민균 on 12/3/23.
//

#include "Mymap.h"

void Mymap::register_place(string place_name, int x, int y)
{
    placelist.new_place_add(place_name, x, y);
}

void Mymap::remove_place(string place_name)
{
    placelist.place_delete(place_name);
}

void Mymap::remove_place(int x, int y)
{
    placelist.place_delete(x, y);
}

void Mymap::register_place_and_building(string place_name, int x, int y)
{
    try 
    {
        string temp = "\0";
        if(base(x, y) == ROAD) throw 1;
        if(placelist.return_pos(place_name) != pair<int, int>(-1, -1)) throw 2;
        if(placelist.return_name(x, y) != temp) throw 3;
        placelist.new_place_add(place_name, x, y);
        base(x, y) = HOUSE;
    }
    catch (int Errortype)
    {
        switch (Errortype)
        {
            case 1:
                cout << "지정한 곳은 길 위입니다." << endl;
                break;
            case 2:
                cout << "이미 사용중인 이름입니다. 다른 이름을 사용하세요." << endl;
            case 3:
                cout << "이 장소는 이름이 이미 등록되어 있습니다. remove_place를 사용한 후 다시 입려해주세요." << endl;
            default:
                break;
        }
    }
}

void Mymap::remove_place_and_building(string place_name)
{
    pair<int, int> place_pos(placelist.return_pos(place_name));
    try 
    {
        if(place_pos == pair<int, int>(-1, -1)) throw 1;
        if(base(place_pos.first, place_pos.second) != HOUSE) throw 2;
        remove_place(place_name);
        remove_house(place_pos.first, place_pos.second);
    }
    catch (int Errortype)
    {
        switch (Errortype)
        {
            case 1:
                cout << place_name << "이라는 건물은 지도에 없습니다." << endl;
                break;
            case 2:
                cout << "이 장소는 건물이 아닙니다." << endl;
                break;
            default:
                break;
        }
    }
}

void Mymap::remove_place_and_building(int x, int y)
{
    pair<int, int> place_pos(x, y);
    try 
    {
        string temp = "\0";
        if(placelist.return_name(x, y) == temp) throw 1;
        if(base(x, y) != HOUSE) throw 2;
    }
    catch (int Errortype)
    {
        switch (Errortype)
        {
            case 1:
                cout << "이 장소는 이름이 등록되어 있지 않습니다." << endl;
                break;
            case 2:
                cout << "이 장소는 건물이 아닙니다." << endl;
                break;
            default:
                break;
        }
    }
}

pair<int, int> Mymap::return_place_pos(string place_name)
{
    return placelist.return_pos(place_name);
}
string Mymap::return_place_name(int x, int y)
{
    return placelist.return_name(x, y);
}

void Mymap::register_place_print()
{
    placelist.print_list();
}
