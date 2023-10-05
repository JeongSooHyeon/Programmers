#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

// ��ĭ. ����ĭ#

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer = { 100,100,-100,-100 };

    //int lux=50, luy=50;   // ������
    //int rdx=-1, rdy=-1;   // ����

    const int n = wallpaper.size(); // ����ȭ !
    const int m = wallpaper[0].size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (wallpaper[i][j] == '#') {   // ����ĭ
                answer[0] = min(answer[0], i);
                answer[1] = min(answer[1], j);
                answer[2] = max(answer[2], i+1);
                answer[3] = max(answer[3], j+1);

                //if (lux > i) {  // ���� ���� ������
                //    lux = i;
                //}
                //if (luy > j) {
                //    luy = j;
                //}
                //if (rdx < i+1) {  // ���� ū ����
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