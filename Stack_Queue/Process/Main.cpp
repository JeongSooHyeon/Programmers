#include <string>
#include <vector>
#include <iostream>
using namespace std;

// ���μ����� �߿䵵�� ������� ��� �迭, �� ��°�� ����Ǵ��� ��ġ
int solution(vector<int> priorities, int location) {
    int answer = 0;


    int first;   // ��� ���� ù��° ���μ���
    int pri;   // ���� ���� �켱���� 

    while (true) {
        first = priorities.front();
        pri = priorities[0];

        // ���� ���� �켱���� ã��
        for (int i = 1; i < priorities.size(); i++) {
            if (pri < priorities[i]) {
                pri = priorities[i];
            }
        }

        // �迭 �ű��
        for (int i = 0; i < priorities.size() - 1; i++) {
            priorities[i] = priorities[i + 1];
        }

        // ���� ���μ������� �� ���� ���μ����� ������
        if (first < pri) {   
            
            priorities[priorities.size() - 1] = first;   // �ٽ� �ڷ� �־���
        }
        else {  // ������ ����
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