//
//  Mymap_navigator.cpp
//  term project
//
//  Created by 손민균 on 12/3/23.
//

#include "Mymap.h"

void Mymap::print_navigator(int start_x, int start_y, int end_x, int end_y)
{
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    MapImage navigator_road_first = base;
    MapImage navigator_shortest_distance = base;
    
    vector<vector<int>> visit(base.return_limit_x(), vector<int>(base.return_limit_y(), 0));
    
    pair<int, int> start_point(start_x, start_y);
    pair<int, int> end_point(end_x, end_y);
    queue<pair<int, int>> q;
    
    try
    {
        if(start_x == end_x && start_y == end_y) 
        {
            throw 1;
        }
        
        int work_shortest = 0;      //최단거리 bfs에서 걸은 거리
        int work_road_first = 0;    //도로우선 bfs에서 걸은 거리
        int road_length = 0;        //도로우선 bfs에서 도로를 주행한 거리
        {
            //최단거리 bfs
            q.push(start_point);
            visit[start_x][start_y] = 1;
            while (1)
            {
                if(q.empty())
                {
                    throw 2;
                }
                
                pair<int,int> current_point = q.front();
                int x = current_point.first;
                int y = current_point.second;
                q.pop();
                
                for(int i = 0; i < 4; i++)
                {
                    int ix = x + dx[i];
                    int iy = y + dy[i];
                    if(ix < 0 || iy < 0 || ix >= navigator_shortest_distance.return_limit_x() || iy >= navigator_shortest_distance.return_limit_y())
                    {
                        continue;       //범위초과
                    }
                    else if(ix == end_x && iy == end_y)     //도착지점 도달
                    {
                        visit[ix][iy] = visit[x][y] + 1;    //도착지점에 최종 거리값
                        int last = visit[ix][iy];
                        
                        for(int j = visit[ix][iy]; j > 1; j--)
                        {
                            
                            for(int k = 0; k < navigator_shortest_distance.return_limit_x(); k++) //도착지점으로 가는 경로가 아닌 위치의 visit값을 0으로 초기화
                            {
                                for(int l = 0; l < navigator_shortest_distance.return_limit_y(); l++)
                                {
                                    if(visit[k][l] == j && !(k == ix && l == iy))
                                    {
                                        visit[k][l] = 0;
                                    }
                                }
                            }
                            
                            for(int k = 0; k < 4; k++)                                            //도착지점에서 출발지점으로 경로 거슬러 올라가기
                            {
                                int tempx = ix + dx[k];
                                int tempy = iy + dy[k];
                                if(tempx < 0 || tempy < 0 || tempx >= navigator_shortest_distance.return_limit_x() || tempy >= navigator_shortest_distance.return_limit_y()) continue;
                                if(visit[tempx][tempy] == j - 1)
                                {
                                    ix = tempx;
                                    iy = tempy;
                                    break;
                                }
                            }
                        }
                        
                        pair<int, int> now(start_x, start_y);
                        for(int j = 1; j < last; j++)
                        {
                            for(int k = 0; k < 4; k++)
                            {
                                pair<int, int> next(now.first + dx[k], now.second + dy[k]);
                                if(next.first < 0 || next.second < 0 || next.first >= navigator_shortest_distance.return_limit_x() || next.second >= navigator_shortest_distance.return_limit_y()) continue;
                                if(visit[next.first][next.second] == j + 1)
                                {
                                    switch (k)
                                    {
                                        case 0:
                                            navigator_shortest_distance(now.first, now.second) = WEST;
                                            break;
                                        case 1:
                                            navigator_shortest_distance(now.first, now.second) = SOUTH;
                                            break;
                                        case 2:
                                            navigator_shortest_distance(now.first, now.second) = EAST;
                                            break;
                                        case 3:
                                            navigator_shortest_distance(now.first, now.second) = NORTH;
                                            break;
                                        default:
                                            break;
                                    }
                                    now = next;
                                    break;
                                }
                            }
                        }
                        navigator_shortest_distance(start_x, start_y) = CURRENT;
                        navigator_shortest_distance(end_x, end_y) = CURRENT;
                        work_shortest = last;
                        goto end;
                    }
                    else if(navigator_shortest_distance(ix, iy) == HOUSE)
                    {
                        continue;
                    }
                    else if (visit[ix][iy] > 0)
                    {
                        continue;
                    }
                    else
                    {
                        visit[ix][iy] = visit[x][y] + 1;
                        q.push(pair<int, int>(ix, iy));
                    }
                }
            }
        end:
            {
                
            }
        }
        
        {
            //도로 우선 bfs
            pair<int, int> road_start;
            pair<int, int> road_end;
            //시작지점이 길이 아닐때 처리
            if(navigator_road_first(start_x, start_y) != ROAD)
            {
                while (!q.empty()) //큐 비우기
                {
                    q.pop();
                }
                for(auto & e : visit) //visit 벡터 비우기
                {
                    fill(e.begin(), e.end(), 0);
                }
                q.push(start_point);
                visit[start_x][start_y] = 1;
                while (1)
                {
                    if(q.empty())
                    {
                        throw 3;
                    }
                    
                    pair<int,int> current_point = q.front();
                    int x = current_point.first;
                    int y = current_point.second;
                    q.pop();
                    
                    for(int i = 0; i < 4; i++)
                    {
                        int ix = x + dx[i];
                        int iy = y + dy[i];
                        if(ix < 0 || iy < 0 || ix >= navigator_road_first.return_limit_x() || iy >= navigator_road_first.return_limit_y())
                        {
                            continue;       //범위초과
                        }
                        else if(navigator_road_first(ix, iy) == ROAD)     //도착지점 도달
                        {
                            road_start = pair<int, int>(ix, iy);
                            visit[ix][iy] = visit[x][y] + 1;    //도착지점에 최종 거리값
                            int last = visit[ix][iy];
                            
                            for(int j = visit[ix][iy]; j > 1; j--)
                            {
                                
                                for(int k = 0; k < navigator_road_first.return_limit_x(); k++) //도착지점으로 가는 경로가 아닌 위치의 visit값을 0으로 초기화
                                {
                                    for(int l = 0; l < navigator_road_first.return_limit_y(); l++)
                                    {
                                        if(visit[k][l] == j && !(k == ix && l == iy))
                                        {
                                            visit[k][l] = 0;
                                        }
                                    }
                                }
                                
                                for(int k = 0; k < 4; k++)                                            //도착지점에서 출발지점으로 경로 거슬러 올라가기
                                {
                                    int tempx = ix + dx[k];
                                    int tempy = iy + dy[k];
                                    if(tempx < 0 || tempy < 0 || tempx >= navigator_road_first.return_limit_x() || tempy >= navigator_road_first.return_limit_y()) continue;
                                    if(visit[tempx][tempy] == j - 1)
                                    {
                                        ix = tempx;
                                        iy = tempy;
                                        break;
                                    }
                                }
                            }
                            
                            pair<int, int> now(start_x, start_y);
                            for(int j = 1; j < last; j++)
                            {
                                for(int k = 0; k < 4; k++)
                                {
                                    pair<int, int> next(now.first + dx[k], now.second + dy[k]);
                                    if(next.first < 0 || next.second < 0 || next.first >= navigator_road_first.return_limit_x() || next.second >= navigator_road_first.return_limit_y()) continue;
                                    if(visit[next.first][next.second] == j + 1)
                                    {
                                        switch (k)
                                        {
                                            case 0:
                                                navigator_road_first(now.first, now.second) = WEST;
                                                break;
                                            case 1:
                                                navigator_road_first(now.first, now.second) = SOUTH;
                                                break;
                                            case 2:
                                                navigator_road_first(now.first, now.second) = EAST;
                                                break;
                                            case 3:
                                                navigator_road_first(now.first, now.second) = NORTH;
                                                break;
                                            default:
                                                break;
                                        }
                                        now = next;
                                        break;
                                    }
                                }
                            }
                            work_road_first += last;
                            goto end1;
                        }
                        else if(navigator_road_first(ix, iy) == HOUSE)
                        {
                            continue;
                        }
                        else if (visit[ix][iy] > 0)
                        {
                            continue;
                        }
                        else
                        {
                            visit[ix][iy] = visit[x][y] + 1;
                            q.push(pair<int, int>(ix, iy));
                        }
                    }
                }
            }
            else
            {
                road_start = pair<int, int>(start_x, start_y);
            }
        end1:
            {
                
            }
            //끝지점이 길이 아닐 때 처리
            if(navigator_road_first(end_x, end_y) != ROAD)
            {
                while (!q.empty()) //큐 비우기
                {
                    q.pop();
                }
                for(auto & e : visit) //visit 벡터 비우기
                {
                    fill(e.begin(), e.end(), 0);
                }
                q.push(end_point);
                visit[end_x][end_y] = 1;
                while (1)
                {
                    if(q.empty())
                    {
                        throw 3;
                    }
                    
                    pair<int,int> current_point = q.front();
                    int x = current_point.first;
                    int y = current_point.second;
                    q.pop();
                    
                    for(int i = 0; i < 4; i++)
                    {
                        int ix = x + dx[i];
                        int iy = y + dy[i];
                        if(ix < 0 || iy < 0 || ix >= navigator_road_first.return_limit_x() || iy >= navigator_road_first.return_limit_y())
                        {
                            continue;       //범위초과
                        }
                        else if(navigator_road_first(ix, iy) == ROAD)     //도착지점 도달
                        {
                            road_end = pair<int, int>(ix, iy);
                            visit[ix][iy] = visit[x][y] + 1;    //도착지점에 최종 거리값
                            int last = visit[ix][iy];
                            
                            for(int j = visit[ix][iy]; j > 1; j--)
                            {
                                
                                for(int k = 0; k < navigator_road_first.return_limit_x(); k++) //도착지점으로 가는 경로가 아닌 위치의 visit값을 0으로 초기화
                                {
                                    for(int l = 0; l < navigator_road_first.return_limit_y(); l++)
                                    {
                                        if(visit[k][l] == j && !(k == ix && l == iy))
                                        {
                                            visit[k][l] = 0;
                                        }
                                    }
                                }
                                
                                for(int k = 0; k < 4; k++)                                            //도착지점에서 출발지점으로 경로 거슬러 올라가기
                                {
                                    int tempx = ix + dx[k];
                                    int tempy = iy + dy[k];
                                    if(tempx < 0 || tempy < 0 || tempx >= navigator_road_first.return_limit_x() || tempy >= navigator_road_first.return_limit_y()) continue;
                                    if(visit[tempx][tempy] == j - 1)
                                    {
                                        ix = tempx;
                                        iy = tempy;
                                        break;
                                    }
                                }
                            }
                            
                            pair<int, int> now(end_x, end_y);
                            for(int j = 1; j < last; j++)
                            {
                                for(int k = 0; k < 4; k++)
                                {
                                    pair<int, int> next(now.first + dx[k], now.second + dy[k]);
                                    if(next.first < 0 || next.second < 0 || next.first >= navigator_road_first.return_limit_x() || next.second >= navigator_road_first.return_limit_y()) continue;
                                    if(visit[next.first][next.second] == j + 1)
                                    {
                                        switch (k)
                                        {
                                            case 0:
                                                navigator_road_first(next.first, next.second) = EAST;
                                                break;
                                            case 1:
                                                navigator_road_first(next.first, next.second) = NORTH;
                                                break;
                                            case 2:
                                                navigator_road_first(next.first, next.second) = WEST;
                                                break;
                                            case 3:
                                                navigator_road_first(next.first, next.second) = SOUTH;
                                                break;
                                            default:
                                                break;
                                        }
                                        now = next;
                                        break;
                                    }
                                }
                            }
                            work_road_first += last;
                            goto end2;
                        }
                        else if(navigator_road_first(ix, iy) == HOUSE)
                        {
                            continue;
                        }
                        else if (visit[ix][iy] > 0)
                        {
                            continue;
                        }
                        else
                        {
                            visit[ix][iy] = visit[x][y] + 1;
                            q.push(pair<int, int>(ix, iy));
                        }
                    }
                }
            }
            else
            {
                road_end = pair<int, int>(end_x, end_y);
            }
        end2:
            {
                
            }
            //길 안에서의 bfs
            while (!q.empty()) //큐 비우기
            {
                q.pop();
            }
            for(auto & e : visit) //visit 벡터 비우기
            {
                fill(e.begin(), e.end(), 0);
            }
            
            q.push(road_start);
            visit[road_start.first][road_start.second] = 1;
            while (1)
            {
                if(q.empty())
                {
                    if(road_start == road_end)
                        break;
                    else
                        throw 3;
                }
                
                pair<int,int> current_point = q.front();
                int x = current_point.first;
                int y = current_point.second;
                q.pop();
                
                for(int i = 0; i < 4; i++)
                {
                    int ix = x + dx[i];
                    int iy = y + dy[i];
                    if(ix < 0 || iy < 0 || ix >= navigator_road_first.return_limit_x() || iy >= navigator_road_first.return_limit_y())
                    {
                        continue;       //범위초과
                    }
                    else if(pair<int, int>(ix, iy) == road_end)     //도착지점 도달
                    {
                        visit[ix][iy] = visit[x][y] + 1;    //도착지점에 최종 거리값
                        int last = visit[ix][iy];
                        
                        for(int j = visit[ix][iy]; j > 1; j--)
                        {
                            
                            for(int k = 0; k < navigator_road_first.return_limit_x(); k++) //도착지점으로 가는 경로가 아닌 위치의 visit값을 0으로 초기화
                            {
                                for(int l = 0; l < navigator_road_first.return_limit_y(); l++)
                                {
                                    if(visit[k][l] == j && !(k == ix && l == iy))
                                    {
                                        visit[k][l] = 0;
                                    }
                                }
                            }
                            
                            for(int k = 0; k < 4; k++)                                            //도착지점에서 출발지점으로 경로 거슬러 올라가기
                            {
                                int tempx = ix + dx[k];
                                int tempy = iy + dy[k];
                                if(tempx < 0 || tempy < 0 || tempx >= navigator_road_first.return_limit_x() || tempy >= navigator_road_first.return_limit_y()) continue;
                                if(visit[tempx][tempy] == j - 1)
                                {
                                    ix = tempx;
                                    iy = tempy;
                                    break;
                                }
                            }
                        }
                        
                        pair<int, int> now(road_start);
                        for(int j = 1; j < last; j++)
                        {
                            for(int k = 0; k < 4; k++)
                            {
                                pair<int, int> next(now.first + dx[k], now.second + dy[k]);
                                if(next.first < 0 || next.second < 0 || next.first >= navigator_road_first.return_limit_x() || next.second >= navigator_road_first.return_limit_y()) continue;
                                if(visit[next.first][next.second] == j + 1)
                                {
                                    switch (k)
                                    {
                                        case 0:
                                            navigator_road_first(now.first, now.second) = WEST;
                                            break;
                                        case 1:
                                            navigator_road_first(now.first, now.second) = SOUTH;
                                            break;
                                        case 2:
                                            navigator_road_first(now.first, now.second) = EAST;
                                            break;
                                        case 3:
                                            navigator_road_first(now.first, now.second) = NORTH;
                                            break;
                                        default:
                                            break;
                                    }
                                    now = next;
                                    break;
                                }
                            }
                        }
                        road_length = last;
                        goto end3;
                    }
                    else if(navigator_road_first(ix, iy) != ROAD)
                    {
                        continue;
                    }
                    else if (visit[ix][iy] > 0)
                    {
                        continue;
                    }
                    else
                    {
                        visit[ix][iy] = visit[x][y] + 1;
                        q.push(pair<int, int>(ix, iy));
                    }
                }
            }
        end3:
            {
                
            }
            navigator_road_first(start_x, start_y) = CURRENT;
            navigator_road_first(end_x, end_y) = CURRENT;
        }
        if(work_shortest <= work_road_first)
        {
            navigator_shortest_distance.print();
        }
        else
        {
            navigator_road_first.print();
        }
    }
    catch(int Errortype)
    {
        switch (Errortype)
        {
            case 1:
                cout << "출발 지점과 끝지점이 같습니다." << endl;
                break;
            case 2:
                cout << "경로가 없습니다." << endl;
            case 3:
                navigator_shortest_distance.print();
            default:
                break;
        }
    }
}
