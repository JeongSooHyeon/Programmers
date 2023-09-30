#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

// ���� ���� w, ���� ���� h
vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int startX, startY;
    int x, y;
    int w = park[0].size();
    int h = park.size();

    map<pair<int, int>, char> m;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            m.insert(pair<pair<int, int>, char>(pair<int, int>(i, j), park[i][j]));
            if (park[i][j] == 'S') {
                startX = j; x = j;
                startY = i; y = i;
            }
        }
    }

    for (int i = 0; i < routes.size(); i++) {
        switch (routes[i][0]) {
        case 'N':
            // ����
            //x -= (routes[i][2] - '0');

            // ��ֹ� ����
            for (int j = 0; j < routes[j][2] - '0'; j++) {

                x--;
                if(park[x][y]=='X' ||
                    ((x < 0 || x >= w) || (y < 0 || y >= h))){
                    x = startX;
                    y = startY;
                    break;;

                }
            }
            break;
        case 'S':
            // ����
           // x += (routes[i][2] - '0');

            // ��ֹ� ����
            for (int j = 0; j < routes[j][2] - '0'; j++) {

                x++;
                if (park[x][y] == 'X' ||
                    ((x < 0 || x >= w) || (y < 0 || y >= h))) {
                    x = startX;
                    y = startY;
                    break;;

                }
            }

            break;
        case 'W':
            // ����
            //y -= (routes[i][2] - '0');

            // ��ֹ� ����
            for (int j = 0; j < routes[j][2] - '0'; j++) {

                y--;
                if (park[x][y] == 'X' ||
                    ((x < 0 || x >= w) || (y < 0 || y >= h))) {
                    x = startX;
                    y = startY;
                    break;;

                }
            }

            break;
        case 'E':
            // ����
//            y += (routes[i][2] - '0');

            // ��ֹ� ���� || ���� ���
            for (int j = 0; j < routes[j][2] - '0'; j++) {
                y++;
                if (park[x][y] == 'X' ||
                    ((x < 0 || x >= w) || (y < 0 || y >= h))
                    ) {
                    x = startX;
                    y = startY;
                    break;;
                }
            }
            break;
        }

        startX = x, startY = y;
    }

    answer.push_back(x);
    answer.push_back(y);
    return answer;
}

int main() {
    vector<string> park;
    vector<string> routes;

    //park.push_back("SOO");
    //park.push_back("OOO");
    //park.push_back("OOO");

    routes.push_back("E 2");
    routes.push_back("S 2");
    routes.push_back("W 1");

    park.push_back("SOO");
    park.push_back("OXX");
    park.push_back("OOO");

    //routes.push_back("E 2");
    //routes.push_back("S 3");
    //routes.push_back("W 1");

    //park.push_back("OSO");
    //park.push_back("OOO");
    //park.push_back("OXO");
    //park.push_back("OOO");  


    vector<int> result = solution(park, routes);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }




}