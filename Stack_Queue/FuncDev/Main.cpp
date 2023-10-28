#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

// 선입 선출 Queue
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    int n = progresses.size();
    vector<int> finish(n, 0);

    int pred = 0;   // 먼저 끝내야될 기능
    int result = 0; 

    // 하루 작업하기
    for (int i = pred; i < n; i++) {   
        if (finish[i] == 0) {   // 아직 작업이 끝나지 않았음
            if (progresses[i] < 100)    // 작업하기
                progresses[i] += speeds[i];


            if (progresses[i] >= 100 && finish[i-1]) { // 내 기능을 처음으로 다 했다, 내 전 작업이 끝났다
                finish[i] = 1;  // 작업했음으로 바꿔주기
                q.push(i);

                if (i == pred) {    // 내가 먼저 해야할 기능이면
                    pred++;

                }

            }
        }

    }

    
  

   

    return answer;
}

int main() {
    vector<int> progresses = { 93,30,55 };    // 작업 진도
    vector<int> speeds = { 1,30,5 };        // 개발 속도

    vector<int> result = solution(progresses, speeds);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << ' ';

}