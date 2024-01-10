#include <string>
#include <vector>
#include <iostream>
using namespace std;

// 프로세스의 중요도가 순서대로 담긴 배열, 몇 번째로 실행되는지 위치
int solution(vector<int> priorities, int location) {
    int answer = 0;


    int first;   // 대기 중인 첫번째 프로세스
    int pri;   // 가장 높은 우선순위 

    while (true) {
        first = priorities.front();
        pri = priorities[0];

        // 가장 높은 우선순위 찾기
        for (int i = 1; i < priorities.size(); i++) {
            if (pri < priorities[i]) {
                pri = priorities[i];
            }
        }

        // 배열 옮기기
        for (int i = 0; i < priorities.size() - 1; i++) {
            priorities[i] = priorities[i + 1];
        }

        // 현재 프로세스보다 더 높은 프로세스가 있으면
        if (first < pri) {   
            
            priorities[priorities.size() - 1] = first;   // 다시 뒤로 넣어줌
        }
        else {  // 없으면 실행
            answer++;
            if (location == 0)
                break;
            priorities.pop_back();  
        }
      

        location--;
        if (location < 0) {
            location = priorities.size() - 1;
        }
    }
    return answer;
}
int main() {
    vector<int> priorities = { 2,1,3,2 };
    cout << solution(priorities, 2);

}