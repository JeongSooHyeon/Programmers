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

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (park[i][j] == 'S') {
                startX = x = i;
                startY = y = j;
                i = h;
                break;
            }
        }
    }

    for (int i = 0; i < routes.size(); i++) {
        switch (routes[i][0]) { // ����
        case 'N':
            // ����
            // ��ֹ� ����
            for (int j = 0; j < routes[i][2] - '0'; j++) {
                x--;
                if (((x < 0 || x >= h) || (y < 0 || y >= w)) ||
                    park[x][y] == 'X') {
                    x = startX;
                    break;;
                }
            }
            break;
        case 'S':
            // ����
            // ��ֹ� ����
            for (int j = 0; j < routes[i][2] - '0'; j++) {

                x++;
                if (((x < 0 || x >= h) || (y < 0 || y >= w)) ||
                    park[x][y] == 'X') {
                    x = startX;
                    break;;
                }
            }
            break;
        case 'W':
            // ����
            // ��ֹ� ����
            for (int j = 0; j < routes[i][2] - '0'; j++) {
                y--;
                if (((x < 0 || x >= h) || (y < 0 || y >= w)) ||
                    park[x][y] == 'X') {
                    y = startY;
                    break;;
                }
            }
            break;
        case 'E':
            // ����
            // ��ֹ� ���� || ���� ���
            for (int j = 0; j < routes[i][2] - '0'; j++) {
                y++;
                if (((x < 0 || x >= h) || (y < 0 || y >= w)) ||
                    park[x][y] == 'X') {
                    y = startY;
                    break;;
                }
            }
            break;
        }

        startX = x, startY = y; // �̵� ���� �� ���� ���� �� �ٲٱ�
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

    //routes.push_back("E 2");
    //routes.push_back("S 2");
    //routes.push_back("W 1");

    //park.push_back("SOO");
    //park.push_back("OXX");
    //park.push_back("OOO");

    routes.push_back("E 2");
    routes.push_back("S 3");
    routes.push_back("W 1");

    park.push_back("OSO");
    park.push_back("OOO");
    park.push_back("OXO");
    park.push_back("OOO");  


    vector<int> result = solution(park, routes);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }




}