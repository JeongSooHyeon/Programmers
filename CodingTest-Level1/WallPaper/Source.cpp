#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

// ��ĭ. ����ĭ#

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;

    int lux=50, luy=50;   // ������
    int rdx=-1, rdy=-1;   // ����

    for (int i = 0; i < wallpaper.size(); i++) {
        for (int j = 0; j < wallpaper[i].size(); j++) {
            if (wallpaper[i][j] == '#') {   // ����ĭ
                if (lux > j) {  // ���� ���� ������
                    lux = j;
                }
                if (luy > i) {
                    luy = i;
                }
                if (rdx < j) {  // ���� ū ����
                    rdx = j;
                }
                if (rdy < i) {
                    rdy = i;
                }
            }
        }
    }

    answer.push_back(lux);
    answer.push_back(luy);
    answer.push_back(rdx);
    answer.push_back(rdy);

    return answer;
}

int main() {
    vector<string> wallpaper = { ".#...", "..#..", "...#." };
    //vector<string> wallpaper = { "..........", ".....#....", "......##..", "...##.....", "....#....." };
    //vector<string> wallpaper = { ".##...##.", "#..#.#..#", "#...#...#", ".#.....#.", "..#...#..", "...#.#...", "....#....", "....#....." };
    //vector<string> wallpaper = { "..", "#." };

    solution(wallpaper);
}