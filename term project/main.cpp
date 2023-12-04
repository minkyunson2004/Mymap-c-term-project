#include "Mymap/Mymap.h"
using namespace std;

int main(int argc, const char * argv[])
{
    cout << "지도의 가로 크기, 세로 크기를 입력하시오. 형식 : 가로 세로" << endl;
    int x, y;
    cin >> x >> y;
    Mymap mymap(x, y);
    while (1)
    {
        mymap.print();
        cout << "명령어를 입력하세요." << endl;
        string command;
        cin >> command;
        if(command == "exit")
        {
            break;
        }
        else if(command == "add_nsroad")
        {
            cout << "설치할 도로의 x좌표 값과 y좌표 범위를 입력하시오. 형식 : x좌표 y좌표시작점 y좌표끝점" << endl;
            int x, y_start, y_end;
            cin >> x >> y_start >> y_end;
            
            cout << "현재 지도위에 있는 집을 무시하고 도로를 설치하시겠습니까? y 또는 n" << endl;
            char answer = '\0';
            cin >> answer;
            switch (answer)
            {
                case 'y':
                    mymap.add_NSroad(x, y_start, y_end, true);
                    break;
                case 'n':
                    mymap.add_NSroad(x, y_start, y_end);
                    break;
                default:
                    cout << "올바른 대답을 입력하시오." << endl;
                    break;
            }
            cin.clear();
            while (cin.get() != '\n') continue;
        }
        else if (command == "add_weroad")
        {
            cout << "설치할 도로의 y좌표 값과 x좌표 범위를 입력하시오. 형식 : y좌표 x좌표시작점 x좌표끝점" << endl;
            int y, x_start, x_end;
            cin >> y >> x_start >> x_end;
            
            cout << "현재 지도위에 있는 집을 무시하고 도로를 설치하시겠습니까? y 또는 n" << endl;
            char answer = '\0';
            cin >> answer;
            switch (answer)
            {
                case 'y':
                    mymap.add_WEroad(y, x_start, x_end, true);
                    break;
                case 'n':
                    mymap.add_WEroad(y, x_start, x_end);
                    break;
                default:
                    cout << "올바른 대답을 입력하시오." << endl;
                    break;
            }
            cin.clear();
            while (cin.get() != '\n') continue;
        }
        else if (command == "add_road")
        {
            cout << "설치할 도로의 x좌표 값과 y좌표 값을 입력하시오. 형식 : x좌표 y좌표" << endl;
            int x, y;
            cin >> x >> y;
            
            cout << "현재 지도위에 있는 집을 무시하고 도로를 설치하시겠습니까? y 또는 n" << endl;
            char answer = '\0';
            cin >> answer;
            switch (answer)
            {
                case 'y':
                    mymap.add_road(x, y, true);
                    break;
                case 'n':
                    mymap.add_road(x, y);
                    break;
                default:
                    cout << "올바른 대답을 입력하시오." << endl;
                    break;
            }
            cin.clear();
            while (cin.get() != '\n') continue;
        }
        else if (command == "remove_nsroad")
        {
            cout << "삭제할 도로의 x좌표 값과 y좌표 범위를 입력하시오. 형식 : x좌표 y좌표시작점 y좌표끝점" << endl;
            int x, y_start, y_end;
            cin >> x >> y_start >> y_end;
            
            mymap.remove_NSroad(x, y_start, y_end);
            cin.clear();
            while (cin.get() != '\n') continue;
        }
        else if (command == "remove_weroad")
        {
            cout << "삭제할 도로의 y좌표 값과 x좌표 범위를 입력하시오. 형식 : y좌표 x좌표시작점 x좌표끝점" << endl;
            int y, x_start, x_end;
            cin >> y >> x_start >> x_end;
            
            mymap.remove_WEroad(y, x_start, x_end);
            cin.clear();
            while (cin.get() != '\n') continue;
        }
        else if (command == "remove_road_area")
        {
            cout << "삭제할 도로의 x좌표 범위와 y좌표 범위를 입력하시오. 형식 : x좌표시작점 y좌표시작점 x좌표끝점 y좌표끝점" << endl;
            int x_start, y_start, x_end, y_end;
            cin >> x_start >> y_start >> x_end >> y_end;
            
            mymap.remove_road_area(x_start, y_start, x_end, y_end);
            cin.clear();
            while (cin.get() != '\n') continue;
        }
        else if (command == "remove_road")
        {
            cout << "삭제할 도로의 x좌표와 y좌표를 입력하시오. 형식 : x좌표 y좌표" << endl;
            int x, y;
            cin >> x >> y;
            
            mymap.remove_road(x, y);
            cin.clear();
            while (cin.get() != '\n') continue;
        }
        else if (command == "add_house")
        {
            cout << "설치할 집의 x좌표와 y좌표를 입력하시오. 형식 : x좌표 y좌표" << endl;
            int x, y;
            cin >> x >> y;
            
            cout << "현재 지도위에 있는 도로를 무시하고 집을 설치하시겠습니까? y 또는 n" << endl;
            char answer = '\0';
            cin >> answer;
            switch (answer)
            {
                case 'y':
                    mymap.add_house(x, y, true);
                    break;
                case 'n':
                    mymap.add_house(x, y);
                    break;
                default:
                    cout << "올바른 대답을 입력하시오." << endl;
                    break;
            }
            
            cin.clear();
            while (cin.get() != '\n') continue;
        }
        else if (command == "remove_house")
        {
            cout << "제거할 집의 x좌표와 y좌표를 입력하시오. 형식 : x좌표 y좌표" << endl;
            int x, y;
            cin >> x >> y;
            
            mymap.remove_house(x, y);
            
            cin.clear();
            while (cin.get() != '\n') continue;
        }
        else if (command == "remove_house_area")
        {
            cout << "제거할 집들의 x좌표 범위와 y좌표 범위를 입력하시오. 형식 : x좌표시작점 y좌표시작점 x좌표끝점 y좌표끝점" << endl;
            int x_start, y_start, x_end, y_end;
            cin >> x_start >> y_start >> x_end >> y_end;
            
            mymap.remove_house_area(x_start, y_start, x_end, y_end);
            
            cin.clear();
            while (cin.get() != '\n') continue;
        }
        else if (command == "remove_all_initialrize")
        {
            cout << "지도가 초기화 되었습니다." << endl;
        }
        else if (command == "register_place")
        {
            string name;
            int x, y;
            cout << "등록할 장소의 이름과 좌표를 입력해주세요." << endl;
            cin >> name >> x >> y;
            mymap.register_place(name, x, y);
            
            cin.clear();
            while (cin.get() != '\n') continue;
        }
        else if (command == "remove_place")
        {
            cout << "목록에서 지울 장소의 이름을 입력 or 좌표를 입력 y/n" << endl;
            char answer = '\0';
            cin >> answer;
            cin.clear();
            while (cin.get() != '\n') continue;
            switch (answer)
            {
                case 'y':
                {
                    string name;
                    cout << "장소의 이름을 입력해주세요." << endl;
                    cin >> name;
                    mymap.remove_place(name);
                    break;
                }
                case 'n':
                {
                    int x, y;
                    cout << "장소의 좌표를 입력해주세요." << endl;
                    cin >> x >> y;
                    mymap.remove_place(x, y);
                    break;
                }
                default:
                    cout << "올바른 대답을 입력하시오." << endl;
                    break;
            }
            cin.clear();
            while (cin.get() != '\n') continue;
        }
        else if (command == "register_place_and_building")
        {
            string name;
            int x, y;
            cout << "등록할 건물의 이름과 좌표를 입력해주세요." << endl;
            cin >> name >> x >> y;
            mymap.register_place_and_building(name, x, y);
            
            cin.clear();
            while (cin.get() != '\n') continue;
        }
        else if (command == "remove_place_and_building")
        {
            cout << "목록에서 지울 건물의 이름을 입력 or 좌표를 입력 y/n" << endl;
            char answer = '\0';
            cin >> answer;
            cin.clear();
            while (cin.get() != '\n') continue;
            switch (answer)
            {
                case 'y':
                {
                    string name;
                    cout << "장소의 이름을 입력해주세요." << endl;
                    cin >> name;
                    mymap.remove_place_and_building(name);
                    break;
                }
                case 'n':
                {
                    int x, y;
                    cout << "장소의 좌표를 입력해주세요." << endl;
                    cin >> x >> y;
                    mymap.remove_place_and_building(x, y);
                    break;
                }
                default:
                    cout << "올바른 대답을 입력하시오." << endl;
                    break;
            }
            cin.clear();
            while (cin.get() != '\n') continue;
        }
        else if (command == "register_place_print")
        {
            mymap.register_place_print();
            cin.clear();
            while (cin.get() != '\n') continue;
        }
        else if (command == "command_list")
        {
            cout << "void add_WEroad(int y, int x_start, int x_end, bool house_destroy = false) 동서방향 길추가" << endl;
            cout << "void add_NSroad(int x, int y_start, int y_end, bool house_destroy = false); 남북방향 길추가" << endl;
            cout << "void add_road(int x, int y, bool house_destroy = false); 길추가" << endl;
            cout << "void remove_WEroad(int y, int x_start, int x_end); 동서방향 길삭제" << endl;
            cout << "void remove_NSroad(int x, int y_srart, int y_end); 남북방향 길삭제" << endl;
            cout << "void remove_road(int x, int y); 길삭제" << endl;
            cout << "void remove_road_area(int x_start, int y_start, int x_end, int y_end); 영역안의 도로 모두 삭제" << endl;
            cout << "bool add_house(int x, int y, bool ignore_road = false); 집추가" << endl;
            cout << "void remove_house(int x, int y); 집제거" << endl;
            cout << "void remove_house_area(int x_start, int y_start, int x_end, int y_end); 영역안의 집모두 제거" << endl;
            cout << "void remove_all_initialrize(); 지도를 초기화" << endl;
            cout << "void register_place(string place_name, int x, int y); 특정 좌표에 장소명 부여" << endl;
            cout << "void remove_place(string place_name); 부여된 장소명 삭제" << endl;
            cout << "void remove_place(int x, int y); 해당좌표에 부여된 장소명 삭제" << endl;
            cout << "void register_place_and_building(string place_name, int x, int y); 이름이 부여된 건물 생성" << endl;
            cout << "void remove_place_and_building(string place_name); 이름이 부여된 건물 삭제" << endl;
            cout << "void remove_place_and_building(int x, int y); 해당좌표에 이름이 부여된 건물 삭제" << endl;
            cout << "void register_place_print(); 현재 장소명 전부 나열" << endl;
            
            cout << "\n\ncommand_list 명령어 목록 출력" << endl;
            cout << "navigator 좌표에 따른 네비게이션 기능제공" << endl;
            cout << "exit 프로그램 종료" << endl;
            cout << "\n\n명령어 리스트의 함수명을 소문자로 입력 이후 출력되는 지시에 따라 입력" << endl;
            cin.clear();
            while (cin.get() != '\n') continue;
        }
        else if (command == "navigator")
        {
            try
            {
                int option;
                cout << "네비게이터 옵션을 선택 해주세요." << endl;
                cout << "1. 장소 이름 -> 장소 이름" << endl;
                cout << "2. 장소 이름 -> 좌표" << endl;
                cout << "3. 좌표 -> 장소 이름" << endl;
                cout << "4. 좌표 -> 좌표" << endl;
                cin >> option;
                switch (option)
                {
                    case 1:
                    {
                        string start_name, end_name;
                        cin >> start_name >> end_name;
                        if(mymap.return_place_pos(start_name) == pair<int, int>(-1, -1) || mymap.return_place_pos(end_name) == pair<int, int>(-1, -1)) throw 1;
                        mymap.print_navigator(mymap.return_place_pos(start_name).first, mymap.return_place_pos(start_name).second, mymap.return_place_pos(end_name).first, mymap.return_place_pos(end_name).second);
                        break;
                    }
                    case 2:
                    {
                        string start_name;
                        int end_x, end_y;
                        cin >> start_name >> end_x >> end_y;
                        if(mymap.return_place_pos(start_name) == pair<int, int>(-1, -1)) throw 1;
                        mymap.print_navigator(mymap.return_place_pos(start_name).first, mymap.return_place_pos(start_name).second, end_x, end_y);
                        break;
                    }
                    case 3:
                    {
                        int start_x, start_y;
                        string end_name;
                        cin >> start_x >> start_y >> end_name;
                        if(mymap.return_place_pos(end_name) == pair<int, int>(-1, -1)) throw 1;
                        mymap.print_navigator(start_x, start_y, mymap.return_place_pos(end_name).first, mymap.return_place_pos(end_name).second);
                        break;
                    }
                    case 4:
                    {
                        int x1, y1, x2, y2;
                        cin >> x1 >> y1 >> x2 >> y2;
                        mymap.print_navigator(x1, y1, x2, y2);
                    }
                    default:
                        break;
                }
                cin.clear();
                while (cin.get() != '\n') continue;
            } 
            catch(int Errortype)
            {
                cout << "입력하신 이름의 장소가 존재하지 않습니다." << endl;
                cin.clear();
                while (cin.get() != '\n') continue;
            }
        }
        else
        {
            cout << "잘못된 명령어입니다." << endl;
            cin.clear();
            while (cin.get() != '\n') continue;
        }
    }
}
