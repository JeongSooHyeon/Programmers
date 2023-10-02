#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

// 빈칸. 파일칸#

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;

    int lux=50, luy=50;   // 시작점
    int rdx=-1, rdy=-1;   // 끝점

    for (int i = 0; i < wallpaper.size(); i++) {
        for (int j = 0; j < wallpaper[i].size(); j++) {
            if (wallpaper[i][j] == '#') {   // 파일칸
                if (lux > i) {  // 가장 작은 시작점
                    lux = i;
                }
                if (luy > j) {
                    luy = j;
                }
                if (rdx < i) {  // 가장 큰 끝점
                    rdx = i+1;
                }
                if (rdy < j) {
                    rdy = j+1;
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