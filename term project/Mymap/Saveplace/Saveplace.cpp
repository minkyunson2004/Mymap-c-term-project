//
//  saveplace.cpp
//  term project
//
//  Created by 손민균 on 12/3/23.
//

#include "Saveplace.h"

void Saveplace::new_place_add(string new_place_name, int new_place_xpos, int new_place_ypos)
{
    pair<int, int> new_place_pos(new_place_xpos, new_place_ypos);
    try
    {
        if(name_pos_search.find(new_place_name) != name_pos_search.end()) throw 1;
        if(pos_name_search.find(new_place_pos) != pos_name_search.end()) throw 2;
        name_pos_search[new_place_name] = new_place_pos;
        pos_name_search[new_place_pos] = new_place_name;
    }
    catch(int Errortype)
    {
        switch (Errortype) 
        {
            case 1:
                cout << "이미 사용중인 이름입니다. 다른 이름을 사용하세요." << endl;
                break;
            case 2:
                cout << "이 장소는 이름이 이미 등록되어 있습니다. remove_place를 사용한 후 다시 입려해주세요." << endl;
                break;
            default:
                break;
        }
    }
}
void Saveplace::place_delete(string delete_place_name)
{
    try 
    {
        if(name_pos_search.find(delete_place_name) == name_pos_search.end()) throw 1;
        pair<int, int> delete_place_pos(name_pos_search[delete_place_name].first, name_pos_search[delete_place_name].second);
        
        name_pos_search.erase(delete_place_name);
        pos_name_search.erase(delete_place_pos);
    } 
    catch (int Errortype)
    {
        cout << "해당 명칭의 장소가 없습니다." << endl;
    }
}
void Saveplace::place_delete(int delete_place_xpos, int delete_place_ypos)
{
    try
    {
        pair<int, int> delete_place_pos(delete_place_xpos, delete_place_ypos);
        if(pos_name_search.find(delete_place_pos) == pos_name_search.end()) throw 1;
        
        name_pos_search.erase(pos_name_search[delete_place_pos]);
        pos_name_search.erase(delete_place_pos);
    }
    catch (int Errortype)
    {
        cout << "해당 좌표는 명칭이 등록되어있지 않습니다." << endl;
    }
}
pair<int, int> Saveplace::return_pos(const string & name)
{
    try
    {
        if(name_pos_search.find(name) == name_pos_search.end()) throw -1;
        return name_pos_search[name];
    }
    catch (int error)
    {
        return pair<int, int>(-1, -1);
    }
}
string Saveplace::return_name(const int x, const int y)
{
    pair<int, int> temp(x, y);
    if(pos_name_search.find(temp) == pos_name_search.end())
    {
        return "\0";
    }
    else
    {
        return pos_name_search[temp];
    }
}

void Saveplace::print_list()
{
    for(auto e : name_pos_search)
    {
        cout << e.first << ": (" << e.second.first << ", " << e.second.second << ')' << endl;
    }
}
