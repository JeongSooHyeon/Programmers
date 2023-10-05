#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

// 빈칸. 파일칸#

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer = { 100,100,-100,-100 };

    //int lux=50, luy=50;   // 시작점
    //int rdx=-1, rdy=-1;   // 끝점

    const int n = wallpaper.size(); // 최적화 !
    const int m = wallpaper[0].size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (wallpaper[i][j] == '#') {   // 파일칸
                answer[0] = min(answer[0], i);
                answer[1] = min(answer[1], j);
                answer[2] = max(answer[2], i+1);
                answer[3] = max(answer[3], j+1);

                //if (lux > i) {  // 가장 작은 시작점
                //    lux = i;
                //}
                //if (luy > j) {
                //    luy = j;
                //}
                //if (rdx < i+1) {  // 가장 큰 끝점
                //    rdx = i+1;
                //}
                //if (rdy < j+1) {
                //    rdy = j+1;
                //}
            }
        }
    }

    //answer.push_back(lux);
    //answer.push_back(luy);
    //answer.push_back(rdx);
    //answer.push_back(rdy);

    return answer;
}

int main() {
    //vector<string> wallpaper = { ".#...", "..#..", "...#." };
    vector<string> wallpaper = { "..........", ".....#....", "......##..", "...##.....", "....#....." };
    //vector<string> wallpaper = { ".##...##.", "#..#.#..#", "#...#...#", ".#.....#.", "..#...#..", "...#.#...", "....#....", "....#....." };
    //vector<string> wallpaper = { "..", "#." };

    vector<int> result = solution(wallpaper);

    for (int i = 0; i < result.size(); i++)
        cout << result[i] << ' ';
}