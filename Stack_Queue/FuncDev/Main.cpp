#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

// ���� ���� Queue
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    int n = progresses.size();
    vector<int> finish(n, 0);

    int pred = 0;   // ���� �����ߵ� ���
    int result = 0; 

    // �Ϸ� �۾��ϱ�
    for (int i = pred; i < n; i++) {   
        if (finish[i] == 0) {   // ���� �۾��� ������ �ʾ���
            if (progresses[i] < 100)    // �۾��ϱ�
                progresses[i] += speeds[i];


            if (progresses[i] >= 100 && finish[i-1]) { // �� ����� ó������ �� �ߴ�, �� �� �۾��� ������
                finish[i] = 1;  // �۾��������� �ٲ��ֱ�
                q.push(i);

                if (i == pred) {    // ���� ���� �ؾ��� ����̸�
                    pred++;

                }

            }
        }

    }

    
  

   

    return answer;
}

int main() {
    vector<int> progresses = { 93,30,55 };    // �۾� ����
    vector<int> speeds = { 1,30,5 };        // ���� �ӵ�

    vector<int> result = solution(progresses, speeds);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << ' ';

}