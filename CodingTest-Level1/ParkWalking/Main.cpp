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
            x -= (routes[i][2] - '0');
            break;
        case 'S':
            // ����
            x += (routes[i][2] - '0');
            break;
        case 'W':
            // ����
            y -= (routes[i][2] - '0');
            break;
        case 'E':
            // ����
            y += (routes[i][2]-'0');
            break;
        }

        if (park[x][y] == 'X') {
            continue;
        }

        if ((x < 0 || x >= w) || (y < 0 || y >= h)) {   // ������ ���
            continue;
        }
        startX = x, startY = y;
        answer.push_back(startX+x);
        answer.push_back(startY+y);
    }

    return answer;
}

int main() {
    vector<string> park;
    vector<string> routes;

    park.push_back("SOO");
    park.push_back("OOO");
    park.push_back("OOO");

    routes.push_back("E 2");
    routes.push_back("S 2");
    routes.push_back("W 1");

    solution(park, routes);
    //park.push_back("SOO");
    //park.push_back("OXX");
    //park.push_back("OOO");

    //park.push_back("OSO");
    //park.push_back("OOO");
    //park.push_back("OxO");
    //park.push_back("OOO");


}