#include <string>
#include <vector>
#include <iostream>
using namespace std;

// n : 구역 갯수, m : 롤러 길이
int solution(int n, int m, vector<int> section) {
    int answer = 1; // 최소 한 번

    int pivot = section[0];
    for (const auto v : section) {
        if (v < pivot + m) {    // 칠한 범위에 있으면
            continue;
        }
        else {  // 없으면
            pivot = v;  // 시작점 바꾸기
            answer++;   // 한 번 더 칠하기
        }
    }




    //vector<int> walls;
    //int answer = 0; // 롤러로 페인트칠해야 하는 최소 횟수

    //int idx = 0;    // section의 인덱스
    //int overPaint; // 색칠할 부분
    //while (idx < section.size()) {
    //    overPaint = section[idx];   // 처음 색칠할 부분
    //    overPaint += (m-1); // 색칠하기
    //    answer++;
    //    idx++;
    //    while (idx < section.size() && 
    //        overPaint >= section[idx]) { // 색칠 안 한 부분 찾기
    //            idx++;
    //    }
    //}

    return answer;
}

int main() {
    //vector<int> section = { 2,3,6 };
    //vector<int> section = { 1,3 };
    vector<int> section = { 1,2,3,4 };

    cout << solution(4, 1, section);

}