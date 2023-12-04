//
//  Mymap.cpp
//  term project
//
//  Created by 손민균 on 12/3/23.
//

#include "Mymap.h"

Mymap::Mymap(int ix, int iy)
: base(ix, iy)
{
    
}

void Mymap::add_WEroad(int y, int x_start, int x_end, bool house_destroy)
{
    try
    {
        if(x_start > x_end) throw 1;
        if(y < 0 || y >= base.return_limit_y()) throw 2;
        if(x_start < 0 || x_end >= base.return_limit_x()) throw 3;
        
        int idx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
        int idy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        bool is_road[8] = {false};
        for(int i = 0; i < 8; i++)
        {
            int tempx = x_start + idx[i];
            int tempy = y + idy[i];
            if(tempx < 0 || tempy < 0 || tempx >= base.return_limit_x() || tempy >= base.return_limit_y())
                is_road[i] = false;
            else if(base(tempx, tempy) == ROAD)
                is_road[i] = true;
            else
                is_road[i] = false;
        }
        if(is_road[0])
            if(is_road[1] && is_road[3])
                throw 4;
        if(is_road[2])
            if(is_road[1] && is_road[4])
                throw 4;
        if(is_road[5])
            if(is_road[3] && is_road[6])
                throw 4;
        if(is_road[7])
            if(is_road[4] && is_road[6])
                throw 4;
        for(int i = 0; i < 8; i++)
        {
            int tempx = x_end + idx[i];
            int tempy = y + idy[i];
            if(tempx < 0 || tempy < 0 || tempx >= base.return_limit_x() || tempy >= base.return_limit_y())
                is_road[i] = false;
            else if(base(tempx, tempy) == ROAD)
                is_road[i] = true;
            else
                is_road[i] = false;
        }
        if(is_road[0])
            if(is_road[1] && is_road[3])
                throw 4;
        if(is_road[2])
            if(is_road[1] && is_road[4])
                throw 4;
        if(is_road[5])
            if(is_road[3] && is_road[6])
                throw 4;
        if(is_road[7])
            if(is_road[4] && is_road[6])
                throw 4;
        
        int exist_north_road = 0;
        int exist_south_road = 0;
        for(int i = x_start; i <= x_end; i++)
        {
            if(base(i, y) == HOUSE && !house_destroy) throw pair<int, int>(i, y);
            
            if(y == 0)
            {
                if(base(i, y + 1) == ROAD)
                    exist_south_road++;
                else
                    exist_south_road = 0;
            }
            else if(y == base.return_limit_y())
            {
                if(base(i, y - 1) == ROAD)
                    exist_north_road++;
                else
                    exist_north_road = 0;
            }
            else
            {
                if(base(i, y + 1) == ROAD)
                    exist_south_road++;
                else
                    exist_south_road = 0;
                if(base(i, y - 1) == ROAD)
                    exist_north_road++;
                else
                    exist_north_road = 0;
            }
            
            if(exist_south_road == 2 || exist_north_road == 2) throw 4;
        }
        
        for(int i = x_start; i <= x_end; i++)
        {
            base(i, y) = ROAD;
        }
    }
    catch (int Errortype)
    {
        switch (Errortype) 
        {
            case 1:
                cout << "start값이 end값보다 큽니다." << endl;
                break;
            case 2:
                cout << "y값이 올바른 범위 밖에 있습니다, 올바른 범위는 0 <= y < " << base.return_limit_y() << " 입니다." << endl;
                break;
            case 3:
                cout << "x값이 올바른 범위 밖에 있습니다, 올바른 범위는 0 <= x < " << base.return_limit_x() << " 입니다." << endl;
                break;
            case 4:
                cout << "인접한 도로때문에 도로를 설치할 수 없습니다." << endl;
                break;
            default:
                break;
        }
    }
    catch (pair<int, int> Errortype)
    {
        cout << "도로를 설치하려는 자리에 집이 있습니다. 집의 위치는 (" << Errortype.first << ", " << Errortype.second << ") 입니다." << endl;
    }
}
void Mymap::add_NSroad(int x, int y_start, int y_end, bool house_destroy)
{
    try
    {
        if(y_start > y_end) throw 1;
        if(x < 0 || x >= base.return_limit_x()) throw 2;
        if(y_start < 0 || y_end >= base.return_limit_y()) throw 3;
        
        int idx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
        int idy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        bool is_road[8] = {false};
        for(int i = 0; i < 8; i++)
        {
            int tempx = x + idx[i];
            int tempy = y_start + idy[i];
            if(tempx < 0 || tempy < 0 || tempx >= base.return_limit_x() || tempy >= base.return_limit_y())
                is_road[i] = false;
            else if(base(tempx, tempy) == ROAD)
                is_road[i] = true;
            else
                is_road[i] = false;
        }
        if(is_road[0])
            if(is_road[1] && is_road[3])
                throw 4;
        if(is_road[2])
            if(is_road[1] && is_road[4])
                throw 4;
        if(is_road[5])
            if(is_road[3] && is_road[6])
                throw 4;
        if(is_road[7])
            if(is_road[4] && is_road[6])
                throw 4;
        for(int i = 0; i < 8; i++)
        {
            int tempx = x + idx[i];
            int tempy = y_end + idy[i];
            if(tempx < 0 || tempy < 0 || tempx >= base.return_limit_x() || tempy >= base.return_limit_y())
                is_road[i] = false;
            else if(base(tempx, tempy) == ROAD)
                is_road[i] = true;
            else
                is_road[i] = false;
        }
        if(is_road[0])
            if(is_road[1] && is_road[3])
                throw 4;
        if(is_road[2])
            if(is_road[1] && is_road[4])
                throw 4;
        if(is_road[5])
            if(is_road[3] && is_road[6])
                throw 4;
        if(is_road[7])
            if(is_road[4] && is_road[6])
                throw 4;
        
        int exist_west_road = 0;
        int exist_east_road = 0;
        for(int i = y_start; i <= y_end; i++)
        {
            if(base(x, i) == HOUSE && !house_destroy) throw pair<int, int>(x, i);
            
            if(x == 0)
            {
                if(base(x + 1, i) == ROAD)
                    exist_east_road++;
                else
                    exist_east_road = 0;
            }
            else if(x == base.return_limit_x())
            {
                if(base(x - 1, i) == ROAD)
                    exist_west_road++;
                else
                    exist_west_road = 0;
            }
            else
            {
                if(base(x + 1, i) == ROAD)
                    exist_east_road++;
                else
                    exist_east_road = 0;
                if(base(x - 1, i) == ROAD)
                    exist_west_road++;
                else
                    exist_west_road = 0;
            }
            
            if(exist_east_road == 2 || exist_west_road == 2) throw 4;
        }
        
        for(int i = y_start; i <= y_end; i++)
        {
            base(x, i) = ROAD;
        }
    }
    catch (int Errortype)
    {
        switch (Errortype)
        {
            case 1:
                cout << "start값이 end값보다 큽니다." << endl;
                break;
            case 2:
                cout << "x값이 올바른 범위 밖에 있습니다, 올바른 범위는 0 <= x < " << base.return_limit_x() << " 입니다." << endl;
                break;
            case 3:
                cout << "y값이 올바른 범위 밖에 있습니다, 올바른 범위는 0 <= y < " << base.return_limit_y() << " 입니다." << endl;
                break;
            case 4:
                cout << "인접한 도로때문에 도로를 설치할 수 없습니다." << endl;
                break;
            default:
                break;
        }
    }
    catch (pair<int, int> Errortype)
    {
        cout << "도로를 설치하려는 자리에 집이 있습니다. 집의 위치는 (" << Errortype.first << ", " << Errortype.second << ") 입니다." << endl;
    }
}

void Mymap::add_road(int x, int y, bool house_destroy)
{
    try 
    {
        if(x < 0 || x >= base.return_limit_x() || y < 0 || y >= base.return_limit_y()) throw 1;
        if(base(x,y) == HOUSE && !house_destroy) throw 2;
        
        int idx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
        int idy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        bool is_road[8] = {false};
        for(int i = 0; i < 8; i++)
        {
            int tempx = x + idx[i];
            int tempy = y + idy[i];
            if(tempx < 0 || tempy < 0 || tempx >= base.return_limit_x() || tempy >= base.return_limit_y())
                continue;
            else if(base(tempx, tempy) == ROAD)
                is_road[i] = true;
        }
        if(is_road[0])
            if(is_road[1] && is_road[3])
                throw  3;
        if(is_road[2])
            if(is_road[1] && is_road[4])
                throw  3;
        if(is_road[5])
            if(is_road[3] && is_road[6])
                throw  3;
        if(is_road[7])
            if(is_road[4] && is_road[6])
                throw  3;
        
        base(x, y) = ROAD;
    }
    catch (int Error)
    {
        switch (Error)
        {
            case 1:
                cout << "x값 또는 y값이 올바른 범위 밖에 있습니다, 올바른 범위는 0 <= x < " << base.return_limit_x() <<" , 0 <= y < " << base.return_limit_y() << "입니다" << endl;
                break;
            case 2:
                cout << "도로를 설치하려는 자리에 집이 있습니다. 집의 위치는 (" << x << ", " << y << ") 입니다." << endl;
                break;
            case 3:
                cout << "인접한 도로때문에 도로를 설치할 수 없습니다." << endl;
                break;
            default:
                break;
        }
    }
}

void Mymap::remove_WEroad(int y, int x_start, int x_end)
{
    try
    {
        if(x_start > x_end) throw 1;
        if(y < 0 || y >= base.return_limit_y()) throw 2;
        if(x_start < 0 || x_end >= base.return_limit_x()) throw 3;
        
        for(int i = x_start; i <= x_end; i++)
        {
            if(base(i, y) == ROAD)
                base(i, y) = PLAIN;
        }
    }
    catch(int Errortype)
    {
        switch (Errortype)
        {
            case 1:
                cout << "start값이 end값보다 큽니다." << endl;
                break;
            case 2:
                cout << "y값이 올바른 범위 밖에 있습니다, 올바른 범위는 0 <= y < " << base.return_limit_y() << " 입니다." << endl;
                break;
            case 3:
                cout << "x값이 올바른 범위 밖에 있습니다, 올바른 범위는 0 <= x < " << base.return_limit_x() << " 입니다." << endl;
                break;
            default:
                break;
        }
    }
}

void Mymap::remove_NSroad(int x, int y_start, int y_end)
{
    try
    {
        if(y_start > y_end) throw 1;
        if(x < 0 || x >= base.return_limit_x()) throw 2;
        if(y_start < 0 || y_end >= base.return_limit_y()) throw 3;
        
        for(int i = y_start; i <= y_end; i++)
        {
            if(base(x, i) == ROAD)
                base(x, i) = PLAIN;
        }
    }
    catch(int Errortype)
    {
        switch (Errortype)
        {
            case 1:
                cout << "start값이 end값보다 큽니다." << endl;
                break;
            case 2:
                cout << "x값이 올바른 범위 밖에 있습니다, 올바른 범위는 0 <= x < " << base.return_limit_x() << " 입니다." << endl;
                break;
            case 3:
                cout << "y값이 올바른 범위 밖에 있습니다, 올바른 범위는 0 <= y < " << base.return_limit_y() << " 입니다." << endl;
                break;
            default:
                break;
        }
    }
}

void Mymap::remove_road(int x, int y)
{
    try 
    {
        if(x < 0 || x >= base.return_limit_x() || y < 0 || y >= base.return_limit_y()) throw 1;
        if(base(x, y) != ROAD) throw 2;
        base(x, y) = PLAIN;
    }
    catch (int Errortype)
    {
        switch (Errortype)
        {
            case 1:
                cout << "x값 또는 y값이 올바른 범위 밖에 있습니다, 올바른 범위는 0 <= x < " << base.return_limit_x() <<" , 0 <= y < " << base.return_limit_y() << '.' << endl;
                break;
            case 2:
                cout << "지정한 곳은 길이 아닙니다." << endl;
                break;
            default:
                break;
        }
    }
}

void Mymap::remove_road_area(int x_start, int y_start, int x_end, int y_end)
{
    try 
    {
        if(x_start < 0 || x_end >= base.return_limit_x() || y_start < 0 || y_end >= base.return_limit_y()) throw 1;
        for(int i = x_start; i <= x_end; i++)
        {
            for(int j = y_start; j <= y_end; j++)
            {
                if(base(i, j) == ROAD)
                {
                    base(i, j) = PLAIN;
                }
            }
        }
    }
    catch (int Errortype)
    {
        cout << "x값 또는 y값이 올바른 범위 밖에 있습니다, 올바른 범위는 0 <= x < " << base.return_limit_x() <<" , 0 <= y < " << base.return_limit_y() << '.' << endl;
    }
}

bool Mymap::add_house(int x, int y, bool ignore_road)
{
    try
    {
        if(x < 0 || x >= base.return_limit_x() || y < 0 || y >= base.return_limit_y()) throw 1;
        if(base(x, y) == ROAD && !ignore_road) throw 2;
        base(x, y) = HOUSE;
        return true;
    }
    catch (int Errortype)
    {
        switch (Errortype)
        {
            case 1:
                cout << "x값 또는 y값이 올바른 범위 밖에 있습니다, 올바른 범위는 0 <= x < " << base.return_limit_x() <<" , 0 <= y < " << base.return_limit_y() << '.' << endl;
                break;
            case 2:
                cout << "지정한 곳은 길이 아닙니다." << endl;
                break;
            default:
                break;
        }
        return false;
    }
}

void Mymap::remove_house(int x, int y)
{
    try
    {
        if(x < 0 || x >= base.return_limit_x() || y < 0 || y >= base.return_limit_y()) throw 1;
        if(base(x, y) != HOUSE) throw 2;
        base(x, y) = HOUSE;
    }
    catch (int Errortype)
    {
        switch (Errortype)
        {
            case 1:
                cout << "x값 또는 y값이 올바른 범위 밖에 있습니다, 올바른 범위는 0 <= x < " << base.return_limit_x() << " , 0 <= y < " << base.return_limit_y() << '.' << endl;
                break;
            case 2:
                cout << "지정한 곳에는 건물이 없습니다." << endl;
                break;
            default:
                break;
        }
    }
}

void Mymap::remove_house_area(int x_start, int y_start, int x_end, int y_end)
{
    try
    {
        if(x_start < 0 || x_end >= base.return_limit_x() || y_start < 0 || y_end >= base.return_limit_y()) throw 1;
        for(int i = x_start; i <= x_end; i++)
        {
            for(int j = y_start; j <= y_end; j++)
            {
                if(base(i, j) == HOUSE)
                {
                    base(i, j) = PLAIN;
                }
            }
        }
    }
    catch (int Errortype)
    {
        cout << "x값 또는 y값이 올바른 범위 밖에 있습니다, 올바른 범위는 0 <= x < " << base.return_limit_x() <<" , 0 <= y < " << base.return_limit_y() << '.' << endl;
    }
}

void Mymap::remove_all_initialrize()
{
    for(int i = 0; i < base.return_limit_x(); i++)
    {
        for(int j = 0; j < base.return_limit_y(); j++)
        {
            base(i, j) = PLAIN;
        }
    }
}

void Mymap::print()
{
    base.print();
}
