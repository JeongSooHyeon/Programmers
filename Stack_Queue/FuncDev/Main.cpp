#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

// 선입 선출 Queue
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    queue<int> q;

    ///////////////// 다른 사람 풀이 ////////////////////////////
    // 걸리는 기간 queue에 저장
    //for (int i = 0; i< progresses.size(); i++) {
    //    int temp = (100 - progresses[i]) % speeds[i];   // 일하고 나머지
    //    if (temp == 0) {    // 일을 다 했어
    //        q.push((100 - progresses[i]) / speeds[i]);
    //    }
    //    else {
    //        q.push((100 - progresses[i]) / speeds[i] + 1);
    //    }
    //}

    //while (!q.empty()) {
    //    int cnt = 1;    // 한 번에 끝나는 작업 개수
    //    int cur = q.front();    // 먼저 끝난 작업
    //    q.pop();

    //    while (cur >= q.front() && !q.empty()) {
    //        q.pop();
    //        cnt++;
    //    }
    //    answer.push_back(cnt);
    //}
    //return answer;















    int n = progresses.size();


    int pred = 0;   // 먼저 끝내야될 기능
    int result = 0; 

    for (int i = 0; i < n; i++) {
        q.push(i);  // 작업 순서대로 넣어놓기
    }

    while(true){
        // 하루 작업
        for (int i = 0; i < n; i++) {
            progresses[i] += speeds[i]; // 작업하기
            if (pred == i && progresses[i] >= 100) { // 작업 완료
                pred++; 
                if (q.front() < pred) {
                    q.pop();
                    result++;
                }
            }
        }
        if (result != 0)
            answer.push_back(result);
        result = 0;
        if (pred == n)
            break;
    }

    return answer;
}

int main() {
    //vector<int> progresses = { 93,30,55 };    // 작업 진도
    //vector<int> speeds = { 1,30,5 };        // 개발 속도
    vector<int> progresses = { 93,90,99,99,80,99 };    // 작업 진도
    vector<int> speeds = { 1,1,1,1,1,1 };        // 개발 속도
    vector<int> result = solution(progresses, speeds);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << ' ';

}